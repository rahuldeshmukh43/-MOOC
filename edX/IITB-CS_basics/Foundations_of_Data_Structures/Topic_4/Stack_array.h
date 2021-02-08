//Linked list using arrays

#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

class Stack{
int size;
char s[MAX_SIZE];
	public:
	Stack();
	bool IsEmpty();
	bool IsFull();
	bool Top(char &top_el);
	bool Push(char el);
	bool Pop(char &el);
};

class Queue{
int size;
char q[MAX_SIZE];
	public:
	Queue();
	bool IsEmpty();
	bool IsFull();
	bool Front(char &f_el);
	bool End(char &end_el);
	bool Push(char el);
	bool Pop(char &el);
};

#endif
