/*
 * fifo.c
 *
 *  Created on: 4 Oct 2022
 *      Author: Ahmed
 */
#include "fifo.h"



FIFO_status FIFO_init (FIFO_Buf_t* f_Buf, element_type* buf, unsigned int lenght){

	if (f_Buf == NULL || buf == NULL)
	{
		return FIFO_null;
	}

	f_Buf->base = buf;
	f_Buf->tail = buf;
	f_Buf->head = buf;
	f_Buf->lenght = lenght;
	f_Buf->count = 0;

	return FIFO_no_error;
}

FIFO_status FIFO_lenght_status (FIFO_Buf_t* f_Buf){
	if (!f_Buf || !f_Buf->base || !f_Buf->tail || !f_Buf->head)
	{
		return FIFO_null;
	}

	if(f_Buf->count >= f_Buf->lenght){
		return FIFO_full; // Check if lifo is full
	} else if (f_Buf->count == 0){
		return FIFO_empty;// Check if lifo is empty
	}else{
		return FIFO_partial_full;
	}
}

FIFO_status FIFO_enqueue (FIFO_Buf_t* f_Buf, element_type item){

	//Checking if the buffer is valid and if it is not full
	FIFO_status stat = FIFO_lenght_status(f_Buf);
	if (stat == FIFO_null || stat == FIFO_full)
	{
		printf("\nAdd failed\n");
		return stat;
	}

	*(f_Buf->head) = item;
	printf("\nFIFO Enqueue Done (%d): %d\n", f_Buf->count, *(f_Buf->head));
	f_Buf->count++;
	//Checking if the head have reached the end if so returning it to the start again
	if(f_Buf->head == f_Buf->base + (f_Buf->lenght * sizeof(element_type))){
		f_Buf->head = f_Buf->base;
	}else{
		f_Buf->head++;
	}

	return FIFO_no_error;
}
FIFO_status FIFO_dequeue (FIFO_Buf_t* f_Buf, element_type* item){

	//Checking if the buffer is valid and if it is not empty
	FIFO_status stat = FIFO_lenght_status(f_Buf);
	if (stat == FIFO_null || stat == FIFO_empty)
	{
		printf("\Remove failed\n");
		return stat;
	}

	*(item) = *(f_Buf->tail);
	printf("\nFIFO Dequeue Done (%d): %d\n", f_Buf->count, *(item));
	f_Buf->count--;
	//Checking if the tail have reached the end if so returning it to the start again
	if(f_Buf->tail == f_Buf->base + (f_Buf->lenght * sizeof(element_type))){
		f_Buf->tail = f_Buf->base;
	}else{
		f_Buf->tail++;
	}

	return FIFO_no_error;
}

void FIFO_print (FIFO_Buf_t* f_Buf){

	FIFO_status stat = FIFO_lenght_status(f_Buf);
	if (stat == FIFO_null){
		printf("\n Error NULL pointer\n");
	}else if (stat == FIFO_empty){
		printf("\n Queue is Empty\n");
	}else{
		element_type* read_temp = f_Buf->tail;
		int i = 0;
		printf("\n=======Displaying Queue=======\n");
		for (i = 0; i < f_Buf->count; i++)
		{
			printf("\t %d \n",*(read_temp));
			read_temp++;
		}
	}
}

