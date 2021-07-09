
//二叉链表
#include <iostream>
#include "LinkTree.h"
#include "linkstack.h"
#include "NoMem.h"
#include "LinkQueue.hpp"

using namespace std;

//template<class T>
//LinkBintree<T>::LinkBintree()//构造函数
//{
//	Root = NULL;			//将根节点的指针置为空
//}
//
//template<class T>
//LinkBintree<T>::~LinkBintree()//析构函数
//{
//	Clear();			//清空二叉树中的结点
//}

template<class T>
bool LinkBintree<T>::IsEmpty()								//判断是否为空
{
	return Root == NULL;
}

template<class T>
TLinkNode<T>* LinkBintree<T>::CreatRoot(const T& x)			//以指定元素值创建根节点
{
	if (Root != NULL)		//若原先存在根结点，直接将X赋给根结点
	{
		Root->data = x;
	}
	else					//否则，创建一个新的根节点  赋值为x
	{
		Root = new TLinkNode<T>(x);
	}
	return Root;
}

template<class T>
void LinkBintree<T>::Clear()								//清空二叉树
{
	DeleteSubTree(Root);
}


//获取深度
template<class T>
int LinkBintree<T>::GetDepth(TLinkNode<T>* pNode)			//递归法，求左右子树高度，较大的加1
{
	if (pNode == NULL)
		return 0;
	int leftheitht = GetDepth(pNode->pLeftChild);
	int rightheitht = GetDepth(pNode->pRightChild);
	return max(leftheitht, rightheitht) + 1;
}

template<class T>
TLinkNode<T>* LinkBintree<T>::GetRoot()										//获取根节点
{
	return Root;
}

//template<class T>
//TLinkNode<T>* LinkBintree<T>::Getnode()									//获取指定节点
//{
//
//}

template<class T>
bool LinkBintree<T>::Getnodevalue(TLinkNode<T>* pNode, const T& x)			//获取指定节点元素的值
{
	if (pNode == NULL)
	{
		return false;
	}
	else
	{
		x = pNode->data;
		return true;
	}
}

template<class T>
TLinkNode<T>* LinkBintree<T>::GetLeftnode(TLinkNode<T>* pNode)				//获取结点左孩子
{
	if (pNode == NULL)
	{
		return NULL;
	}
	else
	{
		return pNode->pLeftChild;
	}
}

template<class T>
TLinkNode<T>* LinkBintree<T>::GetRightnode(TLinkNode<T>* pNode)				//获取结点右孩子
{
	if (pNode == NULL)
	{
		return NULL;
	}
	else
	{
		return pNode->pRightChild;
	}
}

template<class T>
TLinkNode<T>* LinkBintree<T>::GetParent(TLinkNode<T>* pNode)					//获取指定节点的双亲结点 非递归方式
{
	LinkQueue<TLinkNode<T>*>q;
	TLinkNode<T>* ppNode = NULL;
	if (Root == pNode || Root == NULL)
	{
		cout << "根节点无双亲" << endl;
		return NULL;
	}
	else
	{
		q.Insert(Root);
		while (!q.IsEmpty())
		{
			q.Delete(ppNode);

			if (ppNode->pLeftChild == pNode || ppNode->pRightChild == pNode)
			{
				return ppNode;
			}
			
			if (ppNode->pLeftChild)
				q.Insert(ppNode->pLeftChild);
			if (ppNode->pRightChild)
				q.Insert(ppNode->pRightChild);
		}
		return NULL;
	}
} 

template<class T>
TLinkNode<T>* LinkBintree<T>::InsertLeftChild(TLinkNode<T>* pNode, const T& x)		//将一个结点作为指定结点的左孩子插入
{
	TLinkNode<T>* newNode;
	if (pNode == NULL)
	{
		return NULL;
	}
	 
	newNode = new TLinkNode<T>(x);
	if (newNode == NULL)
		return NULL;
	pNode->pLeftChild = newNode;
	return newNode;
}

template<class T>
TLinkNode<T>* LinkBintree<T>::InsertRightChild(TLinkNode<T>* pNode, const T& x)		//将一个结点作为指定结点的右孩子插入
{
	TLinkNode<T>* newNode;
	if (pNode == NULL)
	{
		return NULL;
	}

	newNode = new TLinkNode<T>(x);
	if (newNode == NULL)
		return NULL;
	pNode->pRightChild = newNode;
	return newNode;
}

template<class T>
void LinkBintree<T>::DeleteSubTree(TLinkNode<T>* pNode)								//删除以指定节点为跟的子树
{
	TLinkNode<T>* pParentNode = NULL;
	//若指定结点为空
	if (pNode == NULL)
		return;
	//若将整棵二叉树删除，则令根节点为空
	if (Root == pNode)
		Root = NULL;
	//若将指定结点为根的子树删除 指定结点存在双亲结点，则将该结点的左孩子或者右孩子置空
	else if ((pParentNode = GetParent(pNode)) != NULL)
	{
		if (pParentNode->pLeftChild == pNode)
		{
			pParentNode->pLeftChild = NULL;
		}
		else
		{
			pParentNode->pRightChild = NULL;
		}
	}
	//否则，指定节点不是二叉树中的结点，直接返回
	else
		return;
	DeleteSubTreeNode(pNode);		//调用DeleteSubTreeNode删除以pNode为根的子树
}

