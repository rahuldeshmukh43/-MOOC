#include<iostream>
using namespace std;


int main(){
    //Declaring initial variables
    int a,r,n;
    //Input the variables
    cout << "Enter a: "; cin >> a;
    cout << "Enter r: "; cin >> r;
    cout << "Enter n: "; cin >> n;


    cout << " Substituting value of 'a', 'r', and 'n' in the sequence {a, ar^1, ar^2, ..., ar^n}" << endl;
    cout << "= {";
    //First for loop for printing the numbers in the form of the formula
    for(int i=0;i<=n;i++)
    {
        if(i==0){cout << a;} // don't write r^0
        if(i!=0)cout << a << "*" << r << "^" << i;// a*r^i
        if(i!=n){cout << ", ";} // no comma after last number for a GP
    }
    cout << "}" << endl;
    cout << "={";
    int sum=a;

    //Second for loop for computing and printing required numbers
    for(int i=0;i<=n;i++)
    {
        cout << sum;
        sum=sum*r;
        if(i!=n){cout << ", ";} //no comma after last digit
    }
    cout << "}" << endl;
}

