/*
 * activity_noise.c
 *
 *  Created on: Apr 9, 2024
 *      Author: soulacex
 */



#include "GPIO.h"
#include "DAC.h"

void make_noise() {
	// Turn on DAC with a power of 2048.
	GPIO_Init();
	DAC_Init ();
	DAC_Start ();
	while (1) {
		DAC_Set_Value(2048);
	}
}
