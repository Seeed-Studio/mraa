/*
 * Author: Thomas Ingleby <thomas.c.ingleby@intel.com>
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Copyright (c) 2014, 2015 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

#include "pwm.h"
#include "mraa_internal.h"

#define MAX_SIZE 128
#define SYSFS_PWM "/sys/class/pwm"
typedef struct _bone_pwm_list {
	int pin;
	int mraa_num;
	int sysfs;
	char name[8];
	char chip[16];
	char addr[16];
	int index;
	char module[8];
}bone_pwm;
#define BONE_PWM_COUNT 14
static bone_pwm bone_pwm_list[] = {
	{
		.pin = 23,
		.mraa_num = 13,
		.sysfs = 6,
		.name = "P8_13",
		.chip = "48304000.epwmss",
		.addr = "48304200.pwm",
		.index = 1,
		.module = "ehrpwm2"
	},
	{
		.pin = 22,
		.mraa_num = 19,
		.sysfs = 6,
		.name = "P8_19",
		.chip = "48304000.epwmss",
		.addr = "48304200.pwm",
		.index = 0,
		.module = "ehrpwm2"
	},
	{
		.pin = 81,
		.mraa_num = 34,
		.sysfs = 4,
		.name = "P8_34",
		.chip = "48302000.epwmss",
		.addr = "48302200.pwm",
		.index = 1,
		.module = "ehrpwm1"
	},
	{
		.pin = 80,
		.mraa_num = 36,
		.sysfs = 4,
		.name = "P8_36",
		.chip = "48302000.epwmss",
		.addr = "48302200.pwm",
		.index = 0,
		.module = "ehrpwm1"
	},
	{
		.pin = 70,
		.mraa_num = 45,
		.sysfs = 6,
		.name = "P8_45",
		.chip = "48304000.epwmss",
		.addr = "48304200.pwm",
		.index = 0,
		.module = "ehrpwm2"
	},
	{
		.pin = 71,
		.mraa_num = 46,
		.sysfs = 6,
		.name = "P8_46",
		.chip = "48304000.epwmss",
		.addr = "48304200.pwm",
		.index = 1,
		.module = "ehrpwm2"
	},
	{
		.pin = 50,
		.mraa_num = 60,
		.sysfs = 4,
		.name = "P9_14",
		.chip = "48302000.epwmss",
		.addr = "48302200.pwm",
		.index = 0,
		.module = "ehrpwm1"
	},
	{
		.pin = 51,
		.mraa_num = 62,
		.sysfs = 4,
		.name = "P9_16",
		.chip = "48302000.epwmss",
		.addr = "48302200.pwm",
		.index = 1,
		.module = "ehrpwm2"
	},
	{
		.pin = 3,
		.mraa_num = 67,
		.sysfs = 2,
		.name = "P9_21",
		.chip = "48300000.epwmss",
		.addr = "48300200.pwm",
		.index = 1,
		.module = "ehrpwm0"
	},
	{
		.pin = 2,
		.mraa_num = 68,
		.sysfs = 2,
		.name = "P9_22",
		.chip = "48300000.epwmss",
		.addr = "48300200.pwm",
		.index = 0,
		.module = "ehrpwm0"
	},
	{
		.pin = 113,
		.mraa_num = 74,
		.sysfs = 1,
		.name = "P9_28",
		.chip = "48304000.epwmss",
		.addr = "48304100.ecap",
		.index = 2,
		.module = "ecap2"
	},
	{
		.pin = 111,
		.mraa_num = 75,
		.sysfs = 2,
		.name = "P9_29",
		.chip = "48300000.epwmss",
		.addr = "48300200.pwm",
		.index = 1,
		.module = "ehrpwm0"
	},
	{
		.pin = 89,
		.mraa_num = 77,
		.sysfs = 2,
		.name = "P9_31",
		.chip = "48300000.epwmss",
		.addr = "48300200.pwm",
		.index = 0,
		.module = "ehrpwm0"
	},
	{
		.pin = 7,
		.mraa_num = 88,
		.sysfs = 0,
		.name = "P9_42",
		.chip = "48300000.epwmss",
		.addr = "48300100.ecap",
		.index = 0,
		.module = "ecap0"
	}
};
static int get_bone_pwm(int pin){
	int i = 0;
	for(i = 0 ; i < BONE_PWM_COUNT ; i++){
		if(pin == bone_pwm_list[i].mraa_num)
			return i;
	}
}
/*
*Because of pwmchip num random appear, Use this function to get pwmchip number
*/
static char * get_pwmchip(char *chip, char *addr){
	char bu[MAX_SIZE];
	char *pwmchip;
	DIR *dirptr=NULL;
	int timeout = 10;
	struct dirent *entry;
	snprintf(bu, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm", chip, addr);
	while(timeout--){
		if (mraa_file_exist(bu)) {
			//syslog(LOG_ERR, "pwm: pwmchip init O.K!");
			break;
		} else {
			syslog(LOG_ERR, "pwm: wait pwmchip");
			sleep(1);
		}
	}	

    if((dirptr = opendir(bu))==NULL){
        syslog(LOG_ERR, "%s : Failed to open!->%s", bu, strerror(errno));
        return NULL;
    }
    else{
	    while(entry=readdir(dirptr)){
	    	if(bcmp(entry->d_name, "pwmchip",7) == 0){
				pwmchip = (char*)calloc(16,   sizeof(char*)); 
				strncpy(pwmchip, entry->d_name, 16);
				break;
	    	}
	    }
   		closedir(dirptr);
    }	
	return pwmchip;
}
static int
mraa_pwm_setup_duty_fp(mraa_pwm_context dev)
{
    char bu[MAX_SIZE];
	int index = get_bone_pwm(dev->pin);
	char *pwmchip =  get_pwmchip(bone_pwm_list[index].chip, bone_pwm_list[index].addr);
	if(pwmchip == NULL){
		return MRAA_ERROR_INVALID_HANDLE;
	}
	if(bcmp(plat->platform_name, "Beaglebone",10) == 0)
		///sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/pwmchip2/pwm1/period
    	snprintf(bu, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm/%s/pwm%d/duty_cycle", 
    												bone_pwm_list[index].chip, bone_pwm_list[index].addr, pwmchip, bone_pwm_list[index].index);
	else
    	snprintf(bu, MAX_SIZE, "/sys/class/pwm/pwmchip%d/pwm%d/duty_cycle", dev->chipid, dev->pin);

    dev->duty_fp = open(bu, O_RDWR);
    if (dev->duty_fp == -1) {
        return 1;
    }
	free(pwmchip);
    return 0;
}

static mraa_result_t
mraa_pwm_write_period(mraa_pwm_context dev, int period)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: write_period: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (IS_FUNC_DEFINED(dev, pwm_period_replace)) {
        mraa_result_t result = dev->advance_func->pwm_period_replace(dev, period);
        if (result == MRAA_SUCCESS) {
            dev->period = period;
        }
        return result;
    }
    char bu[MAX_SIZE];
	int index = get_bone_pwm(dev->pin);
	char *pwmchip =  get_pwmchip(bone_pwm_list[index].chip, bone_pwm_list[index].addr);
	if(bcmp(plat->platform_name, "Beaglebone",10) == 0)
		///sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/pwmchip2/pwm1/period
    	snprintf(bu, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm/%s/pwm%d/period", 
    												 bone_pwm_list[index].chip,  bone_pwm_list[index].addr, pwmchip, bone_pwm_list[index].index);
	else
    	snprintf(bu, MAX_SIZE, "/sys/class/pwm/pwmchip%d/pwm%d/period", dev->chipid, dev->pin);	
    int period_f = open(bu, O_RDWR);
    if (period_f == -1) {
        syslog(LOG_ERR, "pwm%i write_period: Failed to open period for writing: %s", dev->pin, strerror(errno));
        return MRAA_ERROR_INVALID_RESOURCE;
    }
    char out[MAX_SIZE];
    int length = snprintf(out, MAX_SIZE, "%d", period);
    if (write(period_f, out, length * sizeof(char)) == -1) {
        close(period_f);
        syslog(LOG_ERR, "pwm%i write_period: Failed to write to period: %s", dev->pin, strerror(errno));
        return MRAA_ERROR_INVALID_RESOURCE;
    }

    close(period_f);
	free(pwmchip);
    dev->period = period;
    return MRAA_SUCCESS;
}

