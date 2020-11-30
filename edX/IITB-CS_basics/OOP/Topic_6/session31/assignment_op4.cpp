#include<iostream>
using namespace std;
/*
 * Overloading the assignment operator
 */
class base{
	public:
		int id;
		float balance;
		base(int x):id(x){}
		base & operator=(base &a){
		id=a.id;
		cout<<"base class operator\n";
		return *this;
		}
};

class savings: public base{
	public:
		int age;
		long int ATM;
		savings(int x, int y):base(x),age(y){}
		savings & operator=(base &b){
			cout<<"derived overloaded operator\n";
			cout<<"assignment using base class\n";
			base::operator=(b);
			return *this;
		}
};

int main(){
base b(10);
savings s1(11,20), s2(12,30);

cout<<"old s2: "<<s2.id<<", "<<s2.age<<endl;
s2=s1; // allowed as both of same class, uses base class operator=
cout<<"new s2: "<<s2.id<<", "<<s2.age<<endl;

cout<<"old b: "<<b.id<<endl;
b = s1;//allowed as s1 is thought of as type base
cout<<"new b: "<<b.id<<endl;
b.id = 50;

s2 = b;// using operator overloading
cout<<"mod s2: "<<s2.id<<", "<<s2.age<<endl;
return 0;
}
