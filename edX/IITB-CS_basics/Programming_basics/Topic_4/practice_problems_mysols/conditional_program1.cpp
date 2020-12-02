#include<iostream>
using namespace std;
void swap(int &m, int &n){
	int temp;
	temp = m;
	m = n;
	n = temp;
	return;
}
//program to swap two numbers
int main(){
	int a,b;
	cout<<"Enter value for Number 1: ";cin>>a;
	cout<<"Enter value for Number 2: ";cin>>b;
	swap(a,b);
	cout<<"The modified values after swapping are:"<<endl;
	cout<<"Number 1:"<<a<<endl;
	cout<<"Number 2:"<<b<<endl;
	return 0;
}
