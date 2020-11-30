#include<iostream>
using namespace std;
// read two numbers A&B and
// print the sum C
int main(){
	//declaration
	int A,B,C;
	// user input
	cout<<"Enter two numbers:";
	cin>>A>>B;
	C = A + B;
	//print C
	cout<<"The sum of "<<A<<" + "<<B<<" = "<<C;
	return 1;
}
