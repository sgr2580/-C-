#pragma once
#include "LinearList.h"
#include "NoMem.h"
#include <time.h>
using namespace std;

template<class T>
class DoubleList;

template<class T>
class DoubleNode
{
public:
	friend class DoubleList<T>;
private:
	T data;
	DoubleNode<T>* prior, * next;
};

template<class T>
class DoubleList : public LinearList<T>
{
	//���캯��
	DoubleList()
	{
		//LeftEnd = 0;
	}

	//��������
	virtual ~DoubleList() {};

	//virtual bool IsEmpty() const { return length == 0; } //�ж��Ƿ�Ϊ��

	//virtual int Length() const { return length; } //���س���

	//virtual bool Find(int k, T& x) const = 0; //���ص�K��Ԫ��

	//virtual bool Delete(int k, T& x) = 0; //ɾ����k��Ԫ�ز�����������x��

	//virtual bool Insert(int k, const T& x) = 0; //�ڵ�K��Ԫ��֮�����x

	//virtual void Output(ostream& out) const = 0;

private:
	DoubleNode<T>* first, * last;

};

