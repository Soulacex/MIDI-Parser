/*
 * activity12.c
 *
 *  Created on: Mar 26, 2024
 *      Author: soulacex
 */


// Same thing as activity 10, just with interrupts.

#include "printf.h"
#include "GPIO.h"
#include "main.h"
#include <stm32l4xx.h>
#include "activity11.h"

void setup() {
	GPIO_Init();
	NVIC_EnableIRQ(EXTI15_10_IRQn);
}

//void EXTI15_10_IRQHandler() {
//	printf("Blue Button Pressed! \n");
//	HAL_GPIO_EXTI_IRQHandler(B1_Pin);
//}
