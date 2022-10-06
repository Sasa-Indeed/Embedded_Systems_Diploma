/*
 * main.c
 *
 *  Created on: 4 Oct 2022
 *      Author: Ahmed
 */
#include "lifo.h"

int main(){
	//testing the lifo
	int i = 0;
	element_type temp = 0;
	LIFO_Buf_t buff1;

	LIFO_init(&buff1, buffer_1, buffer1_lenght);

	//adding elements
	for (i = 0; i < 7; i++)
	{
		LIFO_add_item(&buff1,i);
	}
	//removing elements
	for (i = 0; i < 7; i++)
		{
			LIFO_pop_item(&buff1,&temp);
			printf("\n  temp is: %d",temp);
		}

	return 0;
}

