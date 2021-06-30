#pragma once
#ifndef STACK_ARRSTACK_H

//����һ��ջ
//ɾ��һ��ջ
//�ж�ջ�Ƿ�Ϊ��
//�ж�ջ�Ƿ�Ϊ��
//ջ������һ��Ԫ��
//��ջ��Ԫ�ص�ֵ
//ɾ��ջ����һ��Ԫ��
//���ջ

#include <iostream>

#define STACK_ARRSTACK_H
typedef unsigned int UINT

using namespace std;

template <class T>
class arrStack
{
public:
	arrStack(int capacity);			//���캯�� ��ʼ��ջ
	~arrStack(void);		//����ջ
	Destroy();				//ɾ��ջ

	bool IsEmpty() const;		//�ж��Ƿ�Ϊ��
	bool IsFull() const;		//�ж��Ƿ�Ϊ��
	void Clear();				//���ջ

	T& GetTop() const;			//�õ�ջ��Ԫ��
	UINT GetLength() const;		//����ջ�ĳ���

	bool Push(T& data);			//��ջ��ѹ������
	void Expand();				//ջ����
	bool Pop();					//��ջ�����ݵ���
	void print();				//���ջ

private:
	int m_pTop;			//ջ��ָ��
	UINT m_nStackLen	//ջ����
	T* arr;				//����arr
	
};

#endif