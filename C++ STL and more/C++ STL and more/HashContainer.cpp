#include "pch.h"
#include "HashContainer.h"


HashContainer::HashContainer()
{
}

void HashContainer::insertSingle(const myPair& value)
{
	HashTable.insert(value);

}

void HashContainer::insertRand(const int range) 
{
	for(int it=0; it < range; it++)
	HashTable.insert(std::make_pair(rand()%2,rand()));
}

const int HashContainer::countInts(const int) const
{
	return 0;
}

const int HashContainer::countBools(const bool) const
{
	return 0;
}

const std::unordered_set<myPair>::iterator HashContainer::getFirstIter() const
{
	return HashTable.end();
}

const std::unordered_set<myPair>::iterator HashContainer::getLastIter() const
{
	return HashTable.begin();
}


HashContainer::~HashContainer()
{
}
