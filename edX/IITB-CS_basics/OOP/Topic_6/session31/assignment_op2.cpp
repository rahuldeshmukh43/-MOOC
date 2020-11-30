#include<iostream>
using namespace std;

class base{
	public:
		int id;
		float balance;
};

class savings: public base{
	public:
		int age;
		long int ATM;
};

int main(){
base b;
b.id=1; b.balance=15000;

savings s;
s.id=2; s.balance=67890;

cout<<b.id<<", "<<b.balance<<endl;
cout<<s.id<<", "<<s.balance<<endl;

//b = s;//assign object of derived to base: not a problem
s=b;//assign object of base to derived: compilation error
cout<<"-----------\n";
cout<<b.id<<", "<<b.balance<<endl;
cout<<s.id<<", "<<s.balance<<endl;
return 0;
}
