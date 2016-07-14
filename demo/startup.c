#include "startup.h"

__attribute__ ((section(".intvecs")))
int const Vectors[] = {
	/* CPU Exceptions */
    (int)&__stack_end__,          // Top of Stack
    (int)&Reset_Handler,          // Reset Handler
    (int)&NMI_Handler,            // NMI Handler
    (int)&HardFault_Handler,      // Hard Fault Handler
    (int)&MemManage_Handler,      // The MPU fault handler
    (int)&BusFault_Handler,       // The bus fault handler
    (int)&UsageFault_Handler,     // The usage fault handler
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    (int)&SVC_Handler,            // SVCall handler
    (int)&DebugMon_Handler,       // Debug monitor handler
    0,                            // Reserved
    (int)&PendSV_Handler,         // The PendSV handler
    (int)&SysTick_Handler,        // The SysTick handler

    /* IRQ handlers */
    (int)&GPIOPortA_IRQHandler,   // GPIO Port A
    (int)&GPIOPortB_IRQHandler,   // GPIO Port B
    (int)&GPIOPortC_IRQHandler,   // GPIO Port C
    (int)&GPIOPortD_IRQHandler,   // GPIO Port D
    (int)&GPIOPortE_IRQHandler,   // GPIO Port E
    (int)&UART0_IRQHandler,       // UART0 Rx and Tx
    (int)&UART1_IRQHandler,       // UART1 Rx and Tx
    (int)&SSI0_IRQHandler,        // SSI0 Rx and Tx
    (int)&I2C0_IRQHandler,        // I2C0 Master and Slave
    (int)&PWMFault_IRQHandler,    // PWM Fault
    (int)&PWMGen0_IRQHandler,     // PWM Generator 0
    (int)&PWMGen1_IRQHandler,     // PWM Generator 1
    (int)&PWMGen2_IRQHandler,     // PWM Generator 2
    (int)&QEI0_IRQHandler,        // Quadrature Encoder 0
    (int)&ADCSeq0_IRQHandler,     // ADC Sequence 0
    (int)&ADCSeq1_IRQHandler,     // ADC Sequence 1
    (int)&ADCSeq2_IRQHandler,     // ADC Sequence 2
    (int)&ADCSeq3_IRQHandler,     // ADC Sequence 3
    (int)&Watchdog_IRQHandler,    // Watchdog timer
    (int)&Timer0A_IRQHandler,     // Timer 0 subtimer A
    (int)&Timer0B_IRQHandler,     // Timer 0 subtimer B
    (int)&Timer1A_IRQHandler,     // Timer 1 subtimer A
    (int)&Timer1B_IRQHandler,     // Timer 1 subtimer B
    (int)&Timer2A_IRQHandler,     // Timer 2 subtimer A
    (int)&Timer2B_IRQHandler,     // Timer 2 subtimer B
    (int)&Comp0_IRQHandler,       // Analog Comparator 0
    (int)&Comp1_IRQHandler,       // Analog Comparator 1
    (int)&Comp2_IRQHandler,       // Analog Comparator 2
    (int)&SysCtrl_IRQHandler,     // System Control (PLL, OSC, BO)
    (int)&FlashCtrl_IRQHandler,   // FLASH Control
    (int)&GPIOPortF_IRQHandler,   // GPIO Port F
    (int)&GPIOPortG_IRQHandler,   // GPIO Port G
    (int)&GPIOPortH_IRQHandler,   // GPIO Port H
    (int)&UART2_IRQHandler,       // UART2 Rx and Tx
    (int)&SSI1_IRQHandler,        // SSI1 Rx and Tx
    (int)&Timer3A_IRQHandler,     // Timer 3 subtimer A
    (int)&Timer3B_IRQHandler,     // Timer 3 subtimer B
    (int)&I2C1_IRQHandler,        // I2C1 Master and Slave
    (int)&QEI1_IRQHandler,        // Quadrature Encoder 1
    (int)&CAN0_IRQHandler,        // CAN0
    (int)&CAN1_IRQHandler,        // CAN1
    (int)&CAN2_IRQHandler,        // CAN2
    0,                            // Reserved
    (int)&Hibernate_IRQHandler,   // Hibernate
    (int)&USB0_IRQHandler,        // USB0
    (int)&PWMGen3_IRQHandler,     // PWM Generator 3
    (int)&uDMAST_IRQHandler,      // uDMA Software Transfer
    (int)&uDMAError_IRQHandler,   // uDMA Error
    (int)&ADC1Seq0_IRQHandler,    // ADC1 Sequence 0
    (int)&ADC1Seq1_IRQHandler,    // ADC1 Sequence 1
    (int)&ADC1Seq2_IRQHandler,    // ADC1 Sequence 2
    (int)&ADC1Seq3_IRQHandler,    // ADC1 Sequence 3
    0,                            // Reserved
    0,                            // Reserved
    (int)&GPIOPortJ_IRQHandler,   // GPIO Port J
    (int)&GPIOPortK_IRQHandler,   // GPIO Port K
    (int)&GPIOPortL_IRQHandler,   // GPIO Port L
    (int)&SSI2_IRQHandler,        // SSI2 Rx and Tx
    (int)&SSI3_IRQHandler,        // SSI3 Rx and Tx
    (int)&UART3_IRQHandler,       // UART3 Rx and Tx
    (int)&UART4_IRQHandler,       // UART4 Rx and Tx
    (int)&UART5_IRQHandler,       // UART5 Rx and Tx
    (int)&UART6_IRQHandler,       // UART6 Rx and Tx
    (int)&UART7_IRQHandler,       // UART7 Rx and Tx
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    (int)&I2C2_IRQHandler,        // I2C2 Master and Slave
    (int)&I2C3_IRQHandler,        // I2C3 Master and Slave
    (int)&Timer4A_IRQHandler,     // Timer 4 subtimer A
    (int)&Timer4B_IRQHandler,     // Timer 4 subtimer B
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    0,                            // Reserved
    (int)&Timer5A_IRQHandler,     // Timer 5 subtimer A
    (int)&Timer5B_IRQHandler,     // Timer 5 subtimer B
    (int)&WideTimer0A_IRQHandler, // Wide Timer 0 subtimer A
    (int)&WideTimer0B_IRQHandler, // Wide Timer 0 subtimer B
    (int)&WideTimer1A_IRQHandler, // Wide Timer 1 subtimer A
    (int)&WideTimer1B_IRQHandler, // Wide Timer 1 subtimer B
    (int)&WideTimer2A_IRQHandler, // Wide Timer 2 subtimer A
    (int)&WideTimer2B_IRQHandler, // Wide Timer 2 subtimer B
    (int)&WideTimer3A_IRQHandler, // Wide Timer 3 subtimer A
    (int)&WideTimer3B_IRQHandler, // Wide Timer 3 subtimer B
    (int)&WideTimer4A_IRQHandler, // Wide Timer 4 subtimer A
    (int)&WideTimer4B_IRQHandler, // Wide Timer 4 subtimer B
    (int)&WideTimer5A_IRQHandler, // Wide Timer 5 subtimer A
    (int)&WideTimer5B_IRQHandler, // Wide Timer 5 subtimer B
    (int)&FPU_IRQHandler,         // FPU
    0,                            // Reserved
    0,                            // Reserved
    (int)&I2C4_IRQHandler,        // I2C4 Master and Slave
    (int)&I2C5_IRQHandler,        // I2C5 Master and Slave
    (int)&GPIOPortM_IRQHandler,   // GPIO Port M
    (int)&GPIOPortN_IRQHandler,   // GPIO Port N
    (int)&QEI2_IRQHandler,        // Quadrature Encoder 2
    0,                            // Reserved
    0,                            // Reserved
    (int)&GPIOPortP0_IRQHandler,  // GPIO Port P (Summary or P0)
    (int)&GPIOPortP1_IRQHandler,  // GPIO Port P1
    (int)&GPIOPortP2_IRQHandler,  // GPIO Port P2
    (int)&GPIOPortP3_IRQHandler,  // GPIO Port P3
    (int)&GPIOPortP4_IRQHandler,  // GPIO Port P4
    (int)&GPIOPortP5_IRQHandler,  // GPIO Port P5
    (int)&GPIOPortP6_IRQHandler,  // GPIO Port P6
    (int)&GPIOPortP7_IRQHandler,  // GPIO Port P7
    (int)&GPIOPortQ0_IRQHandler,  // GPIO Port Q (Summary or Q0)
    (int)&GPIOPortQ1_IRQHandler,  // GPIO Port Q1
    (int)&GPIOPortQ2_IRQHandler,  // GPIO Port Q2
    (int)&GPIOPortQ3_IRQHandler,  // GPIO Port Q3
    (int)&GPIOPortQ4_IRQHandler,  // GPIO Port Q4
    (int)&GPIOPortQ5_IRQHandler,  // GPIO Port Q5
    (int)&GPIOPortQ6_IRQHandler,  // GPIO Port Q6
    (int)&GPIOPortQ7_IRQHandler,  // GPIO Port Q7
    (int)&GPIOPortR_IRQHandler,   // GPIO Port R
    (int)&GPIOPortS_IRQHandler,   // GPIO Port S
    (int)&PWM1Gen0_IRQHandler,    // PWM 1 Generator 0
    (int)&PWM1Gen1_IRQHandler,    // PWM 1 Generator 1
    (int)&PWM1Gen2_IRQHandler,    // PWM 1 Generator 2
    (int)&PWM1Gen3_IRQHandler,    // PWM 1 Generator 3
    (int)&PWM1Fault_IRQHandler,   // PWM 1 Fault
};

