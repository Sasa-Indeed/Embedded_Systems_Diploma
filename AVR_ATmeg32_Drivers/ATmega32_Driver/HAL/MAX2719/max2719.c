/*
 * max2719.c
 *
 * Created: 02/07/2023 23:13:38
 *  Author: Ahmed
 */ 

#include "max2719.h"

void execute_comand(uint8_t cmd, uint8_t data){
	//Initializing the packet by pulling ss low
	CLEAR_BIT(MAX2719_PORT,SPI_SS);
	
	SPI_transfer_data(cmd); // Sending command
	
	SPI_transfer_data(data);// Sending data
	
	SET_BIT(MAX2719_PORT,SPI_SS);//Terminating the packet by pulling ss high
}

void MAX2719_init(void){
	//Decode Mode &  displaying 11111111
	execute_comand(MAX2719_DECODE_MODE, 0xFF);
	//Set the scan limit to display all digits (digit 0-7)
	execute_comand(MAX2719_SCAN_LIMT,0x07);
	//Set Intensity
	execute_comand(MAX2719_INTENSITY,0x0F);
	//Turning the display on
	execute_comand(MAX2719_SHUTDOWN,0x01);
}

void MAX2719_clear_display(void){
	for (uint8_t i = 0; i < 8; i++){
		execute_comand(i,0);
	}
}

/**===========================================================================
 * @Fn				-MAX2719_display
 * @brief 			-displays numbers-characters in the screen
 * @param [in] 		-screen_number: which screen to display 1-8
 *					 1 is the left most while 8 is the right most
 * @param [in] 		-data: character to display
 * @retval 			-none
 * Note				-none
 *============================================================================
 */
void MAX2719_display(uint8_t screen_number, uint8_t data){
	execute_comand(screen_number,data);
}
