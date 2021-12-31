/*
* display7 library for use a 7 segments display
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

#include "display7.h"
#include "gpio.h"

#define TOTAL_PINS 8

uint8_t segments_pins_table[TOTAL_PINS];
const uint8_t segments_table[] = {
	//0b76543210
	//  .GFEDCBA
	0xFC, //0
	0x60, //1
	0xDA, //2
	0xF2, //3
	0x66, //4
	0xB6, //5
	0xBE, //6
	0xE0, //7
	0xFE, //8
	0xE6, //9
	0x02  //-
};

static void setSegments(uint8_t pins);
static void pinsAsOutput(void);

void display7_showNumber(int8_t number)
{
	if(number < 0 || number > 9)
		return;
	uint8_t pins = segments_table[number];
	setSegments(pins);
}

static void setSegments(uint8_t pins)
{
	int8_t pin_number;
	for(int i = 0; i<TOTAL_PINS; i++){
		pin_number = segments_pins_table[i];
		if((pins &(1<<i)) == 0)
			setPinLevel(pin_number, LOW);
		else
			setPinLevel(pin_number, HIGH);
	}
}

void display7_init(int8_t A, int8_t B, int8_t C, int8_t D, 
		int8_t E, int8_t F, int8_t G, int8_t dot)
{
	segments_pins_table[0] = A;
	segments_pins_table[1] = B;
	segments_pins_table[2] = C;
	segments_pins_table[3] = D;
	segments_pins_table[4] = E;
	segments_pins_table[5] = F;
	segments_pins_table[6] = G;
	segments_pins_table[7] = dot;
	pinsAsOutput();
}

static void pinsAsOutput(void)
{
	int8_t pin;
	for(int i = 0; i<TOTAL_PINS; i++){
		pin = segments_pins_table[i];
		setPinDirection(pin, OUTPUT);
	}
}
