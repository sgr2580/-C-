#pragma once
#include "LinearList.h"
#include "NoMem.h"
#include <time.h>
using namespace std;

template<class T>
class LinearListSqu : public LinearList<T> //��ʾ��LinearList<T>������
{
public:
	//���캯��
	LinearListSqu(int MaxListSize = 10);

	//��������
	virtual ~LinearListSqu();
	//{
	//	if (element)
	//	{
	//		delete[] element;
	//	}
	//}

	//�ж��Ƿ�Ϊ��
	virtual bool IsEmpty() const;
	//{
	//	return length == 0;
	//}

	//���س���
	virtual int Length() const
	{
		return length;
	}

	//���ص�K��Ԫ��
	virtual bool Find(int k, T& x) const;

	//ɾ����k��Ԫ�ز�����������x��
	virtual bool Delete(int k, T& x);

	//����
	virtual bool Insert(int k, const T& x);

	//���
	virtual void Output(ostream& out) const;

protected:
	long length; // ���Ա�ǰ����
	long MaxSize;//��󳤶�
	T* element; //һά��̬���飬��Ԫ������Ϊ�ɱ�����T
};

//���캯��
template<class T>
LinearListSqu<T>::LinearListSqu(int MaxListSize)
{
	//���Ա�Ĺ��캯������ʼ�����Ա�
	MaxSize = MaxListSize;
	try
	{
		element = new T[MaxSize];
	}
	catch (...)
	{
		throw NoMem();
	}
	length = 0;
}

//��������
template<class T>
LinearListSqu<T>::~LinearListSqu()
{
	if (element)
	{
		delete[] element;
	}
}

//�ж��Ƿ�Ϊ��
template<class T>
bool LinearListSqu<T>::IsEmpty() const
{
	return length == 0;
}

//���س���
int LinearListSqu<int>::Length() const
{
	return length;
}

//���ص�K��Ԫ�أ��������ڷ���false ,���򷵻�true
template<class T>
bool LinearListSqu<T>::Find(int k, T& x) const
{
	if (k<1 || k>length)
	{
		return false;
	}
	x = element[k - 1];
	return true;
}

//ɾ����k��Ԫ�� ,������x��
template<class T>
bool LinearListSqu<T>::Delete(int k, T& x)
{
	////�쳣����
	//if (k<0 || k>length)
	//{
	//	throw OutOdBounds;
	//}
	//if (length == MaxSize)
	//{
	//	throw NoMem;
	//}

	//ɾ������
	if (Find(k, x))
	{
		for (int i = k; i < length; i++)
		{
			element[i - 1] = element[i];
		}
		length--;
		return true;
	}
	else
	{
		throw OutOdBounds();
	}
}

//�ڵ�k��Ԫ��֮�����x
template<class T>
bool LinearListSqu<T>::Insert(int k, const T& x)
{
	//�쳣����
	if (k<0 || k>length)
	{
		throw OutOdBounds();
	}
	if (length == MaxSize)
	{
		throw NoMem();
	}

	//�������
	for (int i = length - 1; i >= k; i--)
	{
		element[i + 1] = element[i];
	}
	element[k] = x;
	length++;
	return true;
}

//������� �� ���������<<����
template<class T>
void LinearListSqu<T>::Output(ostream& out) const
{
	for (int i = 0; i < length; i++)
	{
		out << element[i] << "";
	}
}
//����
template<class T>
ostream& operator<<(ostream& out, const LinearListSqu<T>& x)
{
	x.Output(out);
	return out;
}