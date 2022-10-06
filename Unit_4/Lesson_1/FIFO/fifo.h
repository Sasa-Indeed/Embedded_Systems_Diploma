/*
 * fifo.h
 *
 *  Created on: 4 Oct 2022
 *      Author: Ahmed
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdint.h>
#include <stdio.h>

/*USER Configuration:================================================
select the element type (int8_t, uint8_t, int16_t, uint16_t,...)*/
#define element_type uint8_t
#define buffer1_lenght 5
element_type buffer_1 [buffer1_lenght];
//===================================================================


//Type definitions
typedef struct
{
    unsigned int lenght;
    unsigned int count;
    element_type* head;
    element_type* tail;
    element_type* base;
}FIFO_Buf_t;

//status
typedef enum{
    FIFO_no_error,
    FIFO_full,
    FIFO_partial_full,
    FIFO_empty,
    FIFO_null
}FIFO_status;

//APIs
FIFO_status FIFO_init (FIFO_Buf_t* f_Buf, element_type* buf, unsigned int lenght);
FIFO_status FIFO_enqueue (FIFO_Buf_t* f_Buf, element_type item);
FIFO_status FIFO_dequeue (FIFO_Buf_t* f_Buf, element_type* item);
FIFO_status FIFO_lenght_status (FIFO_Buf_t* f_Buf);
void FIFO_print (FIFO_Buf_t* f_Buf);



#endif /* FIFO_H_ */
