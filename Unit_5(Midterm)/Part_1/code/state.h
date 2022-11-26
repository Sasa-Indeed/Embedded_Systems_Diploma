#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"
#include "driver.h"

#define clean fflush(stdin);\
			  fflush(stdout);

//automatic STATE function generation
#define State_definition(_statFUN_) void ST_##_statFUN_()
#define State(_stat_) ST_##_stat_


//STATES Connections'
void set_pressure_value(int pressure_value);
void high_pressure_detected();
void start_alram();
void stop_alram();


#endif /* STATE_H_ */