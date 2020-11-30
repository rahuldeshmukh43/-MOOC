#include<iostream>
using namespace std;
int power(int base, int exp);

int power(int base, int exp){
	if(exp==0){return 1;}
	else{return base*power(base, exp-1);}
}
//Program to print GP
int main(){
	int a,n,d,i;
	cout<<"Enter a: ";cin>>a;
	cout<<"Enter r: ";cin>>d;
	cout<<"Enter n: ";cin>>n;
	cout<<"Substituting value of 'a', 'r', and 'n' in the sequence {a, a*r^1, a*r^2, ... , a*r^n}"<<endl;
	cout<<"= {";
	for(i=0;i<=n;i++){
	if(i==0){cout<<a<<",";}
	else{
		if(i!=n){cout<<" 5*"<<d<<"^"<<i<<",";}
		else{cout<<" 5*"<<d<<"^"<<i;}
	}
	}
	cout<<"}"<<endl;
	//print values
	cout<<"= {";
	for(i=0;i<=n;i++){
	if(i!=n){cout<<a*power(d,i)<<", ";}
	else{cout<<a*power(d,i);}
	}
	cout<<"}"<<endl;
	return 0;
}
