/*
 * activity10.c
 *
 *  Created on: Mar 19, 2024
 *      Author: soulacex
 */


#include "printf.h"
#include "GPIO.h"
#include "main.h"
#include "stm32l4xx.h"

void blue_button_check() {
	GPIO_Init();

	while (1) {
		// Print out a message every time the blue button is pressed
		if (B1_GPIO_Port-> IDR & B1_Pin) {
			printf("Hey Mom and Dad!");
		}
	}
}
