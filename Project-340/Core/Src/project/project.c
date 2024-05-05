/*
 * project.c
 *
 *  Created on: Jan 8, 2023
 *      Author: soulacex
 */

#include <read_track.h>
#include "project.h"
#include "printf.h"
#include "LED.h"
#include "UART.h"
#include "song.h"
#include "GPIO.h"
#include <string.h>
#include "systick.h"
#include <stdio.h>
#include <stdint.h>
#include "midi.h"
#include <handle_functions.h>
#include "manual.h"

#define BACKSPACE 8
#define ENTER 13

/**
 * @brief Displays all available user commands.
 *
 * Prints a list of available user commands to the console.
 *
 * @return None.
 */
void all_commands() {
    printf("Available User Commands\n\r");
    printf("NEXT – Show next song info\n\r");
    printf("PLAY – Play the song (LED on)\n\r");
    printf("PAUSE – Pause the song (LED flash)\n\r");
    printf("STOP – Stop the song (LED off)\n\r");
    printf("***REMOTE MODE ACTIVE***\n\r");
}

/**
 * @brief Initializes the project, including any necessary add-ons, helper functions, and the command-line interface.
 *
 * This function initializes the necessary extra functions, sets up the command-line interface,
 * and prints the available user commands. It then enters a loop to handle user input and
 * control the LED functionality based on what the user enters, of course.
 *
 * @return None.
 */
void start_project() {
    LED_Init(LED_PIN);
    GPIO_Init();
    init_systick();
    printf("***REMOTE LED CONTROL MENU***\n\r");
    all_commands();

    LED_Off(LED_PIN);

    int index = 0;
    char command[16] = {0};
    uint8_t flash = 0;
    int count = 0;
    int song_num = 0;

    while (1) {
        if (!get_toggle()) { // Check if not in manual mode
            handle_flash(&flash, &count);
            handle_input(command, &index, &song_num, &flash);
            count++;
        } else {
            manual();  // Enter Manual Mode
        }
    }
}

