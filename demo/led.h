#ifndef __LED_H__
#define __LED_H__

/* On-board LEDs */
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

void LED_Init(void);

#endif // __LED_H__
