/*
 * USART.h
 *
 * Created: 18/06/2023 14:47:56
 *  Author: Ahmed
 */ 


#ifndef UART_H_
#define UART_H_

//-*-*-*-*-*-*-*-*-*-*-*-
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-
#include <stdint.h>
#include <avr/io.h>
#include "avr/interrupt.h"

#include <util/delay.h>
#include "../Utilities.h"

//=========================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-
#define STOP_SYMBOL	 '#'



//=========================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//APIs:
//-*-*-*-*-*-*-*-*-*-*-*-
void UART_Init(void);

void UART_Send(uint8_t data);

uint8_t UART_Recive(void);

void UART_Send_Number(uint32_t num);

uint32_t UART_Recive_Number(void);

void UART_Send_String(char* str);

void UART_Recive_String(char* str);

uint8_t UART_Recive_Peridic(uint8_t * data);

void UART_Send_NoBlock(uint8_t data);

uint8_t UART_Recive_NoBlock(void);

void UART_RX_Interrupt_Enable(void);

void UART_RX_Interrupt_Disable(void);

void UART_TX_Interrupt_Enable(void);

void UART_TX_Interrupt_Disable(void);

#endif /* UART_H_ */