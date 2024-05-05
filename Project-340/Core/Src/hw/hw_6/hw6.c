/*
 * hw6.c
 *
 *  Created on: Mar 24, 2024
 *      Author: soulacex
 */

#include "UART.h"


void USART2_Init() {
	// Enable the clock of USART 1 & 2
	RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;  // Enable USART 2 clock

	 // Select the USART1 clock source
	 // 00: PCLK selected as USART2 clock
	 // 01: System clock (SYSCLK) selected as USART2 clock
	 // 10: HSI16 clock selected as USART2 clock
	 // 11: LSE clock selected as USART2 clock
	 RCC->CCIPR &= ~RCC_CCIPR_USART2SEL;
	 RCC->CCIPR |=  RCC_CCIPR_USART2SEL_0;

	 USART2->CR1 |= 1 << 5; // Enable RXNEIE

	 UART2_GPIO_Init();
	 USART_Init(USART2);

	 NVIC_EnableIRQ(USART2_IRQn);   // Enable interrupt of USART peripheral.
}


void USART2_IRQHandler() {
    uint8_t byte = (uint8_t)(USART2->RDR & 0xFF);
    if (byte == '\r') {
        USART_Write (USART2, &byte, 1);
        byte = '\n';
        USART_Write (USART2, &byte, 1);
    }
    else
        USART_Write (USART2, &byte, 1);
}
