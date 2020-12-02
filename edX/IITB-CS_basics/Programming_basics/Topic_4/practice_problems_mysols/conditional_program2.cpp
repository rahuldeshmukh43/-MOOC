#include<iostream>
using namespace std;

int main(){
	int a;
	cout<<"Enter a number: ";cin>>a;
	switch (a){
		case 1:{cout<<"You have chosen to buy an iPad!"<<endl;break;}
		case 2:{
		       cout<<"You have chosen to buy a Nokia tablet!"<<endl;break;}
		case 3:{
		       cout<<"You have chosen to buy a Samsung Table!"<<endl;break;}
		default:{cout<<"Ah!You seen to want an Aakash Tablet. Great choice!"<<endl;break;}

	}
	return 0;
}
