/* CPP file for class implementation of Node
 */
#include<iostream>
#include "Node.h"
#include "Polynomial.h"
#include "ConstPoly.h"
using namespace std;

//Node
Node::Node():left(NULL),right(NULL){}
Node::Node(Node* x, Node* y):left(x),right(y){}


//NodeList
NodeList::NodeList():NodeList(0){}
NodeList::NodeList(int n):numNodes(n){List = new Node[n];}
void NodeList::append(int i, Node n){
        List[i] = n; return;}

//PrimaryVarNode
PrimaryVarNode::PrimaryVarNode():Node(){
		NodeExpr = PrimaryPoly();
		NodeGrad = NodeExpr.grad();
		}

//ConstNode
ConstNode::ConstNode(int k):Node(){
		NodeExpr = ConstPoly(k);
		NodeGrad = NodeExpr.grad();
		}

//addNode
addNode::addNode(Node *l, Node *r):Node(l,r){
		NodeExpr = l->NodeExpr + r->NodeExpr;
		NodeGrad = l->NodeGrad + r->NodeGrad;
		}

//substractNode
substractNode::substractNode(Node *l, Node *r):Node(l,r){
		NodeExpr = l->NodeExpr - r->NodeExpr;
		NodeGrad = l->NodeGrad - r->NodeGrad;
		}

//mulNode
mulNode::mulNode(Node *l, Node *r):Node(l,r){
		NodeExpr = (l->NodeExpr)*(r->NodeExpr);
		NodeGrad = (l->NodeGrad)*(r->NodeExpr) +(l->NodeExpr)*(r->NodeGrad);
		}
