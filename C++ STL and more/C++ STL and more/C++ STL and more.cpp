
#include "pch.h"
#include "RegularSet.h"
#include "HashContainer.h"

template< typename T >
struct array_deleter
{
	void operator ()(T const * p)
	{
		std::cout << "Deleter invoked.\n";
		delete[] p;
	}
};

int main()
{
	int choice;
	std::cout << "Insert 1 to work with Hash Container, 2 to work with Set." << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		// this case is entierly hardcoded, could be easily changed to work with user input.
		HashContainer myHashTable;
		
		myHashTable.insertSingle(std::pair<bool, int> (true, 2));
		myHashTable.insertSingle(std::pair<bool, int>(false, 15));
		myHashTable.insertSingle(std::pair<bool, int>(true, 347));
		myHashTable.insertSingle(std::pair<bool, int>(true, 28));
		myHashTable.insertSingle(std::pair<bool, int>(true, 28));
		myHashTable.insertSingle(std::pair<bool, int>(true, 28));
		myHashTable.printTable();


		std::cout << "Number of elements countaining true as first pair value (boolean)\n " << myHashTable.countBools(true) << std::endl;
		//Returns 3.
		std::cout << "Number of elements countaining true as first pair value (boolean) \n" << myHashTable.countInts(14) << std::endl;
		//Returns 0 as it should.
		std::cout << "Number of elements countaining true as first pair value (boolean)\n " << myHashTable.countInts(28) << std::endl;
		//Returns 1, indicating that unordered set doesnt take in duplicates

		if (myHashTable.findPairWithBool(true))
			//finds after single search indicated with "Call" prints from functor
			std::cout << "There is a pair with boolean value true. \n\n";
		else
			std::cout << "None of the pairs in container have their boolean value as true.\n \n";

		if (myHashTable.findPairWithInt(15))
			//finds after single search using hash table to target specific bucket
			std::cout << "There is a pair with int value 15. \n\n";
		else
			
			std::cout << "None of the pairs in container have their int value as 12. \n\n";

		if (myHashTable.findPair(std::make_pair(true,28)))
			std::cout << "There is a pair with int value 28 and bool value true. \n\n";
		else
			std::cout << "None of the pairs in container have their int value as 12. \n\n";
	}
		break;
	case 2:
	{
		RegularSet mySet;
		mySet.insertSet(56);
		mySet.insertSet(34);
		mySet.insertSet(12);
		mySet.insertSet(345);
		mySet.insertSet(1);

		mySet.printSet();


		std::cout << "Enter an integer to search for." << std::endl;
		std::cin >> choice;


		auto result = mySet.searchSet(choice);
		// checking the result with the last iterator of Regular set in order to 
		// find out if the element was found, this could've been condensed into a single function
		// result holds an iterator position we could use to do other things
		if (result != mySet.getLastIter())
			std::cout << "Element was found." << std::endl;
		else
			std::cout << "Element was not found." << std::endl;


		std::cout << "Insert in following order number of elements to insert, low range and high range of random integers to add. " << std::endl;
		//int* inputs = new int[3];
		std::shared_ptr<int> inputs(new int[3], array_deleter<int>());
		std::cin >> inputs.get()[0];
		std::cin >> inputs.get()[1];
		std::cin >> inputs.get()[2];

		mySet.insertRandRange(inputs.get()[0], inputs.get()[1], inputs.get()[2]);
		mySet.printSet();

		std::cout << "Enter an integer to search for MANUALLY." << std::endl;
		std::cin >> choice;
		mySet.manualSearch(choice);
		
	}
		
		break;
	default: 
		std::cout <<"Insert either 1 or 2.\n";
		break;
	}
	return 0;



}


