
#include "ST7735.h"

void ST7735::Release_Bus(void)
{
	//while(!OutputChannel.TransmitBufferFree());
	//PTA->PSOR |= (1<<ST7735CSPin);
}

void ST7735::Write_Command(uint8_t command)
{
	PTA->PSOR |= (1<<ST7735ResetPin);
	PTA->PCOR |= (1<<ST7735DCPin)|(1<<ST7735CSPin);
	OutputChannel<<command;
	//PTA->PSOR |= (1<<ST7735ResetPin)| (1<<ST7735DCPin)|(1<<ST7735CSPin);
	
}

void ST7735::Write_Data(uint8_t data)
{
	PTA->PSOR |= (1<<ST7735DCPin)|(1<<ST7735ResetPin);
	PTA->PCOR |= (1<<ST7735CSPin);
	OutputChannel<<data;
	//PTA->PSOR |= (1<<ST7735ResetPin)| (1<<ST7735DCPin)|(1<<ST7735CSPin);
	
}
void ST7735::SetRect(uint16_t x0,uint16_t y0,uint16_t x,uint16_t y,uint16_t ScreenBuffer[])
{
Write_Command(ST7735_CASET); // Colunmn Address Set command
Write_Data(x0>>8); // first bit is always dont care
Write_Data(x0&0xFF); // Starting Address X axis.
Write_Data(x>>8); // first bit is always dont care
Write_Data(x&0xFF); // Ending Addresss X axis.
//delay_ms(10);
Write_Command(ST7735_RASET);
Write_Data(y0>>8); // first bit is always dont care
Write_Data(y0&0xFF); // Starting Address Y axis.
Write_Data(y>>8); // first bit is always dont care
Write_Data(y&0xFF); // Ending Addresss Y axis.
Write_Command(ST7735_RAMWR); // what ever is sent next is written to the ram
unsigned int PixelsToSet=(x-x0)*(y-y0);	
for (unsigned i=0;i<PixelsToSet;i++)
{
	Write_Data((*ScreenBuffer)>>8); // send first 8 bytes
	Write_Data((*ScreenBuffer)&0xFF); /// send last 8 bytes	
	ScreenBuffer++;
}
Write_Command(ST7735_NOP);
Release_Bus();
}

void ST7735::SetPixel(uint16_t x, uint16_t y, uint16_t color )
{
Write_Command(ST7735_CASET); // Colunmn Address Set command
Write_Data(0); // first bit is always dont care
Write_Data(x); // Starting Address X axis.
Write_Data(0); // first bit is always dont care
Write_Data(x+1); // Ending Addresss X axis.
//delay_ms(10);
Write_Command(ST7735_RASET);
Write_Data(0); // first bit is always dont care
Write_Data(y); // Starting Address Y axis.
Write_Data(0); // first bit is always dont care
Write_Data(y+1); // Ending Addresss Y axis.
//delay_ms(10);
Write_Command(ST7735_RAMWR); // what ever is sent next is written to the ram
Write_Data(color>>8); // send first 8 bytes
Write_Data(color&0xFF); /// send last 8 bytes

Release_Bus();
//	 delay_ms(100);
	
}


