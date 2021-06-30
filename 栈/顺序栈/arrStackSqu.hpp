//
//creat by sgr on 2021/6/30
//

#include "arrStack.h"
#include <iostream>
#include "NoMem.h"

using namespace std;

template <class T>
arrStack<T>::arrStack(int capacity)
{
	m_nStackLen = capacity;
	arr = new T[capacity];
	if (arr == NULL)
		throw NoMem();
	m_pTop = -1;
}

template <class T>
arrStack<T>::~arrStack(void)			//析构栈
{
	Clear();
	delete[] arr;
	arr = NULL;
}

//template <class T>
//arrStack<T>::Destroy()				//删除栈
//{
//
//}

template <class T>
bool arrStack<T>::IsEmpty() const		//判断是否为空
{
	return m_pTop == -1;
}

template <class T>
bool arrStack<T>::IsFull() const		//判断是否为满
{
	return m_pTop + 1 == m_nStackLen;
}

template <class T>
void arrStack<T>::Clear()				//清空栈
{
	m_pTop = -1;
}

template <class T>
T& arrStack<T>::GetTop() const			//得到栈顶元素
{	
	if (!IsEmpty())
		return arr[m_pTop];
	else
		throw OutOfBounds();
}

template <class T>
UINT arrStack<T>::GetLength() const		//返回栈的长度
{
		return m_nStackLen;
}

template <class T>
void arrStack<T>::Push(T& data)			//往栈中压入数据
{
	if (IsFull())
		Expand();
	m_pTop++;
	arr[m_pTop] = data;
	//cout << "插入成功！" << endl;
}

template <class T>
void arrStack<T>::Expand()				//栈扩容
{
	m_nStackLen = 2 * m_nStackLen;
	T* temparr = new T[m_nStackLen];
	for (int i = 0; i <= m_pTop; i++)
	{
		temparr[i] = arr[i];
	}
	T* temp = arr;
	arr = temparr;
	temparr = temp;
	delete[] temparr;
	temparr = NULL;
}

template <class T>
bool arrStack<T>::Pop(T& x)					//将栈顶数据弹出
{
	if (!IsEmpty())
	{
		x = arr[m_pTop];
		m_pTop--;
		cout << "x_value: " << x << endl;
		return true;
	}
	else
	{
		throw OutOfBounds();
	}
		
}

template <class T>
void arrStack<T>::print()				//输出栈
{
	if (!IsEmpty())
	{
		cout << "----arrstack top----" << endl;
			for (int i = m_pTop; i >= 0; i--)
			{
				cout << "No." << i << " elem: " << arr[i] << endl;
			}
		cout << "----arrstack bottom----" << endl;
	}	
	else
	{
		cout << "the stack is empty!" << endl;
	}
}

//重载
template<class T>
ostream& operator<<(ostream& out, const arrStack<T>& x)
{
	x.print(out);
	return out;
}