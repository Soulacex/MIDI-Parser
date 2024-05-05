/*
 * handle_functions.c
 *
 *  Created on: Mar 1, 2024
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

#define BACKSPACE 8
#define ENTER 13

static int parsingInProgress = 0;
static int is_paused = 0;

void handle_backspace(char* command, int* index);
void handle_enter(char* command, int* index, int* song_num, uint8_t* flash);
void handle_next(int* song_num);

/**
 * @brief Handles the flashing of the LED.
 *
 * This function is called periodically to toggle the LED state based on a counter.
 *
 * @param flash Pointer to the flash flag.
 * @param count Pointer to the counter value.
 * @return None.
 */
void handle_flash(uint8_t* flash, int* count) {
    if (*count == 800000) {
        if (*flash) {
        	delay_systick();
            LED_Toggle(LED_PIN);
        }
        *count = 0;
    }
}


/**
 * @brief Handles user input from the UART interface.
 *
 * Reads the user input character from USART2 and takes appropriate actions based on the input.
 *
 * @param command Pointer to the command buffer.
 * @param index Pointer to the command buffer index.
 * @param song_num Pointer to the current song number.
 * @param flash Pointer to the flash flag.
 * @return None.
 */
void handle_input(char* command, int* index, int* song_num, uint8_t* flash) {
	if (get_toggle()) {
		return;
	}

    uint8_t byte = USART_Read_Nonblocking(USART2);

    if (byte != 0) {
        if (byte == BACKSPACE) {
            handle_backspace(command, index);
        } else if (byte == ENTER) {
            handle_enter(command, index, song_num, flash);
        } else {
            putchar(byte);
            command[*index] = byte;
            (*index)++;
        }
    }
}

/**
 * @brief Handles the backspace functionality on the command line.
 *
 * This function allows the user to delete the character before the current cursor position.
 * If the cursor is at the beginning of the command, it does nothing.
 *
 * @param command The string representing the command line input.
 * @param index Pointer to an integer representing the current cursor position in the command.
 */
void handle_backspace(char* command, int* index) {
    if (*index > 0) {
        putchar(BACKSPACE);

        for (int i = *index - 1; i < strlen(command); i++) {
            command[i] = command[i + 1];
        }

        putchar(' ');
        putchar('\b');
        (*index)--;
    }
}



/**
 * @brief Handles the "NEXT" command by displaying the information of the next song.
 *
 * Displays the MIDI information of the next song without incrementing the song number.
 * The song number increment will be handled after the song is played.
 *
 * @param song_num Pointer to the current song number.
 * @return None.
 */
void handle_next(int* song_num) {
    parsingInProgress = 1;
    parse_midi(*song_num);  // Parses but does not increment the song number
    parsingInProgress = 0;
}

/**
 * @brief Handles the "PLAY" command to play the song and then move to the next.
 *
 * Plays the current song and increments the song number afterwards.
 *
 * @param song_num Pointer to the current song number.
 * @return None.
 */
void handle_play(int* song_num) {
	*song_num = 0;
    play_song(*song_num);  // Play the current song
}


/**
 * @brief Handles the Enter key and executes corresponding actions based on the user command.
 *
 * Processes the user command stored in the command buffer and takes appropriate actions.
 *
 * @param command Pointer to the command buffer.
 * @param index Pointer to the command buffer index.
 * @param song_num Pointer to the current song number.
 * @param flash Pointer to the flash flag.
 * @return None.
 */
void handle_enter(char* command, int* index, int* song_num, uint8_t* flash) {
    putchar('\n');
    command[*index] = '\0';  // Null-terminate the command string

    if (strcmp(command, "HELP") == 0) {
        all_commands();
    } else if (strcmp(command, "NEXT") == 0) {
        handle_next(song_num);
    } else if (strcmp(command, "PLAY") == 0) {
        handle_play(song_num);
        *flash = 0;  // Stop flashing when playing music
        LED_On(LED_PIN);  // Indicate playing status via LED
    } else if (strcmp(command, "PAUSE") == 0) {
        is_paused = 1;
        *flash = 1;  // Flashing might indicate paused state
    } else if (strcmp(command, "STOP") == 0) {
        *flash = 0;
        LED_Off(LED_PIN);
    } else {
        printf("Invalid command\n\r");
    }

    *index = 0;  // Reset command index for new input
}

