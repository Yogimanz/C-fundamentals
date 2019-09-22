#include "pch.h"
#include "HashContainer.h"
#include <iostream>

HashContainer::HashContainer()
{
}

void HashContainer::insertSingle(const myPair& value)
{
	HashTable.insert(value);

}

void HashContainer::insertRand(const int& range) 
{
	for(int it=0; it < range; it++)
	HashTable.insert(std::make_pair(rand()%2,rand()));
}

const int HashContainer::countBools(const bool& searchValue) const
{
	return std::count_if(getFirstIter(), getLastIter(), matchFirstFunctor<bool>(searchValue));
}

const int HashContainer::countInts(const int& searchValue) const
{
	return std::count_if(getFirstIter(), getLastIter(), matchSecondFunctor<int>(searchValue));
}

const bool HashContainer::findPairWithInt(const int &searchValue) const
{
	auto result = std::find_if(getFirstIter(), getLastIter(), matchSecondFunctor<int>(searchValue));

	return result != getLastIter();
}

const bool HashContainer::findPairWithBool(const bool &searchValue) const
{
	auto result = std::find_if(getFirstIter(), getLastIter(), matchFirstFunctor<bool>(searchValue));
	return result != getLastIter();
}

const bool HashContainer::findPair(const std::pair<bool, int>& searchPair) const
{
	auto result=std::find(getFirstIter(), getLastIter(), searchPair);
	return result != getLastIter();
}

void HashContainer::printTable()
{
	for (auto it : HashTable)
		std::cout << it.first << " + " << it.second << std::endl;

}

const std::unordered_set<myPair>::iterator HashContainer::getFirstIter() const
{
	return HashTable.begin();
}

const std::unordered_set<myPair>::iterator HashContainer::getLastIter() const
{
	return HashTable.end();
}


HashContainer::~HashContainer()
{
	std::cout << "Hash table deleted. \n";
}
