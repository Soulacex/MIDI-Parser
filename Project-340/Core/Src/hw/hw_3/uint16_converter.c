/*
 * midi_converter.c
 *
 *  Created on: Feb 12, 2024
 *      Author: soulacex
 */


#include <stdint.h>

/**
 * This function converts a big-endian 16-bit value to little-endian.
 *
 * Given a pointer to an array of two uint8_t values, this function interprets
 * them as a big-endian 16-bit value (most significant byte first) and converts
 * it to little-endian format (least significant byte first).
 *
 * @param p_value The pointer to the input array, which contains the big-endian value.
 * @return The converted 16-bit little-endian value.
 */
uint16_t convert_to_uint16(uint8_t* p_value) {
    return (p_value[0] << 8) | p_value[1];
}
