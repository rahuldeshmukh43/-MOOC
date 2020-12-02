#include<iostream>
using namespace std;

int main(){
int N, *A;
cout<<"Enter num of elements for the array: ";cin>>N;
A = new int[N];//A is a ptr to the int array of size N on data segment (heap)
if(A==NULL){cout<<"Dynamic memory not allocated"<<endl;return -1;}
//read in values of A
for(int i=0;i<N;i++){
cout<<"value #"<<i+1<<": ";cin>>A[i];
}
//print the list
cout<<"Input array is:"<<endl;
for(int i=0;i<N;i++){
cout<<*(A + i)<<" ";//content of A + i address (using integer artihmetic)
}
cout<<endl;
//deallocate A
delete[] A;
return 0;
}
