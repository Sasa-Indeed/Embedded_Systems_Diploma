/*
 * keypad.c
 *
 * Created: 04/02/2023 09:46:16
 *  Author: Ahmed
 */ 

#include "keypad.h"
#include "Utils.h"

int keypadRows[] = {R0,R1,R2,R3};
int keypadCols[] = {C0,C1,C2,C3};


void KEYPAD_INIT(){
	//Set the upper keypad port as as input
	keypadDDR &= ~((1 << R0) | (1 << R1) | (1 << R2) | (1 << R3));
	
	//Set the lower keypad port as output
	keypadDDR |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
	
	keypadPORT = 0xff;
}
char KEYPAD_GET_CHAR(){
	int i,j;
	for (i = 0; i < 4 ; i++){
		keypadPORT |= ((1 << C0) | (1 << C1) | (1 << C2) | (1 << C3));
		
		keypadPORT &= ~(1 << keypadCols[i]);
		
		for (j = 0; j < 4 ; j++){
			if (ReadBit(keypadPIN, keypadRows[j]) == 0){
				while(ReadBit(keypadPIN, keypadRows[j]) == 0);
				
				switch(i){
					case (0):{
						if		(j == 0)	return '7';
						else if (j == 1)	return '4';
						else if (j == 2)	return '1';
						else if (j == 3)	return '!';
						break;
					}
					case (1):{
						if		(j == 0)	return '8';
						else if (j == 1)	return '5';
						else if (j == 2)	return '2';
						else if (j == 3)	return '0';
						break;
					}
					case (2):{
						if		(j == 0)	return '9';
						else if (j == 1)	return '6';
						else if (j == 2)	return '3';
						else if (j == 3)	return '=';
						break;
					}
					case (3):{
						if		(j == 0)	return '/';
						else if (j == 1)	return '*';
						else if (j == 2)	return '-';
						else if (j == 3)	return '+';
						break;
					}
					
				}
			}
		}
	}
	
	return 'N';
}
