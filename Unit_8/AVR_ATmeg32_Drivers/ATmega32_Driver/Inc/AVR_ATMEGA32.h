/*
 * AVR_ATMEGA32.h
 *
 * Created: 28/02/2023 12:56:24
 *  Author: Ahmed
 */ 


#ifndef AVR_ATMEGA32_H_
#define AVR_ATMEGA32_H_

//-----------------------------
//Includes
//-----------------------------
#include "stdlib.h"
#include "stdint.h"

//=========================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-
#define DDR_OFFSET					-1
#define PIN_OFFSET					-2




//=========================================================================
//Base Addresses 
//-----------------------------

#define PORTA_BASE						(uint8_t)(0x3B)
#define PORTB_BASE						(uint8_t)(0x38)
#define PORTC_BASE						(uint8_t)(0x35)
#define PORTD_BASE						(uint8_t)(0x32)


//=========================================================================
//Peripheral Registers
//-----------------------------


//PORT 
#define PORTA						(*(volatile uint8_t *)(PORTA_BASE))
#define PORTB						(*(volatile uint8_t *)(PORTB_BASE))
#define PORTC						(*(volatile uint8_t *)(PORTC_BASE))
#define PORTD						(*(volatile uint8_t *)(PORTD_BASE))

//DDR
#define DDRA						(*(volatile uint8_t *)(PORTA_BASE + DDR_OFFSET))
#define DDRB						(*(volatile uint8_t *)(PORTB_BASE + DDR_OFFSET))
#define DDRC						(*(volatile uint8_t *)(PORTC_BASE + DDR_OFFSET))
#define DDRD						(*(volatile uint8_t *)(PORTD_BASE + DDR_OFFSET))

//PIN
#define PINA						(*(volatile uint8_t *)(PORTA_BASE + PIN_OFFSET))
#define PINB						(*(volatile uint8_t *)(PORTB_BASE + PIN_OFFSET))
#define PINC						(*(volatile uint8_t *)(PORTC_BASE + PIN_OFFSET))
#define PIND						(*(volatile uint8_t *)(PORTD_BASE + PIN_OFFSET))







#endif /* AVR_ATMEGA32_H_ */