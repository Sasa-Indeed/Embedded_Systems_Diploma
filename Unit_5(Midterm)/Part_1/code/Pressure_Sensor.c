#include "Pressure_Sensor.h"

//member definitions
void (*pressure_sensor_state)();
unsigned int Pressure_value = 0;


void pressure_sensor_initialize(){
	//initilalizing the sensor and calling reading function
	pressure_sensor_state = State(pressure_sensor_reading);
}
State_definition(pressure_sensor_reading){
	pressure_sensor_state_ID = pressure_sensor_reading;
	
	//reading the pressure value
	Pressure_value = getPressureVal();
	//sending the pressure value
	set_pressure_value(Pressure_value);
	Delay(600);//delay for safe measures
	//changing state to waiting
	pressure_sensor_state = State(pressure_sensor_waiting);
}
State_definition(pressure_sensor_waiting){
	pressure_sensor_state_ID = pressure_sensor_waiting;
	Delay(10000);
	pressure_sensor_state = State(pressure_sensor_reading);
}
