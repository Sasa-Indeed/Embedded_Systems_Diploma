/*
 * Registers.h
 *
 * Created: 31/01/2023 10:46:27
 *  Author: Ahmed
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

//Port A
#define PORTA	(*((volatile unsigned char *) 0x3B))
#define DDRA	(*((volatile unsigned char *) 0x3A))
#define PINA	(*((volatile unsigned char *) 0x39))
#define NUMOFPINSA 8 //For number of pins

//Port C
#define PORTC	(*((volatile unsigned char *) 0x35))
#define DDRC	(*((volatile unsigned char *) 0x34))
#define PINC	(*((volatile unsigned char *) 0x33))



#endif /* REGISTERS_H_ */