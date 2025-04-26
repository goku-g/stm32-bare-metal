/*	
Gokarna
04/04/2025

@Chipset STM32F103C8x
*/
#include <stdint.h>

#define RCC_BASE      0x40021000	// defining the base register address for the registor clock
#define RCC_APB2ENR   (*(volatile unsigned int *)(RCC_BASE + 0x18))	// offset from base address for the peripheral clock enable register 2
#define IOPCEN				(1 << 4)		// for enable the RCC clock for Port C, set bit that assign for enable/desable clock of the GPIO Port C

#define GPIOC_BASE    0x40011000		// defining the base register address for the GPIO Port C
#define GPIOC_CRH			(*(volatile unsigned int *)(GPIOC_BASE + 0x04))	// offset from base address for the port configuration register high (pin 8-15)
#define GPIOC_13_OP		(0x2 << 20);	// for set output mode of the pin 13, write 0x2 in 20-23 bits inside port configuration register

#define GPIOC_ODR			(*(volatile unsigned int *)(GPIOC_BASE + 0x0C))	// offset from base address for the Port output data register
	
#define SET_PIN13			(1 << 13)	// for high output from pin 13, write 1 in the 13th bit of the output data register

int main()
{
	RCC_APB2ENR |= IOPCEN;	// enable RCC for the GPIO port C peripheral
	
	GPIOC_CRH   &= 0xff0fffff;	// clean port configuration register keeping all except GPIOC in open drain output mode!
	GPIOC_CRH		|= GPIOC_13_OP;	// set GPIOC 13 pin as push-pull output mode
	
	while(1)
	{
		GPIOC_ODR ^= SET_PIN13;		// toggle the pin 13
		for (volatile int i = 0; i < 1000000; ++i);
	}
}
