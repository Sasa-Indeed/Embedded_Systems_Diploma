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


#define PA15_red 			(*(volatile unsigned int*)(0x40020014)) ^= (1U << (15))
#define PB15_blue 			(*(volatile unsigned int*)(0x40020414)) ^= (1U << (15))
#define PC15_orange 		(*(volatile unsigned int*)(0x40020814)) ^= (1U << (15))

#include "tp.h"
#include "tpl_os.h"
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

//----------------------(TASk1)----------------------
#define APP_Task_Task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(Task1){

	//Do some action
	for (int i = 0; i < 100; i++){
		PA15_red;
		delay(10);
	}

	SetEvent(Task2,Task2_Event1);

	for (int i = 0; i < 100; i++){
		PA15_red;
		delay(10);
	}

	SetEvent(Task2,Task2_Event2);

	for (int i = 0; i < 100; i++){
		PA15_red;
		delay(10);
	}

	TerminateTask();

}
#define APP_Task_Task1_STOP_SEC_CODE
#include "tpl_memmap.h"
//---------------------------------------------------

//----------------------(TASk2)----------------------
#define APP_Task_Task2_START_SEC_CODE
#include "tpl_memmap.h"
unsigned char EV_Recieved;
TASK(Task2){

	for (int i = 0; i < 100; i++){
		PB15_blue;
		delay(10);
	}

	while(1){
		//Entering waiting state
		WaitEvent(Task2_Event1 | Task2_Event2);
		GetEvent(Task2, &EV_Recieved);
		if((EV_Recieved & Task2_Event1) == Task2_Event1){
			//Handle Task2 event
			ClearEvent(Task2_Event1);
			for (int i = 0; i < 100; i++){
				PB15_blue;
				delay(10);
			}

		}else if((EV_Recieved & Task2_Event2) == Task2_Event2){
			ClearEvent(Task2_Event2);
			for (int i = 0; i < 100; i++){
				PC15_orange;
				delay(10);
			}
		}
	}

	TerminateTask();

}
#define APP_Task_Task2_STOP_SEC_CODE
#include "tpl_memmap.h"
//---------------------------------------------------


/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line){}

