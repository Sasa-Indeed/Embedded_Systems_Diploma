#include "uart.h"

unsigned char buffer [50] = "learn-in-depth:<Ahmed>";
unsigned char const buffer_2 [50] = "learn-in-depth:<Ahmed>";

void main(void){
	
	uart_send_String(buffer);
	
}