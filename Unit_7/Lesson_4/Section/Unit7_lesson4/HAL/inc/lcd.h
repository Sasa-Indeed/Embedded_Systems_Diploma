/*
 * lcd.h
 *
 * Created: 03/02/2023 15:00:28
 *  Author: Ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_

//-----------------------------
//Includes
//-----------------------------
#include "AVR_ATMEGA32.h"
#include "AVR_ATMEGA32_GPIO.h"
 
 
#include <util/delay.h>

#define F_CPU 8000000UL

#define LCD_PORT					PORTA
#define DataDir_LCD_PORT			DDRA

#define LCD_CTRL					PORTB
#define DataDir_LCD_CTRL			DDRB


//LCD Controls
#define RS_Switch				PIN_1//1
#define RW_Switch				PIN_2//2
#define Enable_Switch			PIN_3//3

//LCD Modes
//#define EIGHT_BIT_MODE
#define FOUR_BIT_MODE

#ifdef EIGHT_BIT_MODE
#define DATA_SHIFT 0
#else 
#define DATA_SHIFT 4
#endif



//LCD Instructions
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)



//LCD Functions APIs
void LCD_INIT(void);
void LCD_Clear_Screen(void);
void LCD_WRITE_COMMAND(unsigned char command);
void LCD_WRITE_CHAR(unsigned char  character);
void LCD_Goto_XY(unsigned char line, unsigned char position);
void LCD_WRITE_STRING(char * string);
void LCD_isBusy(void);








#endif /* LCD_H_ */