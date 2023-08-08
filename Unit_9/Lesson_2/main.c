/*
 * ATmega32_Driver.c
 *
 * Created: 26/06/2023 12:24:49
 * Author : Ahmed
 *
 * This is the implementation of the main only if you want to see the driver go to
 * AVR_ATmeg32_Drivers directory to view the ADC Driver
 */ 
#define F_CPU 1000000UL

//#define  Master
#include <avr/io.h>
#include "UART.h"
#include "lcd.h"
#include "SPI.h"
#include "ADC.h"
#include "Timer.h"
#include "max2719.h"
#include "thermometer.h"

void lab1(void);
void lab2(void);

int main(void){
	
	
	ADC_progress_bar_app();
	
	
	return 0;
    
}

void lab1(void){
	uint8_t ch;
	SPI_config_t conf;
	conf.enable = SPI_Enable_on;
	DDRA = 0xff;
	
	#ifdef Master
	conf.master_slave_mode = SPI_Master;
	SPI_init(&conf);
	
	for (ch = 0 ; ch <= 255; ch++){
		_delay_ms(1000);
		PORTA = SPI_transfer_data(ch);
	}
	#else
	conf.master_slave_mode = SPI_Slave;
	SPI_init(&conf);
	while (1){
		for (ch = 255; ch > 0 ; ch--){
			PORTA = SPI_transfer_data(ch);
		}
	}
	
	#endif
}

void lab2(void){
	uint8_t counter = 0;
	SPI_config_t conf;
	conf.enable = SPI_Enable_on;
	conf.master_slave_mode = SPI_Master;
	SPI_init(&conf);
	MAX2719_init();
		
	while(1){
		for (uint8_t index_display = 1; index_display < 9; index_display++){
			MAX2719_display(index_display, counter++);
		}
		_delay_ms(1000);
	}
}