#pragma once
#include "Queue.h"
#include "NoMem.h"
//链式队列

using namespace std;


template<class T>
class LinkQueue;			//友元，提前声明

template<class T>
class LinkNode
{
public:
	friend class LinkQueue<T>;
	//LinkNode()			//构造函数
	//{
	//	next = NULL;
	//}
private:
	T data;
	LinkNode<T>* next;
};

template<class T>
class LinkQueue : public Queue<T>			//表示从Queue抽象类中派生
{
public:
	LinkQueue();			//构造函数

	~LinkQueue();							//析构函数

	bool IsEmpty() const;					//是否为空

	//bool IsFull() const;					//是否满

	T& getHead() const;						//返回队首元素

	T& getTail() const;						//返回队尾元素

	bool Insert(T& x);						//插入

	bool Delete(T& x);						//删除队头

	void print();							//打印队列

	int getlength() const;					//获得队列的长度

	//void erase();							//清空队列

protected:
	int size;								// 当前长度
	LinkNode<T>* front;
	LinkNode<T>* rear;						//队列的队头和队尾指针
};


template<class T>
LinkQueue<T>::LinkQueue()			//构造函数
{
	front = NULL;
	rear = NULL;
	size = 0;
}

template<class T>
LinkQueue<T>::~LinkQueue()							//析构函数
{
	T x;
	while (front != NULL)
	{
		Delete(x);
	}
}

template<class T>
bool LinkQueue<T>::IsEmpty() const					//是否为空
{
	return size == 0;
}

template<class T>
T& LinkQueue<T>::getHead() const						//返回队首元素
{
	if (IsEmpty())
	{
		cout << " the queue is empty ! " << endl;
		return front->data;
	}
	else
	{
		return front->data;
	}

}

template<class T>
T& LinkQueue<T>::getTail() const						//返回队尾元素
{
	if (IsEmpty())
	{
		cout << " the queue is empty ! " << endl;
		return rear->data;
	}
	else
	{
		return rear->data;
	}

}

template<class T>
bool LinkQueue<T>::Insert(T& x)						//插入 入队
{
	LinkNode<T>* p = new LinkNode<T>;
	if (p == NULL)
	{
		return false;
	}
	else
	{
		p->data = x;
		if (front == NULL)
		{
			front = p;
		}
		else
		{
			rear->next = p;
		}
		rear = p;
		size++;
		return true;
	}

}

template<class T>
bool LinkQueue<T>::Delete(T& x)						//删除队头 出队
{
	LinkNode<T>* p;
	if (IsEmpty())
	{
		return false;
	}
	else
	{
		p = front;
		x = front->data;
		front = front->next;
		delete p;					//删除队头结点
		size--;
		return true;
	}
}

template<class T>
void LinkQueue<T>::print()							//打印队列
{
	LinkNode<T>* p;
	cout << "----   print all the queue :   ----" << endl;
	p = front;
	for (int i = 0; i < size; i++)
	{
		cout << "No." << i + 1 << " :" << p->data << endl;
		p = p->next;
	}
	cout << "------------------------------------" << endl;
}

//template<class T>
//void LinkQueue<T>::print(ostream& out)							//打印队列
//{
//	LinkNode<T>* p;
//	cout << "----   print all the queue :   ----" << endl;
//	p = front;
//	for (int i = 0; i < size; i++)
//	{
//		out << p->data << endl;
//		p = p->next;
//	}
//	cout << "------------------------------------" << endl;
//}

template<class T>
int LinkQueue<T>::getlength() const					//获得队列的长度
{
	return size;
}

//template<class T>
//void LinkQueue<T>::erase()							//清空队列
//{
//	
//}


//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out, const LinkQueue<T>& x)
{
	x.print(out);
	return out;
}