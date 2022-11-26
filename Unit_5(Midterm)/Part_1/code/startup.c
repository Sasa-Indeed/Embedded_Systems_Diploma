/*		startup.c 
	Eng.Ahmed Mostafa*/
	
#include <stdint.h>

extern int main(void);
extern int _E_text;
extern int _S_DATA;
extern int _E_DATA;
extern int _S_bss;
extern int _E_bss;
//Reserving 1024B in memory
static unsigned long Stack_top[256];


void Reset_Handler(void){
	int i;
	//copy data from ROM to RAM
	unsigned int DATA_size = (unsigned char*)& _E_DATA - (unsigned char*)& _S_DATA;
	unsigned char* P_src = (unsigned char*)& _E_text;
	unsigned char* P_dst = (unsigned char*)& _S_DATA;
	unsigned char* P_bss = (unsigned char*)& _S_bss;
	
	for(i = 0; i < DATA_size; ++i){
		*((unsigned char*)P_dst++) = *((unsigned char*)P_dst++);
	}
	
	//initialize the .bss section in SRAM with zeros
	unsigned int bss_size = (unsigned char*)& _E_bss - (unsigned char*)& _S_bss;
	P_dst = (unsigned char*)& _S_bss;
	for(i = 0; i < bss_size; i++){
		*((unsigned char*)P_bss++) = (unsigned char) 0;
	}
	
	//jump to main
	main();
}

void Default_Handler(){
	Reset_Handler();
}


void NMI_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void MM_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;
void Bus_Fault(void)__attribute__((weak,alias("Default_Handler")));;
void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));;

void (* const vectors_sections []) (void) __attribute__((section(".vectors"))) = {
	(void (*)(void))((unsigned long)Stack_top + sizeof(Stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler
};