/*
 * lcd.c
 *
 * Created: 03/02/2023 15:00:16
 *  Author: Ahmed
 */ 
#include "lcd.h"


void LCD_KICK(void){
	LCD_CTRL &= ~(1<<Enable_Switch);
	_delay_ms(50);
	LCD_CTRL |= (1<<Enable_Switch);
}

void LCD_INIT(void){
	_delay_ms(20);
	LCD_isBusy();
	
	DataDir_LCD_CTRL |= ((1<<Enable_Switch) | (1<<RS_Switch) | (1<<RW_Switch));
	LCD_CTRL &= ~((1<<Enable_Switch) | (1<<RS_Switch) | (1<<RW_Switch));
	
	DataDir_LCD_PORT = 0xff;
	
	_delay_ms(15);
	LCD_Clear_Screen();
	
	#ifdef EIGHT_BIT_MODE 
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	
	
	#ifdef FOUR_BIT_MODE
	
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	
	
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_Clear_Screen(void){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}


void LCD_WRITE_COMMAND(unsigned char command){
	LCD_isBusy();
	
	#ifdef EIGHT_BIT_MODE
	LCD_PORT = command;
	LCD_CTRL &= ~((1<<RS_Switch) | (1<<RW_Switch));
	LCD_KICK();
	#endif	
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0f) | (command & 0xf0);
	LCD_CTRL &= ~((1<<RS_Switch) | (1<<RW_Switch));
	LCD_KICK();
	
	_delay_ms(100);
	LCD_PORT = (LCD_PORT & 0x0f) | (command << DATA_SHIFT);
	LCD_CTRL &= ~((1<<RS_Switch) | (1<<RW_Switch));
	LCD_KICK();
	
	#endif
}
void LCD_WRITE_CHAR(unsigned char  character){
	
	
	#ifdef EIGHT_BIT_MODE
	LCD_isBusy();
	LCD_CTRL |= (1<<RS_Switch);
	LCD_PORT = ((character) << DATA_SHIFT);
	LCD_CTRL |= (1<<RS_Switch);
	LCD_CTRL &= ~(1<<RW_Switch);
	LCD_KICK();
	#endif
	
	#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0f) | (character & 0xf0);
	LCD_CTRL |= (1<<RS_Switch);
	LCD_CTRL &= ~(1<<RW_Switch);
	LCD_KICK();
	LCD_PORT = (LCD_PORT & 0x0f) | (character << DATA_SHIFT);
	LCD_CTRL |= (1<<RS_Switch);
	LCD_CTRL &= ~(1<<RW_Switch);
	LCD_KICK();
	#endif
}

void LCD_Goto_XY(unsigned char line, unsigned char position){
	
	if (line == 0){
		if ((position >= 0) && (position < 16)){
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}else if (line == 1){
		if ((position >= 0) && (position < 16)){
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
	
}

void LCD_WRITE_STRING(char * string){
	static int count = 0;
	
	while(*string > 0){
		LCD_WRITE_CHAR(*string++);
		++count;
		if (count == 16){
			LCD_Goto_XY(1,0);
		}else if (count == 32){
			LCD_Clear_Screen();
			LCD_Goto_XY(0,0);
			count = 0;
		}
	}
}

void LCD_isBusy(void){
	//Set the port to receive data on the micro-controller (Data direction as input).
	DataDir_LCD_PORT &= ~(0xff<<DATA_SHIFT);
	
	LCD_CTRL |= (1 << RW_Switch);	//Read mode
	LCD_CTRL &= ~(1 << RS_Switch);
	LCD_KICK();
	
	DataDir_LCD_PORT  = 0xff;
	LCD_CTRL &= ~(1 << RW_Switch);
	
}

