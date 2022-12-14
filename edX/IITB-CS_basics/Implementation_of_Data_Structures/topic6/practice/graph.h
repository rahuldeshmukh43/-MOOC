// header file for graph

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <list>

using namespace std;

template<class T>
class Graph{
	vector<list<T> > AdjList;
	public:
	int size();
	void CreateGraphNodes(int size , T *VertexList);
	bool addEdge(T source, T destination);
	bool removeEdge(T source , T destination);
	bool CheckNodeExists(T node);
	void GetVertices(T VertexList[]);
	void DFS(T start);
	void BFS(T start);
	void printOutEdges();
	void printInEdges();
};

//template<class T>
//class Node{
//	public:
//		T data;
//		void CreateNode(T);
//		
//};


#endif
