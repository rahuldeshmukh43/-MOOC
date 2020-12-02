#include<iostream>
using namespace std;

/*
 *How to define constructors for derived class
 */

//class defs
class base {
	public:
		int id;
		float balance;
		base(){
		cout<<"Default constructor:base\n";
		id=0; balance=0.0;//initializations
		}
		void printinfo(){
		cout<<"Printing in base: ";
		cout<<id<<", "<<balance<<endl;
		//return;
		}
};

class savings: public base{
	public:
		int age; long int ATM;
		savings(int x, int y):age(x),ATM(y){
		cout<<"derived Constructor for savings"<<endl;
		}
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
base ac1;
ac1.printinfo();
int age=20;
int ATM=200;
savings ac2(age,ATM);
ac2.printinfo();
return 0;
}
