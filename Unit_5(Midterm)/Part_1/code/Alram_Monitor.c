#include "Alram_Monitor.h"

void (*alram_monitor_state)();
unsigned int  alram_timer;
unsigned int const alram_period = 60;

void alram_monitor_initialize(){
	alram_monitor_state = State(Alram_OFF);
}

State_definition(Alram_OFF){
	alram_monitor_state_ID = Alram_OFF;
	stop_alram();
}

void high_pressure_detected(){
	alram_monitor_state = State(Alram_ON);
}

State_definition(Alram_ON){
	alram_monitor_state_ID = Alram_ON;
	
	start_alram();
	
	alram_monitor_state = State(Alram_Monitor_Waiting);

}

State_definition(Alram_Monitor_Waiting){
	alram_timer = 0;
	while(alram_timer <= alram_period*10000){
		alram_timer++;
	}
	
	alram_monitor_state = State(Alram_OFF);
}