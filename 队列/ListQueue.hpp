#pragma once
#include "Queue.h"
#include "NoMem.h"
//ѭ������
using namespace std;

template<class T>
class ListQueue : public Queue<T>			//��ʾ��Queue������������
{
public:
	ListQueue(int capacity = 10);			//���캯��

	~ListQueue();							//��������

	bool IsEmpty() const;					//�Ƿ�Ϊ��

	bool IsFull() const;					//�Ƿ���

	T& getHead() const;						//���ض���Ԫ��

	T& getTail() const;						//���ض�βԪ��

	bool Insert(T& x);						//����

	bool Delete(T& x);						//ɾ����ͷ

	void print();							//��ӡ����

	int getlength() const;					//��ö��еĳ���

	void erase();							//��ն���

protected:
	int size;			 // ��ǰ����
	int MaxSize;		//��󳤶�
	int front, rear;	//���еĶ�ͷ�Ͷ�βָ��
	T* element;			//һά��̬���飬��Ԫ������Ϊ�ɱ�����T
};


template<class T>
ListQueue<T>::ListQueue(int capacity)				//���캯��
{
	//��ʼ������
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
ListQueue<T>::~ListQueue()							//��������
{
	erase();
	delete[] element;
}

template<class T>
bool ListQueue<T>::IsEmpty() const					//�Ƿ�Ϊ��
{
	return size == 0;
}

template<class T>
bool ListQueue<T>::IsFull() const						//�Ƿ���
{
	return size == MaxSize;
}

template<class T>
T& ListQueue<T>::getHead() const						//���ض���Ԫ��
{
	cout << "front is : " << endl;
	return element[front];
}

template<class T>
T& ListQueue<T>::getTail() const						//���ض�βԪ��
{
	cout << "rear is : " << endl;
		return element[rear-1];
}

template<class T>
bool ListQueue<T>::Insert(T& x)						//����
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
bool ListQueue<T>::Delete(T& x)						//ɾ����ͷ --- ����
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
void ListQueue<T>::print()							//��ӡ����
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
int ListQueue<T>::getlength() const					//��ö��еĳ���
{
	return size;
}

template<class T>
void ListQueue<T>::erase()							//��ն���
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