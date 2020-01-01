#include "julia.h"
#include <stdlib.h>



float* axis(unsigned int Leanght, float min, float max)
{
	float* ax = malloc(sizeof(float)*Leanght);
	for (unsigned int i =0;i<Leanght;i++)
	{
		ax[i]=(((max-min)*i)/Leanght)+min;
	}
	return ax;
}

unsigned char* CreateJuliaSpace()
{
	unsigned char*tmp= malloc(sizeof(unsigned char)*width *hight);
	return tmp;
}

void DelateJuliaSpace(unsigned char*Space)
{
	free(Space);
}
void SetJuliaSpace(unsigned char* NewSpace)
{
	JuliaSpace = NewSpace;
}
unsigned char* GetJuliaSpace(void)
{
	return JuliaSpace;
}



void JuliaInit(void)
{
	x=axis(width,xmin,xmax);
	y=axis(hight,ymax,ymin);  //exchange min and max posytion to change y axis direction;
	JuliaSpace=CreateJuliaSpace();	
}
void JuliaOFF(void)
	{
		free(JuliaSpace);
	};
	
unsigned char JuliaElement(float Z0Re,float Z0Im, float CRe, float CIm)
	{
		float ZRe=Z0Re;
		float ZIm=Z0Im;
		unsigned char iteration;
		for(iteration=0; iteration<0xFF;iteration++)
		{
			float ZRe_tmp=ZRe*ZRe+CRe;
			ZIm=2*ZRe*ZIm+CIm;
			ZRe=ZRe_tmp;
			if(ZIm*ZIm+ZRe*ZRe) break;
		}
		return iteration;
		
	}	
