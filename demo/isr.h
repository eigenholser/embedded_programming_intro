#ifndef __ISR_H__
#define __ISR_H__

/* On-board LEDs */
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

void GPIOPortA_IRQHandler(void);
void SysTick_Handler(void);

#endif // __ISR_H__
