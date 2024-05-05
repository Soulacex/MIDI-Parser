#include "systick.h"
#include <stdint.h>

struct systick_timer {
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};

static struct systick_timer* systick =  (struct systick_timer*) 0xE000E010;
static int counter = 0;
static uint8_t one_sec_elapsed = 0;

int get_count(){
	return counter;
}

uint8_t* get_one_sec_elapsed(){
	return &one_sec_elapsed;
}

struct systick_timer* get_systick() {
    return systick;
}

// This function is to Initialize SysTick registers
void init_systick()
{
	// Use the SysTick global structure pointer to do the following in this
	// exact order with separate lines for each step:
	//
	// Disable SysTick by clearing the CTRL (CSR) register.
	systick->CSR = 0;

	// Set the LOAD (RVR) to 8 million to give us a 100 milliseconds timer.
//	systick->RVR = 7999999;
//	systick->RVR = 79999;
	systick->RVR = 7999;
//	systick->RVR = 79;

	// Set the clock source bit in the CTRL (CSR) to the internal clock.
	systick->CSR |= (1 << 2);

	systick->CSR |= (1 << 1); // Enable interrupt.

	// Set the enable bit in the CTRL (CSR) to start the timer.
	systick->CSR |= 1;
}

//void SysTick_Handler() {
//    counter++;
//}

// This function is to create delay using SysTick timer counter
void delay_systick()
{
	// Using the SysTick global structure pointer do the following:
	// Create a for loop that loops 10 times
	for (int i = 0; i < 7; i++) {
		// Inside that for loop check the COUNTFLAG bit in the CTRL (CSR)
		// register in a loop. When that bit is set exit this inner loop
		// to do another pass in the outer loop of 10.
		while (!(systick->CSR & (1 << 16))) {
			;
        }
	}
}


