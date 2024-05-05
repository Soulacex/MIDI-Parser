/*
 * song_methods.h
 *
 *  Created on: Feb 27, 2024
 *      Author: soulacex
 */

#ifndef INC_PROJECT_READ_TRACK_H_
#define INC_PROJECT_READ_TRACK_H_

#include "song.h"

extern uint32_t tempo;
extern uint16_t division;

typedef struct {
    char chunk_type[4];
    uint32_t length;
    uint16_t format;
    uint16_t num_tracks;
    uint16_t division;
} MIDI_header;

void read_track(uint8_t* mthd, uint32_t len);
uint8_t get_delay(uint8_t* buffer, uint32_t* delay);
MIDI_header* get_song_header(uint8_t song_num);
void parse_division(int song_num);
uint16_t get_division();
uint32_t parse_meta_event(int index);


#endif /* INC_PROJECT_READ_TRACK_H_ */
