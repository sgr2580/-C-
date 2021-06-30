//����һ��ջ
//ɾ��һ��ջ
//�ж�ջ�Ƿ�Ϊ��
//ջ������һ��Ԫ��
//��ջ��Ԫ�ص�ֵ
//ɾ��ջ����һ��Ԫ��
//���ջ

#include <iostream>
#ifndef _STACK_H
#define _STACK_H
typedef unsigned int UINT;
using namespace std;


template<class T>
class stack;					//��Ԫ����ǰ����

template<class T>
class Node					//�ڵ���
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
	Stack(void);			//���캯�� ��ʼ��ջ
	~Stack(void);			//����ջ

	bool IsEmpty() const;		//�ж��Ƿ�Ϊ��
	void Clear();				//���ջ

	bool GetTop(T& x) const;			//�õ�ջ��Ԫ��
	UINT GetLength() const;		//����ջ�ĳ���
	bool Push(T& x);			//��ջ��ѹ������
	bool Pop(T& x);					//��ջ�����ݵ���
	void print();				//���ջ

private:
	Node<T>* top;			//ջ��ָ��
	UINT StackLen;	//ջ����
};

#endif