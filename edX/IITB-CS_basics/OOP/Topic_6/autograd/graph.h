/* Header file for class def of graph
 */

#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

class Graph{
	public:
		NodeList nodeList;
		Node *rootNode;
		//Edge *edgeList;
		Graph(int numNodes);
};

//class Edge{
//Node* from;
//Node* to;
//public:
//Edge(Node &x, Node &y);
//};

#endif
