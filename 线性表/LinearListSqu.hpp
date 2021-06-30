#pragma once
#include "LinearList.h"
#include "NoMem.h"
#include <time.h>
using namespace std;

template<class T>
class LinearListSqu : public LinearList<T> //表示从LinearList<T>中派生
{
public:
	//构造函数
	LinearListSqu(int MaxListSize = 10);

	//析构函数
	virtual ~LinearListSqu();
	//{
	//	if (element)
	//	{
	//		delete[] element;
	//	}
	//}

	//判断是否为空
	virtual bool IsEmpty() const;
	//{
	//	return length == 0;
	//}

	//返回长度
	virtual int Length() const
	{
		return length;
	}

	//返回第K个元素
	virtual bool Find(int k, T& x) const;

	//删除第k个元素并将他返回至x中
	virtual bool Delete(int k, T& x);

	//插入
	virtual bool Insert(int k, const T& x);

	//输出
	virtual void Output(ostream& out) const;

protected:
	long length; // 线性表当前长度
	long MaxSize;//最大长度
	T* element; //一维动态数组，其元素类型为可变类型T
};

//构造函数
template<class T>
LinearListSqu<T>::LinearListSqu(int MaxListSize)
{
	//线性表的构造函数，初始化线性表
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

//析构函数
template<class T>
LinearListSqu<T>::~LinearListSqu()
{
	if (element)
	{
		delete[] element;
	}
}

//判断是否为空
template<class T>
bool LinearListSqu<T>::IsEmpty() const
{
	return length == 0;
}

//返回长度
int LinearListSqu<int>::Length() const
{
	return length;
}

//返回第K个元素，若不存在返回false ,否则返回true
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

//删除第k个元素 ,并返回x中
template<class T>
bool LinearListSqu<T>::Delete(int k, T& x)
{
	////异常处理
	//if (k<0 || k>length)
	//{
	//	throw OutOdBounds;
	//}
	//if (length == MaxSize)
	//{
	//	throw NoMem;
	//}

	//删除操作
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

//在第k个元素之后插入x
template<class T>
bool LinearListSqu<T>::Insert(int k, const T& x)
{
	//异常处理
	if (k<0 || k>length)
	{
		throw OutOdBounds();
	}
	if (length == MaxSize)
	{
		throw NoMem();
	}

	//插入操作
	for (int i = length - 1; i >= k; i--)
	{
		element[i + 1] = element[i];
	}
	element[k] = x;
	length++;
	return true;
}

//输出函数 与 输出流符号<<重载
template<class T>
void LinearListSqu<T>::Output(ostream& out) const
{
	for (int i = 0; i < length; i++)
	{
		out << element[i] << "";
	}
}
//重载
template<class T>
ostream& operator<<(ostream& out, const LinearListSqu<T>& x)
{
	x.Output(out);
	return out;
}