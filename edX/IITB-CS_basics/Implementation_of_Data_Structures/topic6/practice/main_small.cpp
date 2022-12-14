#include<iostream>

#include "graph.cpp"
using namespace std;

int main(){
Graph<char> g;
char VertexList[5] = {'A','B','C','D','E'};
g.CreateGraphNodes(5, VertexList);

//create graph
if(!g.addEdge('A','B')){return 1;}
if(!g.addEdge('A','C')){return 1;}
if(!g.addEdge('B','D')){return 1;}
if(!g.addEdge('C','D')){return 1;}
if(!g.addEdge('D','E')){return 1;}

//print stuff
g.printOutEdges();
g.printInEdges();
cout<<"DFS:"<<endl;
g.DFS('A');
cout<<"BFS:\n";
g.BFS('A');
//remove edges

//print stuff

return 0;
}
