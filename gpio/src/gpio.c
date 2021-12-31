#include "gpio.h"
#include <avr/io.h>

enum {portB, portC, portD};

const int8_t gpio_table[][2] = {
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

volatile uint8_t * const port_table[] = {
	&PORTB,
	&PORTC,
	&PORTD
};


volatile uint8_t * const ddr_table[] = {
	&DDRB,
	&DDRC,
	&DDRD
};

void setPinLevel(int8_t pin_number, PIN_LEVEL level)
{
	int8_t port = gpio_table[pin_number][0];
	int8_t pin = gpio_table[pin_number][1];
	volatile uint8_t * port_register = port_table[port];
	if(level == LOW)
		*port_register &= ~(1<<pin);
	else if(level == HIGH)
		*port_register |= 1<<pin;
}

void setPinDirection(int8_t pin_number, PIN_DIR direction)
{
	int8_t port = gpio_table[pin_number][0];
	int8_t pin = gpio_table[pin_number][1];
	volatile uint8_t * port_register = port_table[port];
	if(direction == INPUT)
		*port_register &= ~(1<<pin);
	else if(direction == OUTPUT)
		*port_register |= 1<<pin;
}
