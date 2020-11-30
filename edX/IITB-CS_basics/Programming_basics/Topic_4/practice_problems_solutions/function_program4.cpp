#include<iostream>
using namespace std;

bool isPrime(int k)
{
    for(int i=2; i<k; i++)
    {
        if(k%i == 0)
        {
            return false;    // condition if remainder is zero. If it is divisible, we want to return false.
        }
    }
    return true; // If the number is not divisible by any of the numbers from 2 to k-1, then it is prime.
    // Hence, return true after executing the whole loop
}


int main()
{
    int n;
    cout << "Enter the number which you want to check for being prime : ";
    cin >> n;

// The test variable and the conditions given in comments can be used to check the program
    int test;
    test = isPrime(n);
    if (test) {cout << "The number is Prime";}
    else {cout << "The number is not Prime";}
    return 0;
}
