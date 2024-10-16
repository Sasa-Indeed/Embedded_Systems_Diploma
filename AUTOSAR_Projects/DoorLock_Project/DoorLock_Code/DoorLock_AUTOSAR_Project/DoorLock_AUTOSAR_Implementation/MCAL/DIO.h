/*
 * DIO.h
 *
 *  Created on: Oct 10, 2024
 *      Author: Ahmed
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_

#include "stm32f103x8_gpio_driver.h"

unsigned char DIO_ReadChannel(unsigned char ID);
void DIO_WriteChannel(unsigned char ID, unsigned char level);

//DIO IDs (PortA)
#define DIO_DOOR_ID 		GPIO_PIN_3
#define LED_ID				GPIO_PIN_7

//Port Used
#define GPIO_PORT_USED		GPIOA


#endif /* MCAL_DIO_H_ */
