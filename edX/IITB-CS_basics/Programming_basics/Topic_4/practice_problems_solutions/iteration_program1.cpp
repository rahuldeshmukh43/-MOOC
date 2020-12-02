#include<iostream>
using namespace std;

int main()
{
   int i;         // row count
   int height;      // number of rows to print
   int j;         // column count
   int length;      // number of columns to print
   
   cout << "Enter length of the rectangle: ";
   cin >> length;
   cout << "Enter height of the rectangle: ";
   cin >> height;
   for(i=1;i<=height;i++)
   {
      // if it is first or last row, print length number of *
      if(i==1 || i==height)
      {
         for(j=1;j<=length;j++)
         {
            cout << "*";
         }
      }
      else
      {
         cout << "*";//first column - print *
         
         // second to second last column - print spaces
         for(j=2;j<=length-1;j++)
         {
            cout << " ";
         }
         cout << "*";//last column - print *
      }
      cout << endl;
   }
   return 0;
}
