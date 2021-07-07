#pragma
//��������
#include <iostream>
#include "LinkTree.h"
#include "linkstack.h"
#include "NoMem.h"

using namespace std;

template<class T>
LinkBintree<T>::LinkBintree()			//���캯��
{
	Root = NULL;			//�����ڵ��ָ����Ϊ��
}

template<class T>
LinkBintree<T>::~LinkBintree()			//��������
{

}

template<class T>
bool LinkBintree<T>::IsEmpty()								//�ж��Ƿ�Ϊ��
{
	return Root == NULL;
}

template<class T>
LinkNode<T>* LinkBintree<T>::CreatRoot(const T& x)			//��ָ��Ԫ��ֵ�������ڵ�
{
	if (Root != NULL)		//��ԭ�ȴ��ڸ���㣬ֱ�ӽ�X���������
	{
		Root->data = x;
	}
	elsw					//���򣬴���һ���µĸ��ڵ�  ��ֵΪx
	{
		Root = new LinkNode<T>(x);
	}
	return Root;
}

template<class T>
void LinkBintree<T>::Clear()								//��ն�����
{

}

template<class T>
int LinkBintree<T>::GetDepth()												//��ȡ���
{

}

template<class T>
LinkNode<T>* LinkBintree<T>::GetRoot()										//��ȡ���ڵ�
{
	return Root;
}

//template<class T>
//LinkNode<T>* LinkBintree<T>::Getnode()									//��ȡָ���ڵ�
//{
//
//}

template<class T>
bool LinkBintree<T>::Getnodevalue(LinkNode<T>* pNode, const T& x)			//��ȡָ���ڵ�Ԫ�ص�ֵ
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
LinkNode<T>* LinkBintree<T>::GetLeftnode(LinkNode<T>* pNode)				//��ȡ�������
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
LinkNode<T>* LinkBintree<T>::GetRightnode(LinkNode<T>* pNode)				//��ȡ����Һ���
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
LinkNode<T>* LinkBintree<T>::GetParent(LinkNode<T>* pNode)					//��ȡָ���ڵ��˫�׽�� �ǵݹ鷽ʽ
{

} 

template<class T>
LinkNode<T>* LinkBintree<T>::InsertLeftChild(LinkNode<T>* pNode, const T& x)		//��һ�������Ϊָ���������Ӳ���
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
LinkNode<T>* LinkBintree<T>::InsertRightChild(LinkNode<T>* pNode, const T& x)		//��һ�������Ϊָ�������Һ��Ӳ���
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
void LinkBintree<T>::DeleteSubTree(LinkNode<T>* pNode)								//ɾ����ָ���ڵ�Ϊ��������
{

}

template<class T>
void LinkBintree<T>::DeleteSubTreeNode(LinkNode<T>* pNode)							//��deletesubtree����
{

}

template<class T>
LinkNode<T>* LinkBintree<T>::SearchByKey(const T& x)								//���ؼ��ֲ��ҽ��
{

}

template<class T>
bool LinkBintree<T>::ModifyNodeValue(LinkNode<T>* pNode, const T& x)				//�޸�ָ���ڵ��Ԫ��ֵ
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
void LinkBintree<T>::PreOrderTraverse(LinkNode<T>* pNode)		//�������
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
void LinkBintree<T>::InOrderTraverse(LinkNode<T>* pNode)		//�������
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
void LinkBintree<T>::PostOrderTraverse(LinkNode<T>* pNode)		//�������
{

}


//�ǵݹ�
template<class T>
void LinkBintree<T>::PreOrderTraverse()	//�������
{
	Stack<LinkNode<T>*> s;
	LinkNode<T>* pNode; = NULL;

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
		if (pNode->pRightChlid)
		{
			s.Push(pNode->pRightChlid);
		}
		//���������������������������ڵ���ջ
		if (pNode->pLeftChlid)
		{
			s.Push(pNode->pLeftChlid);
		}
	}
}

template<class T>
void LinkBintree<T>::InOrderTraverse()		//�������
{

}

template<class T>
void LinkBintree<T>::PostOrderTraverse()	//�������
{

}

template<class T>
void LinkBintree<T>::LevelOrderTraverse()	//������
{

}