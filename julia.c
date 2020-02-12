#include "julia.h"



float xmin=-2;
float xmax=2;
 
float ymin=-2;
float ymax=2;
 
	
const float * x;
const float * y;

unsigned char* JuliaSpace;

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

void SetJuliaElemetn(unsigned char x, unsigned char y, unsigned char value);
{
JuliaSpace[x][y]=value;
}

void ValRefresh(float CRe, float CIm);
{
for(unsigned char i=0; i<128; i++)
for(unsigned char j=0; j<128; j++)
SetJuliaElemetn(i,j,JuliaElement(x[i],y[i],CRe,CIm));
}
