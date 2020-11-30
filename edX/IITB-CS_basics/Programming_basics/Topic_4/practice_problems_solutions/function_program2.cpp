#include<iostream>
using namespace std;

int factorial_finder(int input_value)  // we will use this function to calculate the factorial of a number
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

// we will use the value of factorial in calculating nCr and also we will use the fact that nCr is an integer.
int n_choose_r(int n,int r)
{
    int numerator, denominator_1, denominator_2, result; // split nCr as [ n!/(r!*(n-r)!) ] and calculate each term individually
    numerator = factorial_finder(n); // = n!
    denominator_1 = factorial_finder(r);  // = r!
    denominator_2 = factorial_finder(n-r); // = (n-r)!
    result = numerator/(denominator_1*denominator_2); // final answer that must be returned
    return result;
}

int main()
{
    int n,r,nCr;
    cout << "Enter the values of n and r to compute nCr " << endl;
    cin >> n >> r;

    if(r<=n && r>=0)
    {
        nCr = n_choose_r(n,r);
        cout << "The value of nCr is " << nCr << endl;
    }
    else
    {
        cout << "Please enter valid input " << endl;
    }


    return 0;
}
