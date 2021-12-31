/*
* display7 library for use a 7 segments display
* Copyright (C) Luis Antonio Sánchez Monterde
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

#ifndef DISPLAY7_H
#define DISPLAY7_H

#include <stdint.h>

void display7_init(	int8_t A,
			int8_t B,
			int8_t C,
			int8_t D,
			int8_t E,
			int8_t F,
			int8_t G,
			int8_t dot
		);
void display7_showNumber(int8_t number);

#endif// DISPLAY7_H
