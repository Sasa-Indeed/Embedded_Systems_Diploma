/*
 * main.c
 *
 *  Created on: 11 Oct 2022
 *      Author: Ahmed
 */
#include "CA.h"


void setup(){
	//set state pointer for each block
	CA_state = State(CA_waiting);
}

void main(){
	setup();
	while(1){
		CA_state();
	}
}