template<class T>
void LinkBintree<T>::DeleteSubTreeNode(TLinkNode<T>* pNode)							//由deletesubtree调用
{
	//按非递归层次遍历的方式删除子树
	LinkQueue<TLinkNode<T>*>q;
	TLinkNode<T>* ppNode;

	if (pNode == NULL)
		return;
	q.Insert(pNode);
	
	while (!q.IsEmpty())
	{
		q.Delete(ppNode);
		if (ppNode->pLeftChild)
			q.Insert(ppNode->pLeftChild);
		if (ppNode->pRightChild)
			q.Insert(ppNode->pRightChild);
		delete ppNode;
	}
}

template<class T>
TLinkNode<T>* LinkBintree<T>::SearchByKey(const T& x)								//按关键字查找结点
{
	LinkQueue<TLinkNode<T>*>q;
	TLinkNode<T>* pNode;
	if (Root == NULL)
		return NULL;

	//按非递归方式层次遍历二叉树
	q.Insert(Root);

	while (!IsEmpty())
	{
		q.Delete(pNode);
		if (pNode->data == x)
			return pNode;

		if (pNode->pLeftChild)
			q.Insert(pNode->pLeftChild);
		if (pNode->pRightChild)
			q.Insert(pNode->pRightChild);
	}
	return NULL;
}

template<class T>
bool LinkBintree<T>::ModifyNodeValue(TLinkNode<T>* pNode, const T& x)				//修改指定节点的元素值
{
	if (pNode == NULL)
	{
		return false;
	}
	else
	{
		pNode->data = x;
		return true;
	}
}


//递归
template<class T>
void LinkBintree<T>::PreOrderTraverse(TLinkNode<T>* pNode)		//先序遍历
{
	if (pNode == NULL)
	{
		return;
	}
	else
	{
		cout << pNode->data << " ";
	}
	PreOrderTraverse(pNode->pLeftChild);
	PreOrderTraverse(pNode->pRightChild);
}

template<class T>
void LinkBintree<T>::InOrderTraverse(TLinkNode<T>* pNode)		//中序遍历
{
	if (pNode == NULL)
	{
		return;
	}
	InOrderTraverse(pNode->pLeftChild);
	cout << pNode->data << " ";
	InOrderTraverse(pNode->pRightChild);
}

template<class T>
void LinkBintree<T>::PostOrderTraverse(TLinkNode<T>* pNode)		//后序遍历
{
	if (pNode == NULL)
	{
		return;
	}
	PostOrderTraverse(pNode->pLeftChild);
	PostOrderTraverse(pNode->pRightChild);
	cout << pNode->data << " ";
}

//非递归
template<class T>
void LinkBintree<T>::PreOrderTraverse()	//先序遍历
{
	Stack<TLinkNode<T>*> s;
	TLinkNode<T>* pNode = NULL;

	if (Root == NULL)
		return;
	//将根节点入栈
	s.Push(Root);

	//循环遍历二叉树
	while (!s.IsEmpty())
	{
		//栈顶元素出栈并被访问
		s.Pop(pNode);
		cout << pNode->data << " ";
		//若结点存在右子树，则将右子树根节点入栈
		if (pNode->pRightChild)
		{
			s.Push(pNode->pRightChild);
		}
		//若结点存在左子树，则将左子树根节点入栈
		if (pNode->pLeftChild)
		{
			s.Push(pNode->pLeftChild);
		}
	}
}

template<class T>
void LinkBintree<T>::InOrderTraverse()		//中序遍历
{
	Stack<TLinkNode<T>*> s;
	TLinkNode<T>* pNode = NULL;

	if (Root == NULL)
		return;
	pNode = Root;

	//循环遍历二叉树
	while (!s.IsEmpty())
	{
		if (pNode || !IsEmpty())
		{
			s.Push(pNode);
			pNode = pNode->pLeftChild;
		}
		else
		{
			s.Pop(pNode);
			cout << pNode->data << " ";
			pNode = pNode->pRightChild;
		}
	}
}

template<class T>
void LinkBintree<T>::PostOrderTraverse()	//后序遍历
{
	Stack<TLinkNode<T>*> s1;
	Stack<TLinkNode<T>*> s2;
	TLinkNode<T>* pNode;
	if (Root == NULL)
	{
		return;
	}
	//根节点压入s1
	s1.Push(Root);
	//循环遍历
	while (!s1.IsEmpty())
	{
		//将节点弹出并压入s2
		s1.Pop(pNode);
		s2.Push(pNode);
		//将左孩子右孩子压入栈
		if (pNode->pLeftChild)
		{
			s1.Push(pNode->pLeftChild);
		}
		if (pNode->pRightChild)
		{
			s1.Push(pNode->pRightChild);
		}
	}
	while (!s2.IsEmpty())
	{
		s2.Pop(pNode);
		cout << pNode->data << " ";
	}
}

template<class T>
void LinkBintree<T>::LevelOrderTraverse()	//逐层遍历
{
	LinkQueue<TLinkNode<T>*>q;
	TLinkNode<T>* pNode = NULL;
	if (Root == NULL)
	{
		return;
	}
	else
	{
		q.Insert(Root);						//将根节点入队

		while (!q.IsEmpty())
		{
			//队头元素出栈并被访问
			q.Delete(pNode);
			cout << pNode->data << " ";

			//若结点存在左子树，则将左子树根节点入栈
			if (pNode->pLeftChild)
			{
				q.Insert(pNode->pLeftChild);
			}
			//若结点存在右子树，则将右子树根节点入栈
			if (pNode->pRightChild)
			{
				q.Insert(pNode->pRightChild);
			}	
		}
	}
}