/*
 * keypad.h
 *
 * Created: 04/02/2023 09:46:31
 *  Author: Ahmed
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>
#include <util/delay.h>

// Keypad Information
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

//Keypad PORT
#define keypadPORT	PORTD
#define keypadPIN	PIND
#define keypadDDR	DDRD

//Functions APIs
void KEYPAD_INIT();
char KEYPAD_GET_CHAR();

#endif /* KEYPAD_H_ */