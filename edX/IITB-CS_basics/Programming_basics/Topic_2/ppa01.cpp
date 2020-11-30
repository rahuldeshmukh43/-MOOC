#include<iostream>
using namespace std;

//main program: assigns value ot ageResult using the table given inin the exercise
int main(){
	int age,ageresult;
	cout<<"Enter the age:"<<endl;
	cin >> age;
	//switch case
	switch (age){
		case 0 ... 5:{ageresult=0;break;}
		case 6 ... 12:{ageresult=1;break;}
		case 13 ... 19:{ageresult=2;break;}	
		case 20 ... 50:{ageresult=3;break;}
		case 51 ... 60:{ageresult=4;break;}
		case 61 ... 101:{ageresult=5;break;}
		default: {ageresult=-1;}
	}
	cout<<"Age result: "<<ageresult<<endl;
	return 0;
}
