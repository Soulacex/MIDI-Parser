/*
 * handle_functions.c
 *
 *  Created on: Mar 1, 2024
 *      Author: soulacex
 */

#ifndef INC_PROJECT_HANDLE_FUNCTIONS_C_
#define INC_PROJECT_HANDLE_FUNCTIONS_C_

void handle_flash(uint8_t* flash, int* count);
void handle_input(char* command, int* index, int* song_num, uint8_t* flash);
void handle_backspace(char* command, int* index);
void handle_enter(char* command, int* index, int* song_num, uint8_t* flash);
void handle_next();
void handle_play(int* song_num);

#endif /* INC_PROJECT_HANDLE_FUNCTIONS_C_ */
