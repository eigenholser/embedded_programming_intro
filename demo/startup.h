#ifndef __STARTUP_H__
#define __STARTUP_H__

extern int __stack_end__;	// From linker.lds

/* Weak prototypes for error handlers */
__attribute__ ((naked)) void assert_failed(char const *module, int loc);

/* Function prototypes */
void Default_Handler(void);  /* Default empty handler */
void Reset_Handler(void);    /* Reset Handler */
void SystemInit(void);       /* CMSIS system initialization */

/* Cortex-M Processor fault exceptions. */
void NMI_Handler           (void) __attribute__ ((weak));
void HardFault_Handler     (void) __attribute__ ((weak));
void MemManage_Handler     (void) __attribute__ ((weak));
void BusFault_Handler      (void) __attribute__ ((weak));
void UsageFault_Handler    (void) __attribute__ ((weak));

/* Cortex-M Processor non-fault exceptions. */
void SVC_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));

/* External interrupts. */
void GPIOPortA_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortB_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortC_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortD_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortE_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI0_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMFault_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen0_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen1_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen2_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI0_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq0_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq1_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq2_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void ADCSeq3_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Watchdog_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer0A_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer0B_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer1A_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer1B_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer2A_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer2B_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Comp0_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void Comp1_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void Comp2_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SysCtrl_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void FlashCtrl_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortF_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortG_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortH_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer3A_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer3B_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN0_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Hibernate_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void USB0_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PWMGen3_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void uDMAST_IRQHandler     (void) __attribute__ ((weak, alias("Default_Handler")));
void uDMAError_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq0_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq1_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq2_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1Seq3_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortJ_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortK_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortL_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI3_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UART3_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART4_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART5_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART6_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void UART7_IRQHandler      (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C3_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer4A_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer4B_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer5A_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Timer5B_IRQHandler    (void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer0A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer0B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer1A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer1B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer2A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer2B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer3A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer3B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer4A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer4B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer5A_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void WideTimer5B_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler        (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C4_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C5_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortM_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortN_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI2_IRQHandler       (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP0_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP3_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP4_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP5_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP6_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortP7_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ0_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ1_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ2_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ3_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ4_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ5_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ6_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortQ7_IRQHandler (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortR_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOPortS_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen0_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen1_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen2_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Gen3_IRQHandler   (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM1Fault_IRQHandler  (void) __attribute__ ((weak, alias("Default_Handler")));

#endif // __STARTUP_H__
