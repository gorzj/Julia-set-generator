#ifndef ST7735_h
#define ST7735_h

#include "SPI.h"

#define display_width
#define display_hight  


//Display Commands

#define ST7735_NOP     0x00
#define ST7735_SWRESET 0x01
#define ST7735_RDDID   0x04
#define ST7735_RDDST   0x09

#define ST7735_SLPIN   0x10
#define ST7735_SLPOUT  0x11
#define ST7735_PTLON   0x12
#define ST7735_NORON   0x13

#define ST7735_INVOFF  0x20
#define ST7735_INVON   0x21
#define ST7735_DISPOFF 0x28
#define ST7735_DISPON  0x29
#define ST7735_CASET   0x2A
#define ST7735_RASET   0x2B
#define ST7735_RAMWR   0x2C
#define ST7735_RAMRD   0x2E

#define ST7735_PTLAR   0x30
#define ST7735_COLMOD  0x3A
#define ST7735_TEOFF	 0x35
#define ST7735_TEON		 0x35
#define ST7735_MADCTL  0x36

#define ST7735_FRMCTR1 0xB1
#define ST7735_FRMCTR2 0xB2
#define ST7735_FRMCTR3 0xB3
#define ST7735_INVCTR  0xB4
#define ST7735_DISSET5 0xB6

#define ST7735_PWCTR1  0xC0
#define ST7735_PWCTR2  0xC1
#define ST7735_PWCTR3  0xC2
#define ST7735_PWCTR4  0xC3
#define ST7735_PWCTR5  0xC4
#define ST7735_VMCTR1  0xC5

#define ST7735_RDID1   0xDA
#define ST7735_RDID2   0xDB
#define ST7735_RDID3   0xDC
#define ST7735_RDID4   0xDD

#define ST7735_PWCTR6  0xFC

#define ST7735_GMCTRP1 0xE0
#define ST7735_GMCTRN1 0xE1


class ST7735
	{
private:


void delay_ms(unsigned int time)
{
	
	for(unsigned int i=0; i<time; i++)
		for(volatile unsigned int j=0; j< 48000; j++);
}

	uint32_t ST7735ResetPin= 8;
	uint32_t ST7735DCPin= 9;
	uint32_t ST7735CSPin= 10;	


 
 SPI OutputChannel;





public:
	ST7735();
	~ST7735();
void SetPixel(uint16_t x, uint16_t y, uint16_t color );
void Write_Command(uint8_t command);
void Write_Data(uint8_t Data);
void Release_Bus(void);
void SetRect(uint16_t x0,uint16_t y0,uint16_t x,uint16_t y,uint16_t ScreenBuffer[]);

	void operator << (unsigned char* rhs);


};
#endif
