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
