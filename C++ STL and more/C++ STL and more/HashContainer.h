#pragma once
#include <unordered_set>

class HashContainer
{
private:
	std::unordered_set<std::pair<bool, int>> HashTable;
public:
	HashContainer();
	void insertSingle(std::pair<bool, int>) const;
	void insertRand(std::pair<bool, int>, int) const;
	const int countInts(int) const;
	const int countBools(bool) const;
	virtual ~HashContainer();
};

