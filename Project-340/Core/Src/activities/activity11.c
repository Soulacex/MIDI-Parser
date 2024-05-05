/*
 * activity11.c
 *
 *  Created on: Mar 21, 2024
 *      Author: soulacex
 */


#include "systick.h"
#include <stdint.h>
#include "printf.h"

// Use interrupts to make a clock which updates once a second.
// Configure the systick
// Intialize the systick.
// Handle interrupt.


static int count = 0;

//void SysTick_Handler() {
//    count++;
//}

int get_time() {
	return count;
}

void activity11() {
    init_systick();
    int seconds = 0;
    printf("%02d:%02d:%02d\r", seconds / 3600, seconds / 60 % 60, seconds % 60);

    while (1) {
        if (count >= 1000) {
            seconds += 1;
            count = 0;
            printf("%02d:%02d:%02d\r", seconds / 3600, seconds / 60 % 60, seconds % 60);
        }
    }
}
