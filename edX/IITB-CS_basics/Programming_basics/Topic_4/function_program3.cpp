#include<iostream>
using namespace std;
bool isFactor(int num, int m);

bool isFactor(int num, int m){
	if(num%m==0){return true;}
	return false;
}
//program to check if given number is same as sum of its factors
int main(){
	int N,i,sum=0;
	cout<<"Enter a number: ";cin>>N;
	for(i=1;i<N;i++){
	if(isFactor(N,i)){sum += i;}
	}
	//cout<<"**sum:"<<sum<<endl;
	if(sum==N){cout<<N<<" is a perfect number"<<endl;}
	else{cout<<N<<" is not a perfect number"<<endl;}
	return 0;
}