void Reset_Handler(void) {
    extern int main(void);
    extern unsigned __data_start__;  		// Start of .data in the linker script
    extern unsigned __data_end__;  			// End of .data in the linker script
    extern unsigned const __data_load__; 	// Initialization values for .data
    extern unsigned __bss_start__; 			// Start of .bss in the linker script
    extern unsigned __bss_end__;   			// End of .bss in the linker script

    unsigned const *src;
    unsigned *dst;

    /* Copy the data segment initializers from flash to RAM */
    src = &__data_load__;
    for (dst = &__data_start__; dst < &__data_end__; ++dst, ++src) {
        *dst = *src;
    }

    // Zero-fill the .bss segment in RAM
    for (dst = &__bss_start__; dst < &__bss_end__; ++dst) {
        *dst = 0;
    }

    /* Start of our code */
    (void)main();

    /* The previous code should not return. */
    assert_failed("Reset_Handler", __LINE__);
}

__attribute__((naked)) void NMI_Handler(void);
void NMI_Handler(void) {
    __asm volatile (
        "    ldr r0,=str_nmi\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_nmi: .asciz \"NMI\"\n\t"
    );
}

__attribute__((naked)) void MemManage_Handler(void);
void MemManage_Handler(void) {
    __asm volatile (
        "    ldr r0,=str_mem\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_mem: .asciz \"MemManage\"\n\t"
    );
}

__attribute__((naked)) void HardFault_Handler(void);
void HardFault_Handler(void) {
    __asm volatile (
        "    ldr r0,=str_hrd\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_hrd: .asciz \"HardFault\"\n\t"
    );
}

__attribute__((naked)) void BusFault_Handler(void);
void BusFault_Handler(void) {
    __asm volatile (
        "    ldr r0,=str_bus\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_bus: .asciz \"BusFault\"\n\t"
    );
}

__attribute__((naked)) void UsageFault_Handler(void);
void UsageFault_Handler(void) {
    __asm volatile (
        "    ldr r0,=str_usage\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_usage: .asciz \"UsageFault\"\n\t"
    );
}

__attribute__((naked)) void Default_Handler(void);
void Default_Handler(void) {
    __asm volatile (
        "    ldr r0,=str_dflt\n\t"
        "    mov r1,#1\n\t"
        "    b assert_failed\n\t"
        "str_dflt: .asciz \"Default\"\n\t"
    );
}

