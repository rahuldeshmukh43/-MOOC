#include<iostream>
using namespace std;

/*
 *Program which redefines the member function of base class for derived class. You can access the member function of base class using the scope operator base::memberfun()
 */

//class defs
class base {
	public:
		int id;
		int balance;
		void printinfo(){
		cout<<"Printing in base: ";
		cout<<id<<", "<<balance<<endl;
		//return;
		}
};

class savings: public base{
	public:
		int age; long int ATM;
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
base ac1; savings ac2; current ac3;
ac1.id = 1; ac1.balance = 10000;
ac2.id = 2; ac2.balance = 20000;
ac3.id = 3; ac3.balance = 30000;

ac2.age =29; ac2.ATM=123456;

ac3.amount = 1000; ac3.overdraft=2500;

ac1.printinfo();
ac2.printinfo();
ac3.printinfo();
return 0;
}
