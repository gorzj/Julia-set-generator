#ifndef SPI_h
#define SPI_h
#include "MKL05Z4.h"


class SPI
{
public:
	SPI();

	~SPI();
	
	bool TransmitBufferFree();
	void operator << (char rhs);
	void operator >> (char& rhs);
};
#endif

