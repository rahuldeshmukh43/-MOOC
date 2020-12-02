#include<iostream>
using namespace std;
//Program to print ASCII value of character
int main(){
	char s;
	int v;
	cout<<"Enter a character: "; cin>>s;
	v = int(s);
	cout<<"The ASCII value of character "<< s <<" is ";
	cout<<v<<endl;
	return 0;
}

