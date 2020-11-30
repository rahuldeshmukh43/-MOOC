#include<iostream>
using namespace std;
bool isPrime(int n);

//function 
bool isPrime(int n){//naive
	int i;
	if(n==2){return true;}
	for(i=2;i<n;i++){
	if(n%i==0){return false;}
	}
	return true;
}

int main(){
	int N,i=2,count=0;
	cout<<"Enter N: ";cin>>N;
	cout<<N<<" is prime: "<<boolalpha<<isPrime(N)<<endl;
	return 0;
}
