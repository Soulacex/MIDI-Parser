#ifndef __NUCLEO476_LED_H
#define __NUCLEO476_LED_H

#include "stm32l476xx.h"

#define LED_PIN 7

void LED_Init(int pin);

void LED_Off(int pin);
void LED_On(int pin);
void LED_Toggle(int pin);

#endif /* __NUCLEO476_LED_H */
