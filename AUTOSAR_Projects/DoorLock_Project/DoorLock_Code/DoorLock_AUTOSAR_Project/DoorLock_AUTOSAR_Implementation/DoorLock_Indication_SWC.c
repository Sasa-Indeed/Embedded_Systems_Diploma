/*
 * DoorLock_Indication_SWC.c
 *
 *  Created on: Oct 14, 2024
 *      Author: Ahmed
 */

#include "RTE_GEN/Rte_DoorLock_Indication_SWC.h"

#define LEDON		0
#define LEDOFF		1

void DoorLock_Indication_Runnable(void){
	unsigned char doorState = 0;

	//Read doorState from RTE SR Interface
	doorState =  Rte_IRead_DoorLock_Indication_SWC_DoorLock_Indication_RP_SR_DoorState_DoorState();
	if(doorState){
		/*Door is open
		 * Invoke the operation "LED_Switch(LedState)"*/
		Rte_Call_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch(LEDON);
	}else{
		/*Door is closed
		 * Invoke the operation "LED_Switch(LedState)"*/
		Rte_Call_DoorLock_Indication_SWC_RP_CS_LED_Switch_LED_Switch(LEDOFF);
	}
}

