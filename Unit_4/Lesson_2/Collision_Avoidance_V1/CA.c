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
int generate_readings(int l,int r ,int count);

State_definition(CA_waiting){
	//set current status
	CA_state_ID = CA_waiting;

	//State Action
	CA_speed = 0;

	//Event Checking
	CA_distance = generate_readings(45,55,1);
	(CA_distance <= CA_threshold)? (CA_state = State(CA_waiting)) : (CA_state = State(CA_driving));
	printf("Waiting STATE: Distance = %d Speed = %d \n",CA_distance,CA_speed);

}

State_definition(CA_driving){
	//set current status
	CA_state_ID = CA_driving;

	//State Action
	CA_speed = 30;

	//Event Checking
	CA_distance = generate_readings(45,55,1);
	(CA_distance > CA_threshold)? (CA_state = State(CA_driving)) : (CA_state = State(CA_waiting));
	printf("Driving STATE: Distance = %d Speed = %d \n",CA_distance,CA_speed);

}

int generate_readings(int l,int r ,int count){
	int i,randnum;

	for(i = 0; i < count; i++){
		randnum = (rand() % (r-l+1)) + l;
	}
	return randnum;
}

