#include "pch.h"
#include "SimpleClock.h"
#include <iostream>

SimpleClock::SimpleClock()
{
	Time = clock();
}


SimpleClock::~SimpleClock()
{
	std::cout << "Elapsed clock clicks: " << Time << " and " << (float)Time / CLOCKS_PER_SEC << " seconds " << std::endl;
}

