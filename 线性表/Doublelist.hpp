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
	//构造函数
	DoubleList()
	{
		//LeftEnd = 0;
	}

	//析构函数
	virtual ~DoubleList() {};

	//virtual bool IsEmpty() const { return length == 0; } //判断是否为空

	//virtual int Length() const { return length; } //返回长度

	//virtual bool Find(int k, T& x) const = 0; //返回第K个元素

	//virtual bool Delete(int k, T& x) = 0; //删除第k个元素并将他返回至x中

	//virtual bool Insert(int k, const T& x) = 0; //在第K个元素之后插入x

	//virtual void Output(ostream& out) const = 0;

private:
	DoubleNode<T>* first, * last;

};

