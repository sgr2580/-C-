#include <iostream>
#include "linkstack.h"
#include "NoMem.h"
#include <string>
#include "LinkTree.h"
#include "LinkTree.hpp"

using namespace std;

void test01()
{
	//测试一下二叉树
	try {
		TLinkNode<int>* pNode;
		LinkBintree<int> bTree;
		cout << bTree.IsEmpty() << endl;
		TLinkNode<int>* mRoot = bTree.CreatRoot(10);
		TLinkNode<int> * Node2 = bTree.InsertLeftChild(mRoot, 5);
		TLinkNode<int> * Node3 = bTree.InsertRightChild(mRoot, 15);
		
		bTree.PreOrderTraverse(mRoot);
		cout << endl;
		bTree.InOrderTraverse(mRoot);
		cout << endl;
		bTree.PostOrderTraverse(mRoot);
		cout << endl;
		TLinkNode<int>* Node4 = bTree.InsertLeftChild(Node2, 3);
		TLinkNode<int>* Node5 = bTree.InsertRightChild(Node2, 7);
		TLinkNode<int>* Node6 = bTree.InsertLeftChild(Node3, 12);
		TLinkNode<int>* Node7 = bTree.InsertRightChild(Node3, 17);
		bTree.InsertLeftChild(Node4, 2);
		bTree.InsertRightChild(Node4, 4);
		bTree.InsertLeftChild(Node5, 6);
		bTree.InsertRightChild(Node5, 8);
		bTree.InsertLeftChild(Node6, 11);
		bTree.InsertRightChild(Node6, 13);
		bTree.InsertLeftChild(Node7, 16);
		bTree.InsertRightChild(Node7, 18);
		bTree.PreOrderTraverse(mRoot);
		cout << endl;
		bTree.InOrderTraverse(mRoot);
		cout << endl;
		bTree.PostOrderTraverse(mRoot);
		cout << endl;
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}

void test02()
{
	//测试一下二叉排序树
	try {
		
	}
	catch (...)
	{
		cerr << "An exception has occurred" << endl;
	}
}

int main()
{
	test01();

	//test02();

	system("pause");
	return 0;
}