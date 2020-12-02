#include<iostream>
using namespace std;

int main()
{
   int n;                        // total count of input numbers
   int x;                        // each indivisual number
   int i;         
   int maximum = -1;               // highest of all input numbers
   int second_maximum = -1;         // second highest of all input numbers
   cout << "Enter n: ";
   cin >> n;
   cout << "Enter " <<  n  << " positive numbers: ";
   for(i=1;i<=n;i++)
   {
      cin >> x;
      
      // if x is greater or equal to than maximum then current max becomes 
      // second max and current input x becomes maximum
      if(x>=maximum)
      {
         second_maximum = maximum;
         maximum = x;
      }
      // if x between maximum and second maximum,  
      // only second maximum gets updated
      else if(second_maximum <= x &&  x < maximum)
      {
         second_maximum = x;
      }
   }
   cout << "From the " <<  n  << " given numbers, the second highest number is "  <<  second_maximum  <<  endl;
   return 0;
}
