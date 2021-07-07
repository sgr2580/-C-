#pragma
//��������
#include <iostream>

using namespace std;

template<class T>
class LinkNode
{
	friend class LinkBinTree;		//��Ԫ
public:
	LinkNode()			//���캯��
	{
		LeftChild = RightChild = NULL;
	}
	LinkNode(constT &x)			//�вι��캯��
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
	LinkBintree();			//���캯��
	~LinkBintree();			//��������

	bool IsEmpty();								//�ж��Ƿ�Ϊ��
	LinkNode<T>* CreatRoot(const T& x);			//��ָ��Ԫ��ֵ�������ڵ�
	void Clear();								//��ն�����

	int GetDepth();												//��ȡ���
	LinkNode<T>* GetRoot();										//��ȡ���ڵ�
	//LinkNode<T>* Getnode();										//��ȡָ���ڵ�
	bool Getnodevalue(LinkNode<T>* pNode, const T& x);			//��ȡָ���ڵ�Ԫ�ص�ֵ
	LinkNode<T>* GetLeftnode(LinkNode<T>* pNode);				//��ȡ�������
	LinkNode<T>* GetRightnode(LinkNode<T>* pNode);				//��ȡ����Һ���
	LinkNode<T>* GetParent(LinkNode<T>* pNode);					//��ȡָ���ڵ��˫�׽�� �ǵݹ鷽ʽ
	
	LinkNode<T>* InsertLeftChild(LinkNode<T>* pNode, const T& x);		//��һ�������Ϊָ���������Ӳ���
	LinkNode<T>* InsertRightChild(LinkNode<T>* pNode, const T& x);		//��һ�������Ϊָ�������Һ��Ӳ���
	void DeleteSubTree(LinkNode<T>* pNode);								//ɾ����ָ���ڵ�Ϊ��������
	void DeleteSubTreeNode(LinkNode<T>* pNode);							//��deletesubtree����
	LinkNode<T>* SearchByKey(const T& x);								//���ؼ��ֲ��ҽ��
	bool ModifyNodeValue(LinkNode<T>* pNode, const T& x);				//�޸�ָ���ڵ��Ԫ��ֵ


	//�ݹ�
	void PreOrderTraverse(LinkNode<T>* pNode);		//�������
	void InOrderTraverse(LinkNode<T>* pNode);		//�������
	void PostOrderTraverse(LinkNode<T>* pNode);		//�������

	//�ǵݹ�
	void PreOrderTraverse();	//�������
	void InOrderTraverse();		//�������
	void PostOrderTraverse();	//�������
	void LevelOrderTraverse();	//������
private:
	LinkNode<T>* Root; //ָ�������ָ��
};