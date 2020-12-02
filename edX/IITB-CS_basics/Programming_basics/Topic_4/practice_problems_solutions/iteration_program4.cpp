#include<iostream>
using namespace std;

int main()
{
   unsigned long int orig;            // input number
   unsigned long int reversed = 0;      // reverse of original number
   unsigned long int n;             // copy of input number
   
   cout << "Enter a number: ";
   cin >> orig;
   
   // copy the input number
   n = orig;
   
   // construct the reverse of original number 
   while (n > 0)
   {
      reversed = reversed * 10 + n % 10;
      n /= 10;
   }
   
   // A number is a palindrome, if the number remains the same after reversing its digits
   if(orig == reversed)
   {
      cout << "The number entered is a palindrome" << endl;
   }
   else
   {
      cout << "The number entered is not a palindrome" << endl;
   }
   return 0;
}
