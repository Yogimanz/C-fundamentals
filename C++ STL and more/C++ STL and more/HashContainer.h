#pragma once
#include <unordered_set>
#include <algorithm>


struct pair_hash
{
	// functor dedicated to handling hash function
	template<typename T, typename U>
	std::size_t operator()(const std::pair<T, U> &rhs) const {
		size_t retval = stdext::hash_value<T>(rhs.first);
		hash_combine(retval, rhs.second);
		return retval;
	}
	//hash function copied from https://www.boost.org/doc/libs/1_53_0/doc/html/hash/reference.html#boost.hash_combine
	template<typename T> void hash_combine(size_t & seed, T const& v) {
		seed ^= stdext::hash_value(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	}
};

template<typename T>
struct matchFirstFunctor
{ 
	matchFirstFunctor(T const& t) : compared(t)
	{}

	template <typename U>
	bool operator()(U const& pair)
	{
		return pair.first == compared;
	}

		T compared;
};

template<typename T>
struct matchSecondFunctor
{
	matchSecondFunctor(T const& t) : compared(t)
	{}

	template <typename U>
	bool operator()(U const& pair)
	{
		return pair.second == compared;
	}

	T compared;
};

typedef std::pair<bool, int> myPair;
class HashContainer
{
private:
	//2nd argument for hash table declaration is hash function we use to override regular one, in this case for hasing pairs of any type
	//myPair is pair of bool and int
	std::unordered_set<myPair, pair_hash> HashTable;
	const std::unordered_set<myPair>::iterator getFirstIter() const;
	const std::unordered_set<myPair>::iterator getLastIter() const;
public:
	HashContainer();
	//insert single into table
	void insertSingle(const myPair&);
	//insert random pairs into hash using argument as the amount of numbers inserted
	void insertRand(const int&);
	//count all found integers in pairs within table
	const int countInts(const int&) const;
	//count all found true or false booleans in pairs within table
	const int countBools(const bool&) const;
	
	virtual ~HashContainer();
};

