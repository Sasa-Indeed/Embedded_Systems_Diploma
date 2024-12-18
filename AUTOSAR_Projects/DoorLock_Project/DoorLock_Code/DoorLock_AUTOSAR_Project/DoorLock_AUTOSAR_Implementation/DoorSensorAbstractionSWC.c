/*
 * DoorSensorAbstractionSWC.c
 *
 *  Created on: Oct 14, 2024
 *      Author: ENG. Ahmed
 */

#include "RTE_GEN/Rte_DoorSensorAbstractionSWC.h"
#include "MCAL/DIO.h"


#define LEDON		0
#define LEDOFF		1


/*****************************************************
 * Port: 		PP_CS_LEDSwitch
 * Interface:	IF_CS_LED
 * Operation:	LED_Switch
 *****************************************************/
Std_ReturnType LED_Switch_Runnable(myunit8 LedState) {

	if(LedState == LEDON){
		DIO_WriteChannel(LED_ID, LEDON);
		return RTE_E_IF_CS_LED_E_OK;
	}else if(LedState == LEDOFF){
		DIO_WriteChannel(LED_ID, LEDOFF);
		return RTE_E_IF_CS_LED_E_OK;
	}

	return RTE_E_IF_CS_LED_E_NOT_OK;
}


/**************** event triggered runnable entities *******************/

/*****************************************************
 * Runnable: 	ReadDoorSensor
 * Period:		0.01
 *****************************************************/
void ReadDoorSensor_Runnable(void){

	uint8_t doorState = 0;

	//Read GPIO PIN 3
	doorState = DIO_ReadChannel(DIO_DOOR_ID);

	//Write doorState to RTE SR IF
	Rte_IWrite_DoorSensorAbstractionSWC_ReadDoorSensor_PP_SR_DoorState(doorState);
}
