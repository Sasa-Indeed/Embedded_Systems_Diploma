/*
 * SPI.c
 *
 * Created: 01/07/2023 18:37:49
 *  Author: Ahmed
 */ 
#include "SPI.h"
static void (*SPI_ISR)(void);

void SPI_init(SPI_config_t * spi){
	
	//Enabling interrupt and assigning callback function
	if (spi->interrupt == SPI_Interrupt_on){
		SET_BIT(SPCR,SPIE);
		SPI_ISR = spi->ptr_SPI;
	} else if (spi->interrupt == SPI_Interrupt_off) {
		CLEAR_BIT(SPCR,SPIE);
	}
	
	//Data order
	if (spi->data_order == SPI_LSB_First){
		SET_BIT(SPCR,DORD);
	} else if (spi->data_order == SPI_MSB_First){
		CLEAR_BIT(SPCR,DORD);
	}
	
	//Master & Slave setup
	if (spi->master_slave_mode == SPI_Master){
		SET_BIT(SPCR,MSTR);
		//Set MOSI, SCK, SS as outputs
		SPI_DDR |= (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_SS);
		//Set MISO as input
		SPI_DDR &= ~(1 << SPI_MISO);
		
		//Pre-scalar
		SPCR = SPCR | (spi->prescalar);
		
		//Double speed
		if (spi->double_speed == SPI_Double_Speed_on){
			SET_BIT(SPCR,SPI2X);
		} else if (spi->double_speed == SPI_Double_Speed_off){
			CLEAR_BIT(SPCR,SPI2X);
		}
		
	} else if (spi->master_slave_mode == SPI_Slave){
		CLEAR_BIT(SPCR,MSTR);
		//Set MISO as output
		SPI_DDR |=	(1 << SPI_MISO);
		//Set SS, SCK, and MOSI as inputs
		SPI_DDR &= ~((1 << SPI_MOSI) | (1 << SPI_SS) | (1 << SPI_SCK));
	}
	
	//Clock polarity
	if (spi->operating_level == SPI_Idle_Low){
		SET_BIT(SPCR,CPOL);
	} else if (spi->operating_level == SPI_Idle_High){
		CLEAR_BIT(SPCR,CPOL);
	}
	
	//Clock phase
	if (spi->smapling_edge == SPI_Rising){
		SET_BIT(SPCR,CPHA);
	} else if (spi->smapling_edge == SPI_Falling){
		CLEAR_BIT(SPCR,CPHA);
	}
	
	if (spi->enable == SPI_Enable_on){
		SET_BIT(SPCR,SPE);
	} else if (spi->enable == SPI_Enable_off){
		CLEAR_BIT(SPCR,SPE);
	}
	
}

uint8_t SPI_transfer_data(uint8_t data){
	SPDR = data;
	//Waiting for data to complete transfers
	while(!(SPSR & (1 << SPIF)));
	return SPDR;
}

/*
if (){
	SET_BIT(SPCR,);
} else if (){
	CLEAR_BIT(SPCR,);
}

*/