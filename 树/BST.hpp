#pragma
//��������� ������
#include <iostream>
#include "linkstack.h"
#include "NoMem.h"
#include "LinkQueue.hpp"
#include "BST.h"
#include "LinkTree.h"
#include "LinkTree.hpp"

using namespace std;


template<class T>
BST<T>::BST()									//���캯��
{
	Root = NULL;
}

//template<class T>
//BST<T>::BST(T R[], int nSize, LinkBinTree<T>& btree)									//�вι��캯��
//{
//	int n;
//	//��R�е�Ԫ����һ���뵽������������
//	for (n = 1; n < nSize; n++)
//		btree.InsertBST(R[n]);
//}

template<class T>
BST<T>::~BST()									//��������
{
	clear(Root);
	Root = NULL;
}

template<class T>
void BST<T>::Clear(BSTNode<T>* pNode)			//��ն�����
{
	if (pNode == NULL)
		return;
	Clear(pNode->pLeftChild);
	Clear(pNode->pRightChild);
	delete pNode;
}

template<class T>
bool BST<T>::IsEmpty()							//�Ƿ��
{
	return Root == NULL;
}

template<class T>
BSTNode<T>* BST<T>::GetRoot()					//��ȡ���ڵ�
{
	return Root;
}

template<class T>
BSTNode<T>* BST<T>::SearchByKey(const T& x)	//���ؼ��ֲ��ҽ��
{
	BSTNode<T>* pNode = Root;
	while (pNode != NULL)
	{
		if (x = pNode->data)
			return pNode;
		else if (x > pNode->data)
			pNode = pNode->pRightChild;
		else
			pNode = pNode->pLeftChild;
	}
	return NULL;
}

template<class T>
T* BST<T>::GetMaxData()		//��ȡ���ֵ
{
	if (IsEmpty())
		return NULL;
	BSTNode<T>* pNode = Root;
	while (pNode->pRightChild)
	{
		pNode = pRightChild;
	}
	return pNode->data;
}

template<class T>
T* BST<T>::GetMinData()		//��ȡ��Сֵ
{
	if (IsEmpty())
		return NULL;
	BSTNode<T>* pNode = Root;
	while (pNode->pLeftChild)
	{
		pNode = pLeftChild;
	}
	return pNode->data;
}


template<class T>
void BST<T>::InsertBST(const T& d)					//�����½ڵ�
{	
	BSTNode<T>* pNode = Root;
	BSTNode<T>* prev = NULL;
	//while (pNode != NULL)
	//{
	//	prev = pNode;
	//	if (d < pNode->data)
	//	{
	//		pNode = pNode->pLeftChild;
	//	}
	//	else
	//		pNode = pNode->pRightChild;
	//}
	if (Root == NULL)
	{
		Root = new BSTNode(d);
	}
	else
	{
		while (pNode != NULL)
		{
			prev = pNode;
			if (d < pNode->data)
			{
				pNode = pNode->pLeftChild;
			} 
			else
				pNode = pNode->pRightChild;
		}
		if (d < prev->data)
			prev->pLeftChild = new BSTNode(d);
		else
			prev->pRightChild = new BSTNode(d);
	}
}

template<class T>
BSTNode<T>* BST<T>::Delete(BSTNode<T>* pNode, T& d)							//ɾ��ָ���ڵ�
{	
	if (pNode == NULL)
		return NULL;
	if (d > pNode->data)
		pNode->pRightChild = Delete(pNode->pRightChild, d);		//ȥ������ɾ��
	else if (d < pNode->pLeftChild)
		pNode->pLeftChild = Delete(pNode->pLeftChild, d);		//ȥ������ɾ��
	else		//��ǰ�ڵ����Ҫɾ���Ľڵ�
	{
		if (!pNode->pLeftChild)
			return pNode->pRightChild; // ���1����ɾ���ڵ�������
		if (!pNode->pRightChild)
			return pNode->pLeftChild;  // ���2����ɾ���ڵ�������
		BSTNode<T>* node = pNode->pRightChild;         // ���3����ɾ���ڵ������Ӷ���
		while (pNode->pLeftChild)			//Ѱ����ɾ���ڵ�����������С����ڵ�
			node = node->pLeftChild;
		node->left = pNode->pLeftChild;    // ����ɾ���ڵ����������Ϊ��������������ڵ��������
		pNode = pNode->pRightChild;         // ��ɾ���ڵ��������������λ�ã��ڵ㱻ɾ��
	}
	return pNode;

	////���������
	//BSTNode<T>* pNode = Root;
	//BSTNode<T>* pFather = NULL;
	//if (Root == NULL)			//����
	//	return;

	//while (pNode != NULL && pNode->data != d)
	//{
	//	pFather = pNode;
	//	if (d > pNode->data)
	//		pNode = pNode->pRightChlid;
	//	else
	//		pNode = pNode->pLeftChlid;
	//}

	//if (pNode == NULL)	//û�ҵ��ڵ�
	//	return;

	//if (pNode->pLeftChlid != NULL && pNode->pRightChlid != NULL)	//�ڵ�����������
	//{
	//	BSTNode<T>* minP = pNode->pRightChlid;
	//	BSTNode<T>* minPfather = pNode;
	//	while (minP->pLeftChlid)				//�ҵ���������С�ĸ�Ҫɾ�Ľ���
	//	{
	//		minPfather = minP;
	//		minP = minP->pLeftChlid;			//��������С�Ŀ϶�����ڵ�
	//	}
	//	minP->pLeftChlid = pNode->pLeftChlid;
	//	pNode = pNode->pRightChlid;
	//	
	//}
}

template<class T>
int BST<T>::GetHeight(BSTNode<T>* pNode)			//��ø߶�
{
	if (pNode == NULL)
		return 0;
	int leftheight = GetHeight(pNode->pLeftChild);
	int rightheight = GetHeight(pNode->pRightChild);
	return max(leftheight, rightheight) + 1
}

template<class T>
void BST<T>::InOrderTraverse(BSTNode<T>* pNode)		//�������������
{
	if (pNode == NULL)
		return;
	InOrderTraverse(pNode->pLeftChild);
	cout << pNode->data << "";
	InOrderTraverse(pNode->pRightChild);
}