#pragma once

#include <iostream>
#include "LinkQueue.hpp"
using namespace std;

const int infinity = INT_MAX;
const int MAX_VERTEX_NUM = 30;


template<class T>
class AdjGraph
{
private:
	T m_vertex[MAX_VERTEX_NUM];		//���㼯��
	int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int m_nVertexNum;		//������Ŀ
	int m_nGraphType;		//ͼ�����ͣ�0������ͼ��1������ͼ��
public:
	//AdjGraph();//���캯��
	AdjGraph(int nGraphType);//����ͼ
	~AdjGraph();//��������

	//�Եݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
	bool DFSTraverse(int nV, int);
	//��DFSTraverse�����Եݹ鷽ʽ���ͼ��������ȱ���
	void DFS(int nV, bool bVisited[]);
	//�Էǵݹ鷽ʽ��ͼ��������ȱ���
	bool DFSTraverse(int nV);

	bool BFSTraverse(int nV);	//���±�ΪnV�Ķ��㿪ʼ��ͼ�������ȱ���

	int GetVertexNUM();	//��ȡ������Ŀ
	int GetFirstEdge(int nV);		//��ȡ��ָ������nV������ĵ�һ����
	int GetNextEdge(int nV1, int nV2);		//��ȡ��ָ����(nV1,nV2)��<nV1,nV2>�����������nV1����һ����
	bool AddOneVertex(const T& vertex);		//���һ������
	bool AddOneEdge(int nV1, int nV2, int nWeight);	//���һ����
	bool GetVertexValue(int nV, T& vertex);	//��ȡһ�������д洢������
	bool IsEdge(int nV1, int nV2);		//�ж�һ�����Ƿ����
	bool SetEdgeWeight(int nV1, int nV2, int nWeight);	//����һ���ߵ�Ȩ
	bool GetEdgeWeight(int nV1, int nV2, int &nWeight);	//��ȡһ���ߵ�Ȩ
	
};

template<class T>
AdjGraph<T>::AdjGraph(int nGraphType)//����ͼ
{
	int nI, nJ;
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	//�����������֮����ϵ�Ȩ��Ϊ����󣬳�ʼʱû�б�
	for (nI = 0; nI < MAX_VERTEX_NUM; nI++)
		for (nJ = 0; nJ < MAX_VERTEX_NUM; nJ++)
			m_nAdjMatrix[nI][nJ] = infinity;
}

template<class T>
AdjGraph<T>::~AdjGraph()//��������
{

}

//�Եݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
template<class T>
bool AdjGraph<T>::DFSTraverse(int nV, int)
{

}

//��DFSTraverse�����Եݹ鷽ʽ���ͼ��������ȱ���
template<class T>
void AdjGraph<T>::DFS(int nV, bool bVisited[])
{

}

//�Էǵݹ鷽ʽ��ͼ��������ȱ���
template<class T>
bool AdjGraph<T>::DFSTraverse(int nV)
{

}

template<class T>
bool AdjGraph<T>::BFSTraverse(int nV)	//���±�ΪnV�Ķ��㿪ʼ��ͼ�������ȱ���
{
	LinkQueue<int>queue;
	int nVisitVertex, nVertex, nBegVertex = nV;
	bool bVisited[MAX_VERTEX_NUM];		//	��¼�Ƿ��ѯ��ĳһ����
	T vertex;
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//�������δ��ѯ��

	while (1)
	{
		queue.Insert(nBegVertex);
		bVisited[nBegVertex] = true;
		while (!queue.IsEmpty())
		{
			queue.Delete(nVisitVertex);
			GetVertexValue(nVisitVertex, vertex);
			cout << vertex << "";
			nVertex = GetFirstEdge(nVisitVertex);
			/*if (nVertex)
				queue.Insert(nVertex);
			while (GetNextEdge(nVisitVertex))
				nVertex = GetNextEdge;
			queue.Insert(nVertex);*/

			while (nVertex != -1)
			{
				if (bVisited[nVertex] == false)
				{
					queue.Insert(nVertex);
					bVisited[nVertex] = true;
				}
				nVertex = GetNextEdge(nVisitVertex, nVertex);
			}
			int n = nBegVertex + 1;
			for (; n < m_nVertexNum; n++)
			{
				if (bVisited[n % m_nVertexNum] == false)
				{
					nBegVertex = n % m_nVertexNum;
					break;
				}
			}
			if (n == m_nVertexNum + nV)
				break;			//���ж��㶼�ѷ��ʣ��˳�ѭ��
		}
		return true;
	}
}

template<class T>
int AdjGraph<T>::GetVertexNUM()	//��ȡ������Ŀ
{
	return m_nVertexNum;
}

template<class T>
int AdjGraph<T>::GetFirstEdge(int nV)		//��ȡ��ָ������nV������ĵ�һ����
{
	int nJ;
	if (nV < 0 || nV >= m_nVertexNum)
		return -1;
	for (nJ = 0; nJ < m_nVertexNum; nJ++)
		if (IsEdge(nV, nJ))
			return nJ;
	return -1;
}

template<class T>
int AdjGraph<T>::GetNextEdge(int nV1, int nV2)		//��ȡ��ָ����(nV1,nV2)��<nV1,nV2>����ͬ��������nV1����һ���ߵ�nV1��Ķ���
{
	int nJ;
	if (!IsEdge(nV1, nV2))
		return -1;
	//����nV2����Ķ��㣬�ҵ���һ����nV1�����ı�
	for (nJ = nV2 = +1; nJ < m_nVertexNum; nJ++)
		if (IsEdge(nV1, nJ))
			return nJ;
	return -1;
}

template<class T>
bool AdjGraph<T>::AddOneVertex(const T& vertex)		//���һ������
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_nVertexNum++;
	return true;
}

template<class T>
bool AdjGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)	//���һ����
{
	if (nV1 < 0 || nV1 >= MAX_VERTEX_NUM || nV2 < 0 || nV2 >= MAX_VERTEX_NUM || IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	if (m_nGraphType = 0)
		m_nAdjMatrix[nV2][nV1] = nWeight;
	return true;
}

template<class T>
bool AdjGraph<T>::GetVertexValue(int nV, T& vertex)	//��ȡһ�������д洢������
{
	if ()
}

template<class T>
bool AdjGraph<T>::IsEdge(int nV1, int nV2)		//�ж�һ�����Ƿ����
{
	return m_nAdjMatrix[nI][nJ] != infinty;
}

template<class T>
bool AdjGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)	//����һ���ߵ�Ȩ
{
	if (!IsEdge)
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	return true;
}

template<class T>
bool AdjGraph<T>::GetEdgeWeight(int nV1, int nV2, int &nWeight)	//��ȡһ���ߵ�Ȩ
{
	if (!IsEdge)
		return false;
	nWeight = m_nAdjMatrix[nV1][nV2];
	return true;
}