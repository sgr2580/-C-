#pragma
//二叉链表
#include <iostream>
#include "LinkTree.h"
#include "linkstack.h"
#include "NoMem.h"

using namespace std;

template<class T>
LinkBintree<T>::LinkBintree()			//构造函数
{
	Root = NULL;			//将根节点的指针置为空
}

template<class T>
LinkBintree<T>::~LinkBintree()			//析构函数
{

}

template<class T>
bool LinkBintree<T>::IsEmpty()								//判断是否为空
{
	return Root == NULL;
}

template<class T>
LinkNode<T>* LinkBintree<T>::CreatRoot(const T& x)			//以指定元素值创建根节点
{
	if (Root != NULL)		//若原先存在根结点，直接将X赋给根结点
	{
		Root->data = x;
	}
	elsw					//否则，创建一个新的根节点  赋值为x
	{
		Root = new LinkNode<T>(x);
	}
	return Root;
}

template<class T>
void LinkBintree<T>::Clear()								//清空二叉树
{

}

template<class T>
int LinkBintree<T>::GetDepth()												//获取深度
{

}

template<class T>
LinkNode<T>* LinkBintree<T>::GetRoot()										//获取根节点
{
	return Root;
}

//template<class T>
//LinkNode<T>* LinkBintree<T>::Getnode()									//获取指定节点
//{
//
//}

template<class T>
bool LinkBintree<T>::Getnodevalue(LinkNode<T>* pNode, const T& x)			//获取指定节点元素的值
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
LinkNode<T>* LinkBintree<T>::GetLeftnode(LinkNode<T>* pNode)				//获取结点左孩子
{
	if (pNode == NULL)
	{
		return NULL;
	}
	else
	{
		return pNode->pLeftChlid;
	}
}

template<class T>
LinkNode<T>* LinkBintree<T>::GetRightnode(LinkNode<T>* pNode)				//获取结点右孩子
{
	if (pNode == NULL)
	{
		return NULL;
	}
	else
	{
		return pNode->pRightChlid;
	}
}

template<class T>
LinkNode<T>* LinkBintree<T>::GetParent(LinkNode<T>* pNode)					//获取指定节点的双亲结点 非递归方式
{

} 

template<class T>
LinkNode<T>* LinkBintree<T>::InsertLeftChild(LinkNode<T>* pNode, const T& x)		//将一个结点作为指定结点的左孩子插入
{
	LinkNode<T>* newNode;
	if (pNode == NULL)
	{
		return NULL;
	}
	 
	newNode = new LinkNode<T>(x);
	if (newNode == NULL)
		return NULL;
	pNode->pLeftChlid = newNode;
	return NewNode;
}

template<class T>
LinkNode<T>* LinkBintree<T>::InsertRightChild(LinkNode<T>* pNode, const T& x)		//将一个结点作为指定结点的右孩子插入
{
	LinkNode<T>* newNode;
	if (pNode == NULL)
	{
		return NULL;
	}

	newNode = new LinkNode<T>(x);
	if (newNode == NULL)
		return NULL;
	pNode->pRightChlid = newNode;
	return NewNode;
}

template<class T>
void LinkBintree<T>::DeleteSubTree(LinkNode<T>* pNode)								//删除以指定节点为跟的子树
{

}

template<class T>
void LinkBintree<T>::DeleteSubTreeNode(LinkNode<T>* pNode)							//由deletesubtree调用
{

}

template<class T>
LinkNode<T>* LinkBintree<T>::SearchByKey(const T& x)								//按关键字查找结点
{

}

template<class T>
bool LinkBintree<T>::ModifyNodeValue(LinkNode<T>* pNode, const T& x)				//修改指定节点的元素值
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
void LinkBintree<T>::PreOrderTraverse(LinkNode<T>* pNode)		//先序遍历
{
	if (pNode == NULL)
	{
		return;
	}
	else
	{
		cout << pNode->data << " ";
	}
	PreOrderTraverse(pNode->pLeftChlid);
	PreOrderTraverse(pNode->pRightChlid);
}

template<class T>
void LinkBintree<T>::InOrderTraverse(LinkNode<T>* pNode)		//中序遍历
{
	if (pNode == NULL)
	{
		return;
	}
	InOrderTraverse(pNode->pLeftChli  d);
	cout << pNode->data << "";
	InOrderTraverse(pNode->pRightChlld);
}

template<class T>
void LinkBintree<T>::PostOrderTraverse(LinkNode<T>* pNode)		//后序遍历
{

}


//非递归
template<class T>
void LinkBintree<T>::PreOrderTraverse()	//先序遍历
{
	Stack<LinkNode<T>*> s;
	LinkNode<T>* pNode; = NULL;

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
		if (pNode->pRightChlid)
		{
			s.Push(pNode->pRightChlid);
		}
		//若结点存在左子树，则将左子树根节点入栈
		if (pNode->pLeftChlid)
		{
			s.Push(pNode->pLeftChlid);
		}
	}
}

template<class T>
void LinkBintree<T>::InOrderTraverse()		//中序遍历
{

}

template<class T>
void LinkBintree<T>::PostOrderTraverse()	//后序遍历
{

}

template<class T>
void LinkBintree<T>::LevelOrderTraverse()	//逐层遍历
{

}