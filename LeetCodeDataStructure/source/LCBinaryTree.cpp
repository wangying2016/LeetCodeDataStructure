#include <iostream>
#include <regex>
#include "../include/LCBinaryTree.h"


// ���죺���� "[1, null, 2]" ���͵��ַ���
LeetCode::LCBinaryTree::LCBinaryTree(std::string strInput)
{
	if (!_ConstructBinaryTree(strInput)) {
		std::cerr << "LCBinaryTree: constructed error." << std::endl;
	}
}

LeetCode::LCBinaryTree::LCBinaryTree(const char* strInput)
{
	if (nullptr != strInput) {
		if (!_ConstructBinaryTree(std::string(strInput))) {
			std::cerr << "LCBinaryTree: constructed error." << std::endl;
		}
	}
}

// ����
LeetCode::LCBinaryTree::~LCBinaryTree()
{
	m_vecBinaryTree.clear();
}

// ��ȡ���������ĸ��ڵ�
const LeetCode::TreeNode* LeetCode::LCBinaryTree::GetTreeBinaryTreeRoot() const
{
	return m_vecBinaryTree.size() == 0 ? nullptr : &m_vecBinaryTree[0];
}

// ��ӡ������������
void LeetCode::LCBinaryTree::PrintBinaryTree() const
{
	if (m_vecBinaryTree.size() == 0)
		std::cout << "LCBinaryTree: empty." << std::endl;
	else {
		std::cout << "LCBinaryTree:" << std::endl;
		_PrintTreeNode(m_vecBinaryTree[0], 0, EPrintDirection_Root);
	}
}

// ���죺���ַ�������ת��Ϊ�������ṹ
// ����\[.*\[|\].*\] ʶ�� [[ �� ]]
// ����\[(\s*\d\s*,|\s*null\s*,)*(\s*\d\s*|\s*null\s*)\] ʶ�� [1, 2, 3, 4, null, 5]
// ����\d|null ʶ�� �ڵ�ֵ
bool LeetCode::LCBinaryTree::_ConstructBinaryTree(std::string strInput)
{
	std::string strTemp(strInput);
	std::smatch match;
	std::regex regexBracket("\\[.*\\[|\\].*\\]");
	std::regex regexString("\\[(\\s*\\d\\s*,|\\s*null\\s*,)*(\\s*\\d\\s*|\\s*null\\s*)\\]");
	std::regex regexValue("\\d|null");
	// ��⣺���ƥ�䵽�� [[ ���� ]]��֤���ַ���������
	if (std::regex_search(strTemp, match, regexBracket)) {
		return false;
	}
	// ��⣺���ƥ����ȷ�����ʾ�ַ�������
	strTemp = strInput;
	std::vector<int> vecBinaryTree;
	if (std::regex_search(strTemp, match, regexString)) {
		std::string strValue = match.str();
		std::smatch matchValue;
		while (std::regex_search(strValue, matchValue, regexValue)) {
			std::string strTempValue = matchValue.str();
			// ����������ڵ�Ϊ�գ����Ϊ -1
			if (strTempValue == "null") vecBinaryTree.push_back(-1);
			else vecBinaryTree.push_back(std::atoi(strTempValue.c_str()));
			strValue = matchValue.suffix().str();
		}
	} else {
		return false;
	}
	// ���죺����ȡ���Ķ������ڵ�ֵ std::vector ת��Ϊ������
	return _MakeBinaryTree(vecBinaryTree);
}

// ���죺�� std::vector ת��Ϊ������
bool LeetCode::LCBinaryTree::_MakeBinaryTree(std::vector<int> vecBinaryTree)
{
	// ��⣺����Ϊ��ֱ�ӷ���
	if (vecBinaryTree.size() == 0) return true;
	// ��⣺Ԫ�س���һ������һ��Ԫ�ز���Ϊ null���� -1 ָ����
	if (vecBinaryTree.size() > 1 && vecBinaryTree[0] == -1) return false;
	// ��һ�����죺��ֵ
	for (auto val : vecBinaryTree) {
		LeetCode::TreeNode newTreeNode(val);
		m_vecBinaryTree.push_back(newTreeNode);
	}
	// �ڶ������죺ָ��i �����ӽڵ�Ӧ��Ϊ 2 * i + 1��i �����ӽڵ�Ϊ 2 * i + 2
	for (int i = 0; i < vecBinaryTree.size(); ++i) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < vecBinaryTree.size()) m_vecBinaryTree[i].left = &m_vecBinaryTree[left];
		else m_vecBinaryTree[i].left = nullptr;
		if (right < vecBinaryTree.size()) m_vecBinaryTree[i].right = &m_vecBinaryTree[right];
		else m_vecBinaryTree[i].right = nullptr;
	}
	// ���������죺ָ�� null ����ֵΪ -1 �Ľڵ㣩�Ľڵ���Ϊָ���� nullptr
	for (auto &node : m_vecBinaryTree) {
		if (node.left != nullptr && node.left->val == -1)
			node.left = nullptr;
		if (node.right != nullptr && node.right->val == -1)
			node.right = nullptr;
	}
	return true;
}

// ��ӡ����ӡһ���ڵ�
void LeetCode::LCBinaryTree::_PrintTreeNode(const TreeNode node, int depth, enum EPrintDirection eDirection) const
{
	int myDepth = depth;
	std::cout << "|";
	while (myDepth--) std::cout << "   ";
	switch (eDirection) 
	{
		case EPrintDirection_Root: std::cout << "---";
		break;
		case EPrintDirection_Left: std::cout << "L--";
		break;
		case EPrintDirection_Right:std::cout << "R--";
		break;
	}
	std::cout << node.val << std::endl;

	if (node.left != nullptr)
		_PrintTreeNode(*node.left, depth + 1, EPrintDirection_Left);
	if (node.right != nullptr)
		_PrintTreeNode(*node.right, depth + 1, EPrintDirection_Right);
}