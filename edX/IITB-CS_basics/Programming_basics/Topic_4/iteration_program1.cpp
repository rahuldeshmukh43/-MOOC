#include<iostream>
using namespace std;

int main(){
	int l,h,i,j;
	cout<<"Enter length of the rectangle: ";cin>>l;
	cout<<"Enter height of the rectangle: ";cin>>h;
	for(i=0;i<l;i++){cout<<'*';}
	cout<<endl;
	for(j=0;j<h-2;j++){
		for(i=0;i<l;i++){
		if((i==0)||(i==l-1)){cout<<'*';}
		else{cout<<' ';}}
		cout<<endl;
	}
	for(i=0;i<l;i++){cout<<'*';}
	cout<<endl;
	return 0;
}

