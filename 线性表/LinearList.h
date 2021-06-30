//线性表抽象类
#pragma once
#include <iostream>
using namespace std;

template<class T>
class LinearList
{
public:
	LinearList()
	{

	}; //构造函数

	virtual ~LinearList()
	{

	}; //析构函数

	virtual bool IsEmpty() const { return length == 0; } //判断是否为空

	virtual int Length() const { return length; } //返回长度

	virtual bool Find(int k, T& x) const = 0; //返回第K个元素

	virtual bool Delete(int k, T& x) = 0; //删除第k个元素并将他返回至x中

	virtual bool Insert(int k, const T& x) = 0; //在第K个元素之后插入x

	virtual void Output(ostream& out) const = 0;
protected:
	long length;
};