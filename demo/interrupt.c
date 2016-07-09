#include "TM4C123GH6PM.h"
#include "lm4f120h5qr.h"
#include "interrupt.h"
#include "larson.h"
#include "led.h"

int pa3flag = 0;

void GPIOA_Pin_Init(void) {
	SYSCTL->GPIOHBCTL |= (1U); 	  	/* enable AHB for GPIOA */

	/* GPIOA pin configuration */
	GPIOA_AHB->DIR |= PA2;			/* PA2 is OUTPUT */
									/* PA3 is INPUT on reset */
	GPIOA_AHB->DEN |= (PA2 | PA3);	/* PA2, PA3 digital enable */

	/* GPIOA interrupt configuration */
	GPIO_PA3_Interrupt_Enable();
	GPIOA_AHB->IBE |= PA3;			/* PA3 interrupt rising and falling edge */
	GPIOA_AHB->PDR |= PA3; 			/* PA3 pull down resistor enabled */

	NVIC_Init();
}

void GPIO_PA3_Interrupt_Enable(void) {
	GPIOA_AHB->IM |= PA3;		/* PA3 not masked */
	pa3flag = 0;
}

void GPIO_PA3_Interrupt_Disable(void) {
	GPIOA_AHB->IM |= PA3;		/* PA3 masked */
}

void NVIC_Init() {
	/* NVIC configuration */
	NVIC_PRI0_R = 0;					/* Priority 0, highest */
	NVIC_EN0_R = 1U;					/* Enable IRQ0 - GPIOA */
}

void SysTick_Init() {
	/* Configure SysTick to interrupt after short delay */
	SysTick->LOAD = SYS_CLOCK_HZ/200U - 1U;
	SysTick->VAL  = 0U;
	SysTick->CTRL = (1U << 2) | (1U << 1) | 1U;
}
