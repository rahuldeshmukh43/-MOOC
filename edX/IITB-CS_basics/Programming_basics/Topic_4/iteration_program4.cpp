#include<iostream>
using namespace std;
int Len(int n);
int power(int base,int exponent);
//function for power
int power(int base, int exponent){
	if(exponent==0){return 1;}
	else{return base*power(base,exponent-1);}
}
//function for finding length of number
int Len(int n){
	int i;
	for(i=0;;i++){
	if(n%10==0){break;}
	n= n/10;
	}
	return i;
}
//check for palindrome number
int main(){
	int N,n,rev_n=0,d,len;
	cout<<"Enter a number: ";cin>>N;
	n=N;
	len = Len(n);
	//cout<<"len:"<<len<<endl;
	for(int i=0;i<len;i++){
		d = n%10;//Lsb
		rev_n += d*power(10,len-i-1);
		n=n/10;
	}
//	cout<<rev_n<<endl;
	if(N==rev_n){cout<<"The number entered is a palindrome."<<endl;}
	else{cout<<"The number entered is not a palindrome."<<endl;}
	return 0;
}
