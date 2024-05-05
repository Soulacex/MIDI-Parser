/*
 * midi.c
 *
 *  Created on: Feb 28, 2024
 *      Author: soulacex
 */

#include <stdint.h>
#include "uint_converters.h"
#include <string.h>
#include "song.h"
#include <read_track.h>
#include "dac.h"
#include "systick.h"
#include "uint_converters.h"
#include "GPIO.h"
#include "tone.h"
#include "hw8.h"
#include "printf.h"
#include <stdlib.h>
#include "midi.h"
#include "read_track.h"


uint16_t get_header(uint8_t* song_data);
void parse_midi(int number);

song the_song;

typedef struct {
	uint32_t delay;
	uint8_t status;
	uint32_t note;
	uint8_t velocity;
} tone;

tone tones[700];
uint8_t tones_index = 0;


/**
 * @brief Parses a MIDI file and processes the first track.
 *
 * This function parses the MIDI file identified by the given number, retrieves the
 * first track, and processes it using the read_track function. It advances to the
 * next track in a circular manner, as best it can anyways.
 *
 * @param number The identifier (song number) of the MIDI file to be parsed.
 *
 * @return None.
 */
void parse_midi(int number) {
	memset(tones, 0, sizeof(tones));
	tones_index = 0;  // Reset the index for tones array
    uint8_t* mthd = (uint8_t*)(get_song(number).p_song);
    uint32_t len = mthd[7];
    uint8_t num_tracks = mthd[11];
    mthd += 8 + len;
    uint8_t buffer[5]; // Increase buffer size for null-terminating character

    for (int i = 1; i <= num_tracks; i++) {
        strncpy((char*)buffer, (char*)mthd, 4);
        buffer[4] = '\0';

        if (strcmp((char*)buffer, "MTrk") == 0) {
            mthd += 4;
            uint32_t trk_len = convert_into_uint32((uint8_t*)&(*(uint32_t*)mthd));
            mthd += 4;

            if (i == 1) {
                read_track(mthd, trk_len);
            }
        }
    }
}

/**
 * @brief Processes MIDI channel events to populate the tones array.
 *
 * This function parses MIDI channel events from a specific index in the MIDI data array,
 * handling 'Note On', 'Note Off', and some system messages to populate the `tones` array.
 * It adjusts and returns the index based on the bytes processed.
 *
 * @param index The starting index in the MIDI data for parsing events.
 * @return The new index after processing the MIDI event.
 *
 */
uint32_t parse_channel_event(int index) {
    uint32_t delay = 0;  // Variable to store the delay extracted from the MIDI data
    tone toneOfSong;  // Structure to hold tone data
    uint8_t bytes_read = get_delay(&the_song.p_song[index], &delay);  // Calculate delay from MIDI variable-length quantity
    index += bytes_read;  // Move index forward by the number of bytes read for the delay

    // Check the event type at the current index position
    if (the_song.p_song[index] == 0x90) { // Note On event
        index++;  // Increment index to move past the event type byte
        toneOfSong.delay = delay;  // Set delay in the tone structure
        toneOfSong.status = 1;  // Set status to 1 indicating a Note On
        toneOfSong.note = hertz_to_midi_ticks(get_frequency_from_note(the_song.p_song[index]));  // Convert frequency to MIDI ticks and store
        index++;  // Move to the next byte for velocity
        toneOfSong.velocity = the_song.p_song[index];  // Set velocity from MIDI data
        tones[tones_index++] = toneOfSong;  // Add the tone to the tones array and increment index
    }
    else if (the_song.p_song[index] == 0x80) { // Note Off event
        index++;  // Increment index to move past the event type byte
        toneOfSong.delay = delay;  // Set delay in the tone structure
        toneOfSong.status = 0;  // Set status to 0 indicating a Note Off
        toneOfSong.note = hertz_to_midi_ticks(get_frequency_from_note(the_song.p_song[index]));  // Convert frequency to MIDI ticks and store
        index++;  // Move to the next byte for velocity
        toneOfSong.velocity = 0;  // Velocity for Note Off is zero
        tones[tones_index++] = toneOfSong;  // Add the tone to the tones array and increment index
    }
    else {
        // Handle other MIDI events not directly linked to tone generation
        if (the_song.p_song[index] == 0xC0 || the_song.p_song[index] == 0xD0) {
            index += 1;  // Program Change or Channel Pressure (one-byte event data)
        } else if (the_song.p_song[index] != 0xFF) {
            index += 2;  // Other events assumed to have two bytes of data
        } else {
            index -= 1;  // Correct for boundary case if an unexpected FF byte is encountered
        }
    }
    return index;  // Return the updated index
}

/**
 * @brief Parses a MIDI song and populates the tones array based on events found.
 *
 * This function traverses the MIDI data of a specified song, handling track headers,
 * meta events, and channel events. It adjusts indices accordingly to correctly parse
 * each segment of the song data.
 *
 * @param song_num The identifier for the song to be parsed.
 */
void parse_song(int song_num) {
    the_song = get_song(song_num);  // Retrieve song data
    uint8_t numOfTracks = 0;  // Initialize track count

    // Iterate through song data
    for (int i = 0; i < the_song.size; i++) {
        uint8_t hexValue = the_song.p_song[i];  // Current byte value

        // Handling different MIDI data types
        if (hexValue == 0x4D) {  // Track header
            if (numOfTracks < 1) {
                i += 7 + the_song.p_song[i + 7];  // Jump past the header for the first track
            } else {
                i += 7;  // Jump past subsequent headers
            }
            numOfTracks++;  // Increment track counter
        }
        else if (hexValue == 0xFF) {  // Meta event
            i = parse_meta_event(i);  // Process meta event and update index
        }
        else {  // Channel event
            i = parse_channel_event(i);  // Process channel event and update index
        }
    }
}

/**
 * @brief Plays the specified MIDI song using hardware peripherals.
 *
 * This function initializes system hardware, parses song structure, and then iterates through
 * the tones array to play each tone based on its timing and note characteristics. Tones are played
 * by setting DAC values according to note frequencies and durations calculated from MIDI data.
 *
 * @param song_num The identifier for the song to be played.
 */
void play_song(int song_num) {
	init_systick();
	GPIO_Init();
	DAC_Init();
	DAC_Start();
	parse_division(song_num);
	parse_song(song_num);
	for (int i = 0; i < tones_index; i++) {

		uint32_t delayInMicroseconds = (tones[i+1].delay * (tempo / division)) / 79;

		uint32_t end_time = (uint32_t) get_counter() + delayInMicroseconds;
		while (((uint32_t) get_counter()) < end_time) {
			uint32_t half = tones[i].note / 2;
			uint32_t temp_count = (uint32_t) get_counter();

			if ((temp_count % tones[i].note) < half) {
				DAC_Set_Value(2048);
			} else {
				DAC_Set_Value(0);
			}

			if (tones[i].velocity > 0) {
				DAC_Set_Value(0);
			}
		}
	}
}
