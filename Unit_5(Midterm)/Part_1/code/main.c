#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Pressure_Sensor.h"
#include "Main_Algorithm.h"
#include "Alram_Monitor.h"

void setup(){

	//initialize Block
	GPIO_INITIALIZATION();
	pressure_sensor_initialize();
	alram_monitor_initialize();
	
}

int main (){
	setup();
	while (1){
		pressure_sensor_state(); 
		pressure_detector();
		alram_monitor_state();
	}

}
