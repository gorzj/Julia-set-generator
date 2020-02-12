
#include "SPI.h"



  
SPI::SPI()
{
	SIM->SCGC4|=SIM_SCGC4_SPI0_MASK;
	SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
	SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;
	
	//SPI0->C1 config
	
	SPI0->C2|=SPI_C2_BIDIROE_MASK;//input on single line
	SPI0->C1&=~ SPI_C1_SPIE_MASK; // Interrupts from SPRF and MODF are inhibited—use polling 
	SPI0->C1&=~ SPI_C1_SPTIE_MASK;// Interrupts from SPTEF inhibited (use polling)
	SPI0->C1|= SPI_C1_MSTR_MASK; 	// SPI module configured as a master SPI device
	SPI0->C1&=~ SPI_C1_CPOL_MASK; // Configures SPI clock as active-high
	SPI0->C1&=~ SPI_C1_CPHA_MASK; 	//First edge on SPSCK at start of first data transfer cycle
	SPI0->C1&=~SPI_C1_SSOE_MASK; 	// SS pin function is general-purpose I/O (not SPI).
	
	//SPI0->C2 config
	
	SPI0->C2&=~SPI_C2_SPMIE_MASK; // Interrupts from SPMF inhibited (use polling)
	SPI0->C2&=~SPI_C2_TXDMAE_MASK;// DMA request for transmit is disabled and interrupt from SPTEF is allowed
	SPI0->C2&=~SPI_C2_MODFEN_MASK;// Mode fault function disabled, master SS pin reverts to general-purpose I/O not controlled by SPI
	SPI0->C2&=~SPI_C2_RXDMAE_MASK;// DMA request for receive is disabled and interrupt from SPRF is allowed
	SPI0->C2&=~SPI_C2_SPISWAI_MASK;//SPI clocks stop when the MCU enters wait mode 
	//SPI0->C2|= SPI_C2_SPC0_MASK;	// SPI uses separate pins for data input and data output (pin mode is normal).In master mode of operation: MISO is master in and MOSI is master out.
	
	//Ports PCR setup
	PORTA->PCR[6] = PORT_PCR_MUX(3);//SPI MISO
	PORTA->PCR[7] = PORT_PCR_MUX(3);//SPI MOSI
	PORTB->PCR[0] = PORT_PCR_MUX(3);//SPI SCK
	
	// Boundrate setup
	SPI0->BR|= SPI_BR_SPR(0x07)| SPI_BR_SPPR(0x08); //Baud rate prescaler divisor is 4, Baud rate divisor is 16
	
	SPI0->C1|= SPI_C1_SPE_MASK;			//SPI system enabled
}


SPI::~SPI()
{
}

void SPI::operator<<(char rhs)
{
	//SPI0->C2|=SPI_C2_BIDIROE_MASK;//output on single line
	while(!(SPI0->S&SPI_S_SPTEF_MASK)){}
		SPI0->D= rhs;//SPI_D_Bits(rhs);
		while(!TransmitBufferFree());
		
		
}

void SPI::operator>>(char& rhs)
{
	while(!(SPI0->S&SPI_S_SPRF_MASK)){}
		rhs=SPI0->D;
		
		
	
}

bool SPI::TransmitBufferFree()
{
	return SPI0->S&SPI_S_SPTEF_MASK;
}