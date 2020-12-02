#include<iostream>
using namespace std;
//Program to separate fractional part from a floating number
int main(){
	float num, fp;
	cout<<"Enter a floating point number : ";cin>>num;
	fp = num - int(num);
	cout<<"Fractional part of the number "<<num<<" is "<<fp<<endl;
	return 0;
}
