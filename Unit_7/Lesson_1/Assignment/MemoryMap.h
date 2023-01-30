/*
 * MemoryMap.h
 *
 * Created: 30/01/2023 19:20:24
 *  Author: Ahmed
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_


//Port D
#define DDRD	(*((volatile unsigned char *) 0x31))
#define PORTD	(*((volatile unsigned char *) 0x32))
#define PIND	(*((volatile unsigned char *) 0x30))

#endif /* MEMORYMAP_H_ */