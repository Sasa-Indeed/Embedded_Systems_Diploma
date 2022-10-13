/*
 * main.c
 *
 *  Created on: 11 Oct 2022
 *      Author: Ahmed
 */
#include "CA.h"
#include "DC_motor.h"
#include "US_sensor.h"

void setup(){

	//initialize Block
	DC_M_Initialize();
	US_sensor_Initialize();
	//set state pointer for each block
	CA_state = State(CA_waiting);
	DC_state = State(DC_M_idle);
	US_sensor_state = State(US_sensor_busy);
}

void main(){
	volatile int i;
	setup();
	while(1){
		//calling each state
		US_sensor_state();
		CA_state();
		DC_state();

		//delay
		for(i = 0; i <= 1000;i++);
	}
}
