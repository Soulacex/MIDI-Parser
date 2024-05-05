/*
 * uint32_converter.c
 *
 *  Created on: Feb 12, 2024
 *      Author: soulacex
 */


#include <stdint.h>

/**
 * This function converts a big-endian 32-bit value to little-endian.
 *
 * Given a pointer to an array of two uint8_t values, this function interprets
 * them as a big-endian 32-bit value (most significant byte first) and converts
 * it to little-endian format (least significant byte first).
 *
 * @param p_value The pointer to the input array, which contains the big-endian value.
 * @return The converted 32-bit little-endian value.
 */
uint32_t convert_to_uint32(uint8_t* p_value) {
//    return (p_value[0] << 24) | (p_value[1] << 16) | (p_value[2] << 8) | p_value[3];
    uint32_t value;
    for (int i = 0; i < sizeof(uint32_t); i++) {
    	value = value << 8;
    	value += p_value[i];
    }
    return value;
}
