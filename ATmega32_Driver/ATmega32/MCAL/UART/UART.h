/*
 * USART.h
 *
 * Created: 18/06/2023 14:47:56
 *  Author: Ahmed
 */ 


#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>

#include "../Utilities.h"

void UART_Init(void);

void UART_Send(uint8_t data);

uint8_t UART_Recive(void);

void UART_Send_Number(uint32_t num);

uint32_t UART_Recive_Number(void);

void UART_Send_String(char* str);

void UART_Recive_String(char* str);



#endif /* UART_H_ */