#pragma

#include <iostream>
#include "LinkTree.h"

using namespace std;

template<class T>
class BST;

template<class T>
class BSTNode
{
	friend class BST<T>;
public:
	BSTNode()
	{
		pLeftChild = NULL;
		pRightChild = NULL;
	}
	BSTNode(const T& d, BSTNode<T>* l = NULL, BSTNode<T>* r = NULL)
	{
		data = d;   left = l;   right = r;
	}
private:
	T data;
	BSTNode<T>* pLeftChild;
	BSTNode<T>* pRightChild;
};

template<class T>
class BST
{
public:
	BST();									//���캯��
	//BST(T R[],int nSize,LinkBinTree<T> &btree);	//�вι��캯�� ���ɶ���������
	~BST();									//��������

	void Clear(BSTNode<T>* pNode);			//��ն�����
	bool IsEmpty();							//�Ƿ��
	BSTNode<T>* GetRoot();					//��ȡ���ڵ�
	BSTNode<T>* SearchByKey(const T& x);	//���ؼ��ֲ��ҽ��
	T* GetMaxData();		//��ȡ���ֵ
	T* GetMinData();		//��ȡ��Сֵ

	void InsertBST(const T& d);				//����
	BSTNode<T>* Delete(BSTNode<T>* Root, T& d);	//ɾ��
	int GetHeight(BSTNode<T>* pNode);		//��ø߶�

	void InOrderTraverse(BSTNode<T>* pNode);					//�������������
private:
	BSTNode<T>* Root;
	int Nodelen;
};