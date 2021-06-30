//���Ա������
#pragma once
#include <iostream>
using namespace std;

template<class T>
class LinearList
{
public:
	LinearList()
	{

	}; //���캯��

	virtual ~LinearList()
	{

	}; //��������

	virtual bool IsEmpty() const { return length == 0; } //�ж��Ƿ�Ϊ��

	virtual int Length() const { return length; } //���س���

	virtual bool Find(int k, T& x) const = 0; //���ص�K��Ԫ��

	virtual bool Delete(int k, T& x) = 0; //ɾ����k��Ԫ�ز�����������x��

	virtual bool Insert(int k, const T& x) = 0; //�ڵ�K��Ԫ��֮�����x

	virtual void Output(ostream& out) const = 0;
protected:
	long length;
};