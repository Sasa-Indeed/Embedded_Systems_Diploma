/*
 * LCD-project.c
 *
 * Created: 03/02/2023 14:17:00
 * Author : Ahmed
 */ 

#include <avr/io.h>
#include "LCD/lcd.h"
#include "Keypad/keypad.h"


int main(void)
{
    char button;
	LCD_INIT();
	KEYPAD_INIT();
    
	while (1) {
		button = KEYPAD_GET_CHAR();
		switch(button){
			case ('N'):
			break;
			case ('!'):
			LCD_Clear_Screen();
			break;
			default:
			LCD_WRITE_CHAR(button);
		}
    }
}

