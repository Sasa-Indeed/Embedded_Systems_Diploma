/*
 * WDT.c
 *
 * Created: 31/07/2023 14:16:39
 *  Author: Ahmed
 */ 

#include "WDT.h"

void WDT_on(void){
	WDTCR = (1 << WDP0) | (1 << WDP1) | (1 << WDP2) | (1 << WDE);
}

void WDT_off(void){
		WDTCR = (1<<WDTOE)|(1<<WDE);
		WDTCR = 0x00;
}