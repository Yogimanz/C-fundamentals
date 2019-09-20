#pragma once
class RegularSet
{
private:
	std::set<int> Set;


public:
	RegularSet();
	void insertSet(const int&);
	std::set<int>::iterator searchSet(const int&) const;
	void printSet() const;
	virtual ~RegularSet();
};

