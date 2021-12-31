#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef enum {LOW=0, HIGH} PIN_LEVEL;
typedef enum {INPUT=0, OUTPUT}PIN_DIR;

void setPinLevel(int8_t pin_number, PIN_LEVEL level);
void setPinDirection(int8_t pin_number, PIN_DIR direction);

#endif// GPIO_H
