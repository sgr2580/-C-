//创建一个栈
//删除一个栈
//判断栈是否为空
//栈顶插入一个元素
//求栈顶元素的值
//删除栈顶的一个元素
//输出栈

#include "linkstack.h"
#include <iostream>
#include "NoMem.h"

using namespace std;


template <class T>
Stack<T>::Stack()			//构造函数 初始化栈
{
	top = NULL;
	StackLen = 0;
}

template <class T>
Stack<T>::~Stack()		//析构栈
{
	//Clear();
	//top = NULL;
	T x;
	while (top != NULL)
	{
		Pop(x);
	}
}
						
template <class T>
bool Stack<T>::IsEmpty() const		//判断是否为空
{
	return top == NULL;
}

template <class T>
void Stack<T>::Clear()				//清空栈
{
	T x;
	while (top != NULL)
	{
		Pop(x);
	}
}

template <class T>
bool Stack<T>::GetTop(T& x) const			//得到栈顶元素
{
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		x = top->data;
		return true;
	}
}

template <class T>
UINT Stack<T>::GetLength() const		//返回栈的长度
{
	return StackLen;
}

template <class T>
bool Stack<T>::Push(T& x)			//往栈中压入数据
{
	Node<T>* p = new Node<T>;
	if (p == NULL)
		return false;
	else
	{
		p->data = x; //为元素赋值
		p->next = top; //新元素插入栈顶
		top = p; //top指向栈顶
		StackLen++;
		return true;
	}
}

template <class T>
bool Stack<T>::Pop(T& x)					//将栈顶数据弹出
{
	Node<T>* p;
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		x = top->data;
		p = top;			//得到待删除的结点
		top = top->next;  //指向新的节点
		delete p;
		StackLen--;
		return true;
	}
}

template <class T>
void Stack<T>::print()				//输出栈
{	
	Node<T>* temp = top;
	cout << "----stack top----" << endl;
	for (int i = 0; i < StackLen; i++)
	{
		cout << "No." << i + 1 << " elem :" << temp->data << endl;
		temp = temp->next;
	}
	cout << "----stack bottom----" << endl;

	//cout << "----stack top----" << endl;
	//for (int i = 0; i < StackLen; i++)
	//{
	//	out << p->data << endl;
	//	temp = temp->next;
	//}
	//cout << "----stack bottom----" << endl;
}

template <class T>
ostream& operator<<(ostream& out, const Node<T>& x)
{
	x.print(out);
	return out;
}

