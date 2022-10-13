/*
 * State.h
 *
 *  Created on: 11 Oct 2022
 *      Author: Ahmed
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"


//automatic STATE function generation
#define State_definition(_statFUN_) void ST_##_statFUN_()
#define State(_stat_) ST_##_stat_

//STATE pointer to function
extern void (*CA_state)();

#endif /* STATE_H_ */
