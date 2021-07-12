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
	T m_vertex[MAX_VERTEX_NUM];		//顶点集合
	int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int m_nVertexNum;		//顶点数目
	int m_nGraphType;		//图的类型（0：无向图，1：有向图）
public:
	//AdjGraph();//构造函数
	AdjGraph(int nGraphType);//创建图
	~AdjGraph();//析构函数

	//以递归方式从下标为nV的顶点开始对图左深度优先遍历
	bool DFSTraverse(int nV, int);
	//由DFSTraverse调用以递归方式完成图的深度优先遍历
	void DFS(int nV, bool bVisited[]);
	//以非递归方式对图做深度优先遍历
	bool DFSTraverse(int nV);

	bool BFSTraverse(int nV);	//从下标为nV的顶点开始对图左广度优先遍历

	int GetVertexNUM();	//获取顶点数目
	int GetFirstEdge(int nV);		//获取与指定顶点nV相关联的第一条边
	int GetNextEdge(int nV1, int nV2);		//获取与指定边(nV1,nV2)或<nV1,nV2>有相关联顶点nV1的下一条边
	bool AddOneVertex(const T& vertex);		//添加一个顶点
	bool AddOneEdge(int nV1, int nV2, int nWeight);	//添加一条边
	bool GetVertexValue(int nV, T& vertex);	//获取一个顶点中存储的数据
	bool IsEdge(int nV1, int nV2);		//判断一条边是否存在
	bool SetEdgeWeight(int nV1, int nV2, int nWeight);	//设置一条边的权
	bool GetEdgeWeight(int nV1, int nV2, int &nWeight);	//获取一条边的权
	
};

template<class T>
AdjGraph<T>::AdjGraph(int nGraphType)//创建图
{
	int nI, nJ;
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	//将任俩个结点之间边上的权置为无穷大，初始时没有边
	for (nI = 0; nI < MAX_VERTEX_NUM; nI++)
		for (nJ = 0; nJ < MAX_VERTEX_NUM; nJ++)
			m_nAdjMatrix[nI][nJ] = infinity;
}

template<class T>
AdjGraph<T>::~AdjGraph()//析构函数
{

}

//以递归方式从下标为nV的顶点开始对图左深度优先遍历
template<class T>
bool AdjGraph<T>::DFSTraverse(int nV, int)
{

}

//由DFSTraverse调用以递归方式完成图的深度优先遍历
template<class T>
void AdjGraph<T>::DFS(int nV, bool bVisited[])
{

}

//以非递归方式对图做深度优先遍历
template<class T>
bool AdjGraph<T>::DFSTraverse(int nV)
{

}

template<class T>
bool AdjGraph<T>::BFSTraverse(int nV)	//从下标为nV的顶点开始对图左广度优先遍历
{
	LinkQueue<int>queue;
	int nVisitVertex, nVertex, nBegVertex = nV;
	bool bVisited[MAX_VERTEX_NUM];		//	记录是否查询过某一个点
	T vertex;
	if (nV < 0 || nV >= m_nVertexNum)
		return false;
	memset(bVisited, 0, sizeof(bVisited));	//各顶点均未查询过

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
				break;			//所有顶点都已访问，退出循环
		}
		return true;
	}
}

template<class T>
int AdjGraph<T>::GetVertexNUM()	//获取顶点数目
{
	return m_nVertexNum;
}

template<class T>
int AdjGraph<T>::GetFirstEdge(int nV)		//获取与指定顶点nV相关联的第一条边
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
int AdjGraph<T>::GetNextEdge(int nV1, int nV2)		//获取与指定边(nV1,nV2)或<nV1,nV2>有相同关联顶点nV1的下一条边的nV1外的顶点
{
	int nJ;
	if (!IsEdge(nV1, nV2))
		return -1;
	//访问nV2后面的顶点，找到下一条与nV1关联的边
	for (nJ = nV2 = +1; nJ < m_nVertexNum; nJ++)
		if (IsEdge(nV1, nJ))
			return nJ;
	return -1;
}

template<class T>
bool AdjGraph<T>::AddOneVertex(const T& vertex)		//添加一个顶点
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_nVertexNum++;
	return true;
}

template<class T>
bool AdjGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)	//添加一条边
{
	if (nV1 < 0 || nV1 >= MAX_VERTEX_NUM || nV2 < 0 || nV2 >= MAX_VERTEX_NUM || IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	if (m_nGraphType = 0)
		m_nAdjMatrix[nV2][nV1] = nWeight;
	return true;
}

template<class T>
bool AdjGraph<T>::GetVertexValue(int nV, T& vertex)	//获取一个顶点中存储的数据
{
	if ()
}

template<class T>
bool AdjGraph<T>::IsEdge(int nV1, int nV2)		//判断一条边是否存在
{
	return m_nAdjMatrix[nI][nJ] != infinty;
}

template<class T>
bool AdjGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)	//设置一条边的权
{
	if (!IsEdge)
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	return true;
}

template<class T>
bool AdjGraph<T>::GetEdgeWeight(int nV1, int nV2, int &nWeight)	//获取一条边的权
{
	if (!IsEdge)
		return false;
	nWeight = m_nAdjMatrix[nV1][nV2];
	return true;
}