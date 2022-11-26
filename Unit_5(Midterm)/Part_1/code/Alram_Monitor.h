#ifndef ALRAM_MONITOR_H_
#define ALRAM_MONITOR_H_
#include "state.h"

//define states
enum{
	Alram_OFF,
	Alram_ON,
	Alram_Monitor_Waiting
}alram_monitor_state_ID;

//state functions prototypes of alram monitor
void alram_monitor_initialize();
State_definition(Alram_OFF);
State_definition(Alram_ON);
State_definition(Alram_Monitor_Waiting);

//STATE pointer to function
extern void (*alram_monitor_state)();

#endif /* ALRAM_MONITOR_H_ */