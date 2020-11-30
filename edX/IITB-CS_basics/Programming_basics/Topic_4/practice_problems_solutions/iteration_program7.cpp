#include<iostream>
using namespace std;
int main()
{
    cout << "Enter the number: ";
    int num; cin >> num; //Print the number as it is
    cout << "The reverse of " << num << " is ";
    int digit; // Digits will be printed one after another
    while(num>0)
        {
            digit=num%10; // The last digit of the number will be stored in the variable eg 123%10=3
            num=num/10; // The last digit will be eliminated from the number eg 123/10=12;
            cout << digit;// Print the extracted last digit
            /* Note that we have chosen int data type for the variable num so that on division by 10,
            the quotient shall be the one excluding the last digit and on modulus with 10,
            we will get the required last digit. Printing the last digits is same as printing the original
            number in the reverse order */
        }
    cout << endl;
}
