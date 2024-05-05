/*
 * hw5.c
 *
 *  Created on: Feb 26, 2024
 *      Author: soulacex
 */

#include "LED.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "printf.h"
#include "UART.h"
#include "demo.h"
#include "systick.h"


/**
 * This function initializes hardware components and reads commands from a USART_Read Non-Blocking Function to control LED behavior.
 * It toggles the LED based on the received commands, specifically toggling the LED when the command "flash" is received.
 * Characters are echoed back for verification, and the LED flashes once per second when in flash mode.
 * A user can also still input characters, even while the light is flashing.
 */
void hw5() {
    LED_Init(LED_PIN);

    int index = 0;
    char command[16];
    uint8_t flash = 0;

    init_systick();

    while (1) {
        if (flash)
        	delay_loop(8000000);
            LED_Toggle(LED_PIN);

        uint8_t byte = USART_Read_Nonblocking(USART2);
        if (byte != 0) {
            putchar(byte);
            if (byte == '\r') {
                putchar('\n');
                command[index] = 0;
                if (strcmp(command, "flash") == 0) {
                    printf("LED_FLASH\n");
                    LED_Toggle(LED_PIN);
                    flash = 1;
                }
                index = 0;
            } else {
                command[index] = byte;
                index++;
            }
        }
    }
}
