#include<iostream>
using namespace std;
void row(int i, int size);
//
void row(int i,int size){
	int start,len,j;
	len = 2*i+1;	
	start = (size - len)/2 ;
	for(j=1;j<=size;j++){
	if((j>start)&&(j<=start+len)){cout<<'*';}
	else{cout<<' ';}
	}
	return;
}
//program to print pyramid pattern
int main(){
	int n,i,j,size;
	cout<<"Enter n: ";cin>>n;
	size=2*n-1;
	for(i=0;i<n;i++){
	row(i,size);
	cout<<endl;
	}
	return 0;
}
