
#include "pch.h"
#include "RegularSet.h"


template< typename T >
struct array_deleter
{
	void operator ()(T const * p)
	{
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




}


