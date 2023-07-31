/*
 * Timer.h
 *
 * Created: 27/07/2023 18:49:52
 *  Author: Ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

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

//Interrupts
#define ENABLE_INTERRUPTS()				SREG |= (1 << 7)
#define DISABLE_INTERRUPTS()			SREG &= ~(1 << 7)

/******************************************************************************
*				     Configuration Structure	                			  *
*******************************************************************************/
typedef struct{
	uint8_t				timer_mode; /*Specifies the mode of the timer Clear Timer on Compare match (CTC),
							PWM,etc...	this parameter must be configured form @ref timer_mode*/
	
	uint8_t				clk_source; /*This parameter must be configured form @ref clk_source*/
	
	uint8_t				irq_enable; /*This parameter enables the interrupt must be configured form @ref irq_enable*/
	
	void(*P_callback_func)(void); 
	
	}timer0_config_t;


//-------------------------------------------------------------------
//==================Macros Configuration References==================
//-------------------------------------------------------------------

//@ref timer_mode
#define TIMER0_MODE_NORMAL															(uint8_t)(0x0<<WGM01)

#define TIMER0_MODE_PHASE_CORRECT_PWM_MODE_NORMAL									(uint8_t)(0x1<<WGM01)
#define TIMER0_MODE_PHASE_CORRECT_PWM_CLEAR_ON_COMPARE								(uint8_t)(0x5<<WGM01)/*	Clears pin OC0 which is PB3 Clear OC0 on compare match when up-counting. Set OC0 on compare match when down-counting.*/
#define TIMER0_MODE_PHASE_CORRECT_PWM_SET_ON_COMPARE								(uint8_t)(0x7<<WGM01)/*Set OC0 on compare match when up-counting. Clear OC0 on compare match when down-counting.*/

#define TIMER0_MODE_CTC_NORMAL														(uint8_t)(0x8<<WGM01)
#define TIMER0_MODE_CTC_TOGGLE_ON_COMPARE											(uint8_t)(0xA<<WGM01)
#define TIMER0_MODE_CTC_CLEAR_ON_COMPARE											(uint8_t)(0xC<<WGM01)
#define TIMER0_MODE_CTC_SET_ON_COMPARE												(uint8_t)(0xE<<WGM01)

#define TIMER0_MODE_FAST_PWM_MODE_NORMAL											(uint8_t)(0x9<<WGM01)
#define TIMER0_MODE_FAST_PWM_MODE_NON_INVERTING										(uint8_t)(0xD<<WGM01)
#define TIMER0_MODE_FAST_PWM_MODE_INVERTING											(uint8_t)(0xF<<WGM01)


//@ref clk_source
#define TIMER0_CLK_SOURCE_NO_PRESCALER												(uint8_t)(0x1<<CS00)
#define TIMER0_CLK_SOURCE_8_PRESCALER												(uint8_t)(0x2<<CS00)
#define TIMER0_CLK_SOURCE_64_PRESCALER												(uint8_t)(0x3<<CS00)
#define TIMER0_CLK_SOURCE_256_PRESCALER												(uint8_t)(0x4<<CS00)
#define TIMER0_CLK_SOURCE_1024_PRESCALER											(uint8_t)(0x5<<CS00)
#define TIMER0_CLK_SOURCE_EXTERNAL_FALLING											(uint8_t)(0x6<<CS00)
#define TIMER0_CLK_SOURCE_EXTERNAL_RISING											(uint8_t)(0x7<<CS00)

//@ref irq_enable
#define TIMER0_IRQ_ENABLE_NONE														(uint8_t)(0X0)
#define TIMER0_IRQ_ENABLE_TOIE0														(uint8_t)(1<<TOIE0)
#define TIMER0_IRQ_ENABLE_OCIE0														(uint8_t)(1<<OCIE0)

//------------------------------------------------------------------------------------------
//								APIs supported by "MCAL TIMER Driver"
//------------------------------------------------------------------------------------------
void MCAL_timer0_init(timer0_config_t * config);
void MCAL_timer0_deinit(void);

void MCAL_timer0_GetCompareValue(uint8_t* pu8_TicksNumber);
void MCAL_timer0_SetCompareValue(uint8_t u8_TicksNumber);

void MCAL_timer0_GetCounterValue(uint8_t* pu8_TicksNumber);
void MCAL_timer0_SetCounterValue(uint8_t u8_TicksNumber);

void MCAL_timer0_GetOverflowValue(uint8_t* pu8_TicksNumber);
void MCAL_timer0_SetOverflowValue(uint8_t u8_TicksNumber);

void MCAL_timer0_phaseCorrectPWM_DutyCycle(uint8_t Duty_Cycle);


#endif /* TIMER_H_ */