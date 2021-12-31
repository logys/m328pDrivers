/*
* gpio Simple library for access to gpio of atmega329p.
* Copyright (C) 2021  Luis Antonio Sánchez Monterde
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

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef enum {LOW=0, HIGH} PIN_LEVEL;
typedef enum {INPUT=0, OUTPUT}PIN_DIR;

void setPinLevel(int8_t pin_number, PIN_LEVEL level);
void setPinDirection(int8_t pin_number, PIN_DIR direction);

#endif// GPIO_H
