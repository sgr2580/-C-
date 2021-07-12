#pragma once
//���г�����
#include <iostream>
using namespace std;

template<class T>
class Queue
{
public:
	Queue() {};			//���캯��
	~Queue() {};		//��������

	virtual bool IsEmpty() const = 0;			//�Ƿ�Ϊ��
	//virtual bool IsFull() const = 0;			//�Ƿ���
	virtual T& getHead() const = 0;				//���ض���Ԫ��
	virtual T& getTail() const = 0;				//���ض�βԪ��
	virtual bool Insert(T& x) = 0;				//����
	virtual bool Delete(T& x) = 0;				//ɾ����ͷ
	virtual void print() = 0;					//��ӡ����
	virtual int getlength() const = 0;			//��ö��еĳ���
	//virtual void erase() = 0;					//��ն���

};
