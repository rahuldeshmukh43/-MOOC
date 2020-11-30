/*
This program accepts a number i.e. an year from the user and
tells you if that year is a leap year or not.

A Year Y is a leap year if :
Y is divisible 4 and not by 100.
Y is divisible by 400.
*/

#include<iostream>

using namespace std;

int main()
{
   int year;
   cout << "Enter Year: ";
   cin >> year;
   if (year < 1000 || year > 9999)
   {
      cout << "The year entered is not valid" << endl;
   }
   else if (year%400 == 0 || ((year%4==0)&&(year%100!=0)) )
   {
      cout << "The year entered is a leap year" << endl;
   }
   else
   {
      cout << "The year entered is not a leap year" << endl;
   }

}
