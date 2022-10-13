/*
 * State.h
 *
 *  Created on: 11 Oct 2022
 *      Author: Ahmed
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"
#define clean fflush(stdin);\
			  fflush(stdout);

//automatic STATE function generation
#define State_definition(_statFUN_) void ST_##_statFUN_()
#define State(_stat_) ST_##_stat_


//STATES Connections
void US_get_distance(int US_distance);
void DC_M_set_speed(int speed);
#endif /* STATE_H_ */
