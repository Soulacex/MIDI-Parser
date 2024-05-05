/*
 * printf.c
 *
 *  Created on: Jan 25, 2024
 *      Author: soulacex
 */


#include "printf.h"
#include "UART.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * This function implements printf-like functionality using USART.
 * It formats a string and writes it to output.
 *
 * @param format A format string as in printf.
 * @param ... Variable arguments for the formating of the string.
 *
 * @return The number of characters written too output.
 */
int printf (const char* format, ...) {
    char buffer[80];  // The buffer created to store the formatted string

    va_list args;
    va_start(args, format);

    // Basically here, we format the string and store it in the buffer, we made.
    int ret = vsprintf (buffer, format, args);

    // This ends the processing of all arguments put in.
    va_end(args);

    // Writing the output to the terminal via USART.
    USART_Write (USART2, (uint8_t *)buffer, ret);

    return ret;
}

int putns (const char* str, int size) {
    char buffer[80];  // The buffer created to store the formatted string
	int ret = snprintf(buffer, size + 1, "%s", str);
	USART_Write (USART2, (unsigned char*) buffer, ret);
	USART_Write(USART2, (unsigned char*) "\r\n", 2);
	return ret;
}



