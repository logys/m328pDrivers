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
#include <avr/io.h>
#include <assert.h>
#include <avr/pgmspace.h>

enum {portB, portC, portD};

const int8_t gpio_table[][2] PROGMEM = {
	{-1, -1}, //pin 0 dummy
	{-1, -1}, //pin 1
	{portD, PD0},
	{portD, PD1},
	{portD, PD2},
	{portD, PD3},
	{portD, PD4},
	{-1, -1}, //Vcc
	{-1, -1}, //Gnd
	{portB, PB6},
	{portB, PB7},
	{portD, PD5},
	{portD, PD6},
	{portD, PD7},
	{portB, PB0}, //pin 14
	{portB, PB1},
	{portB, PB2},
	{portB, PB3},
	{portB, PB4},
	{portB, PB5},
	{-1, -1}, //AVcc
	{-1, -1}, //ARef
	{-1, -1}, //Gnd
	{portC, PC0},
	{portC, PC1},
	{portC, PC2},
	{portC, PC3},
	{portC, PC4},
	{portC, PC5}, //pin 28
};

volatile uint8_t * const port_table[] PROGMEM = {
	&PORTB,
	&PORTC,
	&PORTD
};

volatile uint8_t * const ddr_table[] PROGMEM = {
	&DDRB,
	&DDRC,
	&DDRD
};

volatile uint8_t * const pin_table[] PROGMEM = {
	&PINB,
	&PINC,
	&PIND
};

void gpio_setPinDirection(Pin * pin, PIN_DIR direction)
{
	if(direction == INPUT)
		*pin->ddrx &= ~(1<<pin->number);
	else if(direction == OUTPUT)
		*pin->ddrx |=  1<<pin->number;
}

void gpio_setPinLevel(Pin * pin, PIN_LEVEL level)
{
	if(level == LOW)
		*pin->portx &= ~(1<<pin->number);
	else if(level == HIGH)
		*pin->portx |=  1<<pin->number;
}

PIN_LEVEL gpio_pinLevel(Pin * pin)
{
	if (*pin->pinx & (1<<pin->number))
		return HIGH;
	else 
		return LOW;
}

Pin gpio_create(uint8_t pin_number, PIN_DIR direction, PIN_LEVEL level)
{
	assert(pin_number > 0 && pin_number <29);
	uint8_t gpio_port = pgm_read_byte(&gpio_table[pin_number][0]);
	assert(gpio_port != -1);
	volatile uint8_t * ddrx = pgm_read_ptr(&ddr_table[gpio_port]);
	volatile uint8_t * portx = pgm_read_ptr(&port_table[gpio_port]);
	volatile uint8_t * pinx = pgm_read_ptr(&pin_table[gpio_port]);
	uint8_t gpio_pin = pgm_read_byte(&gpio_table[pin_number][1]);
	Pin pin = {.number = gpio_pin,
		.ddrx = ddrx,
		.portx = portx,
		.pinx = pinx
	};
	gpio_setPinDirection(&pin, direction);
	gpio_setPinLevel(&pin, level);
	return pin;
}
