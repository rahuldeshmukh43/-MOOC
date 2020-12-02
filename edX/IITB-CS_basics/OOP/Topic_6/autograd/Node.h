/* Header file for class def of Node
*/

#ifndef NODE_H
#define NODE_H
#include "Polynomial.h"

class Node {
	public:
		Node* left;
		Node* right;
		Polynomial NodeExpr, NodeGrad;
		Node();
		Node(Node* x, Node* y);
};


class NodeList {                                                   
int numNodes;
        public: 
        Node* List;  
	NodeList();	      
	NodeList(int n);
        void append(int i, Node n);          
};

class PrimaryVarNode:public Node{
	public:
		PrimaryVarNode();
};

class ConstNode: public Node{
	public:
		ConstNode(int k);
};


class addNode:public Node{
	public:
		addNode(Node *l, Node *r);
};

class substractNode:public Node{
	public:
		substractNode(Node *l, Node *r);
};

class mulNode:public Node{
	public:
		mulNode(Node *l, Node *r);
};

//class divNode:public Node{};//later

#endif
