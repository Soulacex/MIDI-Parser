/*
 * hello_world.c
 *
 *  Created on: Jan 23, 2024
 *      Author: soulacex
 */


#include <stdio.h>
#include "UART.h"

void hello() {
	// Use the USART to print something.
	char* welcome = "Hello, World!";
	USART_Write (USART2, (unsigned char *)welcome, 13);

	printf("Enter your name");
	char name [64];
	scanf(name);

	printf("Hello, %s\n", name);

}
