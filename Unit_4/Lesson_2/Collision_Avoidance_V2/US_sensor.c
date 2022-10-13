/*
 * US_sensor.c
 *
 *  Created on: 12 Oct 2022
 *      Author: Ahmed
 */
#include "US_sensor.h"

unsigned int US_distance =0;
void (*US_sensor_state)();
int generate_readings(int l,int r ,int count);


void US_sensor_Initialize(){
	//initialize  ultrasonic sensor
		printf("==========Ultrasonic sensor init==========\n");
		clean
}

State_definition(US_sensor_busy){
	//set current status
	US_sensor_state_ID = US_sensor_busy;

	//read distance
	US_distance = (unsigned int)generate_readings(45,55,1);
	printf("Ultrasonic sensor Busy STATE: distance = %d\n", US_distance);
	clean

	//send readings
	US_get_distance(US_distance);

	//call Drive
	US_sensor_state = State(US_sensor_busy);

}

int generate_readings(int l,int r ,int count){
	int i,randnum;

	for(i = 0; i < count; i++){
		randnum = (rand() % (r-l+1)) + l;
	}
	return randnum;
}
