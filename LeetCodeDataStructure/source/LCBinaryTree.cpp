#include <iostream>
#include <regex>
#include "../include/LCBinaryTree.h"


// 构造：输入 "[1, null, 2]" 类型的字符串
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

// 析构
LeetCode::LCBinaryTree::~LCBinaryTree()
{
	m_vecBinaryTree.clear();
}

// 获取：二叉树的根节点
const LeetCode::TreeNode* LeetCode::LCBinaryTree::GetTreeBinaryTreeRoot() const
{
	return m_vecBinaryTree.size() == 0 ? nullptr : &m_vecBinaryTree[0];
}

// 打印：二叉树内容
void LeetCode::LCBinaryTree::PrintBinaryTree() const
{
	if (m_vecBinaryTree.size() == 0)
		std::cout << "LCBinaryTree: empty." << std::endl;
	else {
		std::cout << "LCBinaryTree:" << std::endl;
		_PrintTreeNode(m_vecBinaryTree[0], 0, EPrintDirection_Root);
	}
}

// 构造：将字符串输入转化为二叉树结构
// 正则：\[.*\[|\].*\] 识别 [[ 和 ]]
// 正则：\[(\s*\d\s*,|\s*null\s*,)*(\s*\d\s*|\s*null\s*)\] 识别 [1, 2, 3, 4, null, 5]
// 正则：\d|null 识别 节点值
bool LeetCode::LCBinaryTree::_ConstructBinaryTree(std::string strInput)
{
	std::string strTemp(strInput);
	std::smatch match;
	std::regex regexBracket("\\[.*\\[|\\].*\\]");
	std::regex regexString("\\[(\\s*\\d\\s*,|\\s*null\\s*,)*(\\s*\\d\\s*|\\s*null\\s*)\\]");
	std::regex regexValue("\\d|null");
	// 检测：如果匹配到了 [[ 或者 ]]，证明字符串不合理
	if (std::regex_search(strTemp, match, regexBracket)) {
		return false;
	}
	// 检测：如果匹配正确，则表示字符串合理
	strTemp = strInput;
	std::vector<int> vecBinaryTree;
	if (std::regex_search(strTemp, match, regexString)) {
		std::string strValue = match.str();
		std::smatch matchValue;
		while (std::regex_search(strValue, matchValue, regexValue)) {
			std::string strTempValue = matchValue.str();
			// 特殊情况：节点为空，标记为 -1
			if (strTempValue == "null") vecBinaryTree.push_back(-1);
			else vecBinaryTree.push_back(std::atoi(strTempValue.c_str()));
			strValue = matchValue.suffix().str();
		}
	} else {
		return false;
	}
	// 构造：将获取到的二叉树节点值 std::vector 转换为二叉树
	return _MakeBinaryTree(vecBinaryTree);
}

// 构造：将 std::vector 转化为二叉树
bool LeetCode::LCBinaryTree::_MakeBinaryTree(std::vector<int> vecBinaryTree)
{
	// 检测：数组为空直接返回
	if (vecBinaryTree.size() == 0) return true;
	// 检测：元素超过一个，第一个元素不能为 null（用 -1 指代）
	if (vecBinaryTree.size() > 1 && vecBinaryTree[0] == -1) return false;
	// 第一步构造：赋值
	for (auto val : vecBinaryTree) {
		LeetCode::TreeNode newTreeNode(val);
		m_vecBinaryTree.push_back(newTreeNode);
	}
	// 第二步构造：指向，i 的左子节点应该为 2 * i + 1，i 的右子节点为 2 * i + 2
	for (int i = 0; i < vecBinaryTree.size(); ++i) {
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < vecBinaryTree.size()) m_vecBinaryTree[i].left = &m_vecBinaryTree[left];
		else m_vecBinaryTree[i].left = nullptr;
		if (right < vecBinaryTree.size()) m_vecBinaryTree[i].right = &m_vecBinaryTree[right];
		else m_vecBinaryTree[i].right = nullptr;
	}
	// 第三步构造：指向 null （即值为 -1 的节点）的节点认为指向了 nullptr
	for (auto &node : m_vecBinaryTree) {
		if (node.left != nullptr && node.left->val == -1)
			node.left = nullptr;
		if (node.right != nullptr && node.right->val == -1)
			node.right = nullptr;
	}
	return true;
}

// 打印：打印一个节点
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