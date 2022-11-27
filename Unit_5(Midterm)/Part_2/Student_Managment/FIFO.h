//
// Created by Ahmed on 26/11/2022.
//

#ifndef STUDENT_MANAGMENT_FIFO_H
#define STUDENT_MANAGMENT_FIFO_H

#include "StudentsList.h"
#define Element_type Student_Data_t

typedef struct{
    Element_type *base;
    Element_type *head;
    Element_type *tail;
    uint32_t length;
    uint32_t count;
} FIFO_t;

extern FIFO_t Queue;

typedef enum{
    FIFO_no_error,
    FIFO_error,
    FIFO_full,
    FIFO_partial_full,
    FIFO_empty,
    FIFO_null
} FIFO_status;

FIFO_status FIFO_init (FIFO_t* f_Buf, Element_type* buf, uint32_t length);

/*This Function checks if the
 * Queue is full or partial full or empty*/
FIFO_status FIFO_length_status (FIFO_t* f_Buf);

FIFO_status FIFO_enqueue (FIFO_t* f_Buf, Element_type item);
FIFO_status FIFO_dequeue (FIFO_t* f_Buf, Element_type* item);

int FIFO_FindId(FIFO_t *p_buf, Element_type *item, uint32_t ID);

#endif //STUDENT_MANAGMENT_FIFO_H
