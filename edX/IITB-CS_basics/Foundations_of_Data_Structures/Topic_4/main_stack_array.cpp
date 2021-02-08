#include<iostream>
#include "Stack.h"
using namespace std;

int main(){
Stack S;
char el;

//check if stackis empty
if(S.IsEmpty()){
cout<<"Stack is empty as expected\n";
}
else{cout<<"ERROR: Stack is not empty"; return -1;}

//Populate stack
while(true){
	cout<<"Enter char to be pushed: ";
	cin>>el;
	S.Push(el);
	if(S.IsFull()){
		cout<<"Stack is now full\n";
		break;
	}
}

//print top
S.Top(el);
cout<<"Top-most element in Stack is: "<<el<<endl;

//Pop till empty
while(true){
if(!S.Pop(el)){cout<<"Stack is empty\n";break;}
cout<<"Popped element is: "<<el<<endl;
}

return 0;
}
