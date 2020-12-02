#include<iostream>
using namespace std;

/*
 *How to define destructors for derived class:
 *
 */

//class defs
class base {
	public:
		int id;
		float balance;
		base(int a){
		cout<<"Non-Default constructor:base\n";
		id=a; balance=0.0;//initializations
		}
		~base(){cout<<"Destructor for base\n";}
		void printinfo(){
		cout<<"Printing in base: ";
		cout<<id<<", "<<balance<<endl;
		//return;
		}
};

class savings: public base{
	public:
		int age; long int ATM;
		savings(int x, int y, int z):base(x), age(y),ATM(z){
		cout<<"derived Constructor for savings"<<endl;
		}
		~savings(){cout<<"Destructor for savings"<<endl;}
		void printinfo(){
			base::printinfo();
			cout<<"Printing in savings: ";
			cout<<age<<", "<<ATM<<endl;
			//return;
		}
};

class current: public base{
	public:
		int amount; int overdraft;
		void printinfo(){
			base::printinfo();
			cout<<"Printing in current: ";
			cout<<amount<<", "<<overdraft<<endl;
			//return;
		}
};

//main program
int main(){
base ac1(1);
ac1.printinfo();
int id=10;
int age=20;
int ATM=200;
savings ac2(id,age,ATM);
ac2.printinfo();
return 0;
}
