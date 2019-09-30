#pragma once
#include <time.h>
//simple RAII class for time measurement of operations
class SimpleClock
{
	clock_t Time;
public:
	SimpleClock();
	~SimpleClock();

};

