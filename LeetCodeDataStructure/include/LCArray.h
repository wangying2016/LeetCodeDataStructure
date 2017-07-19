#include "LeetCodeDataStructure.h"

// ����
namespace LeetCode {

	class LEETCODE_EXP LCArray {
	public:
		// ���죺���� "[1, 2, 3, 4]" ���͵��ַ���
		LCArray();
		LCArray(std::string strInput);
		LCArray(const char* strInput);

		// ����
		~LCArray();

		// ��ȡ��std::vector<int> ���͵�����
		std::vector<int> GetArray();

		// ��ӡ����������
		void PrintArray();

	private:
		// ���죺���ַ�������ת��Ϊ std::vector<int> ��������
		bool _ConstructArray(std::string strInput);

	private:
		std::vector<int> m_vecArray;
	};

}