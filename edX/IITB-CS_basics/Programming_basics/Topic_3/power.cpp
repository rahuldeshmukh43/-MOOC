#include<iostream>
using namespace std;

// Program that computes 
// a = 3^min(m,n) and b = 2^max(m,n)
// using only one loop
int main(){
	int m,n,a=1,b=1;
	int im, in, maxMN=0, minMN=0;
	//take input
	cout<< "Enter the value of m,n: "<<endl;
	cin >>m >>n;
	//start computing a & b
	for(im=m, in=n ; ((im>=1) || (in>=1)) ; im--, in--){//loop max(m,n) times
		b *= 2; maxMN+=1;
		//check if im or in is less than 1
		if ((im>=1) && (in>=1)){a *= 3; minMN += 1;}
	}
	//print results
	cout<<"Inputs m,n: "<<m<<","<<n<<endl;
	cout<<"min,max: "<<minMN<<","<<maxMN<<endl;
	cout<<"3^min(m,n): "<<a<<endl;
	cout<<"2^max(m,n): "<<b<<endl;
	return 0;

}
