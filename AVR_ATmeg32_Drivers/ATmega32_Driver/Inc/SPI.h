/*
 * SPI.h
 *
 * Created: 01/07/2023 18:38:22
 *  Author: Ahmed
 */ 


#ifndef SPI_H_
#define SPI_H_
//-*-*-*-*-*-*-*-*-*-*-*-
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-
#include <stdint.h>
#include <avr/io.h>
#include "avr/interrupt.h"
#include "../Utilities.h"

//=================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros & typdefs:
//-*-*-*-*-*-*-*-*-*-*-*-


typedef enum {
	SPI_Slave = 20,
	SPI_Master
}SPI_master_slave_mode;

typedef enum {
	SPI_Fosc4 = 0b00,
	SPI_Fosc16 = 0b01,
	SPI_Fosc64 = 0b10,
	SPI_Fosc128 = 0b11
}SPI_prescalar;

typedef enum {
	SPI_Enable_off = 20,
	SPI_Enable_on 
}SPI_enable;

typedef enum {
	SPI_Double_Speed_off = 20,
	SPI_Double_Speed_on
}SPI_double_speed;

typedef enum {
	SPI_Idle_Low = 20,
	SPI_Idle_High
}SPI_operating_level;

typedef enum {
	SPI_Falling = 20,
	SPI_Rising
}SPI_sampling_edge;

typedef enum {
	SPI_Interrupt_off = 20,
	SPI_Interrupt_on
}SPI_interrupt;

typedef enum {
	SPI_MSB_First = 20,
	SPI_LSB_First
}SPI_data_order;


typedef struct{
	SPI_master_slave_mode		master_slave_mode;
	SPI_prescalar				prescalar;
	SPI_enable					enable;
	SPI_double_speed			double_speed;
	SPI_operating_level			operating_level;
	SPI_sampling_edge			smapling_edge;
	SPI_interrupt				interrupt;
	void (*ptr_SPI) (void);
	SPI_data_order				data_order;
}SPI_config_t;

#define SPI_DDR			DDRB
#define SPI_PORT		PORTB
#define SPI_MOSI		PB5
#define SPI_MISO		PB6
#define SPI_SCK			PB7
#define SPI_SS			PB4


//==========================================================================================
//-*-*-*-*-*-*-*-*-*-*-*-
//APIs:
//-*-*-*-*-*-*-*-*-*-*-*-
void SPI_init(SPI_config_t * spi);
uint8_t SPI_transfer_data(uint8_t data);



#endif /* SPI_H_ */