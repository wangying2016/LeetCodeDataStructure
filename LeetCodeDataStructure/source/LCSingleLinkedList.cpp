#include <iostream>
#include <regex>
#include "../include/LCSingleLinkedList.h"

// ���죺���� "[1, 2, 3, 4]" ���͵��ַ���
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

// ����
LeetCode::LCSingleLinkedList::~LCSingleLinkedList()
{
	m_vecSingleLinkedList.clear();
}

// ��ȡ��������ĸ��ڵ�
const LeetCode::ListNode* LeetCode::LCSingleLinkedList::GetSingleLinkedListRoot() const
{
	return m_vecSingleLinkedList.size() == 0 ? nullptr : &m_vecSingleLinkedList[0];
}

// ��ӡ������������
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

// ���죺���ַ�������ת��Ϊ������ṹ
// ����\[.*\[|\].*\]  [[ �� ]]
// ����\[(\s*\d\s*[,]\s*)*\s*\d\s*\] ƥ�� [1, 2, 3, 4, 5, 6]
// ����\d ƥ�� 1
bool LeetCode::LCSingleLinkedList::_ConstructSingleLinkedList(std::string strInput)
{
	std::string strTemp(strInput);
	std::smatch match;
	std::regex regexBracket("\\[.*\\[|\\].*\\]");
	std::regex regexString("\\[(\\s*\\d\\s*[,]\\s*)*\\s*\\d\\s*\\]");
	std::regex regexInteger("\\d");
	// ��⣺���ƥ�䵽�� [[ ���� ]]��֤���ַ���������
	if (std::regex_search(strTemp, match, regexBracket)) {
		return false;
	}
	// ��⣺���ƥ����ȷ�����ʾ�ַ�������
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
	// ���죺������
	return _MakeSingleLinkedList(vecSingleLinkedList);
}

// ���죺�� std::vector ת��Ϊ������
bool LeetCode::LCSingleLinkedList::_MakeSingleLinkedList(std::vector<int> vecSingleLinkedList)
{
	// ��һ�����죺��ֵ
	for (auto val : vecSingleLinkedList) {
		ListNode newListNode(val);
		m_vecSingleLinkedList.push_back(newListNode);
	}
	// �ڶ������죺ָ��
	for (int i = 0; i < m_vecSingleLinkedList.size(); ++i) {
		if (i != m_vecSingleLinkedList.size() - 1)
			m_vecSingleLinkedList[i].next = &m_vecSingleLinkedList[i + 1];
		else
			m_vecSingleLinkedList[i].next = nullptr;
	}
	return true;
}