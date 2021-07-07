#pragma once
//队列抽象类
#include <iostream>
using namespace std;

template<class T>
class Queue
{
public:
	Queue() {};			//构造函数
	~Queue() {};		//析构函数

	virtual bool IsEmpty() const = 0;			//是否为空
	//virtual bool IsFull() const = 0;			//是否满
	virtual T& getHead() const = 0;				//返回队首元素
	virtual T& getTail() const = 0;				//返回队尾元素
	virtual bool Insert(T& x) = 0;				//插入
	virtual bool Delete(T& x) = 0;				//删除队头
	virtual void print() = 0;					//打印队列
	virtual int getlength() const = 0;			//获得队列的长度
	//virtual void erase() = 0;					//清空队列

};
