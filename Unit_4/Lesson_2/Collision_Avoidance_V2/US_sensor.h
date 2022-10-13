/*
 * US_sensor.h
 *
 *  Created on: 12 Oct 2022
 *      Author: Ahmed
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_
#include "State.h"

//define states
enum{
	US_sensor_busy
}US_sensor_state_ID;

//state functions prototypes ultrasonic sensor
void US_sensor_Initialize();
State_definition(US_sensor_busy);

//STATE pointer to function
extern void (*US_sensor_state)();

#endif /* US_SENSOR_H_ */
