/*
 * manual.c
 *
 *  Created on: Mar 26, 2024
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

/**
 * @brief Enters manual override mode to control LED behavior.
 *
 * Initializes LED, GPIO, and SysTick timer. Prints a message indicating
 * that manual override mode is active. Controls LED flashing, song playback,
 * and project start based on button presses and timer intervals.
 */
void manual() {
    init_systick(); // Initialize SysTick timer
    printf("***MANUAL OVERRIDE MODE ACTIVE***\n\r"); // Print mode activation message

    uint8_t flash = 0; // Flag to control LED flashing
    int count = 0; // Timer count
    int song_num; // Current song index in playlist, static to maintain state across calls

    LED_Off(LED_PIN);

    // Loop while in manual mode
    while (get_toggle()) {
        int flag = get_flag(); // Get current flag value

        // Manage LED flashing every 800000 ticks
        if (count == 800000) {
            if (flash)
                LED_Toggle(LED_PIN); // Toggle LED if flash flag is set
            count = 0; // Reset timer count
        }

        // Handle different flag values for LED control and song playback
        if (flag == 4) { // Turn on LED and play the current song
            flash = 0; // Disable flashing
            LED_On(LED_PIN);
            if (song_num == 1) {
            	play_song(song_num); // Play the currently loaded song
            }
            set_flag(1); // Reset flag to prevent repeated action
        } else if (flag == 3) { // Pause or enable flashing
            flash = 1; // Enable flashing
        } else if (flag == 1) { // Turn off LED
            flash = 0; // Disable flashing
            LED_Off(LED_PIN);
        } else if (flag == 2) { // Next song on double press within 1 second
            song_num = 1;
            parse_midi(song_num); // Load the next song but don't play it yet
            set_flag(-1); // Reset flag after processing
        }

        count++; // Increment timer count
    }

    start_project(); // Start the project after exiting manual mode
}

