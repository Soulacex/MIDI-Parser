/*
 * activity_wave.c
 *
 *  Created on: Apr 11, 2024
 *      Author: soulacex
 */

#include "printf.h"
#include "activity11.h"
#include "systick.h"
#include "stdint.h"
#include "tone.h"
#include "GPIO.h"

static int number;

//void SysTick_Handler() {
//    // handle the interrupt
//    number++;
//}

void wave(uint32_t duration) {
	// Print 1's for half the frequency.
	// Then print 0's for the other half.
	int count = number % duration;
//	printf("%lu\n", duration);

	// If in first half of duration, print 1.
	// Else print 0.
	if (count < (duration >> 1)) {
		printf("1");
		DAC_Set_Value(2048);
	} else {
		printf("0");
		DAC_Set_Value(0);
	}
}


void run_wave() {
	init_systick();
	GPIO_Init();
	DAC_Init();
	DAC_Start();
	float frequency = 0.5;
	uint32_t duration = hertz_to_midi_ticks(frequency);
	while (1) {
		wave(duration);
	}
}
