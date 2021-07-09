
#ifndef LINK_TREE_H
#define LINK_TREE_H
//������
#include <iostream>

using namespace std;

template<class T>
class LinkBintree;

template<class T>
class TLinkNode
{
	friend class LinkBintree<T>;		//��Ԫ
public:
	TLinkNode()			//���캯��
	{
		pLeftChild = pRightChild = NULL;
	}
	TLinkNode(const T &x)			//�вι��캯��
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
	LinkBintree(void)			//���캯��
	{
		Root = NULL;
	}
	~LinkBintree(void)			//��������
	{
		Clear();
	}

	bool IsEmpty();								//�ж��Ƿ�Ϊ��
	TLinkNode<T>* CreatRoot(const T& x);			//��ָ��Ԫ��ֵ�������ڵ�
	void Clear();								//��ն�����

	int GetDepth(TLinkNode<T>* pNode);												//��ȡ���
	TLinkNode<T>* GetRoot();										//��ȡ���ڵ�
	//TLinkNode<T>* Getnode();									//��ȡָ���ڵ�
	bool Getnodevalue(TLinkNode<T>* pNode, const T& x);			//��ȡָ���ڵ�Ԫ�ص�ֵ
	TLinkNode<T>* GetLeftnode(TLinkNode<T>* pNode);				//��ȡ�������
	TLinkNode<T>* GetRightnode(TLinkNode<T>* pNode);				//��ȡ����Һ���
	TLinkNode<T>* GetParent(TLinkNode<T>* pNode);					//��ȡָ���ڵ��˫�׽�� �ǵݹ鷽ʽ
	
	TLinkNode<T>* InsertLeftChild(TLinkNode<T>* pNode, const T& x);		//��һ�������Ϊָ���������Ӳ���
	TLinkNode<T>* InsertRightChild(TLinkNode<T>* pNode, const T& x);		//��һ�������Ϊָ�������Һ��Ӳ���
	void DeleteSubTree(TLinkNode<T>* pNode);								//ɾ����ָ���ڵ�Ϊ��������
	void DeleteSubTreeNode(TLinkNode<T>* pNode);							//��deletesubtree����
	TLinkNode<T>* SearchByKey(const T& x);								//���ؼ��ֲ��ҽ��
	bool ModifyNodeValue(TLinkNode<T>* pNode, const T& x);				//�޸�ָ���ڵ��Ԫ��ֵ


	//�ݹ�
	void PreOrderTraverse(TLinkNode<T>* pNode);		//�������
	void InOrderTraverse(TLinkNode<T>* pNode);		//�������
	void PostOrderTraverse(TLinkNode<T>* pNode);		//�������

	//�ǵݹ�
	void PreOrderTraverse();	//�������
	void InOrderTraverse();		//�������
	void PostOrderTraverse();	//�������
	void LevelOrderTraverse();	//������
private:
	TLinkNode<T>* Root; //ָ�������ָ��
};

#endif