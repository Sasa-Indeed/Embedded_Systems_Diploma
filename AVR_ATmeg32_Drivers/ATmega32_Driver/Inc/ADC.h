/*
 * ADC.h
 *
 * Created: 04/08/2023 21:28:14
 *  Author: Ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_

//-*-*-*-*-*-*-*-*-*-*-*-
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-
#include <stdint.h>
#include <avr/io.h>
#include "../Utilities.h"
#include "avr/interrupt.h"


//Configuration structures
typedef struct {
	uint8_t ADC_mode;  /*This parameter specifies the mode (free mode or single conversion) 
						 must be specified form @ref ADC_mode*/
	
	uint8_t ADC_data_repersentation; /*This parameter specifies how the data should be represented 
									(right adjusted or left adjusted. It must be specified form @ref ADC_data_repersentation*/
	
	uint8_t ADC_volt_ref; //This parameter specifies ADC Vref Source must be specified form @ref ADC_volt_ref
	
	
	uint8_t ADC_enable_auto; /*This parameter will start a conversion on a positive edge of the selected trigger signal.
						   must be specified form @ref ADC_enable_auto*/
	
	uint8_t ADC_auto_src; /*This parameter specifies which source will trigger ADC when in auto mode.
							must be specified form @ref ADC_auto_src*/
	
	uint8_t ADC_prescaler; //This parameter specifies prescaler must be specified form @ref ADC_prescaler
	
	uint8_t ADC_IRQ_enable; //This parameter enables the interrupt must be specified form @ref ADC_IRQ_enable
	
	void(*P_callback)(void); // //Sets the C Function which will be called once IRQ Happens when conversion completed
	
	}ADC_config_t;

typedef enum{
	polling_enable,
	polling_disable
}polling;

typedef enum{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7	
}channel_sel_t;

/******************************************************************************
                           User Define References Macros
*******************************************************************************/

//@ref ADC_mode ADCSRA
#define ADC_MODE_FREE_MODE														(uint8_t)(0x0)
#define ADC_MODE_SINGLE_CONVERSION												(uint8_t)(1 << 6)

//@ref ADC_data_repersentation ADMUX
#define ADC_DATA_REPRESENTATION_RIGHT_ADJUST									(uint8_t)(0x0)
#define ADC_DATA_REPRESENTATION_LEFT_ADJUST										(uint8_t)(1 << 5)	

//@ref ADC_volt_ref ADMUX 
#define ADC_VOLT_REF_EXTERNAL													(uint8_t)(0X0)
#define ADC_VOLT_REF_AVCC														(uint8_t)(1 << 6)
#define ADC_VOLT_REF_INTERNAL													(uint8_t)(3 << 6)

//@ref ADC_enable_auto  ADCSRA
#define ADC_ENABLE_AUTO_DISABLE													(uint8_t)(0X0)
#define ADC_ENABLE_AUTO_ENABLE													(uint8_t)(1 << 5)

//@ref ADC_auto_src  SFIOR
#define ADC_AUTO_SRC_FREE_RUNNING_MODE											(uint8_t)(0X0)
#define ADC_AUTO_SRC_ANALOG_COMPARATOR											(uint8_t)(1 << 5)
#define ADC_AUTO_SRC_EXTRNAL_INTERRUPT_REQUEST0									(uint8_t)(2 << 5)
#define ADC_AUTO_SRC_TIMER0_COMPARE_MATCH										(uint8_t)(3 << 5)
#define ADC_AUTO_SRC_TIMER0_OVERFLOW											(uint8_t)(4 << 5)
#define ADC_AUTO_SRC_TIMER1_COMPARE_MATCH										(uint8_t)(5 << 5)
#define ADC_AUTO_SRC_TIMER1_OVERFLOW											(uint8_t)(6 << 5)
#define ADC_AUTO_SRC_TIMER1_CAPTURE_EVENT										(uint8_t)(7 << 5)

//@ref ADC_prescaler ADCSRA
#define ADC_PRESCALER_DIV2														(uint8_t)(1 << 0)
#define ADC_PRESCALER_DIV4														(uint8_t)(2 << 0)
#define ADC_PRESCALER_DIV8														(uint8_t)(3 << 0)
#define ADC_PRESCALER_DIV16														(uint8_t)(4 << 0)
#define ADC_PRESCALER_DIV32														(uint8_t)(5 << 0)
#define ADC_PRESCALER_DIV64														(uint8_t)(6 << 0)
#define ADC_PRESCALER_DIV128													(uint8_t)(7 << 0)

//@ref ADC_IRQ_enable  ADCSRA
#define ADC_IRQ_DISABLE															(uint8_t)(0)
#define ADC_IRQ_ENABLE															(uint8_t)(1 << 3)


/*******************************************************************************
                       APIs Supported by "MCAL ADC Driver"
*******************************************************************************/
void MCAL_ADC_init(ADC_config_t * config);
void MCAL_ADC_deinit(void);

void MCAL_ADC_get_results(channel_sel_t channel,uint16_t * data, polling poll);

#endif /* ADC_H_ */