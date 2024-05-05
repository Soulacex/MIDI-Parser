/*
 * activity8.c
 *
 *  Created on: Feb 20, 2024
 *      Author: soulacex
 */

#include <stdint.h>
#include "printf.h"
#include "UART.h"
#include <stdio.h>

static char BUFFER [80];
/**
 * Read one byte from the virtual terminal and print it.
 */
char read_and_echo_byte() {
    char byte = 0;
    for (int i = 0; byte != '\r' && (i < sizeof(BUFFER) - 1); i++) {
        byte = read_and_echo_byte();
        putchar(byte);
        if (byte == '\r')
            putchar('\n');
    }
    return byte;
}

char* readline () {
	// Use the BUFFER to read one line of user input.
	char byte = 0;
	int i = 0;
	for (; byte != '\r' && (i < sizeof(BUFFER) - 1); i++) {
	    byte = read_and_echo_byte();
	    BUFFER[i] = byte;
	}
	BUFFER[i] = 0;


	return BUFFER;
}

void readlines () {
	while (1) {
		printf ("%s\n", readline());
	}
}

void read_bytes() {
	while (1) {
		read_and_echo_byte();
	}
}

