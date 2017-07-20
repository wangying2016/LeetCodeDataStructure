#include <iostream>
#include <regex>
#include "../include/LCSingleLinkedList.h"

// 构造：输入 "[1, 2, 3, 4]" 类型的字符串
LeetCode::LCSingleLinkedList::LCSingleLinkedList(std::string strInput)
{
	if (!_ConstructSingleLinkedList(strInput)) {
		std::cerr << "LCSingleLinkedList: constructed error." << std::endl;
	}
}

LeetCode::LCSingleLinkedList::LCSingleLinkedList(const char* strInput)
{
	if (nullptr != strInput) {
		if (!_ConstructSingleLinkedList(std::string(strInput))) {
			std::cerr << "LCSingleLinkedList: constructed error." << std::endl;
		}
	}
}

// 析构
LeetCode::LCSingleLinkedList::~LCSingleLinkedList()
{
	m_vecSingleLinkedList.clear();
}

// 获取：单链表的根节点
const LeetCode::ListNode* LeetCode::LCSingleLinkedList::GetSingleLinkedListRoot() const
{
	return m_vecSingleLinkedList.size() == 0 ? nullptr : &m_vecSingleLinkedList[0];
}

// 打印：单链表内容
void LeetCode::LCSingleLinkedList::PrintSingleLinkedList() const
{
	if (m_vecSingleLinkedList.size() == 0)
		std::cout << "LCSingleLinkedList: empty." << std::endl;
	else {
		std::cout << "LCSingleLinkedList:" << std::endl << "[";
		for (int i = 0; i < m_vecSingleLinkedList.size(); ++i) {
			if (i != m_vecSingleLinkedList.size() - 1) 
				std::cout << " " << m_vecSingleLinkedList[i].val << ",";
			else std::cout << " " << m_vecSingleLinkedList[i].val << " ]" << std::endl;
		}
	}
}

// 构造：将字符串输入转化为单链表结构
// 正则：\[.*\[|\].*\]  [[ 和 ]]
// 正则：\[(\s*\d\s*[,]\s*)*\s*\d\s*\] 匹配 [1, 2, 3, 4, 5, 6]
// 正则：\d 匹配 1
bool LeetCode::LCSingleLinkedList::_ConstructSingleLinkedList(std::string strInput)
{
	std::string strTemp(strInput);
	std::smatch match;
	std::regex regexBracket("\\[.*\\[|\\].*\\]");
	std::regex regexString("\\[(\\s*\\d\\s*[,]\\s*)*\\s*\\d\\s*\\]");
	std::regex regexInteger("\\d");
	// 检测：如果匹配到了 [[ 或者 ]]，证明字符串不合理
	if (std::regex_search(strTemp, match, regexBracket)) {
		return false;
	}
	// 检测：如果匹配正确，则表示字符串合理
	std::vector<int> vecSingleLinkedList;
	strTemp = strInput;
	if (std::regex_search(strTemp, match, regexString)) {
		std::string strInteger = match.str();
		std::smatch matchInteger;
		while (std::regex_search(strInteger, matchInteger, regexInteger)) {
			std::string integerTemp = matchInteger.str();
			vecSingleLinkedList.push_back(std::atoi(integerTemp.c_str()));
			strInteger = matchInteger.suffix().str();
		}
	} else {
		return false;
	}
	// 构造：单链表
	return _MakeSingleLinkedList(vecSingleLinkedList);
}

// 构造：将 std::vector 转化为二叉树
bool LeetCode::LCSingleLinkedList::_MakeSingleLinkedList(std::vector<int> vecSingleLinkedList)
{
	// 第一步构造：赋值
	for (auto val : vecSingleLinkedList) {
		ListNode newListNode(val);
		m_vecSingleLinkedList.push_back(newListNode);
	}
	// 第二步构造：指向
	for (int i = 0; i < m_vecSingleLinkedList.size(); ++i) {
		if (i != m_vecSingleLinkedList.size() - 1)
			m_vecSingleLinkedList[i].next = &m_vecSingleLinkedList[i + 1];
		else
			m_vecSingleLinkedList[i].next = nullptr;
	}
	return true;
}