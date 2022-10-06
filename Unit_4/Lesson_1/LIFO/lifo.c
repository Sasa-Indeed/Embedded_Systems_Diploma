/*
 * lifo.c
 *
 *  Created on: 4 Oct 2022
 *      Author: Ahmed
 */
#include "lifo.h"

LIFO_status LIFO_init (LIFO_Buf_t* lBuf, element_type* buf, unsigned int lenght){
    //check if buffer is valid
    if(lBuf == NULL)
        return LIFO_null;

    lBuf->base = buf;
    lBuf->head = buf;
    lBuf->lenght = lenght;
    lBuf->count = 0;

    return LIFO_no_error;
}

LIFO_status LIFO_lenght_status(LIFO_Buf_t* lBuf){
    //check if buffer is valid
    if(!lBuf || !lBuf->base || !lBuf->head)
        return LIFO_null;

    if(lBuf->count >= lBuf->lenght){
        return LIFO_full; // Check if lifo is full
    } else if (lBuf->count == 0){
        return LIFO_empty;// Check if lifo is empty
    }else{
        return LIFO_partial_full;
    }

}

LIFO_status LIFO_add_item (LIFO_Buf_t* lBuf, element_type item){

    //Checking if the buffer is valid and if it is  not full
    LIFO_status stat = LIFO_lenght_status(lBuf);
    if (stat == LIFO_null || stat == LIFO_full)
    {
        printf("\nAdd failed\n");
        return stat;
    }

    // Adding the Value
    *(lBuf->head) = item;
    lBuf->count++;
    lBuf->head++;
    printf("\nItem added successfully:  %d\n",item);

    return LIFO_no_error;
}

LIFO_status LIFO_pop_item (LIFO_Buf_t* lBuf, element_type* item){
    //Checking if the buffer is valid and if it is not empty
    LIFO_status stat = LIFO_lenght_status(lBuf);
    if (stat == LIFO_null || stat == LIFO_empty)
    {
        printf("\nPOP failed\n");
        return stat;
    }

    lBuf->head--;
    *(item) = *(lBuf->head);
    lBuf->count--;
    printf("\nItem poped successfully:  %d\n",*item);

    return LIFO_no_error;
}

