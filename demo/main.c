#include <stdio.h>
#include "TM4C123GH6PM.h"
#include "lm4f120h5qr.h"
#include "interrupt.h"
#include "larson.h"
#include "led.h"
#include "UART.h"

int main(void){
	UART_Init();	// Initialize UART before outputting...
	printf("%s\n", "Initializing...");

	LED_Init();				// Initialize LEDs on GPIOF
	Larson_Init();			// Initialize Larson scanner on GPIOB.
	GPIOA_Pin_Init();		// Initialize GPIOA Pins and interrupts.
	SysTick_Init();			// Initialize SysTick interrupts.

	// Loop forever.
	while (1) {}
}
