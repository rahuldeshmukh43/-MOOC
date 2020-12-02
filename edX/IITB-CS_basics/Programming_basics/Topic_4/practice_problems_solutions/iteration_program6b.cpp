#include<iostream>
using namespace std;


int main()
{
    cout << "Celsius" << " " << "Farenheit" << endl;
    float i=10;
    while(i<=30)
        {
            cout << i << " " << 9*i/5+32 << endl;
            i++;
            /*Here 'i' is the value of temperature in degree celsius
            the formula for converting it into farenheit is:
            T(deg farenheit)=(9/5)*(deg cesluis)+32
            So that is printed after it.
            The while loop begins from i=10. It runs till i remains less than or equal to 30.
            We have used float data type for 'i' because we want calculations  involving decimal points.
            */
        }

}
