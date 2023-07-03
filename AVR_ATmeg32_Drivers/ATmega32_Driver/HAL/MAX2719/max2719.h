/*
 * max2719.h
 *
 * Created: 02/07/2023 23:13:51
 *  Author: Ahmed
 */ 


#ifndef MAX2719_H_
#define MAX2719_H_

//-*-*-*-*-*-*-*-*-*-*-*-
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-
#include <stdint.h>
#include <avr/io.h>
#include "SPI.h"

//=================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros & typdefs:

#define MAX2719_PORT						PORTB

#define MAX2719_NO_OP						0x00
#define MAX2719_D0							0x01
#define MAX2719_D1							0x02
#define MAX2719_D2							0x03
#define MAX2719_D3							0x04
#define MAX2719_D4							0x05
#define MAX2719_D5							0x06
#define MAX2719_D6							0x07
#define MAX2719_D7							0x08
#define MAX2719_DECODE_MODE					0x09
#define MAX2719_INTENSITY					0x0A
#define MAX2719_SCAN_LIMT					0x0B
#define MAX2719_SHUTDOWN					0x0C
#define MAX2719_DISPLAY_TEST				0x0F

//==========================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//APIs:
//-*-*-*-*-*-*-*-*-*-*-*-
void MAX2719_init(void);
void MAX2719_clear_display(void);
void MAX2719_display(uint8_t index, uint8_t data);



#endif /* MAX2719_H_ */