#include "pch.h"
#include "RegularSet.h"
#include <set>
#include <algorithm>
#include <iostream>

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

RegularSet::~RegularSet()
{
}
