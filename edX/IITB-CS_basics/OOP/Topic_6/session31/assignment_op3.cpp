#include<iostream>
using namespace std;
/*
 * Object of classes with pointers and references
 * trying out assignment using them
 */

class base{
	public:
		int id;
		float balance;
		void print(){
		cout<<"base called\n";
		return;
		}
};

class savings: public base{
	public:
		int age;
		long int ATM;
		void print(){
		cout<<"savings called\n";
		return;
		}
};

int main(){
base b; savings s;
b.id=1; b.balance=15000;
s.id=2; s.balance=67890; s.age=20; s.ATM=240;

cout<<"old b: "<<b.id<<", "<<b.balance<<endl;
b = s;//allowed assignment
cout<<"new b: "<<b.id<<", "<<b.balance<<endl;
//cout<<s.id<<", "<<s.balance<<endl;
//s=b; //not allowed

base *bptr;
savings *sptr;
bptr = &s;//allowed?(yes): s is of derived class and hence an address of s can be thought of an address of base object
cout<<"access using bptr:\n"<<bptr->id<<", "<<bptr->balance<<endl;
//sptr=&b;//not allowed as &b is address to base object which is not a ptr to derived object
base &bref=s;//allowed s is ptr to object of type savings which can be thought of reference to base type object
cout<<"member fun access using refernce bref:\n";
bref.print();
return 0;
}
