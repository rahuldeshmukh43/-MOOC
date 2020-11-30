#include<iostream>
using namespace std;

// The function definition comes first. Define the function for finding the factorial given a number and returning the final answer
int factorial_finder(int input_value)
{
    int local_factorial = 1; // Declare a local variable to calculate the final answer
    for(int i=1; i<=input_value; i++)
    {
        // In this loop, we go from 1 to n and keep updating
        //the final answer every time we run the loop
        local_factorial = local_factorial*i;
    }
    return local_factorial; // Return the final answer
}

// The main program starts here
int main()
{
    int n=0; //Declare the variable name of the input variable
    int factorial=1;  // Declare the variable that we will output
    cout << "Enter a positive number: ";
    cin >> n;

    if(n<0) // We must show an error if the entered number is negative
    {
        cout << "Entered number is negative" << endl;
    }
    else    // If the number satisfies the given criteria, then we call the function
    {
        factorial = factorial_finder(n);
        cout << "The factorial of " << n << " is " << factorial << endl;
    }
    return 0;
}
