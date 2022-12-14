//binary_tree_1.cpp
//
#include<iostream>
#include "binary_tree_1.h"
using namespace std;

Node* BinaryTree::get_root_ptr(){
return NodeList[0];
}

void BinaryTree::makeNode(int data){
Node* n;
n = new Node; 
n->data = data;
n->leftNode=NULL;
n->rightNode=NULL;
NodeList.push_back(n);
}

void BinaryTree::insertRight(Node* node_ptr, int data){
Node* n;
n = new Node;
n->data = data;
n->leftNode=NULL;
n->rightNode=NULL;
NodeList.push_back(n);
node_ptr->rightNode = n;
}

void BinaryTree::insertLeft(Node* node_ptr,int data){
Node* n;
n = new Node;
n->data = data;
n->leftNode=NULL;
n->rightNode=NULL;
NodeList.push_back(n);
node_ptr->leftNode = n; 
}

void BinaryTree::insert(int data){
//int index=0;
Node* node_ptr;
if (NodeList.size()==0){ makeNode(data); return;}

node_ptr = NodeList.at(0);

while(true){
if(data <= node_ptr->data){//go to left
	if(node_ptr->leftNode == NULL){
	insertLeft(node_ptr, data);
	break;
	}
	else{node_ptr= node_ptr->leftNode;}
}
else{// go to right
	if(node_ptr->rightNode == NULL){
	insertRight(node_ptr, data);
	break;
	}
	else{node_ptr = node_ptr->rightNode;}
}
}//end while 
return;
}

void BinaryTree::traverse(Node* node_ptr, TraverseOrder order){
//node_ptr is pointing to root/ top parent node
if(order==PRE_ORDER){cout<<node_ptr->data<<" ";}

if(node_ptr->leftNode!=NULL){//traverse left
traverse(node_ptr->leftNode, order);
}

if(order==IN_ORDER){
cout<<node_ptr->data<<" ";
}

if(node_ptr->rightNode!=NULL){
traverse(node_ptr->rightNode, order);
}

if(order==POST_ORDER){
cout<<node_ptr->data<< " ";
}
}




