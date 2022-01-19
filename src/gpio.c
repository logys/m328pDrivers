/*
* gpio Simple library for access to gpio of amtega328p
* Copyright (C) 2021 Luis Antonio Sánchez Monterde
* antonio.dgr.ink@gmail.com
* 
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA 
*/

#include "gpio.h"
#include <avr/sfr_defs.h>
#include <assert.h>

void gpio_setPinDirection(Pin * pin, PIN_DIR direction)
{
	if(direction == INPUT)
		_SFR_IO8(pin->port_base+1) &= ~(1<<pin->gpio_pin);
	else if(direction == OUTPUT)
		_SFR_IO8(pin->port_base+1) |=  1<<pin->gpio_pin;
}

void gpio_setPinLevel(Pin * pin, PIN_LEVEL level)
{
	if(level == LOW)
		_SFR_IO8(pin->port_base+2) &= ~(1<<pin->gpio_pin);
	else if(level == HIGH)
		_SFR_IO8(pin->port_base+2) |=  1<<pin->gpio_pin;
}

PIN_LEVEL gpio_pinLevel(Pin * pin)
{
	if (_SFR_IO8(pin->port_base) & (1<<pin->gpio_pin))
		return HIGH;
	else 
		return LOW;
}

Pin gpio_create(PORTBASE port, uint8_t pin_gpio, PIN_DIR direction, PIN_LEVEL level)
{
	assert(port == portB || port == portC || port == portD);
	assert(pin_gpio < 8);
	Pin pin = {.gpio_pin = pin_gpio,
		.port_base = port
	};
	gpio_setPinDirection(&pin, direction);
	gpio_setPinLevel(&pin, level);
	return pin;
}
