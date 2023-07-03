/*
 * AVR_ATMEGA32_GPIO.h
 *
 * Created: 28/02/2023 13:32:11
 *  Author: Ahmed
 */ 


#ifndef _GPIO_H_
#define _GPIO_H_

//-----------------------------
//Includes
//-----------------------------
#include "AVR_ATMEGA32.h"


//--------------------------------
//Macros Configuration References
//--------------------------------
#define PIN_0					((uint8_t)0x01) // Pin 0 with shifting
#define PIN_1					((uint8_t)0x02) // Pin 1 with shifting
#define PIN_2					((uint8_t)0x04) // Pin 2 with shifting
#define PIN_3					((uint8_t)0x08) // Pin 3 with shifting
#define PIN_4					((uint8_t)0x10) // Pin 4 with shifting
#define PIN_5					((uint8_t)0x20) // Pin 5 with shifting
#define PIN_6					((uint8_t)0x40) // Pin 6 with shifting
#define PIN_7					((uint8_t)0x80) // Pin 7 with shifting

#define INPUT_MODE					0
#define OUTPUT_MODE					1

//=========================================================================

//------------------------------------------------------------------------------------------
//								APIs supported by "MCAL GPIO Driver"
//------------------------------------------------------------------------------------------

uint8_t Port_Read(uint8_t PortX);
void Port_Write(uint8_t PortX, uint8_t Value);

void Port_Direction(uint8_t DDRX, uint8_t State);
void Pin_Direction(uint8_t DDRX, uint8_t State, uint8_t Pin);


#endif /* AVR_ATMEGA32_GPIO_H_ */