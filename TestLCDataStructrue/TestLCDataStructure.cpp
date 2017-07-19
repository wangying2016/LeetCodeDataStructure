#include <iostream>
#include <cstdlib>
#include "LeetCodeDataStructure.h"
#include "LCArray.h"

int main()
{
	// Test LCArray
	/*std::string strInput = "[1, 2, 3, 4, 5]";
	LeetCode::LCArray lcArray("[1, 2, 3, 4, 5]");
	lcArray.PrintArray();*/
	std::cout << "This my LeetCode::LCArray class \r\n" << 
		"In order to deal with array structure" << std::endl;
	std::string strInput;
	while (std::getline(std::cin, strInput)) {
		LeetCode::LCArray lcArray(strInput);
		lcArray.PrintArray();
	}
	system("pause");
	return 0;
}