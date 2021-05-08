#include "gpa01.h"
#include<iostream>
using namespace std;

//Node 
Node::Node(int i):id(i){}

void Node::add_outgoing_Edge(Node *to_node){
// adds edge information to nodes. Edge starting from current id to to_node_idx
outgoing_NodeList.push_back(to_node);
}

void Node::add_incoming_Edge(Node *from_node){
incoming_NodeList.push_back(from_node);
}

bool Node::is_connected_to(int to_node_idx){
//outgoing edge should be there to_node_idx
bool flagExists=false;
for(int i=0;i<outgoing_NodeList.size(); i++){
if(outgoing_NodeList[i]->id == to_node_idx){
	flagExists=true;break;
}
}
return flagExists;
}

//SafeMap
#define infi 1000000

SafeMap::SafeMap(int n):numNodes(n){
for(int i=0;i<n;i++){
NodeList.push_back(Node(i));}
}

bool SafeMap::addSafeRoute(int s, int d){
Node *from_node, *to_node;
//input sanity check
if((s>=this->numNodes)||(d>=this->numNodes)||(s<0)||(d<0)){
cout<<"Invalid node indices (out of bound). Should be within 0-"<<this->numNodes<<endl;
return false;
}
//add edge info
from_node = &NodeList[s];
to_node = &NodeList[d];
from_node->add_outgoing_Edge(to_node);
to_node->add_incoming_Edge(from_node);
return true;
}

int SafeMap::isReachable(int s, int d){
//returns int distance between nodes is path exists else returns -1
//using dijkstra's algo
vector <bool> visited_mask(this->numNodes,false);
vector <int> distance(this->numNodes, infi);
int i, curr_node=s;
int outgoing_node_idx, temp_d;
bool flag_all_visited=false, tempboo=true;
int count_visited=0, smallest_d, smallest_d_id;

distance[curr_node]=0;
while(true){
	smallest_d = infi;
	cout<<"curr_node: "<<curr_node<<endl;
//do one pass to neighboring nodes
for(i=0; i<NodeList[curr_node].outgoing_NodeList.size(); i++){
outgoing_node_idx = NodeList[curr_node].outgoing_NodeList[i]->id;
if(!visited_mask[outgoing_node_idx]){
	temp_d = distance[curr_node] + 1;
if(distance[outgoing_node_idx]>temp_d){
	distance[outgoing_node_idx]= temp_d;}}
}
visited_mask[curr_node]=true;count_visited+=1;
//check for breaking condition
//flag_all_visited=(count_visited==numNodes)?true:false;
//compute smallest tentative distance among unvisited nodes
for(i=0;i<numNodes;i++){
if(!visited_mask[i]){
if(distance[i]<smallest_d){
	smallest_d= distance[i];
	smallest_d_id = i;}
}
}
if((visited_mask[d]) || (smallest_d==infi)){break;}

//update curr node
curr_node=smallest_d_id;
}
if(distance[d]==infi){return -1;}
return distance[d];
}
