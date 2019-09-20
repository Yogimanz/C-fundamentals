#include "pch.h"
#include "RegularSet.h"
#include <random>


RegularSet::RegularSet()
{
}

void RegularSet::insertSet(const int &value)
{
	// calling STL insert method on container std::set<>
	Set.insert(value);
	std::cout << "Inserted value " << value << " into the set." << std::endl;
}

std::set<int>::iterator RegularSet::searchSet(const int &value) const
{
	// calling STL find method on container std::set<>, result is an iterator which has to be checked before use
	std::set<int>::iterator result = Set.find(value);
	// iterator should be checked by using != std::set<>.end() and if true we can print the sucessful search
	return result;
}
void RegularSet::printSet() const
{
	// printing out all elements with foreach using auto
	for (auto value : Set)
		std::cout << value << std::endl;
}
const std::set<int>::iterator RegularSet::getLastIter() const
{
	return Set.end();
}
void RegularSet::insertRandRange(const int &numEle, const int &lowEnd, const int &highEnd)
{
	//check if the range inserted is invalid
	if (numEle > 0)
	{
		for (int it = 0; it < numEle; it++)
		{
			// this random distribution will NOT be uniform
			Set.insert(lowEnd + (std::rand() % (highEnd - lowEnd + 1)));
		}
		std::cout << "The set now contains: " << Set.size() << " elements." << std::endl;
	}
		

	else
		std::cout << "U've entered an invalid number of elements to insert into the set." << std::endl;
}
void RegularSet::manualSearch(const int &) const
{

}
RegularSet::~RegularSet()
{
}
