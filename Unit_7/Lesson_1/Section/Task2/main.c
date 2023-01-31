/*
 * Task2.c
 *
 * Created: 31/01/2023 12:06:45
 * Author : Ahmed
 */ 

#define F_CPU 8000000UL

#include <util/delay.h>
#include <stdint.h>
#include "Registers.h"
#include "Utils.h"

#define delay 25 //For controlling delays 

void GPIO_init(void);
void turnLedsSeq(void);

int main(void)
{
	GPIO_init();
	
	while (1) {
		if (ReadBit(PINC,1) == 1){
			turnLedsSeq();
			_delay_ms(delay);
		}
		
	}
}

void GPIO_init(void){
	//Initialize all pins A as outputs
	DDRA = 0xff;
	PORTA = 0xff;//Turning off the LEDs
}

void turnLedsSeq(void){
	static uint32_t onFlag = 0;//To keep track LEDs are on or off
	static int32_t i = 0;//To keep track of presses
	
		if (!onFlag){
			if (i > NUMOFPINSA - 1){
				/*if all LEDs are turned ON
				*switch to the off mode to turn 
				*off the LEDS*/
				onFlag = 1;
				i--;
			}else{
				//Turning on the LED
				ToggleBit(PORTA,i++);
				_delay_ms(delay);
			}
		}else{
			if (i < 0){
				/*if all LEDs are turned off
				*switch to the on mode to turn 
				*on the	LEDS*/
				i = 0;
				onFlag = 0;
			}else{
				//Turning off the LED
				ToggleBit(PORTA,i--);
				_delay_ms(delay);
			}
		}
		

}