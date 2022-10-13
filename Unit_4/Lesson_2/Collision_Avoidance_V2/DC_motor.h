/*
 * DC_motor.h
 *
 *  Created on: 12 Oct 2022
 *      Author: Ahmed
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "State.h"

//define states
enum{
	DC_M_idle,
	DC_M_busy
}DC_M_state_ID;

//state functions prototypes DC motor
void DC_M_Initialize();
State_definition(DC_M_idle);
State_definition(DC_M_busy);

//STATE pointer to function
extern void (*DC_state)();


#endif /* DC_MOTOR_H_ */
