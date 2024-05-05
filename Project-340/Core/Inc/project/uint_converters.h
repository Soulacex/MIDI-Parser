/*
 * converters.h
 *
 *  Created on: Feb 29, 2024
 *      Author: soulacex
 */

#ifndef INC_PROJECT_UINT_CONVERTERS_H_
#define INC_PROJECT_UINT_CONVERTERS_H_

#include <stdint.h>

uint16_t convert_into_uint16(uint8_t* p_value);
uint32_t convert_into_uint24(uint8_t* p_value);
uint32_t convert_into_uint32(uint8_t* p_value);

#endif /* INC_PROJECT_UINT_CONVERTERS_H_ */


