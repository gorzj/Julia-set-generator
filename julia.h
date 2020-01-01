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
 
 
  
 
unsigned int width=128;
unsigned int hight=128;
 
float xmin=-2;
float xmax=2;
 
float ymin=-2;
float ymax=2;
 
	
const float * x;
const float * y;
//constructur of tabel that translates number of element to coordinate
float* axis(const unsigned int Leanght, const float min, const float max);

unsigned char* JuliaSpace;

unsigned char* CreateJuliaSpace();
void DelateJuliaSpace(unsigned char*Space);
unsigned char* GetJuliaSpace(void);
void SetJuliaSpace(unsigned char* NewSpace);


unsigned char JuliaElement(float Z0Re,float Z0Im, float CRe, float CIm);

void JuliaInit(void);
void JuliaOFF(void);


	
	
	
	
	
	
 
 
 
 
 #endif
