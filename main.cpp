#include "MKL05Z4.h"
#include "ST7735.h"
#include "pit.h"
#include "SPI.h"
#include "math.h"
#include "julia.h"



#define m_pi 3.14159265359 


 float CRe=1;
 float CIm=1;

const float phi=0.0001;



void SysTick_Handler(void) { 							/* TBD_4.1:  Put the name of SysTick handler */	
	const float ShiftRe=cos(phi*2*m_pi);
	const float ShiftIm=sin(phi*2*m_pi);
	CRe=(CRe*ShiftRe)-(CIm*ShiftIm);
	CIm= (CRe*ShiftIm)+(CIm*ShiftRe);
	
	
}

int main(void){
	pit_initialize();
	ST7735 Display{};		
	JuliaInit();
	
		
	
	
	
	
	
while(1)
{	
	float CReBuf=CRe;
	float CImBuf=CIm;
	
	ValRefresh(float CReBuf, float CImBuf);
		Display.SetRect(0,0,128,128,GetJuliaSpace());
}
  



}
