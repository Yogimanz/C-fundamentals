#include "pch.h"
#include "VectorClass.h"
#include <set>

VectorClass::VectorClass()
{
}

int VectorClass::smallestPositiveMissing(std::vector<int>& VectorRef) const
{
	int result=0;
	std::set<int> Setty;
	for (auto value : VectorRef)
		Setty.insert(value);
	for (int i = 0; i < 1000000; i++)
	{
		//if (!Setty.contains(i)) {
		auto iter = Setty.find(i);
		if(!(iter!=Setty.end())){

			result = i;
			break;
		}
	
	
	}
	return result;
}


VectorClass::~VectorClass()
{
}