static mraa_result_t
mraa_pwm_write_duty(mraa_pwm_context dev, int duty)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: write_duty: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (IS_FUNC_DEFINED(dev, pwm_write_replace)) {
        return dev->advance_func->pwm_write_replace(dev, duty);
    }
    if (dev->duty_fp == -1) {
        if (mraa_pwm_setup_duty_fp(dev) == 1) {
            syslog(LOG_ERR, "pwm%i write_duty: Failed to open duty_cycle for writing: %s", dev->pin, strerror(errno));
            return MRAA_ERROR_INVALID_RESOURCE;
        }
    }
    char bu[64];
    int length = sprintf(bu, "%d", duty);
    if (write(dev->duty_fp, bu, length * sizeof(char)) == -1)
    {
        syslog(LOG_ERR, "pwm%i write_duty: Failed to write to duty_cycle: %s", dev->pin, strerror(errno));
        return MRAA_ERROR_INVALID_RESOURCE;
    }
    return MRAA_SUCCESS;
}

static int
mraa_pwm_read_period(mraa_pwm_context dev)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: read_period: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (IS_FUNC_DEFINED(dev, pwm_read_replace)) {
        return dev->period;
    }
	
	

    char bu[MAX_SIZE];
    char output[MAX_SIZE];
	int index = get_bone_pwm(dev->pin);
	char *pwmchip =  get_pwmchip(bone_pwm_list[index].chip, bone_pwm_list[index].addr);
	if(bcmp(plat->platform_name, "Beaglebone",10) == 0)
		///sys/devices/platform/ocp/48302000.epwmss/48302200.pwm/pwm/pwmchip2/pwm1/period
    	snprintf(bu, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm/%s/pwm%d/period", 
    												 bone_pwm_list[index].chip,  bone_pwm_list[index].addr, pwmchip, bone_pwm_list[index].index);
	else
		snprintf(bu, MAX_SIZE, "/sys/class/pwm/pwmchip%d/pwm%d/period", dev->chipid, dev->pin);
	
    int period_f = open(bu, O_RDWR);
    if (period_f == -1) {
        syslog(LOG_ERR, "pwm%i read_period: Failed to open period for reading: %s", dev->pin, strerror(errno));
        return 0;
    }

    ssize_t rb = read(period_f, output, MAX_SIZE);
    close(period_f);

    if (rb < 0) {
        syslog(LOG_ERR, "pwm%i read_period: Failed to read period: %s", dev->pin, strerror(errno));
        return -1;
    }

    char* endptr;
    long int ret = strtol(output, &endptr, 10);
    if ('\0' != *endptr && '\n' != *endptr) {
        syslog(LOG_ERR, "pwm%i read_period: Error in string conversion", dev->pin);
        return -1;
    } else if (ret > INT_MAX || ret < INT_MIN) {
        syslog(LOG_ERR, "pwm%i read_period: Number is invalid", dev->pin);
        return -1;
    }
	free(pwmchip);
    dev->period = (int) ret;
    return (int) ret;
}

