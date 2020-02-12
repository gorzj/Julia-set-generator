/*----------------------------------------------------------------------------
 *      
 *----------------------------------------------------------------------------
 *      Name:    julia.h
 *      Purpose: Microprocessors Laboratory
 *----------------------------------------------------------------------------
 *      
 *---------------------------------------------------------------------------*/
 #ifndef JULIA_H
 #define JULIA_H
 
 
#include <stdlib.h> 
 
#define  width 128
#define  hight 128
 

//constructur of tabel that translates number of element to coordinate
float* axis(const unsigned int Leanght, const float min, const float max);
unsigned char* CreateJuliaSpace();
void DelateJuliaSpace(unsigned char*Space);
unsigned char* GetJuliaSpace(void);
void SetJuliaSpace(unsigned char* NewSpace);
void SetJuliaElemetn(unsigned char x, unsigned char y, unsigned char value);

void ValRefresh(CRe, CIm);
unsigned char JuliaElement(float Z0Re,float Z0Im, float CRe, float CIm);

void JuliaInit(void);
void JuliaOFF(void);


	
	
	
	
	
	
 
 
 
 
 #endif
 