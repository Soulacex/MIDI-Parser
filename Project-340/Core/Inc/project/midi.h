/*
 * midi.h
 *
 *  Created on: Feb 28, 2024
 *      Author: soulacex
 */

#ifndef INC_PROJECT_MIDI_H_
#define INC_PROJECT_MIDI_H_

#include "song.h"
#include "read_track.h"

extern song the_song;

void parse_midi(int number);
void parse_division(int song_num);
uint16_t get_division();
uint32_t parse_meta_event(int index);
uint8_t get_delay(uint8_t* buffer, uint32_t* delay);
uint32_t parse_channel_event(int index);
void parse_song (int song_num);
void play_song(int song_num);


#endif /* INC_PROJECT_MIDI_H_ */
