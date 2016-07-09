/*
 * This enables the UART for debugging messages. Good enough for a demo.
 */

#include <stdio.h>
#include <stdint.h>
#include "TM4C123GH6PM.h"
#include "UART.h"

#define UART_FR_TXFF            0x00000020  // UART Transmit FIFO Full
#define UART_FR_RXFE            0x00000010  // UART Receive FIFO Empty
#define UART_LCRH_WLEN_8        0x00000060  // 8 bit word length
#define UART_LCRH_FEN           0x00000010  // UART Enable FIFOs
#define UART_CTL_UARTEN         0x00000001  // UART Enable

/* UART_Init()
 * Initialize UART for 115,200 baud rate (assuming 16 MHz bus clock),
 * 8 bit word length, no parity bits, one stop bit, FIFOs enabled
 * Input: none
 */
void UART_Init(void){
  SYSCTL->RCGCUART |= 0x01;                 // Activate UART0
  SYSCTL->RCGCGPIO |= 0x01;                 // Activate GPIOA
  UART0->CTL &= ~UART_CTL_UARTEN;      		// Disable UART
  UART0->IBRD = 8;                     		// IBRD = int(16,000,000 / (16 * 115,200)) = int(8.680)
  UART0->FBRD = 44;                    		// FBRD = round(0.5104 * 64 ) = 44
                                        	// 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0->LCRH = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
  UART0->CTL |= UART_CTL_UARTEN;       		// Enable UART
  GPIOA->AFSEL |= 0x03;                 	// Enable alt funct on PA1-0
  GPIOA->DEN |= 0x03;             			// Enable digital I/O on PA1-0
                                        	// Configure PA1-0 as UART
  GPIOA->PCTL = (GPIOA->PCTL & 0xFFFFFF00) + 0x00000011;
  GPIOA->AMSEL &= ~0x03;          			// Disable analog functionality on PA
}

/* UART_OutChar()
 * Write ASCII character to UART. Takes ASCII character to write.
 */
void UART_OutChar(char data){
  while((UART0->FR & UART_FR_TXFF) != 0);
  UART0->DR = data;
}

/*
 * Define as override for printf. GNU ARM compiler specific.
 */

/* Print a character to UART. */
int _write(int fd, char *buf, size_t count){
	size_t CharCnt;
	(void)fd; /* avoid warning */

	for (CharCnt = 0; CharCnt < count; CharCnt++) {
		char ch = buf[CharCnt];
		if((ch == LF) || (ch == CR) || (ch == ESC))
			UART_OutChar(CR);
		UART_OutChar(ch);
	}
	return CharCnt;
}
