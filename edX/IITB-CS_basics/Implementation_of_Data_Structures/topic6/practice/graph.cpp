//Code for Graph class


#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

#include "graph.h"

using namespace std;

//Graph methods
template<class T>
int Graph<T>::size(){
	return AdjList.size();
}

template<class T>
void Graph<T>::CreateGraphNodes(int size, T *VertexList){
	AdjList.resize(size);
	int v_id=0;
	for(typename vector<list <T> >::iterator adjList_iterator=AdjList.begin(); adjList_iterator!=AdjList.end(); v_id++, adjList_iterator++){
	(*adjList_iterator).push_back(VertexList[v_id]);
	}
	return;
}

template<class T>
bool Graph<T>::CheckNodeExists(T node){
	for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin(); adjlist_itr!=AdjList.end(); adjlist_itr++){
		typename list<T>::iterator list_itr = (*adjlist_itr).begin();
		if(node == *list_itr){return true;}
	}
return false;	
}

template<class T>
bool Graph<T>::addEdge(T source, T destination){
	//returns true if edge was not existing and now added
	bool flagExists=false;
	//check args
	if(!(CheckNodeExists(source) && CheckNodeExists(destination))){
	cout<<"NodeError: Nodes do not exist!"<<endl;
	return false;
	}

	//check for existing edge if not the create edge
	for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin(); adjlist_itr!=AdjList.end(); adjlist_itr++){
		typename list<T>::iterator list_itr = (*adjlist_itr).begin();
		if(*list_itr == source){//now check for existing edge
			list_itr++;
			for(;list_itr!=(*adjlist_itr).end();list_itr++){
				if(*list_itr==destination){//edge already exists
					flagExists=true;
					cout<<"EdgeError: Edge already exits in the graph"<<endl;
					return false;					
					}
			}
			if(flagExists!=true){//create edge
			(*adjlist_itr).push_back(destination);
			flagExists=true;
			return true;
			}
		}	
	}
}

template<class T>
bool Graph<T>::removeEdge(T source, T destination){
	//returns true if edge was found and removed 
	bool flagExists=false;
	//check args
	if(!(CheckNodeExists(source) && CheckNodeExists(destination))){
	cout<<"NodeError: Nodes do not exist!"<<endl;
	return false;
	}

	for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin(); adjlist_itr!=AdjList.end(); adjlist_itr++){
		typename list<T>::iterator list_itr = (*adjlist_itr).begin();
		if(*list_itr==source){//now check for existing edge
			list_itr++;
			for(;list_itr!=(*adjlist_itr).end();list_itr++){
				if(*list_itr==destination){//edge exists
					flagExists=true;
					(*adjlist_itr).remove(destination);
					return true;			
					}
			}
			cout<<"EdgeError: Edge does not exist in graph"<<endl;
			return false;
		}
	}
}

template<class T>
void Graph<T>::printOutEdges(){
	cout<<"Printing out edges:\n";
	cout<<"Node:\t List\n";
	for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin(); adjlist_itr!=AdjList.end(); adjlist_itr++){
		typename list<T>::iterator list_itr = (*adjlist_itr).begin();
		cout<<*list_itr<<":\t";
		list_itr++;
		for(;list_itr!=(*adjlist_itr).end();list_itr++){
		cout<<*list_itr<<" ";
		}
		cout<<endl;
	}
	return;
}

template<class T>
void Graph<T>::printInEdges(){
	T current_src;
	cout<<"Printing incoming edges:\n";
	cout<<"Node:\t List\n";
	for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin();
	    adjlist_itr!=AdjList.end();
	    adjlist_itr++){
		typename list<T>::iterator list_itr = (*adjlist_itr).begin();
		cout<<*list_itr<<":\t";//for this node as destination
		//find all sources
		for(typename vector<list<T> >::iterator adjlist_itr2=AdjList.begin(); adjlist_itr2!=AdjList.end(); adjlist_itr2++){
			typename list<T>::iterator list_itr2 = (*adjlist_itr2).begin();
			current_src= *list_itr2;
			list_itr2++;
			for(;list_itr2!=(*adjlist_itr2).end();list_itr2++){
			if(*list_itr2 == *list_itr){
			cout<<current_src<<" ";
			break;
			}}
		}
		cout<<endl;
	}
	return;
}

template<class T>
void Graph<T>::GetVertices(T VertexList[]){
	int i=0;
	for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin(); adjlist_itr!=AdjList.end(); adjlist_itr++, i++){
		typename list<T>::iterator list_itr=(*adjlist_itr).begin();
		VertexList[i]=*list_itr;
	}
}

template<class T>
void Graph<T>::DFS(T start){
int size=this->size();
T *VertexList = new T[size];
this->GetVertices(VertexList);

bool visited[size];
for(int i=0; i<size; i++){visited[i]=false;}

list<T> s;
s.push_back(start);
while(!s.empty()){
	T node = s.back();
	s.pop_back();
	
	int node_id = find(VertexList, VertexList+size, node) - VertexList;
	if(visited[node_id]==false){
		cout<<node<<", ";
		visited[node_id]=true;
		for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin(); adjlist_itr!=AdjList.end(); adjlist_itr++){
			typename list<T>::iterator list_itr=(*adjlist_itr).begin();
			if(node==*list_itr){
				list_itr++; 
				for(;list_itr!=(*adjlist_itr).end();list_itr++){//push adj nodes
				s.push_back(*list_itr);
					}
				break;}
				}
			}
	}
cout<<endl;
}

template<class T>
void Graph<T>::BFS(T node){
int size=this->size();
T *VertexList = new T[size];
this->GetVertices(VertexList);

bool visited[size];
for(int i=0; i<size; i++){visited[i]=false;}

list<T> s;
s.push_back(node);
while(!s.empty()){
	node = s.front();
	s.pop_front();
	
	int node_id = find(VertexList, VertexList+size, node) - VertexList;
	if(visited[node_id]==false){
		cout<<node<<", ";
		visited[node_id]=true;
		for(typename vector<list<T> >::iterator adjlist_itr=AdjList.begin(); adjlist_itr!=AdjList.end(); adjlist_itr++){
			typename list<T>::iterator list_itr=(*adjlist_itr).begin();
			if(node==*list_itr){
				list_itr++; 
				for(;list_itr!=(*adjlist_itr).end();list_itr++){//push adj nodes
				s.push_back(*list_itr);
					}
				break;}
				}
			}
	}
cout<<endl;
}
