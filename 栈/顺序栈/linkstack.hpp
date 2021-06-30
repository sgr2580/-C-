//����һ��ջ
//ɾ��һ��ջ
//�ж�ջ�Ƿ�Ϊ��
//ջ������һ��Ԫ��
//��ջ��Ԫ�ص�ֵ
//ɾ��ջ����һ��Ԫ��
//���ջ

#include "linkstack.h"
#include <iostream>
#include "NoMem.h"

using namespace std;


template <class T>
Stack<T>::Stack()			//���캯�� ��ʼ��ջ
{
	top = NULL;
	StackLen = 0;
}

template <class T>
Stack<T>::~Stack()		//����ջ
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
bool Stack<T>::IsEmpty() const		//�ж��Ƿ�Ϊ��
{
	return top == NULL;
}

template <class T>
void Stack<T>::Clear()				//���ջ
{
	T x;
	while (top != NULL)
	{
		Pop(x);
	}
}

template <class T>
bool Stack<T>::GetTop(T& x) const			//�õ�ջ��Ԫ��
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
UINT Stack<T>::GetLength() const		//����ջ�ĳ���
{
	return StackLen;
}

template <class T>
bool Stack<T>::Push(T& x)			//��ջ��ѹ������
{
	Node<T>* p = new Node<T>;
	if (p == NULL)
		return false;
	else
	{
		p->data = x; //ΪԪ�ظ�ֵ
		p->next = top; //��Ԫ�ز���ջ��
		top = p; //topָ��ջ��
		StackLen++;
		return true;
	}
}

template <class T>
bool Stack<T>::Pop(T& x)					//��ջ�����ݵ���
{
	Node<T>* p;
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		x = top->data;
		p = top;			//�õ���ɾ���Ľ��
		top = top->next;  //ָ���µĽڵ�
		delete p;
		StackLen--;
		return true;
	}
}

template <class T>
void Stack<T>::print()				//���ջ
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

