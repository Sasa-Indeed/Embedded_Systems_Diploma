/*
 * USART.c
 *
 * Created: 18/06/2023 14:48:15
 *  Author: Ahmed
 */ 
#include "UART.h"

static uint8_t* Tx_str;
static uint8_t send_flag = 1;
static uint8_t* Rx_str;
static uint8_t recive_flag = 1;


void UART_Init(void){
	
	
	//Setting baud rate
	UBRRL = 51; 
	CLEAR_BIT(UCSRA,U2X); //Normal mode
	
	
	//Enabling the UART
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
	uint32_t i = 0;
	while(str[i] != '\0'){
		while(!READ_BIT(UCSRA,UDRE));//Busy wait
		UDR = str[i];
		i++;
	}
	while(!READ_BIT(UCSRA,UDRE));//Busy wait
	UDR = STOP_SYMBOL;
}

void UART_Recive_String(char* str){
	uint32_t i = 0;
	
	while(1){
		while(!READ_BIT(UCSRA,RXC));//Busy wait
		str[i] = UDR;
		
		if (str[i] == STOP_SYMBOL){
			str[i] == '\0';
			break;
		}else{
			i++;
		}
	}
	
	
}

uint8_t UART_Recive_Peridic(uint8_t * data){
	
	if (READ_BIT(UCSRA,RXC)){
		*data = UDR;
		return 1;
	}
	return 0;
}

void UART_Send_NoBlock(uint8_t data){
	UDR = data;
}

uint8_t UART_Recive_NoBlock(void){
	return UDR;
}

void UART_RX_Interrupt_Enable(void){
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_Interrupt_Disable(void){
	CLEAR_BIT(UCSRB,RXCIE);
}

void UART_TX_Interrupt_Enable(void){
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_Interrupt_Disable(void){
	CLEAR_BIT(UCSRB,TXCIE);
}

void UART_Send_StringAsch(uint8_t * str){
	if (send_flag == 1){
		UART_TX_Interrupt_Enable();
		UART_Send_NoBlock(str[0]);
		Tx_str = str;
		send_flag = 0;
	}
	
}

void UART_Recive_StringAsch(uint8_t * str){
	if (recive_flag == 1){
		UART_RX_Interrupt_Enable();
		Rx_str = str;
		recive_flag = 0;
	}
	
}


ISR(UART_TXC_vect)	{
	/*Here the i is one cause when it was called originally in
	UART_Send_StringAsch we already sent the first character*/
	static uint8_t i =  1;
	if (Tx_str[i] != STOP_SYMBOL){
		UART_Send_NoBlock(Tx_str[i]);
		i++;
	} else{
		i = 1;
		send_flag = 1;
	}
}

ISR(UART_RXC_vect)	{
	/*Here the i is one cause when it was called originally in
	UART_Send_StringAsch we already sent the first character*/
	static uint8_t i =  0;
	Rx_str[i] = UART_Recive_NoBlock();
	
	if (Rx_str[i] == STOP_SYMBOL){
		Rx_str[i] = '\0';
		i = 0;
		recive_flag = 1;
	}else{
		i++;
	}
	
}