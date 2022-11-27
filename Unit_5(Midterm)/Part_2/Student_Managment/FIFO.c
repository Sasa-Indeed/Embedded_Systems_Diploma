//
// Created by Ahmed on 26/11/2022.
//
#include "FIFO.h"
#include "stdio.h"

FIFO_t Queue;

FIFO_status FIFO_init (FIFO_t* f_Buf, Element_type* buf, uint32_t length){

    if (f_Buf == NULL || buf == NULL)
    {
        return FIFO_null;
    }

    f_Buf->base = buf;
    f_Buf->tail = buf;
    f_Buf->head = buf;
    f_Buf->length = length;
    f_Buf->count = 0;

    return FIFO_no_error;
}

FIFO_status FIFO_length_status (FIFO_t* f_Buf){
    if (!f_Buf || !f_Buf->base || !f_Buf->tail || !f_Buf->head)
    {
        return FIFO_null;
    }

    if(f_Buf->count >= f_Buf->length){
        return FIFO_full; // Check if lifo is full
    } else if (f_Buf->count == 0){
        return FIFO_empty;// Check if lifo is empty
    }else{
        return FIFO_partial_full;
    }
}


FIFO_status FIFO_enqueue (FIFO_t* f_Buf, Element_type item){

    //Checking if the buffer is valid and if it is not full
    FIFO_status stat = FIFO_length_status(f_Buf);
    if (stat == FIFO_null || stat == FIFO_full)
    {
        printf("\nAdd failed\n");
        return stat;
    }

    *(f_Buf->head) = item;
    f_Buf->count++;
    //Checking if the head have reached the end if so returning it to the start again
    if(f_Buf->head == f_Buf->base + (f_Buf->length * sizeof(Element_type))){
        f_Buf->head = f_Buf->base;
    }else{
        f_Buf->head++;
    }

    return FIFO_no_error;
}

FIFO_status FIFO_dequeue (FIFO_t* f_Buf, Element_type* item){

    //Checking if the buffer is valid and if it is not empty
    FIFO_status stat = FIFO_length_status(f_Buf);
    if (stat == FIFO_null || stat == FIFO_empty){
        printf("\nRemove failed\n");
        return stat;
    }

    *(item) = *(f_Buf->tail);
    f_Buf->count--;
    //Checking if the tail have reached the end if so returning it to the start again
    if(f_Buf->tail == f_Buf->base + (f_Buf->length * sizeof(Element_type))){
        f_Buf->tail = f_Buf->base;
    }else{
        f_Buf->tail++;
    }

    return FIFO_no_error;
}

int FIFO_FindId(FIFO_t *f_Buf, Element_type *item, uint32_t ID){
    FIFO_status stat = FIFO_length_status(f_Buf);

    if(stat == FIFO_null){
        return stat;
    } else if (stat == FIFO_empty){
        return 0;
    }

    Element_type* read_temp = f_Buf->tail;

    for (int i = 0; i < f_Buf->count; i++){

        if (read_temp->roll_number == ID){
            *(item) = *(read_temp);
            return 1;
        }

        if(read_temp == f_Buf->base + (f_Buf->length * sizeof(Element_type))){
            read_temp = f_Buf->base;
        }else{
            read_temp++;
        }
    }

    return 0;
}
