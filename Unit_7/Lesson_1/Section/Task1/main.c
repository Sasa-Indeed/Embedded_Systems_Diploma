/*
 * Task1.c
 *
 * Created: 31/01/2023 10:43:54
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
		turnLedsSeq(); //Turning LEDs sequentially 
    }
}

void GPIO_init(void){
	//Initialize all pins A as outputs 
	DDRA = 0xff;
	PORTA = 0xff;
}

void turnLedsSeq(void){
	uint32_t whileFlag = 1, onFlag = 0;
	int32_t i = 0;
	
	while(whileFlag){
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
				*break out of the while loop*/
				whileFlag = 0;
				}else{
					//Turning off the LED
					ToggleBit(PORTA,i--);
					_delay_ms(delay);
				}
			}
			
		}//end while
}
