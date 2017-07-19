#include <iostream>
#include <cstdlib>
#include "LeetCodeDataStructure.h"
#include "LCArray.h"

int main()
{
	// Test LCArray
	std::string strInput = "[1, 2, 3, 4, 5]";
	LeetCode::LCArray lcArray("[1, 2, 3, 4, 5]");
	lcArray.PrintArray();
	system("pause");
	return 0;
}