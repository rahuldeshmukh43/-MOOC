#include<iostream>
using namespace std;
//function declarations
int addTwoints( int A, int B);

//helping functions
int addTwoints(int A, int B){
	int C;
	C = A + B;
	return C;
}

// Main function
// read two numbers A&B and
// print the sum C
int main(){
	//declaration
	int A,B,C;
	// user input
	cout<<"Enter two numbers:";
	cin>>A>>B;
	//invoke function for adding
	C = addTwoints(A, B);
	//print C
	cout<<"The sum of "<<A<<" + "<<B<<" = "<<C;
	return 1;
}
