#pragma once
#include "LinearList.h"
#include "NoMem.h"
#include <time.h>
using namespace std;

//做友元，需要提前声明
template<class T>
class LinearListLink;

template<class T>
class LinkNode
{
public:
	friend class LinearListLink<T>;
private:
	T data;
	LinkNode<T>* link;
};

template<class T>
class LinearListLink : public LinearList<T>
{
public:
	LinearListLink()
	{
		first = 0;
		last = first;
	}

	virtual ~LinearListLink(); //析构函数

	virtual bool IsEmpty() const
	{
		return first == 0;
	}

	virtual int Length() const;

	virtual bool Find(int k, T& x) const;

	virtual int Search(const T& x) const;

	virtual LinkNode<T>* GetNode(long i); //返回第i个结点

	virtual bool Delete(int k, T& x);

	virtual bool Insert(int k, const T& x);

	virtual void Output(ostream& out) const;

	///	virtual bool Get(LinkNode<T>* node, T& x); //获取结点值

	///	virtual bool Set(LinkNode<T>* node, T& x);//设置结点值

	///	virtual bool GetHead();//获得头结点指针

	//	LinearList<T>& changeSize(T* elementNew, int nlength, int max); //改变大小 ，节省空间


protected:
	LinkNode<T>* first; // 记录头指针
	LinkNode<T>* last;	 //记录尾指针
};


//析构函数
template<class T>
LinearListLink<T>::~LinearListLink()
{
	LinkNode<T>* next; // 表示下一个结点
	while (first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}

//确定链表的长度
template<class T>
int LinearListLink<T>::Length() const
{
	LinkNode<T>* current = first;
	int len = 0;
	while (current)
	{
		len++;
		current = current->link;
	}
	return len;
}

//搜索并获得元素算法
template<class T>
bool LinearListLink<T>::Find(int k, T& x) const
{
	if (k < 1)
	{
		return false;
	}
	LinkNode<T>* current = first;
	int index = 1;
	while (index < k && current)
	{
		current = current->link;
		index++;
	}
	if (current)
	{
		x = current->data;
		return true;
	}
	return false;
}

//搜索 --- 查找数据x ，若有返回X的位置，没有返回0
template<class T>
int LinearListLink<T>::Search(const T& x) const
{

	LinkNode<T>* p = first;
	int index = 1;
	for (index; p && p->data != x; index++)
	{
		p = p->link;
	}

	if (p)
	{
		return index;
	}
	return 0;
}


//返回第i个结点
template<class T>
LinkNode<T>* LinearListLink<T>::GetNode(long i)
{
	LinkNode<T>* p = first;
	int index = 1;
	while (index != i)
	{
		p = p->link;
	}
	return p;
}

//删除结点
template<class T>
bool LinearListLink<T>::Delete(int k, T& x)
{
	//不存在第k个元素
	if (k < 1 || !first)
	{
		throw OutOdBounds();
	}
	LinkNode<T>* p = first;


	//LinkNode<T>* q = first;
	//用q指向第k-1个元素
	//for (int index = 1; index < k - 1; index++)
	//{
	//	q = q->link;
	//}
	//p = q->link; //p指向了第k个元素
	//q->link = p->link; //删除操作
	//


	if (k == 1)
	{
		first = first->link; //k为第一个元素 直接删除即可。
	}
	else
	{
		LinkNode<T>* q = first; //用q指向第k-1个元素
		for (int index = 1; index < k - 1 && q; index++)
		{
			q = q->link;
		}

		if (!q && !q->link)	 //不存在
		{
			throw OutOdBounds();
		}
		p = q->link;
		if (p == last)
		{
			last = q;
		}
		q->link = p->link;
	}
	x = p->data;
	delete p;
	return true;
}

//插入
template<class T>
bool LinearListLink<T>::Insert(int k, const T& x)
{
	if (k < 0)
	{
		throw OutOdBounds();
		//不存在
	}
	LinkNode<T>* p = first;
	for (int i = 1; i < k && p; i++)
	{
		p = p->link;
	}
	if (k > 0 && !p)
	{
		throw OutOdBounds();//不存在
	}
	LinkNode<T>* y = new LinkNode<T>;
	y->data = x;
	if (k)
	{
		y->link = p->link;  //在P之后插入
		p->link = y;
	}
	else
	{
		y->link = first;
		first = y;
	}
	if (!y->link)
	{
		last = y;
	}
	return true;
}

//输出
template<class T>
void LinearListLink<T>::Output(ostream& out) const
{
	//将链表元素传送至输出流
	LinkNode<T>* current;
	for (current = first; current; current = current->link)
	{
		out << current->data << "";
	}
}
//重载
template<class T>
ostream& operator<<(ostream& out, const LinearListLink<T>& x)
{
	x.Output(out);
	return out;
}

////获取结点值
//template<class T>
//bool LinearListLink<T>::Get(LinkNode<T>* node, T& x)
//{
//
//}
//
////设置结点值
//template<class T>
//bool LinearListLink<T>::Set(LinkNode<T>* node, T& x)
//{
//
//}
//
////获得头结点指针
//template<class T>
//bool LinearListLink<T>::GetHead()
//{
//
//}

////改变大小，节省空间
//template<class T>
//inline LinearList<T>& LinearList<T>::changeSize(T* elementNew, int nlength, int max)