static int
mraa_pwm_read_duty(mraa_pwm_context dev)
{
    if (!dev) {
       syslog(LOG_ERR, "pwm: read_duty: context is NULL");
       return MRAA_ERROR_INVALID_HANDLE;
    }

    if (IS_FUNC_DEFINED(dev, pwm_read_replace)) {
        return dev->advance_func->pwm_read_replace(dev);
    }

    if (dev->duty_fp == -1) {
        if (mraa_pwm_setup_duty_fp(dev) == 1) {
            syslog(LOG_ERR, "pwm%i read_duty: Failed to open duty_cycle for reading: %s",
                    dev->pin, strerror(errno));
            return -1;
        }
    } else {
        lseek(dev->duty_fp, 0, SEEK_SET);
    }

    char output[MAX_SIZE];
    ssize_t rb = read(dev->duty_fp, output, MAX_SIZE);
    if (rb < 0) {
        syslog(LOG_ERR, "pwm%i read_duty: Failed to read duty_cycle: %s", dev->pin, strerror(errno));
        return -1;
    }

    char* endptr;
    long int ret = strtol(output, &endptr, 10);
    if ('\0' != *endptr && '\n' != *endptr) {
        syslog(LOG_ERR, "pwm%i read_duty: Error in string conversion", dev->pin);
        return -1;
    } else if (ret > INT_MAX || ret < INT_MIN) {
        syslog(LOG_ERR, "pwm%i read_duty: Number is invalid", dev->pin);
        return -1;
    }
    return (int) ret;
}

