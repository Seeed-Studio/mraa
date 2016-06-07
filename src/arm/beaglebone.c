/*
 * Copyright (c) 2016 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : Baozhu Zuo

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
#include <string.h>
#include <sys/mman.h>
#include <mraa/types.h>

#include "common.h"
#include "arm/beaglebone.h"
#include "arm/bbg.h"
#include "arm/bbgw.h"

#define AIN_OVERLAY "BB-ADC"


#define DT_BASE "/sys/firmware/devicetree/base"

#define PLATFORM_NAME_BEAGLEBONE_BLACK "Beaglebone Black"
#define PLATFORM_NAME_BEAGLEBONE_GREEN "Beaglebone Green"
#define PLATFORM_NAME_BEAGLEBONE_GREEN_WIRELESS "Beaglebone Green Wireless"
#define PLATFORM_NAME_BEAGLEBONE_ENHANCED "Beaglebone Enhanced"


#define SYSFS_DEVICES_CAPEMGR_SLOTS "/sys/devices/platform/bone_capemgr/slots"
#define MAX_SIZE 64
static int get_board_model()
{
	int is_rev_c = -1;
	if (mraa_file_exist(DT_BASE "/model")) {
		 // We are on a modern kernel, great!!!!
		 if (mraa_file_contains(DT_BASE "/model", "TI AM335x BeagleBone Green")) {
				is_rev_c = 3;
		 }  
		 if (mraa_file_contains(DT_BASE "/model", "TI AM335x BeagleBone Green Wireless")) {
				is_rev_c = 2;
		}
		 if (mraa_file_contains(DT_BASE "/model", "TI AM335x BeagleBone Black")) {
				is_rev_c = 1;
		}
		 if (mraa_file_contains(DT_BASE "/model", "SanCloud BeagleBone Enhanced")) {
				is_rev_c = 0;
		}
	}
	return is_rev_c;

}
static char * get_pin_name(int pin){
	int is_rev_c = get_board_model();
	mraa_pininfo_t *pininfos;
	char* name = (char*)calloc(8,sizeof(char*)); 
	int i = 0;
	if(is_rev_c == 2)
		pininfos = bbgw_pininfos;
	else
		pininfos = bbg_pininfos;

	for (i = 0; i <= MRAA_BEAGLEBONE_BLACK_PINCOUNT ; i++)
		{
			if(pininfos[i].gpio.pinmap == pin){
				strncpy(name, pininfos[i].name, 8);
				break;
			}
		}
	return name;
}
static int set_pinmux(int pin, char* function){
	char *name;
	char file_path[64] = "";
	name = get_pin_name(pin);
	FILE* fh;
	snprintf(file_path, 64, "/sys/devices/platform/ocp/ocp:%s_pinmux/state", name);
	if (mraa_file_exist(file_path)) {
			fh = fopen(file_path, "w");
	        if (fh == NULL) {
	            syslog(LOG_ERR, "gpio: Failed to open %s for writing, check access rights for user",file_path);
	            return MRAA_ERROR_UNSPECIFIED;
	        }
	        if (fprintf(fh, function) < 0) {
	            syslog(LOG_ERR, "gpio: Failed to write to %s pinmux",function);
	        }
       		fclose(fh);
	}else
			return MRAA_ERROR_UNSPECIFIED;
	free(name);	
	return MRAA_SUCCESS;
}
mraa_result_t mraa_beaglebone_gpio_init_pre (int pin)
{
	if(set_pinmux(pin,"gpio"))
		return MRAA_ERROR_UNSPECIFIED;
	return MRAA_SUCCESS;
}
mraa_result_t mraa_beaglebone_aio_init_internal_replace (mraa_aio_context dev, int pin){
    mraa_result_t ret = MRAA_ERROR_NO_RESOURCES;
    char devpath[MAX_SIZE];
    char overlay[MAX_SIZE];
    char* capepath = NULL;
	int timeout = 5;
	int i = 0;

	 dev->channel = pin - 1;
	 dev->adc_in_fp = -1;
    sprintf(devpath, "/sys/bus/iio/devices/iio:device0/in_voltage%d_raw", dev->channel);

    if (!mraa_file_exist(devpath)) {
        capepath = mraa_file_unglob(SYSFS_DEVICES_CAPEMGR_SLOTS);
        if (capepath == NULL) {
            syslog(LOG_ERR, "ain: Could not find CapeManager");
            return ret;
        }
        FILE* fh;
        fh = fopen(capepath, "w");
        free(capepath);
        if (fh == NULL) {
            syslog(LOG_ERR, "ain: Failed to open capepath for writing, check access rights for user");
            return ret;
        }
        if (fprintf(fh, AIN_OVERLAY) < 0) {
            syslog(LOG_ERR, "ain: Failed to write to CapeManager");
        }

		fclose(fh);

		while(timeout--) {
			if (mraa_file_exist(devpath)) {
				syslog(LOG_ERR, "ain: Device init O.K!");
	    	    return MRAA_SUCCESS;
			} else {
				syslog(LOG_ERR, "ain: sleep(1)");
                sleep(1);
            }
		}
        syslog(LOG_ERR, "ain: Device not initialized!");
    }
    else {
		ret = MRAA_SUCCESS;
	}
    return ret; 

}

mraa_result_t mraa_beaglebone_aio_init_pre(unsigned int aio)
{

}

mraa_result_t mraa_beaglebone_uart_init_pre(int index)
{
    mraa_result_t ret = MRAA_ERROR_NO_RESOURCES;

    return ret;
}

mraa_result_t mraa_beaglebone_spi_init_pre(int index)
{
    mraa_result_t ret = MRAA_ERROR_NO_RESOURCES;

    return ret;
}

mraa_result_t mraa_beaglebone_i2c_init_pre(unsigned int bus)
{
    mraa_result_t ret = MRAA_ERROR_NO_RESOURCES;
    return ret;
}


mraa_pwm_context mraa_beaglebone_pwm_init_pre(int pin)
{
	int pinnum;
	int is_rev_c = get_board_model();
	if(2 == is_rev_c)
		pinnum = bbgw_pininfos[pin].gpio.pinmap;
	else
		pinnum = bbg_pininfos[pin].gpio.pinmap;
	
	if(set_pinmux(pinnum,"pwm")){
		syslog(LOG_ERR, "mraa: Failed to write pwm pinmux");
		return NULL;
	}
	return MRAA_SUCCESS;
}

static int is_cape_load(unsigned int is_rev_c)
{
	mraa_result_t ret = MRAA_ERROR_NO_RESOURCES;
	char* capepath = NULL;
	char capename[16];
	if(is_rev_c == 2)
		 	strncpy(capename, "univ-bbgw", 16);
		else
			strncpy(capename, "cape-universal", 16);
	if(!mraa_file_contains(SYSFS_DEVICES_CAPEMGR_SLOTS, capename)){
		syslog(LOG_INFO, "%s doesnt load ",capename);
		capepath = mraa_file_unglob(SYSFS_DEVICES_CAPEMGR_SLOTS);
		if (capepath == NULL) {
		    syslog(LOG_ERR, "mraa: Could not find CapeManager");
		    return ret;
		}
		FILE* fh;
		fh = fopen(capepath, "w");
		free(capepath);
		if (fh == NULL) {
		    syslog(LOG_ERR, "mraa: Failed to open capepath for writing, check access rights for user");
		    return ret;
		}
		if (fprintf(fh, "univ-bbgw") < 0) {
		    syslog(LOG_ERR,
			   "mraa: Failed to write to CapeManager, check that /lib/firmware/%s.dtbo exists",capename);
		}
		fclose(fh);			
	}
	return 0;
}
mraa_board_t* mraa_beaglebone()
{
    unsigned int is_rev_c = -1;		
	mraa_board_t* b = (mraa_board_t*) calloc(1, sizeof(mraa_board_t));
	if (b == NULL)
	    return NULL;
	is_rev_c = get_board_model();
	if (is_rev_c == 0) {
	    b->platform_name = PLATFORM_NAME_BEAGLEBONE_ENHANCED;
	    b->phy_pin_count = MRAA_BEAGLEBONE_BLACK_PINCOUNT;
	}
	if (is_rev_c == 1) {
	    b->platform_name = PLATFORM_NAME_BEAGLEBONE_BLACK;
	    b->phy_pin_count = MRAA_BEAGLEBONE_BLACK_PINCOUNT;
	}
	if (is_rev_c == 2) {
	    b->platform_name = PLATFORM_NAME_BEAGLEBONE_GREEN_WIRELESS;
	    b->phy_pin_count = MRAA_BEAGLEBONE_BLACK_PINCOUNT;
	}
	if (is_rev_c == 3) {
	    b->platform_name = PLATFORM_NAME_BEAGLEBONE_GREEN;
	    b->phy_pin_count = MRAA_BEAGLEBONE_BLACK_PINCOUNT;
	}
	if (is_rev_c == -1) {
		goto error;
	}
	if (b->platform_name == NULL) {
	    goto error;
	}
	if(is_cape_load(is_rev_c)){
		goto error;
	}

	b->aio_count = 7+1;
	b->adc_raw = 12;
	b->adc_supported = 12;
	b->pwm_default_period = 500;
	b->pwm_max_period = 2147483;
	b->pwm_min_period = 1;

	b->pins = (mraa_pininfo_t*) calloc(b->phy_pin_count,sizeof(mraa_pininfo_t));
	if (b->pins == NULL) {
	    goto error;
	}

	b->adv_func = (mraa_adv_func_t*) calloc(1, sizeof(mraa_adv_func_t));
	if (b->adv_func == NULL) {
	    free(b->pins);
	    goto error;
	}
	if(is_rev_c == 2)
		b->pins = bbgw_pininfos;
	if(is_rev_c == 3)
		b->pins = bbg_pininfos;
	b->adv_func->gpio_init_pre = &mraa_beaglebone_gpio_init_pre;
	//b->adv_func->aio_get_valid_fp = &mraa_beaglebone_aio_get_fp;
	b->adv_func->aio_init_internal_replace =  &mraa_beaglebone_aio_init_internal_replace;
	//b->adv_func->aio_init_pre = &mraa_beaglebone_aio_init_pre;
	b->adv_func->uart_init_pre = &mraa_beaglebone_uart_init_pre;
	b->adv_func->spi_init_pre = &mraa_beaglebone_spi_init_pre;
	b->adv_func->i2c_init_pre = &mraa_beaglebone_i2c_init_pre;
	b->adv_func->pwm_init_pre = &mraa_beaglebone_pwm_init_pre;
	
    // BUS DEFINITIONS
    b->i2c_bus_count = 2;
    b->def_i2c_bus = 0;

    b->i2c_bus[0].bus_id = 0;
    b->i2c_bus[0].sda = 46 + 18;
    b->i2c_bus[0].scl = 46 + 17;

    b->i2c_bus[1].bus_id = 2;
    b->i2c_bus[1].sda = 46 + 20;
    b->i2c_bus[1].scl = 46 + 19;


    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 1;
    b->spi_bus[0].slave_s = 0;
    b->spi_bus[0].cs = 46 + 17;
    b->spi_bus[0].mosi = 46 + 18;
    b->spi_bus[0].miso = 46 + 21;
    b->spi_bus[0].sclk = 46 + 22;
	
    if (is_rev_c == 2)
        b->spi_bus_count = 1;
    else{
	    b->spi_bus_count = 2;
	    b->spi_bus[1].bus_id = 2;
	    b->spi_bus[1].slave_s = 0;
	    b->spi_bus[1].cs = 46 + 28;
	    b->spi_bus[1].mosi = 46 + 29;
	    b->spi_bus[1].miso = 46 + 30;
	    b->spi_bus[1].sclk = 46 + 31;
    }

    b->def_uart_dev = 0;
	b->uart_dev_count = 5;
    b->uart_dev[0].rx = 46 + 26;
    b->uart_dev[0].tx = 46 + 24;
	b->uart_dev[0].device_path = "/dev/ttyO1";
	
    b->uart_dev[1].rx = 46 + 22;
    b->uart_dev[1].tx = 46 + 21;	
	b->uart_dev[1].device_path = "/dev/ttyO2";

	// TODO
	if(is_rev_c == 2)
		b->uart_dev[2].tx = 0;
	else
		b->uart_dev[2].tx = 42;
	
	b->uart_dev[2].rx = 0;
	b->uart_dev[2].device_path = "/dev/ttyO3";
	
	b->uart_dev[3].rx = 46 + 11;
	b->uart_dev[3].tx = 46 + 13;
	b->uart_dev[3].device_path = "/dev/ttyO4";
	
	b->uart_dev[4].rx = 38;
	b->uart_dev[4].tx = 37;
	b->uart_dev[4].device_path = "/dev/ttyO5";

    b->gpio_count = 0;
    int i;
    for (i = 0; i < b->phy_pin_count; i++)
        if (b->pins[i].capabilites.gpio)
            b->gpio_count++;   

	return b;
error:
    syslog(LOG_CRIT, "Beaglebone: failed to initialize");
    free(b);
    return NULL;
};
