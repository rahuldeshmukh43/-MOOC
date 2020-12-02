#include <iostream>
using namespace std;
int main() 
{
   double num;
   cout << "Enter a floating point number : ";
   cin >> num;
   int intpart = (int)num;
   double decpart = num - intpart;
   cout << "Fractional part of the number " << num << " is " << decpart << endl; 
   return 0;
} 
