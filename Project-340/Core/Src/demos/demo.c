/*
 * demo.c
 *
 *  Created on: Feb 14, 2021
 *      Author: larry kiser
 *  Updated on: Sept 6, 2021
 *      Author: Mitesh Parikh
 */

#include <stdio.h>
#include <string.h>

// Custom Include files
#include "LED.h"
#include "UART.h"
#include "demo.h"
#include "stm32l4xx.h"
#include "systick.h"
#include "activity8.h"

struct systick_timer {
    uint32_t CSR;
    uint32_t RVR;
    uint32_t CVR;
    uint32_t CALIB;
};

static struct systick_timer* systick = (struct systick_timer*)0xE000E010;


/**
 * This function configures a SysTick timer for 2-second delay.
 *
 * It disables the SysTick timer by clearing the CTRL (CSR) register.
 * Then it sets the LOAD (RVR) to 16 million for 2 seconds.
 * It sets the clock source bit in the CTRL (CSR) to the internal clock, and
 * sets the enable bit in the CTRL (CSR) to start the timer.
 *
 */
static void init_systick_2s() {
    systick->CSR = 0;

    // Set reload value for 2-second delay
    systick->RVR = 16000000;

    // Enable internal clock source
    systick->CSR |= (1 << 2);

    // Enable SysTick counter
    systick->CSR |= 1;
}



// This function is to create a delay by consuming CPU cycle on counter
//void delay_loop( int value )
//{
//	// spin loop consuming CPU to spend time.
//	for (int i = 0; i < value; i++)
//		;
//}

static int count;

// This function is to print counter on UART port and toggle LED
static void demo_of_UART_print(int counter){
//	int n ;
//	uint8_t buffer[BUFFER_SIZE];
//
//	n = sprintf((char *)buffer, "counter = %d\r\n", counter);
//	USART_Write(USART2, buffer, n);

	read_and_echo_byte();

//	delay_loop( 8000000 ) ;	// comment this out when you are ready to test delay_systick
	delay_systick() ;	// enable this when you are ready to test
	count++;

	// Toggle LED
	if (count == 10) {
		LED_Toggle(LED_PIN);
		count = 0;
	}
}

void run_demo(){
	
	int counter = 0;
	
	init_systick_2s();

	// Run a loop to print counter value on UART port
	while (1)
	{
		//demo_of_printf_scanf();
		demo_of_UART_print(counter);
		counter++;
	}
}

