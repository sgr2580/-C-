#pragma

#include<iostream>

using namespace std;

template<class T>
class HuffmanTree;

template<class T>
class HTNode 
{
	friend class HuffmanTree<T>;
private:
	unsigned int weight;	//Ȩֵ
	unsigned int parent, lchild, rchild; //���ף�����ӣ��Ҷ���ָʾ��
};

template<class T>
class HuffmanTree
{
public:
	HuffmanTree(int size, int* w, unsigned int max)//���캯��
	{
		MaxSize = size;
		wight = new int[MaxSize];
		weight = w;
	}
	~HuffmanTree()					//��������
	{
		if (HTree)
			delete[]HTree;
	}

	void HuffmanCoding()
	{
		CreateHTree();
		HCoding();
	}

	void HuffmanCoding2()
	{
		CreateHTree();
		HCoding2();
	}

	void CreatHTree();		//������������
	void HCoding();			//��Ҷ�ӵ���������ÿ���ַ��Ĺ���������
	void HCoding2();		//��ջ�ǵݹ�������������������������
	void print();			//�����������������

private:
	int* weight;			//MaxSize���ַ���Ȩֵ
	HTNode<T>* HTree;		//��������
	char** HuffmanCode;		//MaxSize���ַ��Ĺ���������
	int MaxSize;			//����ַ�����
	int Select2Small(int i, unsigned int& s1, unsigned int& s2);
};

template<class T>
void HuffmanTree<T>::CreatHTree()//������������
{
	if (MaxSize <= 0)
		return;
	int m = 2 * MaxSize - 1;
	HTree = new HTNode<T>[m + 1];		//0�ŵ�Ԫ����
	HTNode<T>* p;
	int i;
	for (p = HTree, i = 1, p++; i < MaxSize; ++i, ++p, ++weight)
	{
		(*p).weight = *weight;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	for (; i <= m; ++i, ++p)
	{
		(*p).weight = 0;
		(*p).parent = 0;
		(*p).lchild = 0;
		(*p).rchild = 0;
	}
	unsigned int s1, s2;
	for (i = MaxSize; i <= m; ++i)
	{
		//����������
		//��HT[1...i-1]��ѡ��parentΪ0��weight��С�������ڵ㣬����ŷֱ�Ϊs1��s2
		Select2Small(i - 1, s1, s2);
		HTree[s1].parent = i;
		HTree[s2].parent = i;
		HTree[i], lchild = s1;
		HTree[i].rchild = s2;
		HTree[i].weight = HTree[s1].weight + HTree[s2].weight;
	}
}