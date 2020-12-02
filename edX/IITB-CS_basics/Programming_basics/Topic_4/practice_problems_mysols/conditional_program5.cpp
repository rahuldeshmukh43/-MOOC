#include<iostream>
using namespace std;
//program that identifies a vowel
int main(){
	char c;
	bool vowFlag;
	cout<<"Enter a character: ";cin>>c;
	switch(int(c)){
	case(int('A')):
	case(int('E')):
	case(int('I')):
	case(int('O')):
	case(int('U')):
	case(int('a')):
	case(int('e')):
	case(int('i')):
	case(int('o')):
	case(int('u')):vowFlag=true;break;
	default:vowFlag=false;break;
	}
	if (vowFlag){cout<<"Printing 1 since it is a vowel"<<endl;}
	else{cout<<"Printing 0 as it is not a vowel"<<endl;}
	return 0;
}