static mraa_pwm_context
mraa_pwm_init_internal(mraa_adv_func_t* func_table, int chipin, int pin)
{
    mraa_pwm_context dev = (mraa_pwm_context) calloc(1,sizeof(struct _pwm));
    if (dev == NULL) {
        return NULL;
    }
    dev->duty_fp = -1;
    dev->chipid = chipin;
    dev->pin = pin;
    dev->period = -1;
    dev->advance_func = func_table;

    return dev;
}
static int bone_pwm_export(int pin){
	int index = get_bone_pwm(pin);
	char *pwmchip =  get_pwmchip(bone_pwm_list[index].chip, bone_pwm_list[index].addr);
	if(pwmchip == NULL){
		return MRAA_ERROR_INVALID_HANDLE;
	}
	char bu[MAX_SIZE];
	//sys/devices/platform/ocp/48300000.epwmss/48300200.pwm/pwm/pwmchip0/export
	snprintf(bu, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm/%s/export",  
						   bone_pwm_list[index].chip,  bone_pwm_list[index].addr, pwmchip);
    int export_f = open(bu, O_WRONLY);
    if (export_f == -1) {
        syslog(LOG_ERR, "pwm%i open_export: Failed to open export for writing: %s", pin, strerror(errno));
        return MRAA_ERROR_INVALID_RESOURCE;
    }
    char out[MAX_SIZE];
	char pwmfile[MAX_SIZE];
	snprintf(pwmfile, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm/%s/pwm%d",  
		 bone_pwm_list[index].chip,  bone_pwm_list[index].addr, pwmchip, bone_pwm_list[index].index);
    int length = snprintf(out, MAX_SIZE, "%d",  bone_pwm_list[index].index);
	if(!mraa_file_exist(pwmfile)){
	    if (write(export_f, out, length * sizeof(char)) == -1) {
	        close(export_f);
	        syslog(LOG_ERR, "pwm%i write_export: Failed to write to export index: %s", pin, strerror(errno));
	        return MRAA_ERROR_INVALID_RESOURCE;
	    }
	}
    close(export_f);
	free(pwmchip);
	return 0;
}

