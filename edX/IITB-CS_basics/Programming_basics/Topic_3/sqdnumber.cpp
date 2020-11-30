#include<iostream>
using namespace std;

//Program to compute the sum of squares of individual digits of the the number
int main(){
	int num,d,sum=0;
	cout<<"Enter the number: "<<endl; cin>>num;
	//loop and add squares
	for(int i=0;;i++){
		if(num==0){break;}
		d = num%10;
		sum += d*d;
		num /= 10;
	}
	//print stuff:
	cout<<"Sum of squares: "<<sum<<endl;
	return 0;
}
