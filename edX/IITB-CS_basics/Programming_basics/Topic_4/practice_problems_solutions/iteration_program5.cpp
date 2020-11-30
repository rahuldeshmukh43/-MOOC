#include<iostream>
using namespace std;

int main()
{
   int n;            // input number
   int status = 1;    // variable to check whether a number is prime
   int num = 3;      // each of the intermediate prime numbers
   int count;          // to maintain count of prime numbers printed so far
   int c;            // to check divisibility
   
   cout  <<  "Enter a number: ";
   cin  >>  n;
   
   if ( n >= 1 )
   {
       cout  <<  "First "  <<  n  << " prime numbers are : "  <<  endl;
       cout  <<  2  <<  endl;
   }
 
   for ( count = 2 ; count <=n ;  ) //loop that will iterate through n numbers
   {
      for ( c = 2 ; c <= num - 1; c++ )// for each element check whether it is prime or not
      {
         //if number is completely divisible by a number other than 1 and itself,then number is not prime
         if ( num%c == 0 ) 
         {
            status = 0;
            break;
         }
      }
      
      //if it is a prime number, print it and increment the count
      if ( status != 0 )
      {
         cout  <<  num  <<  endl;
         count++;
      }
      
      //reset the status and check next number
      status = 1;
      num++;
   }         
 
   return 0;
}
