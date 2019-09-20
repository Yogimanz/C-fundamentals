
#include "pch.h"
#include "RegularSet.h"


int main()
{
	RegularSet mySet;
	mySet.insertSet(56);
	mySet.insertSet(34);
	mySet.insertSet(12);
	mySet.insertSet(345);
	mySet.insertSet(1);

	mySet.printSet();

	int searcVal;
	std::cout << "Enter an integer to search for." << std::endl;
	std::cin >> searcVal;


	auto result = mySet.searchSet(searcVal);
	// checking the result with the last iterator of Regular set in order to 
	// find out if the element was found, this could've been condensed into a single function
	// result holds an iterator position we could use to do other things
	if (result != mySet.getLastIter())
		std::cout << "Element was found." << std::endl;
	else
		std::cout << "Element was not found." << std::endl;


	std::cout << "Insert in following order number of elements to insert, low range and high range of random integers to add. " << std::endl;
	int* inputs= new int[3];
	
	std::cin >> inputs[0];
	std::cin >> inputs[1];
	std::cin >> inputs[2];

	mySet.insertRandRange(inputs[0], inputs[1], inputs[2]);
	mySet.printSet();

	std::cout << "Enter an integer to search for MANUALLY." << std::endl;
	std::cin >> searcVal;
	mySet.manualSearch(searcVal);
	delete[] inputs;
}


