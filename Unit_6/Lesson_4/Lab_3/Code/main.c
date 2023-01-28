/*
 * GccApplication1.c
 *
 * Created: 28/01/2023 02:59:20
 * Author : Ahmed
 */ 

/*LAB1
 * Write C Code using the 3 eternal interrupts
 * External Interrupt 0 (INT0)-PD2. >> irqoccur when “any logical change”
 * External Interrupt 1 (INT1)-PD3. >> irqoccur when “rising edge”
 * External Interrupt 2 (INT2)-PB2. >> irqoccur when “Falling edge”
 * We have also 3 LEDs (PD5,6,7) (led0,1,2).
 * Each interrupt just make the led 0N for 1 sec
 * The main function is always make all the LEDs off
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 16000000UL 

//APIs
void interrupt_init(void);
void GICR_init(void);
void IO_ports_init(void);


int main(){
	//Bit 7 – SPIE: SPI Interrupt Enable
	sei();
	interrupt_init();
	GICR_init();
	IO_ports_init();

	while(1){
		PORTD &= ~(1<<5);
		PORTD &= ~(1<<6);
		PORTD &= ~(1<<7);
	}
}


void interrupt_init(void){
	//Enabling INT0 for any logical change
	MCUCR |= (0b01 << 0);

	//Enabling INT1 for any rising edge change
	MCUCR |= (0b11 << 0);

	//Enabling INT2 for any falling edge change
	MCUCSR &= ~(1 << 6);
}

void GICR_init(void){
	//Bit 5 – INT2: External Interrupt Request 2 Enable
	GICR |= (1 << 5);

	//Bit 6 – INT0: External Interrupt Request 0 Enable
	GICR |= (1 << 6);

	//Bit 7 – INT1: External Interrupt Request 1 Enable
	GICR |= (1 << 7);
}

void IO_ports_init(void){
	//Enable pin D 5 as output
	DDRD |= (1 << 5);

	//Enable pin D 6 as output
	DDRD |= (1 << 6);

	//Enable pin D 7 as output
	DDRD |= (1 << 7);
}

ISR(INT0_vect){
	PORTD |= (1<<5);	//Turning ON led on pin 5
	_delay_ms(1000);	//Waiting for one second
	PORTD &= ~(1<<5);	//Turning OFF led on pin 5
}

ISR(INT1_vect){
	PORTD |= (1<<6);	//Turning ON led on pin 6
	_delay_ms(1000);	//Waiting for one second
	PORTD &= ~(1<<6);	//Turning OFF led on pin 6
}

ISR(INT2_vect){
	PORTD |= (1<<7);	//Turning ON led on pin 7
	_delay_ms(1000);	//Waiting for one second
	PORTD &= ~(1<<7);	//Turning OFF led on pin 7
}


