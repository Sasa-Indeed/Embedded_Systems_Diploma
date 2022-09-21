#include <stdint.h>
typedef volatile unsigned int vuint32_t;

#define RCC_BASE 		0x40021000
#define GPIOA_BASE 		0x40010800
//registers
#define RCC_APB2ENR 	*(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH 		*(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR		*(volatile uint32_t *)(GPIOA_BASE + 0x0C)


typedef union{
	vuint32_t all_fields;
	struct{
		vuint32_t reserved:13;
		vuint32_t P13:1;
	} Pin;
} R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile uint32_t *)(GPIOA_BASE + 0x0C);
unsigned char g_vaiables [3] = {1,2,3}; //To increase the data section for learning purpose
unsigned char const const_varaible [3] = {1,2,3}; //For creating the rodata section for learning purpose
unsigned char bss_var[3];

int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;
	int i;
	
	while(1){
		R_ODR->Pin.P13 = 1;
		for(i = 0; i < 5000;i++);
		R_ODR->Pin.P13 = 0;
		for(i = 0; i < 5000;i++);
	}

}
