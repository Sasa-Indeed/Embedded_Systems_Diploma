/*
 * Timer.c
 *
 * Created: 27/07/2023 18:50:10
 *  Author: Ahmed
 */ 
#include "Timer.h"
uint8_t overflowCounter = 0;

void(*G_callback_func)(void);
	
timer0_config_t g_config;



void MCAL_timer0_init(timer0_config_t * config){
	g_config = *config;
	uint8_t regTemp = 0;
	
	regTemp |= config->timer_mode;
	if (config->timer_mode != TIMER0_MODE_NORMAL || config->timer_mode != TIMER0_MODE_CTC_CLEAR_ON_COMPARE
	|| config->timer_mode != TIMER0_MODE_CTC_NORMAL || config->timer_mode != TIMER0_MODE_CTC_TOGGLE_ON_COMPARE
	|| config->timer_mode != TIMER0_MODE_CTC_SET_ON_COMPARE){
		SET_BIT(DDRB,3); //Set pin OC0 as output for wave generation
	}
	
	regTemp |= config->clk_source;
	if (config->clk_source == TIMER0_CLK_SOURCE_EXTERNAL_FALLING ||config->clk_source == TIMER0_CLK_SOURCE_EXTERNAL_RISING){
		CLEAR_BIT(DDRB,3);//Set pin OC0 as input 
	}
	
	if (config->irq_enable != TIMER0_IRQ_ENABLE_NONE){
		ENABLE_INTERRUPTS();
		TIMSK |= config->irq_enable;
	}
	
	G_callback_func = config->P_callback_func;
	
	TCCR0 = regTemp;
}
void MCAL_timer0_deinit(void){
	TCCR0 = 0;
	TIMSK &= ~(0b11);
}

void MCAL_timer0_GetCompareValue(uint8_t* pu8_TicksNumber){
	*pu8_TicksNumber = OCR0;
}
void MCAL_timer0_SetCompareValue(uint8_t u8_TicksNumber){
	OCR0 = u8_TicksNumber;
}

void MCAL_timer0_GetCounterValue(uint8_t* pu8_TicksNumber){
	*pu8_TicksNumber = TCNT0; 
}
void MCAL_timer0_SetCounterValue(uint8_t u8_TicksNumber){
	TCNT0 = u8_TicksNumber;
}

void MCAL_timer0_GetOverflowValue(uint8_t* pu8_TicksNumber){
	*pu8_TicksNumber = overflowCounter;
}
void MCAL_timer0_SetOverflowValue(uint8_t u8_TicksNumber){
	overflowCounter = u8_TicksNumber;
}

void MCAL_timer0_phaseCorrectPWM_DutyCycle(uint8_t Duty_Cycle){
	if (g_config.timer_mode == TIMER0_MODE_FAST_PWM_MODE_NON_INVERTING){
		OCR0 = Duty_Cycle;
	} else {
		OCR0 = 255 - Duty_Cycle;
	}
}

ISR(TIMER0_COMP_vect){
	G_callback_func();
}

ISR(TIMER0_OVF_vect){
	overflowCounter++;
	G_callback_func();
}