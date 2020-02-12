#include "pit.h"

void PIT_IRQHandler(void) {
	PIT->CHANNEL[1].TFLG |= PIT_TFLG_TIF_MASK;										//clear interrupt flag
	PIT->CHANNEL[1].TCTRL |=  (PIT_TCTRL_TEN_MASK |	PIT_TCTRL_TIE_MASK);
}


void pit_initialize(void) {
	SIM->SCGC6 |= SIM_SCGC6_PIT_MASK;	
	NVIC_ClearPendingIRQ(PIT_IRQn);
	NVIC_EnableIRQ(PIT_IRQn);
	PIT->CHANNEL[1].LDVAL = 0x249F00;
	PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_TIE_MASK;									//enable interrupts for overflow PIT channel 0
	PIT->CHANNEL[1].TCTRL |= PIT_TCTRL_TEN_MASK;									//enable timmer
	PIT->MCR = 0x00;
}

