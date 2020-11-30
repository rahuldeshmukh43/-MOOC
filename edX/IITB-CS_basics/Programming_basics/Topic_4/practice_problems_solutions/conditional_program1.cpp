/*
The following program accepts to numbers from the user and stores them in
variables num1 and num2. It then swaps the values of these variables.
*/

#include<iostream>
using namespace std;
int main()
{
   int num1, num2; //Assigning memory locations to store two int values
   int temp; //A temporary int variable which is needed for swapping
   cout << "Enter value for Number 1: ";
   cin >> num1;
   cout << "Enter value for Number 2: ";
   cin >> num2;
       
   temp = num2; //Store the value of num2 in temp before reassigning the value of num2.   
   num2 = num1; //Assigning the value of num1 to num2
   num1 = temp; //Successfully swapped after assigning value of temp (which now contains the original value of num2) to num1
   
   cout << "The modified values after swapping are :\n";
   cout << "Number 1: " << num1 << endl;
   cout << "Number 2: " << num2 << endl;
   return 0;
}
