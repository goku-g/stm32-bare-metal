/*
Gokarna
08/04/2025

@Chipset	STM32F103C8xx, STM32F446RETx, STM32L452RETx, STM32L452RETxP
*/

#include <stdint.h>	// standered library to include all types of the intergers (including uintx_t)

int main()
{
	uint8_t* add;	// make a pointer of the unsigned int 8 bit type
	
	/*
	* assign a address to that pointer
	* caution!! Please see the address map from the datasheet or reference manual, otherwise you can mess things up!
	* 0x20000000 is the starting address of the 512-Mbyte Block 1 SRAM (Figure 2. Memory map : pg57)
	*/
	add = (uint8_t*)0x20000000;
	
	*add = 56; // place the whatever value you like in that address (it should between 0-255 because of the uint8_t)
	
	while(1)
	{
	}
}
