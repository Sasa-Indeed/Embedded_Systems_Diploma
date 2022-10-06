/*
 * lifo.h
 *
 *  Created on: 4 Oct 2022
 *      Author: Ahmed
 */

#ifndef LIFO_H_
#define LIFO_H_

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
    element_type* base;
}LIFO_Buf_t;

//status
typedef enum{
    LIFO_no_error,
    LIFO_full,
    LIFO_partial_full,
    LIFO_empty,
    LIFO_null
}LIFO_status;

//APIs
LIFO_status LIFO_init (LIFO_Buf_t* lBuf, element_type* buf, unsigned int lenght);
LIFO_status LIFO_add_item (LIFO_Buf_t* lBuf, element_type item);
LIFO_status LIFO_pop_item (LIFO_Buf_t* lBuf, element_type* item);



#endif /* LIFO_H_ */
