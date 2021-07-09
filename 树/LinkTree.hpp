
//��������
#include <iostream>
#include "LinkTree.h"
#include "linkstack.h"
#include "NoMem.h"
#include "LinkQueue.hpp"

using namespace std;

//template<class T>
//LinkBintree<T>::LinkBintree()//���캯��
//{
//	Root = NULL;			//�����ڵ��ָ����Ϊ��
//}
//
//template<class T>
//LinkBintree<T>::~LinkBintree()//��������
//{
//	Clear();			//��ն������еĽ��
//}

template<class T>
bool LinkBintree<T>::IsEmpty()								//�ж��Ƿ�Ϊ��
{
	return Root == NULL;
}

template<class T>
TLinkNode<T>* LinkBintree<T>::CreatRoot(const T& x)			//��ָ��Ԫ��ֵ�������ڵ�
{
	if (Root != NULL)		//��ԭ�ȴ��ڸ���㣬ֱ�ӽ�X���������
	{
		Root->data = x;
	}
	else					//���򣬴���һ���µĸ��ڵ�  ��ֵΪx
	{
		Root = new TLinkNode<T>(x);
	}
	return Root;
}

template<class T>
void LinkBintree<T>::Clear()								//��ն�����
{
	DeleteSubTree(Root);
}


//��ȡ���
template<class T>
int LinkBintree<T>::GetDepth(TLinkNode<T>* pNode)			//�ݹ鷨�������������߶ȣ��ϴ�ļ�1
{
	if (pNode == NULL)
		return 0;
	int leftheitht = GetDepth(pNode->pLeftChild);
	int rightheitht = GetDepth(pNode->pRightChild);
	return max(leftheitht, rightheitht) + 1;
}

template<class T>
TLinkNode<T>* LinkBintree<T>::GetRoot()										//��ȡ���ڵ�
{
	return Root;
}

//template<class T>
//TLinkNode<T>* LinkBintree<T>::Getnode()									//��ȡָ���ڵ�
//{
//
//}

template<class T>
bool LinkBintree<T>::Getnodevalue(TLinkNode<T>* pNode, const T& x)			//��ȡָ���ڵ�Ԫ�ص�ֵ
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
TLinkNode<T>* LinkBintree<T>::GetLeftnode(TLinkNode<T>* pNode)				//��ȡ�������
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
TLinkNode<T>* LinkBintree<T>::GetRightnode(TLinkNode<T>* pNode)				//��ȡ����Һ���
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
TLinkNode<T>* LinkBintree<T>::GetParent(TLinkNode<T>* pNode)					//��ȡָ���ڵ��˫�׽�� �ǵݹ鷽ʽ
{
	LinkQueue<TLinkNode<T>*>q;
	TLinkNode<T>* ppNode = NULL;
	if (Root == pNode || Root == NULL)
	{
		cout << "���ڵ���˫��" << endl;
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
TLinkNode<T>* LinkBintree<T>::InsertLeftChild(TLinkNode<T>* pNode, const T& x)		//��һ�������Ϊָ���������Ӳ���
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
TLinkNode<T>* LinkBintree<T>::InsertRightChild(TLinkNode<T>* pNode, const T& x)		//��һ�������Ϊָ�������Һ��Ӳ���
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
void LinkBintree<T>::DeleteSubTree(TLinkNode<T>* pNode)								//ɾ����ָ���ڵ�Ϊ��������
{
	TLinkNode<T>* pParentNode = NULL;
	//��ָ�����Ϊ��
	if (pNode == NULL)
		return;
	//�������ö�����ɾ����������ڵ�Ϊ��
	if (Root == pNode)
		Root = NULL;
	//����ָ�����Ϊ��������ɾ�� ָ��������˫�׽�㣬�򽫸ý������ӻ����Һ����ÿ�
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
	//����ָ���ڵ㲻�Ƕ������еĽ�㣬ֱ�ӷ���
	else
		return;
	DeleteSubTreeNode(pNode);		//����DeleteSubTreeNodeɾ����pNodeΪ��������
}

template<class T>
void LinkBintree<T>::DeleteSubTreeNode(TLinkNode<T>* pNode)							//��deletesubtree����
{
	//���ǵݹ��α����ķ�ʽɾ������
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
TLinkNode<T>* LinkBintree<T>::SearchByKey(const T& x)								//���ؼ��ֲ��ҽ��
{
	LinkQueue<TLinkNode<T>*>q;
	TLinkNode<T>* pNode;
	if (Root == NULL)
		return NULL;

	//���ǵݹ鷽ʽ��α���������
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
bool LinkBintree<T>::ModifyNodeValue(TLinkNode<T>* pNode, const T& x)				//�޸�ָ���ڵ��Ԫ��ֵ
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


//�ݹ�
template<class T>
void LinkBintree<T>::PreOrderTraverse(TLinkNode<T>* pNode)		//�������
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
void LinkBintree<T>::InOrderTraverse(TLinkNode<T>* pNode)		//�������
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
void LinkBintree<T>::PostOrderTraverse(TLinkNode<T>* pNode)		//�������
{
	if (pNode == NULL)
	{
		return;
	}
	PostOrderTraverse(pNode->pLeftChild);
	PostOrderTraverse(pNode->pRightChild);
	cout << pNode->data << " ";
}

//�ǵݹ�
template<class T>
void LinkBintree<T>::PreOrderTraverse()	//�������
{
	Stack<TLinkNode<T>*> s;
	TLinkNode<T>* pNode = NULL;

	if (Root == NULL)
		return;
	//�����ڵ���ջ
	s.Push(Root);

	//ѭ������������
	while (!s.IsEmpty())
	{
		//ջ��Ԫ�س�ջ��������
		s.Pop(pNode);
		cout << pNode->data << " ";
		//���������������������������ڵ���ջ
		if (pNode->pRightChild)
		{
			s.Push(pNode->pRightChild);
		}
		//���������������������������ڵ���ջ
		if (pNode->pLeftChild)
		{
			s.Push(pNode->pLeftChild);
		}
	}
}

template<class T>
void LinkBintree<T>::InOrderTraverse()		//�������
{
	Stack<TLinkNode<T>*> s;
	TLinkNode<T>* pNode = NULL;

	if (Root == NULL)
		return;
	pNode = Root;

	//ѭ������������
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
void LinkBintree<T>::PostOrderTraverse()	//�������
{
	Stack<TLinkNode<T>*> s1;
	Stack<TLinkNode<T>*> s2;
	TLinkNode<T>* pNode;
	if (Root == NULL)
	{
		return;
	}
	//���ڵ�ѹ��s1
	s1.Push(Root);
	//ѭ������
	while (!s1.IsEmpty())
	{
		//���ڵ㵯����ѹ��s2
		s1.Pop(pNode);
		s2.Push(pNode);
		//�������Һ���ѹ��ջ
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
void LinkBintree<T>::LevelOrderTraverse()	//������
{
	LinkQueue<TLinkNode<T>*>q;
	TLinkNode<T>* pNode = NULL;
	if (Root == NULL)
	{
		return;
	}
	else
	{
		q.Insert(Root);						//�����ڵ����

		while (!q.IsEmpty())
		{
			//��ͷԪ�س�ջ��������
			q.Delete(pNode);
			cout << pNode->data << " ";

			//���������������������������ڵ���ջ
			if (pNode->pLeftChild)
			{
				q.Insert(pNode->pLeftChild);
			}
			//���������������������������ڵ���ջ
			if (pNode->pRightChild)
			{
				q.Insert(pNode->pRightChild);
			}	
		}
	}
}