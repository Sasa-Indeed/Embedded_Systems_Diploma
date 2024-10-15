/*
 * DIO.c
 *
 *  Created on: Oct 10, 2024
 *      Author: Ahmed
 */

#include "DIO.h"

unsigned char DIO_ReadChannel(unsigned char ID){
	return MCAL_GPIO_ReadPin(GPIO_PORT_USED, ID);
}

void DIO_WriteChannel(unsigned char ID, unsigned char level){
	MCAL_GPIO_WritePin(GPIO_PORT_USED, ID, level);
}
