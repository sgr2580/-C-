#pragma once
#include "Queue.h"
#include "NoMem.h"
//��ʽ����

using namespace std;


template<class T>
class LinkQueue;			//��Ԫ����ǰ����

template<class T>
class LinkNode
{
public:
	friend class LinkQueue<T>;
	//LinkNode()			//���캯��
	//{
	//	next = NULL;
	//}
private:
	T data;
	LinkNode<T>* next;
};

template<class T>
class LinkQueue : public Queue<T>			//��ʾ��Queue������������
{
public:
	LinkQueue();			//���캯��

	~LinkQueue();							//��������

	bool IsEmpty() const;					//�Ƿ�Ϊ��

	//bool IsFull() const;					//�Ƿ���

	T& getHead() const;						//���ض���Ԫ��

	T& getTail() const;						//���ض�βԪ��

	bool Insert(T& x);						//����

	bool Delete(T& x);						//ɾ����ͷ

	void print();							//��ӡ����

	int getlength() const;					//��ö��еĳ���

	//void erase();							//��ն���

protected:
	int size;								// ��ǰ����
	LinkNode<T>* front;
	LinkNode<T>* rear;						//���еĶ�ͷ�Ͷ�βָ��
};


template<class T>
LinkQueue<T>::LinkQueue()			//���캯��
{
	front = NULL;
	rear = NULL;
	size = 0;
}

template<class T>
LinkQueue<T>::~LinkQueue()							//��������
{
	T x;
	while (front != NULL)
	{
		Delete(x);
	}
}

template<class T>
bool LinkQueue<T>::IsEmpty() const					//�Ƿ�Ϊ��
{
	return size == 0;
}

template<class T>
T& LinkQueue<T>::getHead() const						//���ض���Ԫ��
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
T& LinkQueue<T>::getTail() const						//���ض�βԪ��
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
bool LinkQueue<T>::Insert(T& x)						//���� ���
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
bool LinkQueue<T>::Delete(T& x)						//ɾ����ͷ ����
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
		delete p;					//ɾ����ͷ���
		size--;
		return true;
	}
}

template<class T>
void LinkQueue<T>::print()							//��ӡ����
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
//void LinkQueue<T>::print(ostream& out)							//��ӡ����
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
int LinkQueue<T>::getlength() const					//��ö��еĳ���
{
	return size;
}

//template<class T>
//void LinkQueue<T>::erase()							//��ն���
//{
//	
//}


//���ز��������<<
template<class T>
ostream& operator<<(ostream& out, const LinkQueue<T>& x)
{
	x.print(out);
	return out;
}