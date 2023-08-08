/*
 * thermometer.c
 *
 * Created: 08/08/2023 00:48:31
 *  Author: Ahmed
 */ 

//-*-*-*-*-*-*-*-*-*-*-*-
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-

#include "thermometer.h"
#include <stddef.h>

uint32_t vin, temp, data, i, barSize;




void ADC_callBack(void){
	data = ((data * 100) / 1023);
	LCD_WRITE_STRING("Perc : ");
	LCD_WRITE_Intger_Number(data);
	LCD_WRITE_CHAR('%');
	LCD_WRITE_COMMAND(LCD_CMD_BEGIN_AT_SECOND_ROW);
	barSize = (160 / (1000 / data));
	for (i = 0; i < barSize; i++){
		LCD_WRITE_CHAR(0xff);
	}
	_delay_ms(1000);
	LCD_CLEAR_SCREEN();
}
void ADC_progress_bar_app(void){
	ADC_config_t config;
	
	config.ADC_mode = ADC_MODE_SINGLE_CONVERSION;
	config.ADC_prescaler = ADC_PRESCALER_DIV64;
	config.ADC_data_repersentation = ADC_DATA_REPRESENTATION_RIGHT_ADJUST;
	config.ADC_volt_ref = ADC_VOLT_REF_AVCC;
	
	#ifdef USING_POLLING 
	config.ADC_IRQ_enable = ADC_IRQ_DISABLE;
	config.P_callback = NULL;
	#endif
	
	#ifdef USING_INTERRUPT
	config.ADC_IRQ_enable = ADC_IRQ_ENABLE;
	config.P_callback = ADC_callBack; 
	#endif
	
	MCAL_ADC_init(&config);
	LCD_INIT();
	
	#ifdef USING_POLLING
	MCAL_ADC_get_results(ADC1, &data, polling_enable);
	ADC_callBack();
	#endif
	
	#ifdef USING_INTERRUPT
	MCAL_ADC_get_results(ADC1, &data, polling_disable);
	#endif
	
}