/*Unit 3 lab 3 main.c for cortex-m4
	Eng.Ahmed Mostafa */
	
#define SYSCTL_RCGC2_R		(*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DIR_R	(*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R	(*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_DATA_R	(*((volatile unsigned long *)0x400253FC))

int main(void){
	int delay_counter;
	
	SYSCTL_RCGC2_R = 0x00000020; // writing 0x20 on the register to enable the GPIO
	
	// giving time for GPIO to initialize for safe measures
	for(delay_counter = 0; delay_counter < 200 ; delay_counter++); 
	GPIO_PORTF_DIR_R |= 1<<3; // To set the direction of portF pin 3 to output
	GPIO_PORTF_DEN_R |= 1<<3; // To enable portF pin 3
	while(1){
		GPIO_PORTF_DATA_R |= 1<<3;
		for(delay_counter = 0; delay_counter < 200000 ; delay_counter++);// making a delay to be able to see the led light up
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(delay_counter = 0; delay_counter < 200000 ; delay_counter++);// making a delay to be able to see the led turn off
	}
	return 0;
}