#include<iostream>
using namespace std;

/*
 * Example showing that assignment operator is not derived from the base class
 * The program does not compile if we try to assign base class object to derived class object
 */

//class defs
class base {
	public:
		int id;
		float balance;
		base(){
		cout<<"Default constructor: base\n";
		id=0;balance=0.0;
		}
		base(int a){
		cout<<"Non-Default constructor:base\n";
		id=a; balance=0.0;//initializations
		}
		~base(){cout<<"Destructor for base\n";}
		base & operator=(base &a){
		id = a.id;
		cout<<"base class operator\n";
		return *this;
		}
		void printinfo(){
		cout<<"Printing in base: ";
		cout<<id<<", "<<balance<<endl;
		return;
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
			return;
		}
};

class current: public base{
	public:
		int amount; int overdraft;
		void printinfo(){
			base::printinfo();
			cout<<"Printing in current: ";
			cout<<amount<<", "<<overdraft<<endl;
			return;
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
cout<<"---------------\n";
ac1=ac2;
ac1.printinfo();
// default assignment operator for savings will copy data members:age,ATM from ac1 to ac2
// As ac1 does not have a data member age or ATM we get a compilation error
//ac2 = ac1;
//ac2.printinfo();
return 0;
}

