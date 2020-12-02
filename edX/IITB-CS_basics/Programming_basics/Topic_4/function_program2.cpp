#include<iostream>
using namespace std;
int fac(int n);

int fac(int n){
	if(n==0){return 1;}
	else{return n*fac(n-1);}
}

//Program to compute factorial
int main(){
	int n,r;
	float ncr;
	cout<<"Enter n: ";cin>>n;
	cout<<"Enter r: ";cin>>r;
	//check for valid inputs
	if(!((r<=n)&&(r>=0))){cout<<"Bad inputs"<<endl;return -1;}
	//compute ncr
	ncr = 1.0*fac(n)/(fac(n-r)*fac(r));
	cout<<"nCr: "<<ncr<<endl;
	return 0;
}
