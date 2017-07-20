#include "LeetCodeDataStructure.h"

// LeetCode's Binary Tree Definition
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

// ������
namespace LeetCode {

	class LEETCODE_EXP LCBinaryTree {
	public:
		// ���죺���� "[1, null, 2]" ���͵��ַ���
		LCBinaryTree() = default;
		LCBinaryTree(std::string strInput);
		LCBinaryTree(const char* strInput);

		// ����
		~LCBinaryTree();

		// ��ȡ���������ĸ��ڵ�
		const TreeNode* GetTreeBinaryTreeRoot() const;

		// ��ӡ������������
		void PrintBinaryTree() const;

	private:
		// ���죺���ַ�������ת��Ϊ�������ṹ
		bool _ConstructBinaryTree(std::string strInput);

		// ���죺�� std::vector ת��Ϊ������
		bool _MakeBinaryTree(std::vector<int> vecBinaryTree);

		// ���壺�������ڵ㷽��
		enum EPrintDirection {
			EPrintDirection_Left = 0,
			EPrintDirection_Right,
			EPrintDirection_Root,
		};

		// ��ӡ����ӡһ���ڵ�
		void _PrintTreeNode(const TreeNode node, int depth, enum EPrintDirection eDirection) const;

	private:
		std::vector<TreeNode> m_vecBinaryTree; 
	};

}