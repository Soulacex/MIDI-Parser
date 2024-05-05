// Create a struct for the MIDI header

#include "song.h"
#include "printf.h"

struct MIDI_header {
	char chunk_type [4];
	unsigned int length;
	unsigned short format;
	unsigned short ntrks;
	unsigned short division;
};



void use_header() {
	unsigned char* song = get_song(0).p_song;
	struct MIDI_header* song_header = (struct MIDI_header*)song;


//	 print out all the pieces of the header, one per line.
//	for (int i = 0; i < song_header.length; i++) {
//		printf((const char*) i);
//		printf("\n");
//	}

	putns(song_header->chunk_type, 4);
	printf("%d\n", song_header->length);
	printf("%d\n", song_header->format);
	printf("%d\n", song_header->ntrks);
	printf("%d\n", song_header->division);
//	global_division = song_header->division;

}
