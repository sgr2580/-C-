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
	BST();									//构造函数
	//BST(T R[],int nSize,LinkBinTree<T> &btree);	//有参构造函数 生成二叉排序树
	~BST();									//析构函数

	void Clear(BSTNode<T>* pNode);			//清空二叉树
	bool IsEmpty();							//是否空
	BSTNode<T>* GetRoot();					//获取根节点
	BSTNode<T>* SearchByKey(const T& x);	//按关键字查找结点
	T* GetMaxData();		//获取最大值
	T* GetMinData();		//获取最小值

	void InsertBST(const T& d);				//插入
	BSTNode<T>* Delete(BSTNode<T>* Root, T& d);	//删除
	int GetHeight(BSTNode<T>* pNode);		//获得高度

	void InOrderTraverse(BSTNode<T>* pNode);					//中序遍历，有序
private:
	BSTNode<T>* Root;
	int Nodelen;
};