/*
 * gpio.h
 *
 *  Created on: Nov 4, 2021
 *      Author: Mitesh Parikh
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include "main.h"
#include <stdint.h>
#include "stdbool.h"

#define S1_Pin GPIO_PIN_9
#define S1_GPIO_Port GPIOA

extern int toggle;
extern bool manual_mode;

void GPIO_Init(void);
void EXTI15_10_IRQHandler();
int get_toggle();
int get_flag();
int get_timer_count();
void set_flag(int num);
void EXTI9_5_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_GPIO_H_ */
