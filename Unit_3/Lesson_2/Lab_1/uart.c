#include "uart.h"

#define UART0DR *((volatile unsigned int* const)((unsigned int*) 0x101f1000))

void uart_send_String(unsigned char* text){

	while(*text != '\0'){
		UART0DR = (unsigned int)(*text);
		++text;
	}

}