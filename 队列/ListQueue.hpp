#pragma once
#include "Queue.h"
#include "NoMem.h"
//循环队列
using namespace std;

template<class T>
class ListQueue : public Queue<T>			//表示从Queue抽象类中派生
{
public:
	ListQueue(int capacity = 10);			//构造函数

	~ListQueue();							//析构函数

	bool IsEmpty() const;					//是否为空

	bool IsFull() const;					//是否满

	T& getHead() const;						//返回队首元素

	T& getTail() const;						//返回队尾元素

	bool Insert(T& x);						//插入

	bool Delete(T& x);						//删除队头

	void print();							//打印队列

	int getlength() const;					//获得队列的长度

	void erase();							//清空队列

protected:
	int size;			 // 当前长度
	int MaxSize;		//最大长度
	int front, rear;	//队列的队头和队尾指针
	T* element;			//一维动态数组，其元素类型为可变类型T
};


template<class T>
ListQueue<T>::ListQueue(int capacity)				//构造函数
{
	//初始化队列
	MaxSize = capacity;
	try
	{
		element = new T[MaxSize];
	}
	catch (...)
	{
		throw NoMem();
	}
	front = 0;
	rear = 0;
	size = 0;
}

template<class T>
ListQueue<T>::~ListQueue()							//析构函数
{
	erase();
	delete[] element;
}

template<class T>
bool ListQueue<T>::IsEmpty() const					//是否为空
{
	return size == 0;
}

template<class T>
bool ListQueue<T>::IsFull() const						//是否满
{
	return size == MaxSize;
}

template<class T>
T& ListQueue<T>::getHead() const						//返回队首元素
{
	cout << "front is : " << endl;
	return element[front];
}

template<class T>
T& ListQueue<T>::getTail() const						//返回队尾元素
{
	cout << "rear is : " << endl;
		return element[rear-1];
}

template<class T>
bool ListQueue<T>::Insert(T& x)						//插入
{
	if (IsFull())
	{
		cout << "The queue is full!" << endl;
		return false;
	}
	else
	{
		element[rear] = x;
		rear = (rear + 1) % MaxSize;
		size++;
		return true;
	}
}

template<class T>
bool ListQueue<T>::Delete(T& x)						//删除队头 --- 出队
{
	if (IsEmpty())
	{
		cout << "The queue is empty!" << endl;
		return false;
	}
	else
	{
		x = element[front];
		front = (front + 1) % MaxSize;
		size--;
		return true;
	}
}

template<class T>
void ListQueue<T>::print()							//打印队列
{
	if (IsEmpty())
	{
		cout << "The queue is empty!" << endl;
	}
	else
	{
		int index = front;

		cout << "Queue from head to tail as follow: " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "No." << i + 1 << " elem is " << element[index] << endl;
			index = (index + 1) % MaxSize;
		}
		cout << "--------------print end----------------" << endl;
	}
}

template<class T>
int ListQueue<T>::getlength() const					//获得队列的长度
{
	return size;
}

template<class T>
void ListQueue<T>::erase()							//清空队列
{
	if (IsEmpty())
	{
		cout << "The queue is empty!" << endl;
	}
	else
	{
		front = 0;
		rear = 0;
		size = 0;
	}
}