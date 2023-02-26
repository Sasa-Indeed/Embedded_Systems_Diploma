/*
 * keypad.h
 *
 * Created: 04/02/2023 09:46:31
 *  Author: Ahmed
 */ 

#ifndef KEYPAD_H_
#define KEYPAD_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103C6_GPIO_Driver.h"
#include "STM32F103x6.h"
#include <stdlib.h>
#include <stdint.h>


// Keypad Information
#define R0 			GPIO_PIN_0
#define R1 			GPIO_PIN_1
#define R2 			GPIO_PIN_3
#define R3 			GPIO_PIN_4
#define C0 			GPIO_PIN_5
#define C1 			GPIO_PIN_6
#define C2 			GPIO_PIN_7
#define C3 			GPIO_PIN_8

//Keypad PORT
#define keypadPORT	GPIOB


//Functions APIs
void KEYPAD_INIT();
char KEYPAD_GET_CHAR();


#endif /* KEYPAD_H_ */
