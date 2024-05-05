/*
 * systick.h
 *
 *  Created on: Jan 8, 2023
 *      Author: bruce
 */

#ifndef INC_SYSTICK_H_
#define INC_SYSTICK_H_

#include <stdint.h>


typedef struct {
    uint32_t CSR;
    uint32_t RVR;
    uint32_t CVR;
    uint32_t CALIB;
} systick_timer;


int get_count();
uint8_t* get_one_sec_elapsed();
struct systick_timer* get_systick();

//void SysTick_Handler();

// This function is to Initialize SysTick registers
void init_systick();

// This function is to create delay using SysTick timer counter
void delay_systick();

#endif /* INC_SYSTICK_H_ */
