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
	unsigned int weight;	//权值
	unsigned int parent, lchild, rchild; //父亲，左儿子，右儿子指示器
};

template<class T>
class HuffmanTree
{
public:
	HuffmanTree(int size, int* w, unsigned int max)//构造函数
	{
		MaxSize = size;
		wight = new int[MaxSize];
		weight = w;
	}
	~HuffmanTree()					//析构函数
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

	void CreatHTree();		//建立哈夫曼树
	void HCoding();			//从叶子到根逆向求每个字符的哈夫曼编码
	void HCoding2();		//无栈非递归遍历哈夫曼树，求哈夫曼编码
	void print();			//输出哈夫曼树及编码

private:
	int* weight;			//MaxSize个字符的权值
	HTNode<T>* HTree;		//哈夫曼树
	char** HuffmanCode;		//MaxSize个字符的哈夫曼编码
	int MaxSize;			//最大字符个数
	int Select2Small(int i, unsigned int& s1, unsigned int& s2);
};

template<class T>
void HuffmanTree<T>::CreatHTree()//创建哈夫曼树
{
	if (MaxSize <= 0)
		return;
	int m = 2 * MaxSize - 1;
	HTree = new HTNode<T>[m + 1];		//0号单元不用
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
		//建哈夫曼树
		//在HT[1...i-1]中选择parent为0且weight最小的俩个节点，其序号分别为s1和s2
		Select2Small(i - 1, s1, s2);
		HTree[s1].parent = i;
		HTree[s2].parent = i;
		HTree[i], lchild = s1;
		HTree[i].rchild = s2;
		HTree[i].weight = HTree[s1].weight + HTree[s2].weight;
	}
}