#include <iostream>
#include <regex>
#include <cstdlib>
#include "../include/LCArray.h"

LeetCode::LCArray::LCArray()
{

}

LeetCode::LCArray::LCArray(std::string strInput)
{
	if (!_ConstructArray(strInput)) {
		std::cerr << "LCArray: contruct error." << std::endl;
	}
}

LeetCode::LCArray::LCArray(const char* strInput)
{
	if (nullptr != strInput) {
		if (!_ConstructArray(std::string(strInput))) {
			std::cerr << "LCArray: contruct error." << std::endl;
		}
	}
}

LeetCode::LCArray::~LCArray()
{
	m_vecArray.clear();
}

// ��ȡ��std::vector<int> ���͵�����
std::vector<int> LeetCode::LCArray::GetArray()
{
	return m_vecArray;
}

// ��ӡ����������
void LeetCode::LCArray::PrintArray()
{
	std::cout << "LCArray: [ ";
	for (size_t i = 0; i < m_vecArray.size() - 1; ++i)
		std::cout << m_vecArray[i] << ", ";
	if (m_vecArray.size() != 0)
		std::cout << m_vecArray[m_vecArray.size() - 1] << " ]" << std::endl;
}

// ���죺���ַ�������ת��Ϊ std::vector<int> ��������
// ����\[.*\[|\].*\]  [[ �� ]]
// ����\[(\s*\d\s*[,]\s*)*\s*\d\s*\] ƥ�� [1, 2, 3, 4, 5, 6]
// ����
bool LeetCode::LCArray::_ConstructArray(std::string strInput)
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
	strTemp = strInput;
	if (std::regex_search(strTemp, match, regexString)) {
		std::string strInteger = match.str();
		std::smatch matchInteger;
		while (std::regex_search(strInteger, matchInteger, regexInteger)) {
			std::string integerTemp = matchInteger.str();
			m_vecArray.push_back(std::atoi(integerTemp.c_str()));
			strInteger = matchInteger.suffix().str();
		}
		return true;
	} else {
		return false;
	}
} 