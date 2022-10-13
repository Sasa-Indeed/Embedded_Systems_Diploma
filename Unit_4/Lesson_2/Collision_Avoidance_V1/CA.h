/*
 * CA.h
 *
 *  Created on: 11 Oct 2022
 *      Author: Ahmed
 */

#ifndef CA_H_
#define CA_H_
#include "State.h"

//define states
enum{
	CA_waiting,
	CA_driving
}CA_state_ID;

//state functions prototypes CA
State_definition(CA_waiting);
State_definition(CA_driving);



#endif /* CA_H_ */
