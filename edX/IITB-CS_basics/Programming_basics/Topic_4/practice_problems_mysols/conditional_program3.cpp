#include<iostream>
using namespace std;

//program that checks is triangle is rt trig
int main(){
	int a,b,c;
	bool RtTrigFlag;
	cout<<"Enter Length for Side 1: ";cin>>a;
	cout<<"Enter Length for Side 2: ";cin>>b;
	cout<<"Enter Length for Side 3: ";cin>>c;
	RtTrigFlag = (((a*a + b*b)==c*c)||((a*a+c*c)==b*b)||((b*b+c*c)==a*a))?true:false;
	if (RtTrigFlag){cout<<"The given triangle is a right angled triangle."<<endl;}
	else{cout<<"The given triangle is not right angled triangle."<<endl;}
	return 0;
}

