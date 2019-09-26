#pragma once
//simple RAII class for time measurement of operations
class SimpleClock
{
	clock_t Time;
public:
	SimpleClock();
	~SimpleClock();
};

