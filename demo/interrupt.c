#include "TM4C123GH6PM.h"
#include "lm4f120h5qr.h"
#include "interrupt.h"
#include "larson.h"
#include "led.h"

int pa3flag = 0;

void GPIOA_Pin_Init(void) {
	printf("%s\n", ">> GPIOA pin setup");
	SYSCTL->GPIOHBCTL |= (1U); 	  	// Enable AHB for GPIOA

	/* GPIOA pin configuration */
	GPIOA_AHB->DIR |= PA2;			// PA2 is OUTPUT, p 663.
									// PA3 is INPUT on reset.
	GPIOA_AHB->DEN |= (PA2 | PA3);	// PA2, PA3 digital enable, p 682.

	/* GPIOA interrupt configuration */
	GPIO_PA3_Interrupt_Enable();
	GPIOA_AHB->IBE |= PA3;			// PA3 interrupt rising and falling edge, p 665.
	GPIOA_AHB->PDR |= PA3; 			// PA3 pull down resistor enabled, p 679.

	NVIC_Init();					// Enable GPIO interrupts and set priority.
}

void GPIO_PA3_Interrupt_Enable(void) {
	GPIOA_AHB->IM |= PA3;			// PA3 not masked, p 667.
	pa3flag = 0;					// Disable PA3 polling.
}

void GPIO_PA3_Interrupt_Disable(void) {
	GPIOA_AHB->IM |= PA3;			// PA3 masked, p 667.
}

void NVIC_Init() {
	/* NVIC configuration */
	printf("%s\n", ">> Nested Vector Interrupt Controller");
	NVIC_PRI0_R = (7U << 5);		// Priority 7, lowest, p 152.
	NVIC_EN0_R = 1U;				// Enable IRQ0 - GPIOA, p 142.
}

void SysTick_Init() {
	/* Configure SysTick to interrupt after short delay */
	printf("%s\n", ">> SysTick");
	SysTick->LOAD = SYS_CLOCK_HZ/200U - 1U;			// STRELOAD, p 140.
	SysTick->VAL  = 0U;								// STCURRENT - write-clear. Also clears `count' bit of STCTRL, p 141.
	SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;		// STCTRL, p 138.
}
