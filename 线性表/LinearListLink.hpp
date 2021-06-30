#pragma once
#include "LinearList.h"
#include "NoMem.h"
#include <time.h>
using namespace std;

//����Ԫ����Ҫ��ǰ����
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

	virtual ~LinearListLink(); //��������

	virtual bool IsEmpty() const
	{
		return first == 0;
	}

	virtual int Length() const;

	virtual bool Find(int k, T& x) const;

	virtual int Search(const T& x) const;

	virtual LinkNode<T>* GetNode(long i); //���ص�i�����

	virtual bool Delete(int k, T& x);

	virtual bool Insert(int k, const T& x);

	virtual void Output(ostream& out) const;

	///	virtual bool Get(LinkNode<T>* node, T& x); //��ȡ���ֵ

	///	virtual bool Set(LinkNode<T>* node, T& x);//���ý��ֵ

	///	virtual bool GetHead();//���ͷ���ָ��

	//	LinearList<T>& changeSize(T* elementNew, int nlength, int max); //�ı��С ����ʡ�ռ�


protected:
	LinkNode<T>* first; // ��¼ͷָ��
	LinkNode<T>* last;	 //��¼βָ��
};


//��������
template<class T>
LinearListLink<T>::~LinearListLink()
{
	LinkNode<T>* next; // ��ʾ��һ�����
	while (first)
	{
		next = first->link;
		delete first;
		first = next;
	}
}

//ȷ������ĳ���
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

//���������Ԫ���㷨
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

//���� --- ��������x �����з���X��λ�ã�û�з���0
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


//���ص�i�����
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

//ɾ�����
template<class T>
bool LinearListLink<T>::Delete(int k, T& x)
{
	//�����ڵ�k��Ԫ��
	if (k < 1 || !first)
	{
		throw OutOdBounds();
	}
	LinkNode<T>* p = first;


	//LinkNode<T>* q = first;
	//��qָ���k-1��Ԫ��
	//for (int index = 1; index < k - 1; index++)
	//{
	//	q = q->link;
	//}
	//p = q->link; //pָ���˵�k��Ԫ��
	//q->link = p->link; //ɾ������
	//


	if (k == 1)
	{
		first = first->link; //kΪ��һ��Ԫ�� ֱ��ɾ�����ɡ�
	}
	else
	{
		LinkNode<T>* q = first; //��qָ���k-1��Ԫ��
		for (int index = 1; index < k - 1 && q; index++)
		{
			q = q->link;
		}

		if (!q && !q->link)	 //������
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

//����
template<class T>
bool LinearListLink<T>::Insert(int k, const T& x)
{
	if (k < 0)
	{
		throw OutOdBounds();
		//������
	}
	LinkNode<T>* p = first;
	for (int i = 1; i < k && p; i++)
	{
		p = p->link;
	}
	if (k > 0 && !p)
	{
		throw OutOdBounds();//������
	}
	LinkNode<T>* y = new LinkNode<T>;
	y->data = x;
	if (k)
	{
		y->link = p->link;  //��P֮�����
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

//���
template<class T>
void LinearListLink<T>::Output(ostream& out) const
{
	//������Ԫ�ش����������
	LinkNode<T>* current;
	for (current = first; current; current = current->link)
	{
		out << current->data << "";
	}
}
//����
template<class T>
ostream& operator<<(ostream& out, const LinearListLink<T>& x)
{
	x.Output(out);
	return out;
}

////��ȡ���ֵ
//template<class T>
//bool LinearListLink<T>::Get(LinkNode<T>* node, T& x)
//{
//
//}
//
////���ý��ֵ
//template<class T>
//bool LinearListLink<T>::Set(LinkNode<T>* node, T& x)
//{
//
//}
//
////���ͷ���ָ��
//template<class T>
//bool LinearListLink<T>::GetHead()
//{
//
//}

////�ı��С����ʡ�ռ�
//template<class T>
//inline LinearList<T>& LinearList<T>::changeSize(T* elementNew, int nlength, int max)