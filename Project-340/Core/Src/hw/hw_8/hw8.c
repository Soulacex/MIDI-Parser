/*
 * hw8.c
 *
 *  Created on: Apr 11, 2024
 *      Author: soulacex
 */


#include <stdint.h>
#include "printf.h"

// Function to parse the variable-length field and return the delay value
uint32_t parseDelay(uint8_t* delay) {
    uint32_t ret = 0;
    uint8_t byte_in;

    // Read bytes until the MSB is clear
    while (1) {
        byte_in = *delay;
        ret = (ret << 7) | (byte_in & 0x7F);
        delay++;

        if (!(byte_in & 0x80)) {
            break; // Stop when MSB is clear
        }
    }

    return ret;
}

// Example usage
void testParser() {
    uint8_t midi1[] = {0x3B, 0x80, 0x27, 0x00};
    uint8_t midi2[] = {0x83, 0x18, 0x91, 0x54, 0x64};
    uint8_t midi3[] = {0xC5, 0x92, 0x74, 0xE3, 0x74, 0x12};
    uint8_t midi4[] = {0x90, 0x82, 0x93, 0x64, 0xD3, 0x89};

    printf("Delay 1: %lu\n", parseDelay(midi1));
    printf("Delay 2: %lu\n", parseDelay(midi2));
    printf("Delay 3: %lu\n", parseDelay(midi3));
    printf("Delay 4: %lu\n", parseDelay(midi4));
}
