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



#define DT_BASE "/sys/firmware/devicetree/base"

#define PLATFORM_NAME_BEAGLEBONE_BLACK "Beaglebone Black"
#define PLATFORM_NAME_BEAGLEBONE_GREEN "Beaglebone Green"
#define PLATFORM_NAME_BEAGLEBONE_GREEN_WIRELESS "Beaglebone Green Wireless"
#define PLATFORM_NAME_BEAGLEBONE_ENHANCED "Beaglebone Enhanced"


#define SYSFS_DEVICES_CAPEMGR_SLOTS "/sys/devices/platform/bone_capemgr/slots"
#define SYSFS_CLASS_PWM "/sys/class/pwm/"
#define SYSFS_CLASS_MMC "/sys/class/mmc_host/"
#define SYSFS_PWM_OVERLAY "BB-PWM"
#define AIN_OVERLAY "BB-ADC"
#define UART_OVERLAY "BB-UART"
#define SPI_OVERLAY "BB-SPIDEV"
#define I2C_OVERLAY "BB-I2C"
#define MAX_SIZE 64

mraa_result_t mraa_beaglebone_aio_get_fp(mraa_aio_context dev)
{
    return MRAA_SUCCESS;
}

mraa_result_t mraa_beaglebone_aio_init_pre(unsigned int aio)
{
    mraa_result_t ret = MRAA_ERROR_NO_RESOURCES;

    return ret; 
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


mraa_pwm_context
mraa_beaglebone_pwm_init_replace(int pin)
{
	
}
 
int is_cape_load()
{
	mraa_result_t ret = MRAA_ERROR_NO_RESOURCES;
	char* capepath = NULL;
	if(!mraa_file_contains(SYSFS_DEVICES_CAPEMGR_SLOTS, "univ-bbgw")){
		syslog(LOG_INFO, "univ-bbgw doesnt load ");
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
			   "mraa: Failed to write to CapeManager, check that /lib/firmware/univ-bbgw.dtbo exists");
		}
		fclose(fh);				
	}
	return 0;
}
mraa_board_t* mraa_beaglebone()
{
    unsigned int is_rev_c = -1;		
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
	mraa_board_t* b = (mraa_board_t*) calloc(1, sizeof(mraa_board_t));
	if (b == NULL)
	    return NULL;
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
	if(is_cape_load()){
		goto error;
	}

	b->aio_count = 7;
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

	b->adv_func->aio_get_valid_fp = &mraa_beaglebone_aio_get_fp;
	b->adv_func->aio_init_pre = &mraa_beaglebone_aio_init_pre;
	b->adv_func->uart_init_pre = &mraa_beaglebone_uart_init_pre;
	b->adv_func->spi_init_pre = &mraa_beaglebone_spi_init_pre;
	b->adv_func->i2c_init_pre = &mraa_beaglebone_i2c_init_pre;
	b->adv_func->pwm_init_replace = &mraa_beaglebone_pwm_init_replace;
	
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
    b->uart_dev_count = 6;
    b->def_uart_dev = 0;
	b->uart_dev[0].device_path = "/dev/ttyO0";
	
    b->uart_dev[1].rx = 46 + 26;
    b->uart_dev[1].tx = 46 + 24;
	b->uart_dev[1].device_path = "/dev/ttyO1";
	
    b->uart_dev[2].rx = 46 + 22;
    b->uart_dev[2].tx = 46 + 21;	
	b->uart_dev[2].device_path = "/dev/ttyO2";
    // TODO
    //b->uart_dev[3].rx = 0;
    //b->uart_dev[3].tx = 42;
	b->uart_dev[3].device_path = "/dev/ttyO3";
	
    b->uart_dev[4].rx = 46 + 11;
    b->uart_dev[4].tx = 46 + 13;
	b->uart_dev[4].device_path = "/dev/ttyO4";
	
    //b->uart_dev[5].rx = 38;
    //b->uart_dev[5].tx = 37;
	b->uart_dev[5].device_path = "/dev/ttyO5";

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
