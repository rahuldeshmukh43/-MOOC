#include<iostream>
using namespace std;

//Program to print expansion of (a+b)^2
int main(){
	int a,b,ab,a2,b2, sum;
	cout<<"Enter a: ";cin>>a;
	cout<<"Enter b: ";cin>>b;
	a2 = a*a; b2 = b*b;
	ab = 2*a*b;
	sum = a2 + b2 + ab;
	cout<<"("<<a<<" + "<<b<<")^2"<<endl;
	cout<<"= "<<a<<"^2 + "<<"2*"<<a<<"*"<<b<<" + "<<b<<"^2"<<endl;
	cout<<"= "<<a2<<" + "<<ab<<" + "<<b2<<endl;
	cout<<"= "<<sum<<endl;
	return 0;
}
