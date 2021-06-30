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
arrStack<T>::~arrStack(void)			//����ջ
{
	Clear();
	delete[] arr;
	arr = NULL;
}

//template <class T>
//arrStack<T>::Destroy()				//ɾ��ջ
//{
//
//}

template <class T>
bool arrStack<T>::IsEmpty() const		//�ж��Ƿ�Ϊ��
{
	return m_pTop == -1;
}

template <class T>
bool arrStack<T>::IsFull() const		//�ж��Ƿ�Ϊ��
{
	return m_pTop + 1 == m_nStackLen;
}

template <class T>
void arrStack<T>::Clear()				//���ջ
{
	m_pTop = -1;
}

template <class T>
T& arrStack<T>::GetTop() const			//�õ�ջ��Ԫ��
{	
	if (!IsEmpty())
		return arr[m_pTop];
	else
		throw OutOfBounds();
}

template <class T>
UINT arrStack<T>::GetLength() const		//����ջ�ĳ���
{
		return m_nStackLen;
}

template <class T>
void arrStack<T>::Push(T& data)			//��ջ��ѹ������
{
	if (IsFull())
		Expand();
	m_pTop++;
	arr[m_pTop] = data;
	//cout << "����ɹ���" << endl;
}

template <class T>
void arrStack<T>::Expand()				//ջ����
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
bool arrStack<T>::Pop(T& x)					//��ջ�����ݵ���
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
void arrStack<T>::print()				//���ջ
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

//����
template<class T>
ostream& operator<<(ostream& out, const arrStack<T>& x)
{
	x.print(out);
	return out;
}