/*
 * This file is part of the TREZOR project, https://trezor.io/
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BUTTONS_H__
#define __BUTTONS_H__

#include <libopencm3/stm32/gpio.h>
#include <stdbool.h>

#define PARTICL
static const char dig[3][3] = {{'7', '8', '9'},
				  		       {'4', '5', '6'},
				  		       {'1', '2', '3'}};

#ifdef PARTICL
typedef struct {
	char tmp;
	int row;
	int col;
	int x;
	int y;	
	int step;
	bool recovery_mode;
}t_particl;

extern t_particl _particl;
#endif

struct buttonState {
	volatile bool YesUp;
	volatile int YesDown;
	volatile bool NoUp;
	volatile int NoDown;
};

extern struct buttonState button;

uint16_t buttonRead(void);
void buttonUpdate(void);

#ifndef BTN_PORT
#define BTN_PORT	GPIOC
#endif

#ifndef BTN_PIN_YES
#define BTN_PIN_YES	GPIO2
#endif

#ifndef BTN_PIN_NO
#define BTN_PIN_NO	GPIO5
#endif

#endif
