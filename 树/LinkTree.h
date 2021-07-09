
#ifndef LINK_TREE_H
#define LINK_TREE_H
//二叉树
#include <iostream>

using namespace std;

template<class T>
class LinkBintree;

template<class T>
class TLinkNode
{
	friend class LinkBintree<T>;		//友元
public:
	TLinkNode()			//构造函数
	{
		pLeftChild = pRightChild = NULL;
	}
	TLinkNode(const T &x)			//有参构造函数
	{
		pLeftChild = pRightChild = NULL;
		data = x;
	}
private:
	T data;
	TLinkNode<T>* pLeftChild;
	TLinkNode<T>* pRightChild;
};

template<class T>
class LinkBintree
{
public:
	LinkBintree(void)			//构造函数
	{
		Root = NULL;
	}
	~LinkBintree(void)			//析构函数
	{
		Clear();
	}

	bool IsEmpty();								//判断是否为空
	TLinkNode<T>* CreatRoot(const T& x);			//以指定元素值创建根节点
	void Clear();								//清空二叉树

	int GetDepth(TLinkNode<T>* pNode);												//获取深度
	TLinkNode<T>* GetRoot();										//获取根节点
	//TLinkNode<T>* Getnode();									//获取指定节点
	bool Getnodevalue(TLinkNode<T>* pNode, const T& x);			//获取指定节点元素的值
	TLinkNode<T>* GetLeftnode(TLinkNode<T>* pNode);				//获取结点左孩子
	TLinkNode<T>* GetRightnode(TLinkNode<T>* pNode);				//获取结点右孩子
	TLinkNode<T>* GetParent(TLinkNode<T>* pNode);					//获取指定节点的双亲结点 非递归方式
	
	TLinkNode<T>* InsertLeftChild(TLinkNode<T>* pNode, const T& x);		//将一个结点作为指定结点的左孩子插入
	TLinkNode<T>* InsertRightChild(TLinkNode<T>* pNode, const T& x);		//将一个结点作为指定结点的右孩子插入
	void DeleteSubTree(TLinkNode<T>* pNode);								//删除以指定节点为跟的子树
	void DeleteSubTreeNode(TLinkNode<T>* pNode);							//由deletesubtree调用
	TLinkNode<T>* SearchByKey(const T& x);								//按关键字查找结点
	bool ModifyNodeValue(TLinkNode<T>* pNode, const T& x);				//修改指定节点的元素值


	//递归
	void PreOrderTraverse(TLinkNode<T>* pNode);		//先序遍历
	void InOrderTraverse(TLinkNode<T>* pNode);		//中序遍历
	void PostOrderTraverse(TLinkNode<T>* pNode);		//后序遍历

	//非递归
	void PreOrderTraverse();	//先序遍历
	void InOrderTraverse();		//中序遍历
	void PostOrderTraverse();	//后序遍历
	void LevelOrderTraverse();	//逐层遍历
private:
	TLinkNode<T>* Root; //指向根结点的指针
};

#endif