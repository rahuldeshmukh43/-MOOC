#include<iostream>
#include "textEditor.h"
//#include<stack>
using namespace std;

int main(){
int i=0;
char text[80];
textEditor txt;

cout<<"Enter the word to be inserted: ";
cin.getline(text,80);
txt.insertWord(text);
cout<<"Inerting word: "<<endl;
txt.examineTop();
print_stack(txt);

cout<<"Move cursor to the position 14: "<<endl;
txt.moveCursor(14); txt.examineTop(); print_stack(txt);

cout<<"Move cursor to the position 17: \n";
txt.moveCursor(17); txt.examineTop(); print_stack(txt);

//delete chars
for(i=0;i<3;i++){
if(!txt.deleteChar()){
cout<<"There is nothing to delete. Move your cursor accordingly to delete the character.";
}
else{cout<<"Deleting characters using DEL: \n";
txt.examineTop(); print_stack(txt);}
}

//backsapce chars
for(i=0;i<7;i++){
if(!txt.backSpaceChar()){
cout<<"There is nothing to delete. Move your cursor accordingly to delete the character.";
}
else{cout<<"Deleting characters using BKSPACE: \n";
txt.examineTop(); print_stack(txt);}
}

txt.findAndReplaceChar('t','T');
cout<<"Replace occurances of t with T: \n";
txt.examineTop(); print_stack(txt);
return 0;
}
