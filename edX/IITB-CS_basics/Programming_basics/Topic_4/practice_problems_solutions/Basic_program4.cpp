#include <iostream>
using namespace std;

int main()
{
   int a;
   int b; 
   cout << "This is a program to print the expansion of (a+b)^2" << "\n";
   cout << "Enter the value of a: ";
   cin >> a;
   cout << "Enter the value of b: " ;
   cin >> b;
   int ab = a * b;
   cout << "(" << a << "+" << b << ")^2" <<endl;
   cout << " = " << a << "^2 + " << "2*" << a << "*" << b << " + " << b << "^2" << endl;
   cout << " = " << a*a << " + " << 2*a*b << " + " << b*b << endl;
   cout << " = " << (a*a) + (2*a*b) + (b*b) << endl;   
   return 0;
}
