#include<iostream>
using namespace std;

void checkPerfect(int k)
{
    int sum = 0; // declare this local variable to check further the test of perfectness
    // use for loop to find the factors of the given number
    for(int i=1; i<k; i++)
    {
        if(k%i == 0)   // condition if remainder is zero
        {
            cout  << i <<  " is a factor\n";
            sum = sum + i;   // we keep adding the factors in this cumulative sum
        }
    }
    if(sum == k) cout << "The number is perfect";
    else cout << "The number is not perfect";
}


int main()
{
    int n; // the number we will check for
    cout << "Enter the number you want to check if it is perfect  ";
    cin >> n;
    checkPerfect(n);
    return 0;
}
