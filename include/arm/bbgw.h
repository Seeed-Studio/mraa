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
mraa_pininfo_t bbgw_pininfos[] = {
		//pin[0]
	{ 
		.name = "INVALID",                 //valid gpio pwm fast_gpio spi i2c aio uart
		.capabilites  = (mraa_pincapabilities_t){ 0, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[1]
	{ 
		.name = "P8_01",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[2]
	{ 
		.name = "P8_02",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[3]
	{ 
		.name = "P8_03",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},			
	//Pin[4]
	{ 
		.name = "P8_04",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[5]
	{ 
		.name = "P8_05",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[6]
	{ 
		.name = "P8_06",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[7]
	{ 
		.name = "P8_07",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 66,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0
	},
	//Pin[8]
	{ 
		.name = "P8_08",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 67,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0
	},
	//Pin[9]
	{ 
		.name = "P8_09",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 69,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[10]
	{ 
		.name = "P8_10",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 68,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[11]
	{ 
		.name = "P8_11",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[12]
	{ 
		.name = "P8_12",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[13]
	{ 
		.name = "P8_13",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 23,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0,
		.pwm.pinmap = 0,
		.pwm.mux_total = 0

	},			
	//Pin[14]
	{ 
		.name = "P8_14",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[15]
	{ 
		.name = "P8_15",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[16]
	{ 
		.name = "P8_16",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[17]
	{ 
		.name = "P8_17",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[18]
	{ 
		.name = "P8_18",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[19]
	{ 
		.name = "P8_19",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 22,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0,
		.pwm.pinmap = 1,
		.pwm.mux_total = 0
	},
	//Pin[20]
	{ 
		.name = "P8_20",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[21]
	{ 
		.name = "P8_21",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[22]
	{ 
		.name = "P8_22",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[23]
	{ 
		.name = "P8_23",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},			
	//Pin[24]
	{ 
		.name = "P8_24",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[25]
	{ 
		.name = "P8_25",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[26]
	{ 
		.name = "P8_26",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[27]
	{ 
		.name = "P8_27",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 86,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[28]
	{ 
		.name = "P8_28",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
		.gpio.pinmap = 88,
		.gpio.parent_id = 0,
		.gpio.mux_total = 0

	},
	//Pin[29]
	{ 
		.name = "P8_29",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 87,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[30]
	{ 
		.name = "P8_30",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 89,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[31]
	{ 
		.name = "P8_31",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 10,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[32]
	{ 
		.name = "P8_32",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 11,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[33]
	{ 
		.name = "P8_33",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 9,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0

	},			
	//Pin[34]
	{ 
		.name = "P8_34",
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
		.name = "P8_35",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 8,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0

	},
	//Pin[36]
	{ 
		.name = "P8_36",
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
		.name = "P8_37",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 78,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[38]
	{ 
		.name = "P8_38",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 79,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[39]
	{ 
		.name = "P8_39",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 76,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[40]
	{ 
		.name = "P8_40",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 77,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[41]
	{ 
		.name = "P8_41",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 74,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[42]
	{ 
		.name = "P8_42",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 75,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[43]
	{ 
		.name = "P8_43",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 72,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},			
	//Pin[44]
	{ 
		.name = "P8_44",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 73,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[45]
	{ 
		.name = "P8_45",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 70,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 4,
			.pwm.mux_total = 0
	},
	//Pin[46]
	{ 
		.name = "P8_46",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 71,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 5,
			.pwm.mux_total = 0
	},
	//Pin[47]
	{ 
		.name = "P9_01",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[48]
	{ 
		.name = "P9_02",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[49]
	{ 
		.name = "P9_03",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[50]
	{ 
		.name = "P9_04",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[51]
	{ 
		.name = "P9_05",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[52]
	{ 
		.name = "P9_06",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[53]
	{ 
		.name = "P9_07",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},			
	//Pin[54]
	{ 
		.name = "P9_08",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[55]
	{ 
		.name = "P9_09",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[56]
	{ 
		.name = "P9_10",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[57]
	{ 
		.name = "P9_11",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 30,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[58]
	{ 
		.name = "P9_12",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 60,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[59]
	{ 
		.name = "P9_13",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 31,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[60]
	{ 
		.name = "P9_14",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 50,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 6,
			.pwm.mux_total = 0
	},
	//Pin[61]
	{ 
		.name = "P9_15",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 48,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0
	},
	//Pin[62]
	{ 
		.name = "P9_16",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 51,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.pwm.pinmap = 7,
			.pwm.mux_total = 0

	},
	//Pin[63]
	{ 
		.name = "P9_17",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 1, 0, 0 },
			.gpio.pinmap = 5,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.i2c.mux_total = 0
	},			
	//Pin[64]
	{ 
		.name = "P9_18",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 1, 0, 0 },
			.gpio.pinmap = 4,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.i2c.mux_total = 0
	},
	//Pin[65]
	{ 
		.name = "P9_19",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[66]
	{ 
		.name = "P9_20",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[67]
	{ 
		.name = "P9_21",
		.capabilites  = (mraa_pincapabilities_t){1, 1, 1, 0, 1, 0, 0, 1 },
			.gpio.pinmap = 3,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.spi.mux_total = 0,
			.uart.mux_total = 0,
			.pwm.pinmap = 8,
			.pwm.mux_total = 0
	},
	//Pin[68]
	{ 
		.name = "P9_22",
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
		.name = "P9_23",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 49,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[70]
	{ 
		.name = "P9_24",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 15,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[71]
	{ 
		.name = "P9_25",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 117,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[72]
	{ 
		.name = "P9_26",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 14,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0
	},
	//Pin[73]
	{ 
		.name = "P9_27",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 115,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},			
	//Pin[74]
	{ 
		.name = "P9_28",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 }, 
	},
	//Pin[75]
	{ 
		.name = "P9_29",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 }, 
	},
	//Pin[76]
	{ 
		.name = "P9_30",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 }, 
	},
	//Pin[77]
	{ 
		.name = "P9_31",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },

	},
	//Pin[78]
	{ 
		.name = "P9_32",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },

	},
	//Pin[79]
	{ 
		.name = "P9_33",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[80]
	{ 
		.name = "P9_34",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[81]
	{ 
		.name = "P9_35",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[82]
	{ 
		.name = "P9_36",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[83]
	{ 
		.name = "P9_37",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[84]
	{ 
		.name = "P9_38",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},			
	//Pin[85]
	{ 
		.name = "P9_39",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[86]
	{ 
		.name = "P9_40",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 1, 0 },
	},
	//Pin[87]
	{ 
		.name = "P9_41",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 0, 0, 0, 0, 0, 0 },
			.gpio.pinmap = 20,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0

	},
	//Pin[88]
	{ 
		.name = "P9_42",
		.capabilites  = (mraa_pincapabilities_t){ 1, 1, 1, 0, 0, 0, 0, 1 },
			.gpio.pinmap = 7,
			.gpio.parent_id = 0,
			.gpio.mux_total = 0,
			.uart.mux_total = 0,
			.pwm.pinmap = 14,
			.pwm.mux_total = 0

	},
	//Pin[89]
	{ 
		.name = "P9_43",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[90]
	{ 
		.name = "P9_44",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[91]
	{ 
		.name = "P9_45",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	},
	//Pin[92]
	{ 
		.name = "P9_46",
		.capabilites  = (mraa_pincapabilities_t){ 1, 0, 0, 0, 0, 0, 0, 0 },
	}
};


#ifdef __cplusplus
}
#endif

