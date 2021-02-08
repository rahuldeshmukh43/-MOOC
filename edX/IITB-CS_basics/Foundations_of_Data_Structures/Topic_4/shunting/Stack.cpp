#include<iostream>
#include "Stack.h"
using namespace std;

//Node
Node::Node(char x):info(x),next(NULL),prev(NULL){}

//Stack using array
Stack::Stack():top(NULL){}

bool Stack::IsEmpty(){
return (top==NULL);
}

bool Stack::Top(char &top_el){
if(top==NULL){return false;}
top_el=top->info;
return true;
}

bool Stack::Push(char el){
Node* temp;
temp = new Node(el);

if(top==NULL){//first node in list
top = temp;
}
else{//nodes already in list
temp->next = top;
top = temp;
}
return true;
}

bool Stack::Pop(char &el){
Node* temp;
temp = top;
if(top==NULL){return false;}
else{
el = temp->info;
top = temp->next;
delete temp;
return true;}
}

//Queue using array
Queue::Queue():front(NULL),end(NULL){}

bool Queue::IsEmpty(){
return (front==NULL);
}

bool Queue::Front(char &f_el){
if(front==NULL){return false;}
f_el = front->info;
return true;
}

bool Queue::End(char &end_el){
if(end==NULL){return false;}	
end_el= end->info;
return true;
}

bool Queue::Push(char el){
Node* temp;
temp = new Node(el);
if(front==NULL){//first Node
front = temp;
end = temp;
}
else{//Nodes already present in the queue
//insert at the end
temp->prev = end;
end->next = temp;
end = temp;
}
return true;
}

bool Queue::Pop(char &el){
Node* temp;
temp = front;
if(front==NULL){return false;}
else{
el = temp->info;
front= temp->next;
delete temp;
return true;}
}
