#include "Main_Algorithm.h"

unsigned int Pressure_Value = 0;
unsigned const int Pressure_threshold = 20;


void pressure_detector(){
	if(Pressure_Value > Pressure_threshold){
		high_pressure_detected();
	}
}

void set_pressure_value(int pressure_value){
	Pressure_Value = pressure_value;
	pressure_detector();
}