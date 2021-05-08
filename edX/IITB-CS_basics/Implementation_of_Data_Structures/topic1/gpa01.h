#ifndef GPA01_H
#define GPA01_H

#include<vector>
using namespace std;

class Node{
	public:
		int id;
		vector < Node* > outgoing_NodeList;
		vector < Node* > incoming_NodeList;
		Node(int i);
		void add_outgoing_Edge(Node *to_node);
		void add_incoming_Edge(Node *from_node);
		bool is_connected_to(int to_node_idx);
};

class SafeMap{
	private:
		int numNodes;
		vector<Node> NodeList;
	public:
		SafeMap(int n);
		bool addSafeRoute(int s, int d);
		int isReachable(int s, int d);
};


#endif
