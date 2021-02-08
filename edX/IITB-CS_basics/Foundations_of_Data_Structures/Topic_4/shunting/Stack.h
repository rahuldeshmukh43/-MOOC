//Linked list using arrays

#ifndef STACK_LL_H
#define STACK_LL_H

class Node{
	public:
	char info;
	Node* next;
	Node* prev;
	Node(char x);
};

class Stack{
Node* top;
	public:
	Stack();
	bool IsEmpty();
	bool Top(char &top_el);
	bool Push(char el);
	bool Pop(char &el);
};

class Queue{
Node* front;
Node* end;
	public:
	Queue();
	bool IsEmpty();
	bool Front(char &f_el);
	bool End(char &end_el);
	bool Push(char el);
	bool Pop(char &el);
};

#endif
