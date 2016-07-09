#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

/* system clock setting [Hz] */
#define SYS_CLOCK_HZ 16000000U


#define PA2       (1U << 2)
#define PA3       (1U << 3)

extern int systick_counter;
extern int counter;
extern int pa3flag;

void GPIOA_Pin_Init(void);
void GPIO_PA3_Interrupt_Enable(void);
void GPIO_PA3_Interrupt_Disable(void);
void NVIC_Init(void);
void SysTick_Init(void);


#endif // __INTERRUPT_H__
