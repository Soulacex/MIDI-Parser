/*
 * midi_converter_display.c
 *
 *  Created on: Feb 12, 2024
 *      Author: soulacex
 */


// Create a struct for the MIDI header


#include "song.h"
#include "printf.h"
#include "uint16_converter.h"
#include "uint32_converter.h"


struct MIDI_header {
    char chuck_type[4];
    unsigned int length;
    unsigned short format;
    unsigned short ntrks;
    unsigned short division;
};


/**
 * Converts and displays information from a MIDI header using 16-bit little-endian format.
 *
 * This function assumes that the input song data contains a MIDI header structure.
 * It retrieves the chunk type, total length, format, number of tracks, and division
 * from the Midi header struct and prints them to the console.
 *
 */
void use_uint16_header() {
    unsigned char* song = get_song(0).p_song;
    struct MIDI_header* song_header = (struct MIDI_header*)song;

    putns(song_header->chuck_type, 4);
    printf("%d\n", song_header->length);
    printf("%d\n", convert_to_uint16((uint8_t*)&song_header->format));
    printf("%d\n", convert_to_uint16((uint8_t*)&song_header->ntrks));
    printf("%d\n", convert_to_uint16((uint8_t*)&song_header->division));
}


/**
 * Converts and displays information from a MIDI header using 32-bit little-endian format.
 *
 * This function assumes that the input song data contains a MIDI header structure.
 * It retrieves the chunk type, total length, format, number of tracks, and division
 * from the Midi header struct and prints them to the console.
 *
 */
void use_uint32_header() {
    unsigned char* song = get_song(0).p_song;
    struct MIDI_header* song_header = (struct MIDI_header*)song;

    putns(song_header->chuck_type, 4);
    printf("%d\n", song_header->length);
    printf("%lu\n", convert_to_uint32((uint8_t*)&song_header->format));
    printf("%lu\n", convert_to_uint32((uint8_t*)&song_header->ntrks));
    printf("%lu\n", convert_to_uint32((uint8_t*)&song_header->division));
}
