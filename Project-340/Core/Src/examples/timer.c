/*
 * timer.c
 *
 *  Created on: Feb 13, 2024
 *      Author: soulacex
 */


#include <stdint.h>
#include "printf.h"
// Define a Struct for The SysTick Timer.

struct systick_timer {
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};

void print_systick(){
	struct systick_timer* s_tick =  (struct systick_timer*) 0xE000E010;

	s_tick->CSR |= 1 << 2; // Set Internal Clock
	s_tick->CSR |= 1; // Turn on
	s_tick->RVR = 7999999;

	printf("%ld\n", s_tick -> CSR);
	printf("%ld\n", s_tick -> RVR);
	printf("%ld\n", s_tick -> CVR);
	printf("%ld\n", s_tick -> CALIB);

	int count = 0;
	while (1) {
		if ((s_tick->CSR & (1 << 16)) > 0) {
			count++;
			printf("%3d\r", count / 10);
		}
	}
}
