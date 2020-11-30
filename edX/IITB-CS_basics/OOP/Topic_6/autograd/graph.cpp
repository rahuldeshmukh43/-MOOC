/* CPP file for class implementation
 * Code for instantiating a directed binary tree/computational graph
 * for computing the derivative
 */

#include "graph.h"
#include "Node.h"

//Graph
Graph::Graph(int numNodes){
nodeList = NodeList(numNodes);}

////Edge
//graph::Edge(Node &x, Node &y):from(x),to(y){}
