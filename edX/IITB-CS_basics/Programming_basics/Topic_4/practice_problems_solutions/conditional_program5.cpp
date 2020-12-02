/*
This program accepts a character from the user and checks if it
is a vowel or not.
Using switch case.
*/

#include<iostream>
using namespace std;
int main()
{
   char c; //The character to be inputted
   int n; //The number to be outputted
   cout << "Enter a character : ";
   cin >> c;
   switch (c)
   {
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
      n=1;
      cout << "Printing " << n << " since it is a vowel" << endl;
      break;
      default :
      n=0;
      cout << "Printing " << n << " since it is not a vowel" << endl;
   }
   //Note that the variable n is not really required for this particular programme.
   return 0;
}
