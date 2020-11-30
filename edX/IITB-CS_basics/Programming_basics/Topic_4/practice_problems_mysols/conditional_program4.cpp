#include<iostream>
using namespace std;
//Program that check is year is a leap year
int main(){
	int yr;
	bool leapFlag;
	cout<<"Enter year: ";cin>>yr;
	if(yr<1400){cout<<"The year entered is not valid"<<endl;return -1;}
	if (yr%400==0){leapFlag = true;}
	else{
		if(yr%100==0){leapFlag=false;}
		else{
			if(yr%4==0){leapFlag=true;}
			else{leapFlag=false;}
		}
	}
	if(leapFlag){cout<<"The year entered is a leap year"<<endl;}
	else{cout<<"The year entered is not a leap year"<<endl;}
	return 0;
}
