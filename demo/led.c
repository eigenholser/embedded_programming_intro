#include <stdio.h>
#include "TM4C123GH6PM.h"
#include "lm4f120h5qr.h"
#include "led.h"

void LED_Init() {
	printf("%s\n", ">> LEDs on GPIOF");
	SYSCTL->RCGCGPIO  |= (1U << 5); 	// Enable Run mode for GPIOF
	SYSCTL->GPIOHBCTL |= (1U << 5); 	// Enable AHB for GPIOF
	GPIOF_AHB->DIR |= (LED_RED | LED_BLUE | LED_GREEN);
	GPIOF_AHB->DEN |= (LED_RED | LED_BLUE | LED_GREEN);
}
