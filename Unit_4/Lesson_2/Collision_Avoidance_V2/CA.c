/*
 * CA.c
 *
 *  Created on: 11 Oct 2022
 *      Author: Ahmed
 */
#include "CA.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

//global pointer to function
void (*CA_state)();

US_get_distance(int US_distance){
	//setting distance form sensor
	CA_distance = US_distance;

	//Event Checking
	(CA_distance <= CA_threshold)? (CA_state = State(CA_waiting)) : (CA_state = State(CA_driving));

	printf("US --------distance : %d--------> CA\n",CA_distance);
	clean
}


State_definition(CA_waiting){
	//set current status
	CA_state_ID = CA_waiting;

	printf("Waiting STATE: Distance = %d Speed = %d \n",CA_distance,CA_speed);
	clean
	//State Action
	CA_speed = 0;
	DC_M_set_speed(CA_speed);

}

State_definition(CA_driving){
	//set current status
	CA_state_ID = CA_driving;

	printf("Driving STATE: Distance = %d Speed = %d \n",CA_distance,CA_speed);
	clean
	//State Action
	CA_speed = 30;
	DC_M_set_speed(CA_speed);

}



