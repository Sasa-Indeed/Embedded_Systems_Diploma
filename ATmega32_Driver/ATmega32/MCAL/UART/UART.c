/*
 * USART.c
 *
 * Created: 18/06/2023 14:48:15
 *  Author: Ahmed
 */ 
#include "UART.h"

void UART_Init(void){
	
	
	//Setting baud rate
	UBRRL = 51; 
	CLEAR_BIT(UCSRA,U2X); //Normal mode
	
	
	//Enabling the uart
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
}

void UART_Send(uint8_t data){
	
	while(!READ_BIT(UCSRA,UDRE));//Busy wait
	UDR = data;
}

uint8_t UART_Recive(void){
	while(!READ_BIT(UCSRA,RXC));//Busy wait
	return UDR;
}

void UART_Send_Number(uint32_t num){
	uint8_t * pNum = &num;
	
	UART_Send(pNum[0]);
	UART_Send(pNum[1]);
	UART_Send(pNum[2]);
	UART_Send(pNum[3]);
}

uint32_t UART_Recive_Number(void){
	uint32_t num;
	uint8_t * pNum = &num;
	
	pNum[0] = UART_Recive();
	pNum[1] = UART_Recive();
	pNum[2] = UART_Recive();
	pNum[3] = UART_Recive();
	
	return num;	
}

void UART_Send_String(char* str){
	while(*str != '\0'){
		while(!READ_BIT(UCSRA,UDRE));//Busy wait
		UDR = *str;
		str++;
	}
	while(!READ_BIT(UCSRA,UDRE));//Busy wait
	UDR = '\0';
}

void UART_Recive_String(char* str){
	while(1){
		
		while(!READ_BIT(UCSRA,RXC));//Busy wait
		
		*str = UDR;
		
		if (*str == '\0'){
			break;
		}else{
			str++;
		}
	}
	
	
}