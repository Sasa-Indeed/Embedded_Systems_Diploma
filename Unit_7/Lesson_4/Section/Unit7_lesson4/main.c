/*
 * GccApplication1.c
 *
 * Created: 28/02/2023 11:48:02
 * Author : Ahmed
 */ 

#include "lcd.h"
#include "AVR_ATMEGA32_GPIO.h"


int main(void)
{
    /* Replace with your application code */



	LCD_INIT();
	
	LCD_WRITE_STRING("Learn in depth");
    while (1) 
    {
    }
}

