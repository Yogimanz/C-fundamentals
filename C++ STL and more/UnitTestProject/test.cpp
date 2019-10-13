#include "pch.h"
#include "../C++ STL and more/VectorClass.h"

TEST(VectorClass, smallestPositiveMissing) {

	std::vector<int> TestVector = { -1,5,-12,3,2,1,0,7,4 }; 
	VectorClass Vecty;
	int result = Vecty.smallestPositiveMissing(TestVector);
	ASSERT_EQ(result, 6);
}