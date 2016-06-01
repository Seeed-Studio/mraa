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

#pragma once

#ifdef __cplusplus
extern "C" {
#endif
mraa_pininfo_t bbg_pininfos[] = {
		//pin[0]
	{ 
		.name = "INVALID",                 //valid gpio pwm fast_gpio spi i2c aio uart
		.capabilites  = (mraa_pincapabilities_t){ 0, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[1]
	{ 
		.name = "DGND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[2]
	{ 
		.name = "DGND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[3]
	{ 
		.name = "MMC1_DATA6",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},			
	//Pin[4]
	{ 
		.name = "MMC1_DATA7",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[5]
	{ 
		.name = "MMC1_DATA2",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[6]
	{ 
		.name = "MMC1_DATA3",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[7]
	{ 
		.name = "GPIO66",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 66,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0
	},
	//Pin[8]
	{ 
		.name = "GPIO67",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 67,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0
	},
	//Pin[9]
	{ 
		.name = "GPIO69",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 69,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[10]
	{ 
		.name = "GPIO68",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 68,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[11]
	{ 
		.name = "GPIO45",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 45,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[12]
	{ 
		.name = "GPIO44",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 44,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[13]
	{ 
		.name = "GPIO23",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 23,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0,
		.pwm.pinmap = 0,
		.pwm.mux_total = 0

	},			
	//Pin[14]
	{ 
		.name = "GPIO26",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 26,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[15]
	{ 
		.name = "GPIO47",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 47,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[16]
	{ 
		.name = "GPIO46",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 46,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[17]
	{ 
		.name = "GPIO27",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 27,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[18]
	{ 
		.name = "GPIO65",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 65,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[19]
	{ 
		.name = "GPIO22",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 22,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0,
		.pwm.pinmap = 1,
		.pwm.mux_total = 0
	},
	//Pin[20]
	{ 
		.name = "MMC1_CMD",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[21]
	{ 
		.name = "MMC1_CLK",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[22]
	{ 
		.name = "MMC1_DATA5",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[23]
	{ 
		.name = "MMC1_DATA4",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},			
	//Pin[24]
	{ 
		.name = "MMC1_DATA1",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[25]
	{ 
		.name = "MMC1_DATA1",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},

	//Pin[26]
	{ 
		.name = "GPIO61",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 61,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[27]
	{ 
		.name = "GPIO86",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 86,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[28]
	{ 
		.name = "GPIO88",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 88,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[29]
	{ 
		.name = "GPIO87",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 87,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[30]
	{ 
		.name = "GPIO89",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 89,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[31]
	{ 
		.name = "GPIO10",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 10,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[32]
	{ 
		.name = "GPIO11",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 11,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[33]
	{ 
		.name = "GPIO9",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 9,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0

	},			
	//Pin[34]
	{ 
		.name = "GPIO81",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 81,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 2,
			.pwm.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[35]
	{ 
		.name = "GPIO8",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 8,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0

	},
	//Pin[36]
	{ 
		.name = "GPIO80",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 80,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0,
			.pwm.pinmap = 3,
			.pwm.mux_total = 0
	},
	//Pin[37]
	{ 
		.name = "GPIO78",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 78,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[38]
	{ 
		.name = "GPIO79",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 79,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[39]
	{ 
		.name = "GPIO76",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 76,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[40]
	{ 
		.name = "GPIO77",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 77,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[41]
	{ 
		.name = "GPIO74",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 74,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[42]
	{ 
		.name = "GPIO75",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 75,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[43]
	{ 
		.name = "GPIO72",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 72,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},			
	//Pin[44]
	{ 
		.name = "GPIO73",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 73,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[45]
	{ 
		.name = "GPIO70",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 70,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 4,
			.pwm.mux_total = 0
	},
	//Pin[46]
	{ 
		.name = "GPIO71",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 71,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 5,
			.pwm.mux_total = 0
	},
	//Pin[47]
	{ 
		.name = "GND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[48]
	{ 
		.name = "GND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[49]
	{ 
		.name = "3.3V",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[50]
	{ 
		.name = "3.3V",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[51]
	{ 
		.name = "5V",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[52]
	{ 
		.name = "5V",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[53]
	{ 
		.name = "5V",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},			
	//Pin[54]
	{ 
		.name = "5V",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[55]
	{ 
		.name = "PWR",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[56]
	{ 
		.name = "RESET",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[57]
	{ 
		.name = "GPIO30",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 30,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[58]
	{ 
		.name = "GPIO60",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 60,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[59]
	{ 
		.name = "GPIO31",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 31,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[60]
	{ 
		.name = "GPIO50",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 50,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 6,
			.pwm.mux_total = 0
	},
	//Pin[61]
	{ 
		.name = "GPIO48",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 48,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0
	},
	//Pin[62]
	{ 
		.name = "GPIO51",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 51,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 7,
			.pwm.mux_total = 0

	},
	//Pin[63]
	{ 
		.name = "GPIO5",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 1, 1, 0, 0 },
			.gpio.pinmap = 5,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.i2c.mux_total = 0,
			.spi.mux_total = 0
	},			
	//Pin[64]
	{ 
		.name = "GPIO4",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 1, 1, 0, 0 },
			.gpio.pinmap = 4,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.i2c.mux_total = 0,
			.spi.mux_total = 0
	},
	//Pin[65]
	{ 
		.name = "GPIO13",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 1, 0, 0 },
			.gpio.pinmap = 13,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.i2c.mux_total = 0
	},
	//Pin[66]
	{ 
		.name = "GPIO12",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 1, 0, 0 },
			.gpio.pinmap = 12,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.i2c.mux_total = 0
	},
	//Pin[67]
	{ 
		.name = "GPIO3",
		.capabilites  = (mraa_pincapabilities_t){1, 1, 1, 0, 1, 0, 0, 1 },
			.gpio.pinmap = 13,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.spi.mux_total = 0,
			.uart.mux_total = 0,
			.pwm.pinmap = 8,
			.pwm.mux_total = 0
	},
	//Pin[68]
	{ 
		.name = "GPIO2",
		.capabilites  = (mraa_pincapabilities_t){  1, 1, 1, 0, 1, 0, 0, 1 },
			.gpio.pinmap = 2,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.spi.mux_total = 0,
			.uart.mux_total = 0,
			.pwm.pinmap = 9,
			.pwm.mux_total = 0
	},
	//Pin[69]
	{ 
		.name = "GPIO49",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 49,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[70]
	{ 
		.name = "GPIO15",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 15,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[71]
	{ 
		.name = "GPIO117",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 117,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[72]
	{ 
		.name = "GPIO14",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 14,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[73]
	{ 
		.name = "GPIO115",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 115,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},			
	//Pin[74]
	{ 
		.name = "GPIO113",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 1, 0, 1 },
			.gpio.pinmap = 113,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 10,
			.pwm.mux_total = 0,			
			.spi.mux_total = 0

	},
	//Pin[75]
	{ 
		.name = "GPIO111",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 1, 0, 0 },
			.gpio.pinmap = 111,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 11,
			.pwm.mux_total = 0,
			.spi.mux_total = 0

	},
	//Pin[76]
	{ 
		.name = "GPIO112",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 1, 0, 0 },
			.gpio.pinmap = 112,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 12,
			.pwm.mux_total = 0,
			.spi.mux_total = 0
	},
	//Pin[77]
	{ 
		.name = "GPIO110",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 1, 0, 0 },
			.gpio.pinmap = 89,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 13,
			.pwm.mux_total = 0,		
			.spi.mux_total = 0

	},
	//Pin[78]
	{ 
		.name = "VDD_ADC",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },

	},
	//Pin[79]
	{ 
		.name = "AIN4",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[80]
	{ 
		.name = "GND_ADC",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[81]
	{ 
		.name = "AIN6",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[82]
	{ 
		.name = "AIN5",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[83]
	{ 
		.name = "AIN2",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[84]
	{ 
		.name = "AIN3",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},			
	//Pin[85]
	{ 
		.name = "AIN0",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[86]
	{ 
		.name = "AIN1",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[87]
	{ 
		.name = "GPIO20",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 20,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,

	},
	//Pin[88]
	{ 
		.name = "GPIO7",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 1, 0, 1 },
			.gpio.pinmap = 7,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0,
			.spi.mux_total = 0,
			.pwm.pinmap = 14,
			.pwm.mux_total = 0

	},
	//Pin[89]
	{ 
		.name = "GND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[90]
	{ 
		.name = "GND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[91]
	{ 
		.name = "GND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[92]
	{ 
		.name = "GND",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	}
};


#ifdef __cplusplus
}
#endif

