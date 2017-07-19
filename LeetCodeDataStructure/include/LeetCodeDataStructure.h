#ifndef _LEETCODE_DATA_STRUCTURE_H_
#	define _LEETCODE_DATA_STRUCTURE_H_

#ifdef LEETCODE_DATA_STRUCTURE_DLL
#	define LEETCODE_EXP __declspec(dllexport)
#else 
#	define LEETCODE_EXP __declspec(dllimport)
#endif

// 禁用 warning C4251: “xxx::m_strTypeName”: class“std::basic_string<_Elem,_Traits,_Ax>”需要有 dll 接口由 class“xxx”的客户端使用。
// 问题的警告显示，参考博客 (http://blog.sina.com.cn/s/blog_4fc2fb600102y4mu.html)
#pragma warning(disable:4251)

#include <vector>
#include <string>

namespace LeetCode {
	class LEETCODE_EXP LCArray;				// 数组
	class LEETCODE_EXP LCString;			// 字符串
	class LEETCODE_EXP LCSingleLinkedList;	// 单链表
	class LEETCODE_EXP LCBinaryTree;		// 二叉树
}

#endif