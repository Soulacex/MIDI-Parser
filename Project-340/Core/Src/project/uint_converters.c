/*
 * converters.c
 *
 *  Created on: Feb 29, 2024
 *      Author: soulacex
 */


#include <stdint.h>

uint32_t tempo_micros_per_qn;  // Tempo in microseconds per quarter note
uint32_t division_ticks_per_qn;  // Division in MIDI ticks per quarter note
uint32_t midi_tick_duration; // Duration of a MIDI tick in microseconds


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
uint16_t convert_into_uint16(uint8_t* p_value) {
    return (p_value[0] << 8) | p_value[1];
}


/**
 * This function converts a big-endian 24-bit value to little-endian.
 *
 * Given a pointer to an array of two uint8_t values, this function interprets
 * them as a big-endian 24-bit value (most significant byte first) and converts
 * it to little-endian format (least significant byte first).
 *
 * @param p_value The pointer to the input array, which contains the big-endian value.
 * @return The converted 16-bit little-endian value.
 */
uint32_t convert_into_uint24(uint8_t* p_value){
	 return (p_value[0] <<16)+ (p_value[1]<< 8) + p_value[2];
}


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
uint32_t convert_into_uint32(uint8_t* p_value) {
    return (p_value[0] << 24) | (p_value[1] << 16) | (p_value[2] << 8) | p_value[3];
}