ST7735::ST7735()
{
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	PTA->PDDR |= (1<<ST7735ResetPin)|(1<<ST7735DCPin)|(1<<ST7735CSPin);
	PORTA->PCR[ST7735ResetPin] = PORT_PCR_MUX(1);
	PORTA->PCR[ST7735DCPin] = PORT_PCR_MUX(1);
	PORTA->PCR[ST7735CSPin] = PORT_PCR_MUX(1);
	
	Write_Command( ST7735_SWRESET);
	delay_ms(50);
	Write_Command( ST7735_SLPOUT);
	delay_ms(255);
	Write_Command( ST7735_FRMCTR1);
	Write_Data(0x01);			
	Write_Data(0x2C);
	Write_Data(0x2D);			
	delay_ms(10);
	Write_Command( ST7735_FRMCTR2);
	Write_Data(0x01);			
	Write_Data(0x2c);
	Write_Data(0x2d);	    							 //     3 lines back porch
	delay_ms(10);
	Write_Command( ST7735_FRMCTR3);
	Write_Data(0x01);			
	Write_Data(0x2c);
	Write_Data(0x2d);
	Write_Data(0x01);			
	Write_Data(0x2c);
	Write_Data(0x2d);
	delay_ms(10);//?
	
	Write_Command( ST7735_INVCTR);
	Write_Data(0x07);
	delay_ms(10);
	
	
	Write_Command( ST7735_PWCTR1);
	 Write_Data(0xa2);  
		Write_Data(0x02);////     Row addr/col addr, bottom to top refresh
	Write_Data(0X84);
	delay_ms(10);  //?
	
	Write_Command( ST7735_PWCTR2);
	 Write_Data(0xc5);  
	delay_ms(10);  //?
	Write_Command( ST7735_PWCTR3);

   Write_Data(0x0A);  
Write_Data(0x00);                   
	delay_ms(10);	 
	Write_Command( ST7735_PWCTR4);
	Write_Data(0x8A);  
	Write_Data(0x2a);                   
	delay_ms(10);
	Write_Command( ST7735_PWCTR5);
	Write_Data(0x8A);  
Write_Data(0xEE);                   
	delay_ms(10);
	 
	 Write_Command( ST7735_VMCTR1);
	 Write_Data(0x0E);	
	delay_ms(10);	 
	 Write_Command( ST7735_INVOFF);
	 delay_ms(10);
	 Write_Command( ST7735_MADCTL);
	 Write_Data(0xC8);                         
	 delay_ms(10);
	 Write_Command( ST7735_COLMOD);
	 Write_Data(0x05);               
	 delay_ms(10);
	 Write_Command( ST7735_CASET);
	 Write_Data(0x00);  
	 Write_Data(0x00);    
	 Write_Data(0x00);    
	 Write_Data(0x7F);
		delay_ms(10);	 
Write_Command( ST7735_RASET);
	 Write_Data(0x00);  
	 Write_Data(0x00);    
	 Write_Data(0x00);    
	 Write_Data(0x9F);
	 delay_ms(10);
	 Write_Command( ST7735_GMCTRP1);
	 Write_Data(0x02);  
	 Write_Data(0x1c);    
	 Write_Data(0x07);    
	 Write_Data(0x12);
	 Write_Data(0x37);  
	 Write_Data(0x32);    
	 Write_Data(0x29);    
	 Write_Data(0x2d);
	 Write_Data(0x29);  
	 Write_Data(0x25);    
	 Write_Data(0x2b);    
	 Write_Data(0x39);
	 Write_Data(0x00);  
	 Write_Data(0x01);    
	 Write_Data(0x03);    
	 Write_Data(0x10);    
	 delay_ms(10);
	 Write_Command( ST7735_GMCTRN1);
	 Write_Data(0x03);  
	 Write_Data(0x1d);    
	 Write_Data(0x07);    
	 Write_Data(0x06);
	 Write_Data(0x2e);  
	 Write_Data(0x2c);    
	 Write_Data(0x29);    
	 Write_Data(0x2d);
	 Write_Data(0x2e);  
	 Write_Data(0x2e);    
	 Write_Data(0x37);    
	 Write_Data(0x3f);
	 Write_Data(0x00);  
	 Write_Data(0x00);    
	 Write_Data(0x02);    
	 Write_Data(0x10); 
	 delay_ms(100);
	 Write_Command( ST7735_NORON );
	 delay_ms(10);
	 
	 //Dodano 11.02.20
	// Write_Command( ST7735_TEON );
	 //Write_Data(0x00);
	 
	 
	 Write_Command( ST7735_DISPON);
	 delay_ms(250);
	 
	 
	// Release_Bus();
	
}


ST7735::~ST7735()
{
}

void ST7735::operator<<(unsigned char* rhs)
{
	for (int i = 0; i < (display_hight+0); i++)
		for (int j = 0; j < (display_width+0); j++)
		{
		}

}