mraa_pwm_context
mraa_pwm_init(int pin)
{
    mraa_board_t* board = plat;
    if (board == NULL) {
        syslog(LOG_ERR, "pwm_init: Platform Not Initialised");
        return NULL;
    }
    if (mraa_is_sub_platform_id(pin)) {
        syslog(LOG_NOTICE, "pwm_init: Using sub platform");
        board = board->sub_platform;
        if (board == NULL) {
            syslog(LOG_ERR, "pwm_init: Sub platform Not Initialised");
            return NULL;
        }
        pin = mraa_get_sub_platform_index(pin);
    }
    if (pin < 0 || pin > board->phy_pin_count) {
        syslog(LOG_ERR, "pwm_init: pin %i beyond platform definition", pin);
        return NULL;
    }
    if (board->pins[pin].capabilites.pwm != 1) {
        syslog(LOG_ERR, "pwm_init: pin %i not capable of pwm", pin);
        return NULL;
    }
	if(bcmp(plat->platform_name, "Beaglebone",10) == 0){
		bone_pwm_export(pin);
	}
    if (board->adv_func->pwm_init_replace != NULL) {
        return board->adv_func->pwm_init_replace(pin);
    }
    if (board->adv_func->pwm_init_internal_replace != NULL) {
        return board->adv_func->pwm_init_internal_replace(board->adv_func, pin);
    }
    if (board->adv_func->pwm_init_pre != NULL) {
        if (board->adv_func->pwm_init_pre(pin) != MRAA_SUCCESS){
				syslog(LOG_ERR, "pwm_init pre: %d failed", pin);
				return NULL;
        	}
    }
	//beaglebone.c have already seted pinmux
/*  
    if (board->pins[pin].capabilites.gpio == 1) {
        // This deserves more investigation
        mraa_gpio_context mux_i;
        mux_i = mraa_gpio_init_raw(board->pins[pin].gpio.pinmap);
        if (mux_i == NULL) {
            syslog(LOG_ERR, "pwm_init: error in gpio->pwm%i transition. gpio_init", pin);
            return NULL;
        }
        if (mraa_gpio_dir(mux_i, MRAA_GPIO_OUT) != MRAA_SUCCESS) {
            syslog(LOG_ERR, "pwm_init: error in gpio->pwm%i transition. gpio_dir", pin);
            return NULL;
        }
        if (mraa_gpio_write(mux_i, 1) != MRAA_SUCCESS) {
            syslog(LOG_ERR, "pwm_init: error in gpio->pwm%i transition. gpio_write", pin);
            return NULL;
        }
        if (mraa_gpio_close(mux_i) != MRAA_SUCCESS) {
            syslog(LOG_ERR, "pwm_init: error in gpio->pwm%i transition. gpio_close", pin);
            return NULL;
        }
    }
*/
    if (board->pins[pin].pwm.mux_total > 0) {
        if (mraa_setup_mux_mapped(board->pins[pin].pwm) != MRAA_SUCCESS) {
            syslog(LOG_ERR, "pwm_init: Failed to set-up pwm%i multiplexer", pin);
            return NULL;
        }
    }

    int chip = board->pins[pin].pwm.parent_id;
    int pinn = board->pins[pin].pwm.pinmap;

    if (board->adv_func->pwm_init_post != NULL) {
        mraa_pwm_context pret = mraa_pwm_init_raw(chip, pinn);
        mraa_result_t ret = board->adv_func->pwm_init_post(pret);
        if (ret != MRAA_SUCCESS) {
            free(pret);
            return NULL;
        }
        return pret;
    }
    return mraa_pwm_init_raw(chip, pin);
}

mraa_pwm_context
mraa_pwm_init_raw(int chipin, int pin)
{
    mraa_pwm_context dev = mraa_pwm_init_internal(plat == NULL ? NULL : plat->adv_func , chipin, pin);
    if (dev == NULL)
        return NULL;
	/*
    char directory[MAX_SIZE];
    snprintf(directory, MAX_SIZE, SYSFS_PWM "/pwmchip%d/pwm%d", dev->chipid, dev->pin);
    struct stat dir;
    if (stat(directory, &dir) == 0 && S_ISDIR(dir.st_mode)) {
        syslog(LOG_NOTICE, "pwm_init: pwm%i already exported, continuing", pin);
        dev->owner = 0; // Not Owner
    } else {
        char buffer[MAX_SIZE];
        snprintf(buffer, MAX_SIZE, "/sys/class/pwm/pwmchip%d/export", dev->chipid);
        int export_f = open(buffer, O_WRONLY);
        if (export_f == -1) {
            syslog(LOG_ERR, "pwm_init: pwm%i. Failed to open export for writing: %s", pin, strerror(errno));
            free(dev);
            return NULL;
        }

        char out[MAX_SIZE];
        int size = snprintf(out, MAX_SIZE, "%d", dev->pin);
        if (write(export_f, out, size * sizeof(char)) == -1) {
            syslog(LOG_WARNING, "pwm_init: pwm%i. Failed to write to export! (%s) Potentially already in use.", pin, strerror(errno));
            close(export_f);
            free(dev);
            return NULL;
        }
        dev->owner = 1;
        mraa_pwm_period_us(dev, plat->pwm_default_period);
        close(export_f);
    }*/
    	dev->pin = pin;
        dev->owner = 1;
        mraa_pwm_period_us(dev, plat->pwm_default_period);
    mraa_pwm_setup_duty_fp(dev);
    return dev;
}

