#include<iostream>
using namespace std;
//Program to print AP
int main(){
	int a,n,d,i;
	cout<<"Enter a: ";cin>>a;
	cout<<"Enter d: ";cin>>d;
	cout<<"Enter n: ";cin>>n;
	cout<<"Substituting value of 'a', 'd', and 'n' in the sequence {a, a+d, a+2d, ... , a+nd}"<<endl;
	cout<<"= {";
	for(i=0;i<=n;i++){
	if(i==0){cout<<a<<",";}
	else{
		if(i!=n){cout<<" 5 + "<<i<<"*"<<d<<",";}
		else{cout<<" 5 + "<<i<<"*"<<d;}
	}
	}
	cout<<"}"<<endl;
	//print values
	cout<<"= {";
	for(i=0;i<=n;i++){
	if(i!=n){cout<<a+i*d<<", ";}
	else{cout<<a+i*d;}
	}
	cout<<"}"<<endl;
	return 0;
}
