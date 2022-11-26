#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_
#include "state.h"

//define states
enum{
	pressure_sensor_reading,
	pressure_sensor_waiting
}pressure_sensor_state_ID;

//state functions prototypes of pressure sensor
void pressure_sensor_initialize();
State_definition(pressure_sensor_reading);
State_definition(pressure_sensor_waiting);

//STATE pointer to function
extern void (*pressure_sensor_state)();

#endif /* PRESSURE_SENSOR_H_ */