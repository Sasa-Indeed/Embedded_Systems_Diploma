/*
 * Utils.h
 *
 * Created: 31/01/2023 10:47:21
 *  Author: Ahmed
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg,bit) (reg |= (1 << bit))				//For setting bits
#define ResetBit(reg,bit) (reg &= ~(1 << bit))			//For clearing bits
#define ToggleBit(reg,bit) (reg ^= (1<<bit))			//For toggling bits
#define ReadBit(reg,bit) ((reg & (1 << bit)) >> bit)	//For reading from pins


#endif /* UTILS_H_ */