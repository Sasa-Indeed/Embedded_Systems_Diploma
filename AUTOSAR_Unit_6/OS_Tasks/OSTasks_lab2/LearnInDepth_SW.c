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


#define PA15_red (*(volatile unsigned int*)(0x40020014)) ^= (1U << (15))
#define PB15_blue (*(volatile unsigned int*)(0x40020414)) ^= (1U << (15))
#define PC15_orange (*(volatile unsigned int*)(0x40020814)) ^= (1U << (15))

#include "tp.h"
#include "tpl_os.h"
//simple mydelay function
void mydelay(unsigned int ms){
	unsigned int i;
	for(i=0;i<ms;i++){}
}

FUNC(int, OS_APPL_CODE) main(void){
	initBoard();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

/*==================Task1==================*/
#define APP_Task_Task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task1){
	uint32_t count = 0;

	while(count < 100){
		PA15_red;
		mydelay(100);
		count++;
	}

	ActivateTask(Task2);

	while(count < 200){
			PA15_red;
			mydelay(100);
			count++;
	}

	ActivateTask(Task3);

	while(count < 300){
			PA15_red;
			mydelay(100);
			count++;
	}

	TerminateTask();

}
#define APP_Task_Task1_STOP_SEC_CODE
/*=========================================*/

/*==================Task2==================*/
#define APP_Task_Task2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task2){

	uint32_t count = 0;

	while(count < 100){
		PB15_blue;
		mydelay(100);
		count++;
	}

	TerminateTask();

}
#define APP_Task_Task2_STOP_SEC_CODE
/*=========================================*/

/*==================Task3==================*/
#define APP_Task_Task3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task3){

	uint32_t count = 0;

	while(count < 100){
		PC15_orange;
		mydelay(100);
		count++;
	}

	TerminateTask();

}
#define APP_Task_Task3_STOP_SEC_CODE
/*=========================================*/


/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line){}

