/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdint.h>
typedef volatile unsigned int vuint32_t;


//RCC registers
#define RCC_BASE 		0x40021000
#define RCC_APB2ENR 	*(volatile uint32_t *)(RCC_BASE + 0x18)


//GPIO registers
#define GPIOA_BASE 		0x40010800
#define GPIOA_CRL 		*(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH 		*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR		*(volatile uint32_t *)(GPIOA_BASE + 0x0C)


//EXTI registers
#define EXTI_BASE 		0x40010400
#define EXTI_IMR 		*(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR 		*(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR 		*(volatile uint32_t *)(EXTI_BASE + 0x14)


//AFIO register
#define AFIO_BASE 			0x40010000
#define AFIO_EXTICR1 		*(volatile uint32_t *)(AFIO_BASE + 0x08)

//NVIC register
#define NVIC_ISER0 		*(volatile uint32_t *)(0xE000E100)


//APIs
void clock_init(void);
void GPIO_init(void);
void interrupt_init(void);
void AFIO_init(void);

int main(void){

	//Initialising Peripherals
	clock_init();
	GPIO_init();
	interrupt_init();
	AFIO_init();

	while(1);
}


void clock_init(void){
	//Enable GPIOA clock
	RCC_APB2ENR |= 1<<2;

	//Enable AFIO clock
	RCC_APB2ENR |= 1<<0;
}

void GPIO_init(void){
	//pin 13 port A output
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;

	//Enable pin A0 input floating
	GPIOA_CRL |= (0b01 << 2);
}

void EXTI0_IRQHandler(void){
	//Toggle led pin A 13
	GPIOA_ODR ^= (1<<13);

	//Clear the pending request for line 0
	EXTI_PR |= (1<<0);
}

void interrupt_init(void){
	//Enabling the interrupt with rising edge
	EXTI_RTSR |= (1<<0);

	//Enabling EXTI line 0
	EXTI_IMR |= (1<<0);

	/*Configure the enable and mask bits that control the NVIC IRQ 6 channel mapped to
	 * the External Interrupt Controller (EXTI)*/
	NVIC_ISER0 |= (1<<6);
}

void AFIO_init(void){
	//Enabling port A0 as the interrupt input
	AFIO_EXTICR1 |= (0b0000 << 0);
}

