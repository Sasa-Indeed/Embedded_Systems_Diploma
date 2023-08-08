/*
 * ADC.c
 *
 * Created: 04/08/2023 21:28:59
 *  Author: Ahmed
 */ 

#include "ADC.h"

ADC_config_t  G_config;

void MCAL_ADC_init(ADC_config_t * config){
	G_config = *config;
	
	ADCSRA |= config->ADC_mode;
	
	ADMUX |= config->ADC_data_repersentation;
	
	ADMUX |= config->ADC_volt_ref;
	
	ADCSRA |= config->ADC_enable_auto;
	
	SFIOR |= config->ADC_auto_src;
	
	ADCSRA |= config->ADC_prescaler;
	
	ADCSRA |= config->ADC_IRQ_enable;

	if (config->ADC_IRQ_enable == ADC_IRQ_ENABLE){
		sei();
	}
	
	//Enable ADC
	SET_BIT(ADCSRA,ADEN);
	
	if (config->ADC_mode == ADC_MODE_FREE_MODE){
		SET_BIT(ADCSRA,ADSC);
	}
		
}

void MCAL_ADC_deinit(void){
	ADMUX  = 0x00;
	ADCSRA = 0x00;
	SFIOR &= ~((1<<ADTS0) | (1<<ADTS1) | (1<<ADTS2));
}

void MCAL_ADC_get_results(channel_sel_t channel,uint16_t * data, polling poll){
	
	ADMUX &= ~(0x1f);
	
	ADMUX |= channel;
	CLEAR_BIT(DDRA,channel);
	
	
	if (G_config.ADC_mode == ADC_MODE_SINGLE_CONVERSION){
		SET_BIT(ADCSRA, ADSC);
	}
	
	
	if (poll == polling_enable){
		while(!READ_BIT(ADCSRA, ADIF));
	}
	
	if (G_config.ADC_data_repersentation == ADC_DATA_REPRESENTATION_RIGHT_ADJUST){
		*data = (ADCL | ((ADCH & (0x03)) << 8));
	} else {
		*data = (((ADCL & (0xC0)) >> 6) | (ADCH << 2));
	}
	
	
	CLEAR_BIT(ADCSRA,ADIF);
}


ISR(ADC_vect){
	G_config.P_callback();
}
