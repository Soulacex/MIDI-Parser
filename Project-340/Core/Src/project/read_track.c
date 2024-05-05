/*
 * song_methods.c
 *
 *  Created on: Feb 27, 2024
 *      Author: soulacex
 */

#include <read_track.h>
#include "song.h"
#include <stddef.h>
#include "LED.h"
#include "UART.h"
#include "printf.h"
#include "project.h"
#include "systick.h"
#include "string.h"
#include "GPIO.h"
#include "dac.h"
#include "tone.h"
#include "uint_converters.h"
#include "midi.h"
#include <stdlib.h>
#include "stdio.h"


void read_track(uint8_t* mthd, uint32_t len);

uint8_t title[] = {0x00, 0xff, 0x03, 0};
uint8_t copyright[] = {0x00, 0xff, 0x02, 0};
uint32_t tempo;
uint16_t division;
uint8_t end[] = {0xff, 0x2f, 0};
uint8_t buffer[4] = {0};
int flag = 0;

/**
 * @brief Reads MIDI track data and extracts the song title, copyright info, and tempo.
 *
 * This function reads MIDI track data provided in the `mthd` buffer
 * and extracts information speficially song title, copyright,
 * and tempo. It then prints out the extracted information to the console.
 *
 * @param mthd Pointer to the start of the MIDI track data.
 * @param len Length of the MIDI track data.
 *
 * @return None.
 */
void read_track(uint8_t* mthd, uint32_t len) {
    while (len > 0) {
        uint8_t event_type = *mthd++;
        len--;

        if (event_type == 0xFF) { // Meta event
            uint8_t meta_type = *mthd++;
            len--;

            uint8_t event_len = *mthd++;
            len--;

            switch (meta_type) {
                case 0x02: // Copyright Info
                    if (event_len > 0) {
                        char copyright_str[event_len + 1];
                        memcpy(copyright_str, mthd, event_len);
                        copyright_str[event_len] = '\0';
                        printf("Copyright: %s\n\r", copyright_str);
                    }
                    break;

                case 0x03: // Song Title
                    if (event_len > 0) {
                        char title_str[event_len + 1];
                        memcpy(title_str, mthd, event_len);
                        title_str[event_len] = '\0';
                        printf("Song Title: %s\n\r", title_str);
                    }
                    break;

                case 0x51: // Tempo
                    if (event_len == 3) {
                        uint32_t tempo = *((uint32_t*)mthd);
                        tempo = convert_into_uint24((uint8_t*)&tempo);
                        printf("Tempo: %lu\n\r", tempo);
                    }
                    break;

                default:
                    break;
            }
            mthd += event_len;
            len -= event_len;
        }
    }
}

/**
 * @brief Computes the delay from a MIDI variable-length quantity.
 *
 * Parses bytes from the buffer to calculate the MIDI delay as a variable-length quantity.
 * Continues parsing while the most significant bit is set, signifying continuation.
 *
 * @param buffer The byte array containing MIDI data.
 * @param delay Pointer to store the computed delay value.
 * @return Returns the next index in the buffer after the last byte read.
 */
uint8_t get_delay (uint8_t* buffer, uint32_t* delay) {
    int index = 0;
    uint8_t temp;
    while (buffer[index] & (1 << 7)) {
        temp = buffer [index] & ~ (1 << 7);
        *delay = (*delay << 7) + temp;
        index++;
    }
    temp = buffer [index] & ~(1 << 7);
    *delay = (*delay << 7) + temp;

    return index + 1;
}

/**
 * @brief Retrieves and stores the division value from a song's MIDI header.
 *
 * Extracts the division value from the MIDI header of a specified song and converts it to a uint16_t.
 *
 * @param song_num The identifier of the song.
 */
void parse_division(int song_num) {
	MIDI_header * header = get_song_header(song_num);
	division = convert_into_uint16((uint8_t*)&header->division);
}

/**
 * @brief Returns the current division value.
 *
 * Accessor for the division value which defines timing for MIDI ticks.
 *
 * @return The current division value.
 */
uint16_t get_division() {
	return division;
}


/**
 * @brief Parses a meta event in MIDI data and optionally updates tempo.
 *
 * Processes meta events, specifically looking for tempo information to update.
 * Only processes tempo meta events (0x51), converting three bytes into a 24-bit integer.
 *
 * @param index The start index of the meta event in the song's MIDI data.
 * @return The index after processing the meta event, adjusted for parsed bytes.
 */
uint32_t parse_meta_event(int index) {
    int length = the_song.p_song[index + 2];
    unsigned char the_tempo[3];
    if (the_song.p_song[index + 1] == 0x51) {
        index += 3;
        for (int i = 0; i < length; i++) {
            the_tempo[i] = the_song.p_song[index];
            index++;
        }
        tempo = convert_into_uint24((uint8_t*)&the_tempo);
    } else {
        index += length + 2;
    }
    return index;
}

/**
 * @brief Retrieves the MIDI header for a specified song.
 *
 * Fetches the MIDI header from the song data, facilitating access to metadata like division.
 *
 * @param song_num The song identifier.
 * @return Pointer to the MIDI header of the specified song.
 */
MIDI_header* get_song_header(uint8_t song_num){
	MIDI_header* header = (MIDI_header*) get_song(song_num).p_song;
	return header;
}