mraa_result_t
mraa_pwm_write(mraa_pwm_context dev, float percentage)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: write: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (dev->period == -1) {
        if (mraa_pwm_read_period(dev) <= 0)
            return MRAA_ERROR_NO_DATA_AVAILABLE;
    }

    if (percentage > 1.0f) {
        syslog(LOG_WARNING, "pwm_write: %i%% entered, defaulting to 100%%",(int) percentage * 100);
        return mraa_pwm_write_duty(dev, dev->period);
    }
    return mraa_pwm_write_duty(dev, percentage * dev->period);
}

float
mraa_pwm_read(mraa_pwm_context dev)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: read: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    int period = mraa_pwm_read_period(dev);
    if (period > 0) {
        return (mraa_pwm_read_duty(dev) / (float) period);
    }
    return 0.0f;
}

mraa_result_t
mraa_pwm_period(mraa_pwm_context dev, float seconds)
{
    return mraa_pwm_period_ms(dev, seconds * 1000);
}

mraa_result_t
mraa_pwm_period_ms(mraa_pwm_context dev, int ms)
{
    return mraa_pwm_period_us(dev, ms * 1000);
}

mraa_result_t
mraa_pwm_period_us(mraa_pwm_context dev, int us)
{
    int min, max;

    if (!dev) {
        syslog(LOG_ERR, "pwm: period: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (mraa_is_sub_platform_id(dev->chipid)) {
        min = plat->sub_platform->pwm_min_period;
        max = plat->sub_platform->pwm_max_period;
    } else {
        min = plat->pwm_min_period;
        max = plat->pwm_max_period;
    }
    if (us < min || us > max) {
        syslog(LOG_ERR, "pwm_period: pwm%i: %i uS outside platform range", dev->pin, us);
        return MRAA_ERROR_INVALID_PARAMETER;
    }
    return mraa_pwm_write_period(dev, us * 1000);
}

mraa_result_t
mraa_pwm_pulsewidth(mraa_pwm_context dev, float seconds)
{
    return mraa_pwm_pulsewidth_ms(dev, seconds * 1000);
}

mraa_result_t
mraa_pwm_pulsewidth_ms(mraa_pwm_context dev, int ms)
{
    return mraa_pwm_pulsewidth_us(dev, ms * 1000);
}

mraa_result_t
mraa_pwm_pulsewidth_us(mraa_pwm_context dev, int us)
{
    return mraa_pwm_write_duty(dev, us * 1000);
}

mraa_result_t
mraa_pwm_enable(mraa_pwm_context dev, int enable)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: enable: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (IS_FUNC_DEFINED(dev, pwm_enable_replace)) {
        return dev->advance_func->pwm_enable_replace(dev, enable);
    }

    char bu[MAX_SIZE];
	int index = get_bone_pwm(dev->pin);
	char *pwmchip =  get_pwmchip(bone_pwm_list[index].chip, bone_pwm_list[index].addr);
	if(bcmp(plat->platform_name, "Beaglebone",10) == 0)
    	snprintf(bu, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm/%s/pwm%d/enable", 
    												 bone_pwm_list[index].chip,  bone_pwm_list[index].addr, pwmchip, bone_pwm_list[index].index);
	else	
    	snprintf(bu, MAX_SIZE, "/sys/class/pwm/pwmchip%d/pwm%d/enable", dev->chipid, dev->pin);

    int enable_f = open(bu, O_RDWR);

    if (enable_f == -1) {
        syslog(LOG_ERR, "pwm_enable: pwm%i: Failed to open enable for writing: %s", dev->pin, strerror(errno));
        return MRAA_ERROR_INVALID_RESOURCE;
    }
    char out[2];
    int size = snprintf(out, sizeof(out), "%d", enable);
    if (write(enable_f, out, size * sizeof(char)) == -1) {
        syslog(LOG_ERR, "pwm_enable: pwm%i: Failed to write to enable: %s", dev->pin, strerror(errno));
        close(enable_f);
        return MRAA_ERROR_UNSPECIFIED;
    }
    close(enable_f);
	free(pwmchip);
    return MRAA_SUCCESS;
}


