/*
 * unit7_lesson1_assignment.c
 *
 * Created: 30/01/2023 18:58:39
 * Author : Ahmed
 */ 

#include "Utils.h"
#include "MemoryMap.h"
#include <util/delay.h>

#define F_CPU 8000000UL

void GPIO_init(void);



int main()
{
	GPIO_init();//Initializing the Ports
	
	while (1){
		
		//If button 1 is pressed
		if (ReadBit(PIND,0) == 1){
			
			SetBit(PORTD,7);//turn on the first led
			_delay_ms(2000);
			
			SetBit(PORTD,6);//turn on the second led
			_delay_ms(2000);
		
			
			SetBit(PORTD,5);//turn on the third led
			_delay_ms(2000);
		
			SetBit(PORTD,4);//turn on the buzzer
			
			//reset the devices
			_delay_ms(2000);
			ResetBit(PORTD,7);
			ResetBit(PORTD,6);
			ResetBit(PORTD,5);
			ResetBit(PORTD,4);
			_delay_ms(2000);
			
			while(ReadBit(PIND,0) == 1);
		}
	}
}


void GPIO_init(void){
	//Configuring Port D0 as input without pull-up
	ResetBit(DDRD,0);
	ResetBit(PORTD,0);
	
	//Configuring Port D4 as output
	SetBit(DDRD,4);
	
	//Configuring Port D5 as output
	SetBit(DDRD,5);
	
	//Configuring Port D6 as output
	SetBit(DDRD,6);
	
	//Configuring Port D7 as output
	SetBit(DDRD,7);
}


