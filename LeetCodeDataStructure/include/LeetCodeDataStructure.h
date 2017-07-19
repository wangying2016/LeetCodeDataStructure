#ifndef _LEETCODE_DATA_STRUCTURE_H_
#	define _LEETCODE_DATA_STRUCTURE_H_

#ifdef LEETCODE_DATA_STRUCTURE_DLL
#	define LEETCODE_EXP __declspec(dllexport)
#else 
#	define LEETCODE_EXP __declspec(dllimport)
#endif

// ���� warning C4251: ��xxx::m_strTypeName��: class��std::basic_string<_Elem,_Traits,_Ax>����Ҫ�� dll �ӿ��� class��xxx���Ŀͻ���ʹ�á�
// ����ľ�����ʾ���ο����� (http://blog.sina.com.cn/s/blog_4fc2fb600102y4mu.html)
#pragma warning(disable:4251)

#include <vector>
#include <string>

namespace LeetCode {
	class LEETCODE_EXP LCArray;				// ����
	class LEETCODE_EXP LCString;			// �ַ���
	class LEETCODE_EXP LCSingleLinkedList;	// ������
	class LEETCODE_EXP LCBinaryTree;		// ������
}

#endif