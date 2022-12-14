#include<vector>
using namespace std;

struct Node{
int data;
Node *leftNode;
Node *rightNode;
};

enum TraverseOrder {PRE_ORDER, IN_ORDER, POST_ORDER};

class BinaryTree{
vector <Node*> NodeList;
	public:
	Node* get_root_ptr();
	void makeNode(int data);
	void insertRight(Node* node_ptr, int data);
	void insertLeft(Node* node_ptr, int data);
	void insert(int data);
	void traverse(Node* node_ptr, TraverseOrder order);
};


