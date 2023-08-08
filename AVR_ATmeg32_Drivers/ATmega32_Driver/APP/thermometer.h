/*
 * thermometer.h
 *
 * Created: 08/08/2023 00:48:47
 *  Author: Ahmed
 */ 


#ifndef THERMOMETER_H_
#define THERMOMETER_H_

//-*-*-*-*-*-*-*-*-*-*-*-
//Includes:
//-*-*-*-*-*-*-*-*-*-*-*-

#include "ADC.h"
#include "lcd.h"

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros
//-*-*-*-*-*-*-*-*-*-*-*-
#define USING_POLLING
//#define USING_INTERRUPT

/*******************************************************************************
                   APIs Supported by "Thermometer Application"
*******************************************************************************/
void ADC_callBack(void);
void ADC_progress_bar_app(void);




#endif /* THERMOMETER_H_ */