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
	int tempRange =highEnd;
	bool shouldSwap = false;
	if (numEle > 0)
	{
		// check is lowend is higher then highend and swap them if so
		if (lowEnd > highEnd)
		{ 
			// std::swap(lowEnd, highEnd); - not possible with const refs
			shouldSwap = true;
			std::cout << "Swapping ranges since lower range was higher then high range." << std::endl;
		}
		// if both ranges are equall add 100 to high range
		if (lowEnd == highEnd)
		{
			std::cout << "Ranges were equal, adding 100 to highEnd range." << std::endl;
			tempRange += 100;
		}

		if(!shouldSwap)
		for (int it = 0; it < numEle; it++)
		{
			// this random distribution will NOT be uniform
			Set.insert(lowEnd + (std::rand() % (tempRange - lowEnd + 1)));
		}
		else
			for (int it = 0; it < numEle; it++)
			{
				// this random distribution will NOT be uniform
				Set.insert(tempRange + (std::rand() % (lowEnd - tempRange + 1)));
			}
		std::cout << "The set now contains: " << Set.size() << " elements." << std::endl;
	}
		

	else
		std::cout << "U've entered an invalid number of elements to insert into the set." << std::endl;
}
void RegularSet::manualSearch(const int &value) const
{
	bool sucess = false;
	// slowly iterate through each element of the set and compare it with the current iterator
	for (auto result : Set)
	{
		if (result == value)
		{
			sucess = true;
			break;
		}
	}
	if (sucess)
		std::cout << "Sucessfully found " << value << " inside the set!" << std::endl;
	else
		std::cout << "Did not manage to manually find " << value << " inside the set!" << std::endl;

}
RegularSet::~RegularSet()
{
	std::cout<<"Regular Set deleted.\n";
}
