#include<iostream>
using namespace std;
//function declarations
void swap(int &m, int &n);

//function for swapping: call by reference
void swap(int &m, int &n){
	int temp;
	temp = m;
	m = n;
	n = temp;
	return;
}

//Program to swap two numbers
int main(){
	int a,b;
	cout<<"Enter two numbers a,b: "; 
	cin>>a>>b;
	swap(a,b);
	cout<<"Swapped numbers a,b: "<<a<<","<<b<<endl;
	return 0;
}
