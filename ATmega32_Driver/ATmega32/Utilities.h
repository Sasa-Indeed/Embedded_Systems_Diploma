/*
 * Utilities.h
 *
 * Created: 18/06/2023 14:50:00
 *  Author: Ahmed
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

#define CLEAR_BIT(reg,bit)		(reg &= ~(1<<bit))
#define SET_BIT(reg,bit)		(reg |= (1<<bit))
#define TOGGLE_BIT(reg,bit)		(reg ^= (1<<bit))
#define READ_BIT(reg,bit)		((reg>>bit)&1)

#endif /* UTILITIES_H_ */