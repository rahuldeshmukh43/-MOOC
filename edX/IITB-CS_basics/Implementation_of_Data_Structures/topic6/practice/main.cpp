#include<iostream>

#include "graph.cpp"
using namespace std;

int main(){
Graph<char> g;
char VertexList[7] = {'A','B','C','D','E','F','G'};
g.CreateGraphNodes(7, VertexList);

//create graph
if(!g.addEdge('A','B')){return 1;}
if(!g.addEdge('A','C')){return 1;}
if(!g.addEdge('A','D')){return 1;}
if(!g.addEdge('B','C')){return 1;}
if(!g.addEdge('B','D')){return 1;}
if(!g.addEdge('C','A')){return 1;}
if(!g.addEdge('C','F')){return 1;}
if(!g.addEdge('D','C')){return 1;}
if(!g.addEdge('D','F')){return 1;}
if(!g.addEdge('D','G')){return 1;}
if(!g.addEdge('D','E')){return 1;}
if(!g.addEdge('E','G')){return 1;}
if(!g.addEdge('F','G')){return 1;}

//print stuff
g.printOutEdges();
g.printInEdges();
cout<<"DFS:"<<endl;
g.DFS('A');
cout<<"BFS:\n";
g.BFS('A');
//remove edges
cout<<"removing some edges"<<endl;
if(!g.removeEdge('C','A')){return 1;}
if(!g.removeEdge('A','C')){return 1;}
//print stuff
g.printOutEdges();
g.printInEdges();
cout<<"DFS:"<<endl;
g.DFS('A');
cout<<"BFS:\n";
g.BFS('A');

return 0;
}
