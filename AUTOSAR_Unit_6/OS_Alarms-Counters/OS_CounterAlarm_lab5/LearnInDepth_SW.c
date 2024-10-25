/*
 * AUTOSAR IN Depth Materials
 * www.learn-in-depth.com
 * Eng.Ahmed Mostafa
 *
 */


//    PA15   (*(unsigned int*)(0x40020014)) >> 15
//    PB15   (*(unsigned int*)(0x40020414)) >> 15
//    PC15   (*(unsigned int*)(0x40020814)) >> 15
//    PD15:  (*(unsigned int*)(0x40020C14)) >> 15


#define PA15_red 	(*(volatile unsigned int*)(0x40020014)) ^=  (1U << (15))
#define PB15_blue 	(*(volatile unsigned int*)(0x40020414)) ^=  (1U << (15))
#define PC15_orange (*(volatile unsigned int*)(0x40020814)) ^=  (1U << (15))

#define PWM_SET 	(*(volatile unsigned int*)(0x40020414)) |=  (1U << (15))
#define PWM_CLEAR 	(*(volatile unsigned int*)(0x40020414)) &= ~(1U << (15))


#include "tp.h"
#include "tpl_os.h"

volatile unsigned int T_high_ticks = 50;
volatile unsigned int T_Low_ticks = 50;
volatile unsigned int T_PWM_Period_ticks = 100;
volatile unsigned char DutyCycle_percentage = 20;


//simple mydelay function
void mydelay(unsigned int ms)
{
	unsigned int i;
	for(i=0;i<ms;i++)
	{
	}
}
FUNC(int, OS_APPL_CODE) main(void){
	initBoard();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}
//-------------------Task1------------------------
#define APP_Task_Task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task1)
{

	/* Get data from user by using UART but here will be made by changing
	 * the data form the debugger */

	// Calculate T_high and T_low based on the DutyCycle_percentage
	T_high_ticks = (DutyCycle_percentage * T_PWM_Period_ticks) / 100;
	T_Low_ticks = T_PWM_Period_ticks - T_high_ticks;


	TerminateTask();

}
#define APP_Task_Task1_STOP_SEC_CODE
#include "tpl_memmap.h"
//------------------------------------------------

//-------------------Task_High-----------------------
#define APP_Task_Task_High_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task_High)
{
	PWM_SET;
	SetRelAlarm(Task_Low_Alarm, T_high_ticks, 0);

	TerminateTask();

}
#define APP_Task_Task_High_STOP_SEC_CODE
#include "tpl_memmap.h"
//---------------------------------------------------

//-------------------Task_Low------------------------
#define APP_Task_Task_Low_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task_Low)
{
	PWM_CLEAR;
	SetRelAlarm(Task_High_Alarm, T_Low_ticks, 0);
	TerminateTask();

}
#define APP_Task_Task_Low_STOP_SEC_CODE
#include "tpl_memmap.h"
//---------------------------------------------------

/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
				{
				}

