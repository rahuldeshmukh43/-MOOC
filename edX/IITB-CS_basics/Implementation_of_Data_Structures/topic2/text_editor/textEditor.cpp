#include <iostream>
#include<stack>
#include "textEditor.h"
using namespace std;

//textEditor member functions
void textEditor::examineTop(){
if(left.empty()){cout<<"leftStack: empty\t\t";}
else
	cout<<"leftStack: "<<left.top()<<","<<left.size()<<"\t\t";
if(right.empty()){cout<<"rightStack: empty\t\n";}
else
	cout<<"rightStack: "<<right.top()<<","<<right.size()<<"\t\n";
}

void textEditor::insertWord(char word[]){
	int i=0;
	while(word[i]!='\0'){
	insertChar(word[i]);
	i++;
	}
}


void textEditor::insertChar(char c){
left.push(c);
}

bool textEditor::deleteChar(){
if(right.empty()){return false;}
right.pop();
return true;
}

bool textEditor::backSpaceChar(){
if(left.empty()){return false;}
left.pop();
return true;
}

void textEditor::moveCursor(int pos){
int left_size, right_size, count;
left_size = left.size();
right_size = right.size();
if(pos<left_size){
moveLeft(pos);}
else{
count = pos-left_size;
moveRight(count);
}
}

void textEditor::moveLeft(int pos){
int left_size;
left_size= left.size();
while(pos!=left_size){
right.push(left.top());
left.pop();
left_size = left.size();
}
}

void textEditor::moveRight(int count){
int right_size, i;
right_size=right.size();
if(count>right_size){cout<<"cannot move the cursor right to the specified position"<<endl;}
else{
	for(i=0;i<count;i++){
	left.push(right.top());
	right.pop();}
}
}

void textEditor::findAndReplaceChar(char findWhat, char replaceWith){
int original_pos, count=1;
original_pos = left.size();
	//move curdor to left-most position
moveCursor(0);

while(!right.empty()){//for every char in right stack
	if(right.top()==findWhat){//replace by delete + insert
	deleteChar();
	insertChar(replaceWith);
	}
	else{moveCursor(count);}
	count++;
}
moveCursor(original_pos);
}

void print_stack(textEditor txt){
stack<char> out;
cout<<"curent word: ";
while(!txt.left.empty()){out.push(txt.left.top());txt.left.pop();}
while(!out.empty()){cout<<out.top(); out.pop();}
while(!txt.right.empty()){cout<<txt.right.top(); txt.right.pop();}
cout<<"\n\n";
}
