/*
 * gpio.c
 *
 *  Created on: Nov 4, 2021
 *      Author: Mitesh Parikh
 */


/* Includes ------------------------------------------------------------------*/
#include "GPIO.h"
#include <stdbool.h>
#include "stm32l4xx.h"
#include <stdint.h>
#include "systick.h"
#include "stdbool.h"
#include "UART.h"

struct systick_timer {
	uint32_t CSR;
	uint32_t RVR;
	uint32_t CVR;
	uint32_t CALIB;
};


// External Global Variables that we will need access to
int toggle = 0;
static uint8_t flag;

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
void GPIO_Init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	/*Configure GPIO pin : PtPin */
	GPIO_InitStruct.Pin = B1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = S1_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(S1_GPIO_Port, &GPIO_InitStruct);

	/* EXTI15_10_IRQn interrupt init*/
	// Note you will have to add EXTI15_10_IRQn Interrupt handler function as well
	// This is the interrupt handler for the blue button
	NVIC_EnableIRQ(EXTI15_10_IRQn);

	/* EXTI9_5_IRQn interrupt init*/
	// Note you will have to add EXTI9_15_IRQn Interrupt handler function as well
	// This is the interrupt handler for the external buttons (S1)
	NVIC_EnableIRQ(EXTI9_5_IRQn);

}


/**
 * @brief Interrupt handler for EXTI lines 15 to 10.
 *
 * Handles external interrupts on GPIO pins 15 to 10. Checks the state of the B1 button
 * and toggles the mode between manual and remote based on its current state.
 */
void EXTI15_10_IRQHandler() {
    if (HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0) { // B1 button is pressed
        if (toggle == 0) {
            toggle = 1; // Set toggle to 1 for manual mode
        } else if (toggle == 1) {
            toggle = 0; // Set toggle to 0 for remote mode
        }
    }
    HAL_GPIO_EXTI_IRQHandler(B1_Pin); // Call the HAL handler for B1 pin interrupt
}

/**
 * @brief Gets the current toggle mode (manual or remote).
 *
 * @return The current toggle mode value (0 for remote, 1 for manual).
 */
int get_toggle() {
    return toggle; // Return the current toggle mode
}

/**
 * @brief Gets the current flag value.
 *
 * @return The current flag value used for controlling LED behavior and actions.
 */
int get_flag() {
    return flag; // Return the current flag value
}

/**
 * @brief Sets the flag value to control LED behavior.
 *
 * @param num The value to set the flag to.
 */
void set_flag(int num) {
    flag = num; // Set the flag to the specified value
}

/**
 * @brief Interrupt handler for EXTI lines 9 to 5.
 *
 * Handles external interrupts on GPIO pins 9 to 5, specifically for the S1 button.
 */
void EXTI9_5_IRQHandler() {
    HAL_GPIO_EXTI_IRQHandler(S1_Pin); // Call the HAL handler for S1 pin interrupt
}


/**
 * @brief Callback function for handling GPIO external interrupt events.
 *
 * Simplified to only handle:
 * - Flag 2 when the button is pressed and released as a single press.
 * - Flag 4 for a double press within 750 milliseconds.
 *
 * @param GPIO_Pin The GPIO pin that triggered the interrupt.
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    static uint32_t last_press_time = 0;  // Time of the last button press
    static int press_count = 0;           // Track the number of button presses
    uint32_t current_time;

    if (GPIO_Pin == S1_Pin) {
        delay_systick();  // Debounce delay right after detecting the button event

        if (!(S1_GPIO_Port->IDR & S1_Pin)) {  // Button is pressed
            current_time = get_count();  // Get the current time after debounce delay
            if (current_time - last_press_time < 1000) {  // Check for double press within 1000 ms
                press_count++;
            } else {
                press_count = 1;  // Reset press count for a single press
            }

            last_press_time = current_time;  // Update the last press time
        } else {  // Button is released
            if (press_count == 1) {  // Only handle the flag setting if it was a single press
                flag = 2;  // Set flag to 2 for single press
            } else if (press_count == 2) {
                flag = 4;  // Set flag to 4 for double press
                press_count = 0;  // Reset press count after handling double press
            }
        }
    }
}

