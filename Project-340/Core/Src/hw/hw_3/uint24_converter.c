/*
 * uint24_converter.c
 *
 *  Created on: Feb 28, 2024
 *      Author: soulacex
 */

#include <stdint.h>

/*
 * Takes a uint8_t value and grabs the value at index 0,1, and 2.
 * Then we bit shift by factors of 8 to put the most significant values
 * at the front.
 *
 * ptr: a pointer to some 8 bit number
 *
 * returns: a uint32_t number
*/


uint32_t convert_to_uint24(uint8_t* ptr){
	uint32_t num = (ptr[0] <<16)+ (ptr[1]<< 8) + ptr[2];
	return num;
}
