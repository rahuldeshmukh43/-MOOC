#include<iostream>
using namespace std;
int main(){
    //Declaring initial variables
    int a,d,n;
    //Input the variables
    cout << "Enter a: "; cin >> a;
    cout << "Enter d: "; cin >> d;
    cout << "Enter n: "; cin >> n;

    cout << "Substituting value of 'a', 'd', and 'n' in the sequence {a, a+d, a+2d, ..., a+nd}" << endl;
    cout << "= {";
    //First for loop for printing the numbers in the form of the formula
    for(int i=0;i<=n;i++)
    {
        if(i==0){cout << a;} // dont write 0*d
        if(i!=0)cout << a << "+" << i << "*" << d;// tn=a+(n-1)*d for an AP
        if(i!=n){cout << ", ";}//no comma after last number
    }
    cout << "}" << endl;
    cout << "={";
     int sum=a;
    for(int i=0;i<=n;i++)
    {
        cout << sum;
        sum=sum+d; // compute the sum
        if(i!=n){cout << ", ";} //no comma after last digit
    }
    cout << "}" << endl;





}
