#include "TM4C123GH6PM.h"
#include "lm4f120h5qr.h"
#include "larson.h"

int larsonValue = LARSON_MIN_VALUE;
int larsonDir = LEFT;
int larsonFlag = 0;
int larsonFreq = LARSON_FREQ;

void Larson_Init(void) {
	SYSCTL->RCGCGPIO |= (1U << 1);	// Enable run mode for GPIOB
	SYSCTL->GPIOHBCTL |= (1U << 1); // Enable AHB for GPIOB
	GPIOB_AHB->DIR |= 0xFFU;		// All GPIOB pins output
	GPIOB_AHB->DEN |= 0xFFU;		// All GPIOB pins digital
}

void shiftLEDBits(void) {
	if (larsonDir == RIGHT) {
		if (larsonValue > LARSON_MIN_VALUE) {
			larsonValue = larsonValue >> 1;
			return;
		}
		if (larsonValue == LARSON_MIN_VALUE && larsonDir == RIGHT) {
			larsonFlag = 1;
		}
		if (larsonFlag == 1) {
			larsonFlag = 0;
			larsonDir = LEFT;
		}
	}

	if (larsonDir == LEFT) {
		if (larsonValue < LARSON_MAX_VALUE) {
			larsonValue = larsonValue << 1;
			return;
		}
		if (larsonValue == LARSON_MAX_VALUE && larsonDir == LEFT){
			larsonFlag = 1;
		}
		if (larsonFlag == 1) {
			larsonFlag = 0;
			larsonDir = RIGHT;
		}
	}
}
