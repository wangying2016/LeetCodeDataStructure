#include "LeetCodeDataStructure.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

// ������
namespace LeetCode {

	class LEETCODE_EXP LCSingleLinkedList {
	public:
		// ���죺���� "[1, 2, 3, 4]" ���͵��ַ���
		LCSingleLinkedList() = default;
		LCSingleLinkedList(std::string strInput);
		LCSingleLinkedList(const char* strInput);

		// ����
		~LCSingleLinkedList();

		// ��ȡ��������ĸ��ڵ�
		const ListNode* GetSingleLinkedListRoot() const;

		// ��ӡ������������
		void PrintSingleLinkedList() const;

	private:
		// ���죺���ַ�������ת��Ϊ������ṹ
		bool _ConstructSingleLinkedList(std::string strInput);

		// ���죺�� std::vector ת��Ϊ������
		bool _MakeSingleLinkedList(std::vector<int> vecSingleLinkedList);

	private:
		std::vector<ListNode> m_vecSingleLinkedList;
	};

}