// main.c with demo
// Updated and refactored Larry Kiser copyright 2021


// include project specific header files
#include "error_handler.h"
#include "SysClock.h"
#include "LED.h"
#include "UART.h"
#include "demo.h"
#include <stdio.h>
#include "project.h"
#include "printf.h"
#include "uint16_converter.h"
#include "uint32_converter.h"
#include "activity8.h"
#include "hw5.h"
#include "activity10.h"
#include "activity11.h"
#include "hw6.h"
#include "activity12.h"
#include "activity_noise.h"
#include "activity_wave.h"
#include "midi.h"
#include "read_track.h"

int main(void) {

	// initialization code
	System_Clock_Init(); // set System Clock = 80 MHz
	LED_Init(LED_PIN);
	UART2_Init();

//	readlines();
//	print_systick();
//	hw5();

	start_project();
//	make_noise();
//	play_song(0);

//	test_dac_output();
//	activity11();
//	run_wave();
//	testParser();
//	blue_button_check();
//	USART2_IRQHandler();
//	setup();
//	EXTI15_10_IRQHandler();

	//Homework 3 functions:

//	use_uint16_header();
//	use_uint32_header();


//	use_header();
//	run_project ();
//	hello ();
//	// application run function
//	run_demo() ;
}

