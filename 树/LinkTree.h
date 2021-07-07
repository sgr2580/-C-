#pragma
//二叉链表
#include <iostream>

using namespace std;

template<class T>
class LinkNode
{
	friend class LinkBinTree;		//友元
public:
	LinkNode()			//构造函数
	{
		LeftChild = RightChild = NULL;
	}
	LinkNode(constT &x)			//有参构造函数
	{
		LeftChild = RightChild = NULL;
		data = x;
	}
private:
	T data;
	LinkNode<T>* pLeftChlid;
	LinkNode<T>* pRightChlid;
};

template<class T>
class LinkBintree
{
public:
	LinkBintree();			//构造函数
	~LinkBintree();			//析构函数

	bool IsEmpty();								//判断是否为空
	LinkNode<T>* CreatRoot(const T& x);			//以指定元素值创建根节点
	void Clear();								//清空二叉树

	int GetDepth();												//获取深度
	LinkNode<T>* GetRoot();										//获取根节点
	//LinkNode<T>* Getnode();										//获取指定节点
	bool Getnodevalue(LinkNode<T>* pNode, const T& x);			//获取指定节点元素的值
	LinkNode<T>* GetLeftnode(LinkNode<T>* pNode);				//获取结点左孩子
	LinkNode<T>* GetRightnode(LinkNode<T>* pNode);				//获取结点右孩子
	LinkNode<T>* GetParent(LinkNode<T>* pNode);					//获取指定节点的双亲结点 非递归方式
	
	LinkNode<T>* InsertLeftChild(LinkNode<T>* pNode, const T& x);		//将一个结点作为指定结点的左孩子插入
	LinkNode<T>* InsertRightChild(LinkNode<T>* pNode, const T& x);		//将一个结点作为指定结点的右孩子插入
	void DeleteSubTree(LinkNode<T>* pNode);								//删除以指定节点为跟的子树
	void DeleteSubTreeNode(LinkNode<T>* pNode);							//由deletesubtree调用
	LinkNode<T>* SearchByKey(const T& x);								//按关键字查找结点
	bool ModifyNodeValue(LinkNode<T>* pNode, const T& x);				//修改指定节点的元素值


	//递归
	void PreOrderTraverse(LinkNode<T>* pNode);		//先序遍历
	void InOrderTraverse(LinkNode<T>* pNode);		//中序遍历
	void PostOrderTraverse(LinkNode<T>* pNode);		//后序遍历

	//非递归
	void PreOrderTraverse();	//先序遍历
	void InOrderTraverse();		//中序遍历
	void PostOrderTraverse();	//后序遍历
	void LevelOrderTraverse();	//逐层遍历
private:
	LinkNode<T>* Root; //指向根结点的指针
};