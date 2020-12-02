#include<iostream>
using namespace std;
int fac(int n);

int fac(int n){
	if(n==0){return 1;}
	else{return n*fac(n-1);}
}

//Program to compute factorial
int main(){
	int n;
	cout<<"Enter a positive number: ";cin>>n;
	cout<<"The factorial of "<<n<<" is "<<fac(n)<<endl;
	return 0;
}
