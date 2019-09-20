#pragma once

#include <set>
#include <algorithm>
#include <iostream>
class RegularSet
{
private:
	std::set<int> Set;


public:
	RegularSet();
	void insertSet(const int&);
	std::set<int>::iterator searchSet(const int&) const;
	void printSet() const;
	const std::set<int>::iterator getLastIter() const;
	virtual ~RegularSet();
};

