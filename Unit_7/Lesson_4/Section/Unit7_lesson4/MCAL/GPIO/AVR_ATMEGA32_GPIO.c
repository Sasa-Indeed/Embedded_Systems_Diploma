/*
 * AVR_ATMEGA32_GPIO.c
 *
 * Created: 28/02/2023 13:31:48
 *  Author: Ahmed
 */ 
 #include "AVR_ATMEGA32_GPIO.h"
 
 uint8_t Port_Read(uint8_t PortX){
	 return (uint8_t)PortX;
 }
 
 void Port_Write(uint8_t PortX, uint8_t Value){
	 PortX = Value;
 }

 void Port_Direction(uint8_t DDRX, uint8_t State){

	  if(State == OUTPUT_MODE){
		  DDRX = (uint8_t)(0xFF);
	  }else{
		  DDRX = (uint8_t)(0x00);
	  }
	  
 }
 
 void Pin_Direction(uint8_t DDRX, uint8_t State, uint8_t Pin){
	 
	 if(State == OUTPUT_MODE){
		 DDRX |= Pin;
	 }else{
		 DDRX &= ~(Pin);
	 }
	 
 }
 