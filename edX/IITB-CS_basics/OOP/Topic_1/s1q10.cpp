#include<iostream>
using namespace std;
int main(){
   int A[]={0,1,2,3,4,5,6,7}; 
   int n=8; 
   int i,j,k,l,temp; 
   int step=2; 
   for(i=0;i<n-step;i++){ 
      for(j=i;j<i+step;j++){ 
         temp=A[j]; 
         A[j]=A[j+1]; 
         A[j+1]=temp; 
      } 
      step=(step*2)-1; 
   } 

   for(i=0;i<n;i++) 
      cout<<A[i]<<" "; 
   return 0;
}