mraa_result_t
mraa_pwm_unexport_force(mraa_pwm_context dev)
{
    char filepath[MAX_SIZE];
	int index = get_bone_pwm(dev->pin);
	char *pwmchip =  get_pwmchip(bone_pwm_list[index].chip, bone_pwm_list[index].addr);
	if(bcmp(plat->platform_name, "Beaglebone",10) == 0)
    	snprintf(filepath, MAX_SIZE, "/sys/devices/platform/ocp/%s/%s/pwm/%s/unexport", 
    												 bone_pwm_list[index].chip,  bone_pwm_list[index].addr, pwmchip);
	else	
    	snprintf(filepath, MAX_SIZE, "/sys/class/pwm/pwmchip%d/unexport", dev->chipid);

    int unexport_f = open(filepath, O_WRONLY);
    if (unexport_f == -1) {
        syslog(LOG_ERR, "pwm_unexport: pwm%i: Failed to open unexport for writing: %s", dev->pin, strerror(errno));
        return MRAA_ERROR_INVALID_RESOURCE;
    }

    char out[MAX_SIZE];
    int size = snprintf(out, MAX_SIZE, "%d", dev->pin);
    if (write(unexport_f, out, size * sizeof(char)) == -1) {
        syslog(LOG_ERR, "pwm_unexport: pwm%i: Failed to write to unexport: %s", dev->pin, strerror(errno));
        close(unexport_f);
        return MRAA_ERROR_UNSPECIFIED;
    }

    close(unexport_f);
	free(pwmchip);
    return MRAA_SUCCESS;
}

mraa_result_t
mraa_pwm_unexport(mraa_pwm_context dev)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: unexport: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    mraa_pwm_enable(dev, 0);
    if (dev->owner) {
        return mraa_pwm_unexport_force(dev);
    }
    return MRAA_ERROR_INVALID_PARAMETER;
}

mraa_result_t
mraa_pwm_close(mraa_pwm_context dev)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: close: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    mraa_pwm_unexport(dev);
    free(dev);
    return MRAA_SUCCESS;
}

mraa_result_t
mraa_pwm_owner(mraa_pwm_context dev, mraa_boolean_t owner_new)
{
    if (!dev) {
        syslog(LOG_ERR, "pwm: owner: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }
    dev->owner = owner_new;
    return MRAA_SUCCESS;
}

int
mraa_pwm_get_max_period(mraa_pwm_context dev)
{
    if (plat == NULL) {
        return -1;
    }

    if (!dev) {
        syslog(LOG_ERR, "pwm: get_max_period: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (mraa_is_sub_platform_id(dev->chipid)) {
        return plat->sub_platform->pwm_max_period;
    }
    return plat->pwm_max_period;
}

int
mraa_pwm_get_min_period(mraa_pwm_context dev)
{
    if (plat == NULL) {
        return -1;
    }

    if (!dev) {
        syslog(LOG_ERR, "pwm: get_min_period: context is NULL");
        return MRAA_ERROR_INVALID_HANDLE;
    }

    if (mraa_is_sub_platform_id(dev->chipid)) {
        return plat->sub_platform->pwm_min_period;
    }
    return plat->pwm_min_period;
}
