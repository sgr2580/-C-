//创建一个栈
//删除一个栈
//判断栈是否为空
//栈顶插入一个元素
//求栈顶元素的值
//删除栈顶的一个元素
//输出栈

#include <iostream>
#ifndef _STACK_H
#define _STACK_H
typedef unsigned int UINT;
using namespace std;


template<class T>
class stack;					//友元。提前声明

template<class T>
class Node					//节点类
{
	friend class stack<T>;
public:
	T data;
	Node<T>* next;
};

template <class T>
class Stack
{
public:
	Stack(void);			//构造函数 初始化栈
	~Stack(void);			//析构栈

	bool IsEmpty() const;		//判断是否为空
	void Clear();				//清空栈

	bool GetTop(T& x) const;			//得到栈顶元素
	UINT GetLength() const;		//返回栈的长度
	bool Push(T& x);			//往栈中压入数据
	bool Pop(T& x);					//将栈顶数据弹出
	void print();				//输出栈

private:
	Node<T>* top;			//栈顶指针
	UINT StackLen;	//栈容量
};

#endif