#pragma once
#include <unordered_set>
#include <algorithm>

//hash function copied from https://www.boost.org/doc/libs/1_53_0/doc/html/hash/reference.html#boost.hash_combine
template<typename T> void hash_combine(size_t & seed, T const& v) {
	seed ^= stdext::hash_value(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct pair_hash
{
	// functor dedicated to handling hash function
	template<typename T, typename U>
	std::size_t operator()(const std::pair<T, U> &rhs) const {
		size_t retval = stdext::hash_value<T>(rhs.first);
		hash_combine(retval, rhs.second);
		return retval;
	}

};

//Functor used to compare first element within hash tables pairs(elements) - booleans in this case (in main)
template<typename T>
struct matchFirstFunctor
{ 
	matchFirstFunctor(T const& t) : compared(t)
	{}

	template <typename U>
	bool operator()(U const& pair)
	{
		std::cout << "Call functor for first value of pair for comparison.\n";
		return pair.first == compared;
	}

		T compared;
};

//functor used to compare second element within hash tables pairs(elements) - integers in this case (in main)
template<typename T>
struct matchSecondFunctor
{
	matchSecondFunctor(T const& t) : compared(t)
	{}

	template <typename U>
	bool operator()(U const& pair)
	{
		std::cout << "Call functor for second value of pair for comparison \n";
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
	const int countBools(const bool&) const;
	//count all found true or false booleans in pairs within table
	const int countInts(const int&) const;

	//find single pair with its int value as argument
	const bool findPairWithInt(const int&) const;
	//find single pair with its bool value as argument
	const bool findPairWithBool(const bool&) const;
	//find single pair within hash table with a new pair as argument
	const bool findPair(const std::pair<bool,int>&) const;
	//print all pairs within table
	void printTable();
	virtual ~HashContainer();
};

