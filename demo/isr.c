#include <stdio.h>
#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "lm4f120h5qr.h"
#include "interrupt.h"
#include "isr.h"
#include "larson.h"
#include "led.h"

int systick_counter = 0;
int counter = 0;
int sw_count = 0;
int sw_norm_count = 0;

__attribute__((naked)) void assert_failed(char const *file, int line) {
    /* TBD: damage control */
    NVIC_SystemReset(); 	/* reset the system */
}

void GPIOPortA_IRQHandler(void) {
	GPIOA_AHB->ICR |= PA3;				/* Clear PA3 interrupt */

	/* Debounce switch on PA3 */
	GPIO_PA3_Interrupt_Disable();		/* Switch will bounce. Disable interrupt */

	pa3flag = 1;
}

void SysTick_Handler(void) {
	systick_counter++;
	if (systick_counter > larsonFreq) {
		systick_counter = 0;
		shiftLEDBits();
		int larsonWin = (larsonValue & 0x1FEU) >> 1;
		GPIO_PORTB_AHB_DATA_R = larsonWin;

		larsonFreq = LARSON_FREQ > sw_count ? LARSON_FREQ - sw_count : 1;
	}

	sw_norm_count++;
	if (sw_norm_count > LARSON_FREQ * 4) {
		sw_norm_count = 0;

		// Decrement switch counter by 1 until 0 for each full cycle.
		if (sw_count > 0)
			sw_count--;

		if (larsonFreq != LARSON_FREQ)
			iprintf("larsonFreq = %i\n", larsonFreq);
	}

	if (pa3flag == 1) {
		counter++;
		// Check for PA3 logic level
		if ((GPIOA_AHB->GPIO_Bits[PA3] == PA3) & (counter > 1)) {
			counter = 0;
			sw_count++;								/* count the switch */

			// Switch is on.
			GPIOA_AHB->GPIO_Bits[PA2] = PA2;		/* Turn lamp on, set PA2 HIGH */
			printf("Lamp ON\n");

			GPIO_PA3_Interrupt_Enable();			/* Turn interrupt back on */

			GPIOF_AHB->GPIO_Bits[LED_BLUE] = LED_BLUE;	/* Indicate lamp on */
		}

		if ((GPIOA_AHB->GPIO_Bits[PA3] == 0) & (counter > 1)){
			// Switch is off.
			GPIOA_AHB->GPIO_Bits[PA2] = 0;			/* Turn lamp off, set PA2 LOW */
			printf("Lamp OFF\n");
			counter = 0;
			sw_count++;								/* count the switch */
			GPIO_PA3_Interrupt_Enable();			/* Turn interrupt back on */

			GPIOF_AHB->GPIO_Bits[LED_BLUE] = 0;		/* Indicate lamp off */
		}
	}
}
