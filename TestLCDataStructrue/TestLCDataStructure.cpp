#include <iostream>
#include <cstdlib>
#include "LeetCodeDataStructure.h"
#include "LCArray.h"
#include "LCBinaryTree.h"
#include "LCSingleLinkedList.h"

int main()
{
#if 0
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
#endif

#if 0
	// Test LCBinaryTree
	/*std::string strInput = "[1, 2, 3, null, 4, null, 5]";
	LeetCode::LCBinaryTree lcBinaryTree(strInput);
	lcBinaryTree.PrintBinaryTree();*/
	std::string strInput;
	while (std::getline(std::cin, strInput)) {
		LeetCode::LCBinaryTree LCBinaryTree(strInput);
		LCBinaryTree.PrintBinaryTree();
	}
#endif 

#if 1
	// Test LCSingleLinkedList
	/*std::string strInput = "[1, 2, 3 ,4, 5]";
	LeetCode::LCSingleLinkedList lcSingleLinkedList(strInput);
	lcSingleLinkedList.PrintSingleLinkedList();*/
	std::string strInput;
	while (std::getline(std::cin, strInput)) {
		LeetCode::LCSingleLinkedList lcSingleLinkedList(strInput);
		lcSingleLinkedList.PrintSingleLinkedList();
	}
#endif

	system("pause");
	return 0;
}