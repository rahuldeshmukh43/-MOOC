/*
This program illustrates the use of switch-case-default statement
*/

#include<iostream>
using namespace std;
int main()
{
   int n; //Input number
   cout << "Enter a number: ";
   cin >> n;
   switch (n) 
   {
      case 1 :
      cout << "You have chosen to buy an iPad!\n";
      break;
      case 2 :
      cout << "You have chosen to buy a Nokia tablet!\n";
      break;
      case 3 :
      cout << "You have chosen to buy a Samsung tablet!\n";
      break;
      default :
      cout << "Ah! You seem to want an Aakash Tablet. Great Choice!\n";
   } 
   return 0;
}
