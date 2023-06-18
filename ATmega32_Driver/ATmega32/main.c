/*
 * GccApplication1.c
 *
 * Created: 18/06/2023 14:44:21
 * Author : Ahmed
 */ 

#include <avr/io.h>
#include "UART.h"
#include "lcd.h"

int main(void){
    char x[50];
	LCD_INIT();
	UART_Init();
	
	UART_Send_String("Learn-in-depth");

	
    while (1) {
		UART_Recive_String(x);
		LCD_WRITE_STRING(x);
    }
}

