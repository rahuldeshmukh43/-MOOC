#include<iostream>
using namespace std;

int main()
{
   int n;      // number of rows
   int i;      // row number
   int j;      // column number
   cout << "Enter the number of rows: ";
   cin >> n;
   // the sample output has n=4
   for(i=1;i<=n;i++)
   {
      //in row i print n-i spaces first
      for(j=n-i;j>=1;j--)
      {
         cout << " ";
      }
      //then print 2i-1 '*'s
      for(j=1;j<=2*i-1;j++)
      {
         cout << "*";
      }
      cout << endl;
   }
   return 0;
}
