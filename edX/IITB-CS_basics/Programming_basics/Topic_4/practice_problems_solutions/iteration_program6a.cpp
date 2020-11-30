#include<iostream>
using namespace std;
int main()
{

    cout << "Celsius" << " " << "Farenheit" << endl;
    for(float i=10;i<=30;i++)
        {
            cout << i << " " << 9*i/5+32 << endl;
            /*Here 'i' is the value of temperature in degree celsius
            the formula for converting it into farenheit is:
            T(deg farenheit)=(9/5)*(deg cesluis)+32
            So that is printed after it.
            The loop continues from i=10 to i=30.
             We have used float data type for 'i' because we want calculations  involving decimal points.
            */
        }
}
