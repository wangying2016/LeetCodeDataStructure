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

// 获取：std::vector<int> 类型的数组
std::vector<int> LeetCode::LCArray::GetArray()
{
	return m_vecArray;
}

// 打印：数组内容
void LeetCode::LCArray::PrintArray()
{
	std::cout << "LCArray: [ ";
	for (size_t i = 0; i < m_vecArray.size() - 1; ++i)
		std::cout << m_vecArray[i] << ", ";
	if (m_vecArray.size() != 0)
		std::cout << m_vecArray[m_vecArray.size() - 1] << " ]" << std::endl;
}

// 构造：将字符串输入转化为 std::vector<int> 内置类型
// 正则：\[.*\[|\].*\]  [[ 和 ]]
// 正则：\[(\s*\d\s*[,]\s*)*\s*\d\s*\] 匹配 [1, 2, 3, 4, 5, 6]
// 正则：
bool LeetCode::LCArray::_ConstructArray(std::string strInput)
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