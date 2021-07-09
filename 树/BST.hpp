#pragma
//二叉查找树 排序树
#include <iostream>
#include "linkstack.h"
#include "NoMem.h"
#include "LinkQueue.hpp"
#include "BST.h"
#include "LinkTree.h"
#include "LinkTree.hpp"

using namespace std;


template<class T>
BST<T>::BST()									//构造函数
{
	Root = NULL;
}

//template<class T>
//BST<T>::BST(T R[], int nSize, LinkBinTree<T>& btree)									//有参构造函数
//{
//	int n;
//	//将R中的元素逐一插入到二叉排序树中
//	for (n = 1; n < nSize; n++)
//		btree.InsertBST(R[n]);
//}

template<class T>
BST<T>::~BST()									//析构函数
{
	clear(Root);
	Root = NULL;
}

template<class T>
void BST<T>::Clear(BSTNode<T>* pNode)			//清空二叉树
{
	if (pNode == NULL)
		return;
	Clear(pNode->pLeftChild);
	Clear(pNode->pRightChild);
	delete pNode;
}

template<class T>
bool BST<T>::IsEmpty()							//是否空
{
	return Root == NULL;
}

template<class T>
BSTNode<T>* BST<T>::GetRoot()					//获取根节点
{
	return Root;
}

template<class T>
BSTNode<T>* BST<T>::SearchByKey(const T& x)	//按关键字查找结点
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
T* BST<T>::GetMaxData()		//获取最大值
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
T* BST<T>::GetMinData()		//获取最小值
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
void BST<T>::InsertBST(const T& d)					//插入新节点
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
BSTNode<T>* BST<T>::Delete(BSTNode<T>* pNode, T& d)							//删除指定节点
{	
	if (pNode == NULL)
		return NULL;
	if (d > pNode->data)
		pNode->pRightChild = Delete(pNode->pRightChild, d);		//去右子树删除
	else if (d < pNode->pLeftChild)
		pNode->pLeftChild = Delete(pNode->pLeftChild, d);		//去左子树删除
	else		//当前节点就是要删除的节点
	{
		if (!pNode->pLeftChild)
			return pNode->pRightChild; // 情况1，欲删除节点无左子
		if (!pNode->pRightChild)
			return pNode->pLeftChild;  // 情况2，欲删除节点无右子
		BSTNode<T>* node = pNode->pRightChild;         // 情况3，欲删除节点左右子都有
		while (pNode->pLeftChild)			//寻找欲删除节点右子树的最小的左节点
			node = node->pLeftChild;
		node->left = pNode->pLeftChild;    // 将欲删除节点的左子树成为其右子树的最左节点的左子树
		pNode = pNode->pRightChild;         // 欲删除节点的右子树顶替其位置，节点被删除
	}
	return pNode;

	////分三种情况
	//BSTNode<T>* pNode = Root;
	//BSTNode<T>* pFather = NULL;
	//if (Root == NULL)			//空树
	//	return;

	//while (pNode != NULL && pNode->data != d)
	//{
	//	pFather = pNode;
	//	if (d > pNode->data)
	//		pNode = pNode->pRightChlid;
	//	else
	//		pNode = pNode->pLeftChlid;
	//}

	//if (pNode == NULL)	//没找到节点
	//	return;

	//if (pNode->pLeftChlid != NULL && pNode->pRightChlid != NULL)	//节点有俩个孩子
	//{
	//	BSTNode<T>* minP = pNode->pRightChlid;
	//	BSTNode<T>* minPfather = pNode;
	//	while (minP->pLeftChlid)				//找到右子树最小的跟要删的交换
	//	{
	//		minPfather = minP;
	//		minP = minP->pLeftChlid;			//右子树最小的肯定在左节点
	//	}
	//	minP->pLeftChlid = pNode->pLeftChlid;
	//	pNode = pNode->pRightChlid;
	//	
	//}
}

template<class T>
int BST<T>::GetHeight(BSTNode<T>* pNode)			//获得高度
{
	if (pNode == NULL)
		return 0;
	int leftheight = GetHeight(pNode->pLeftChild);
	int rightheight = GetHeight(pNode->pRightChild);
	return max(leftheight, rightheight) + 1
}

template<class T>
void BST<T>::InOrderTraverse(BSTNode<T>* pNode)		//中序遍历，有序
{
	if (pNode == NULL)
		return;
	InOrderTraverse(pNode->pLeftChild);
	cout << pNode->data << "";
	InOrderTraverse(pNode->pRightChild);
}