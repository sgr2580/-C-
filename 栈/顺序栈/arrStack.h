#pragma once
#ifndef STACK_ARRSTACK_H

//创建一个栈
//删除一个栈
//判断栈是否为空
//判断栈是否为满
//栈顶插入一个元素
//求栈顶元素的值
//删除栈顶的一个元素
//输出栈

#include <iostream>

#define STACK_ARRSTACK_H
typedef unsigned int UINT

using namespace std;

template <class T>
class arrStack
{
public:
	arrStack(int capacity);			//构造函数 初始化栈
	~arrStack(void);		//析构栈
	Destroy();				//删除栈

	bool IsEmpty() const;		//判断是否为空
	bool IsFull() const;		//判断是否为满
	void Clear();				//清空栈

	T& GetTop() const;			//得到栈顶元素
	UINT GetLength() const;		//返回栈的长度

	bool Push(T& data);			//往栈中压入数据
	void Expand();				//栈扩容
	bool Pop();					//将栈顶数据弹出
	void print();				//输出栈

private:
	int m_pTop;			//栈顶指针
	UINT m_nStackLen	//栈容量
	T* arr;				//数组arr
	
};

#endif