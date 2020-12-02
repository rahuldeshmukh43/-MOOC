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
	cout<<"Enter num primes: ";cin>>N;
	cout<<"First "<<N<<" prime numbers are: "<<endl;
	while(count<N){
		//check for i
		if(isPrime(i)){cout<<i<<" ";count+=1;}
		i+=1;
	}
	cout<<endl;
	return 0;
}
