#include<iostream>
using namespace std;

/*
 *How to define constructors for derived class:2
 *
 * When the base class does not have a default constructor
 * we need to be careful while defining the constructor of 
 * derived class. The derived class should also call the non-default
 * cnstructor of base class
 * ##########
 * This program does not compile because of the above reason
 * as a solution look at ./constructor3.cpp
 * ########## 
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


/* 
 * g++     constructor2.cpp   -o constructor2
 * <builtin>: recipe for target 'constructor2' failed
 */
