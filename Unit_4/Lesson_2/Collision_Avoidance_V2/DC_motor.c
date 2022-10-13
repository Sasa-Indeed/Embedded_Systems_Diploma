/*
 * DC_motor.c
 *
 *  Created on: 12 Oct 2022
 *      Author: Ahmed
 */
#include "DC_motor.h"

unsigned int DC_M_speed =0;
void (*DC_state)();

void DC_M_Initialize(){
	//initialize  DC motor
	printf("==========DC motor init==========\n");
	clean
}


void DC_M_set_speed(int speed){
	DC_M_speed = (unsigned int) speed;
	DC_state = State(DC_M_busy);
	printf("CA --------speed : %d--------> DC\n",DC_M_speed);
	clean
}

State_definition(DC_M_idle){
	//set current status
	DC_M_state_ID = DC_M_idle;

	//State Action
	DC_state = State(DC_M_idle);

	printf("DC Motor idle STATE: speed = %d\n", DC_M_speed);
	clean
}

State_definition(DC_M_busy){
	//set current status
	DC_M_state_ID = DC_M_busy;

	//State Action
	DC_state = State(DC_M_idle);

	printf("DC Motor Busy STATE: speed = %d\n", DC_M_speed);
	clean
}
