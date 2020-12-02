#include<iostream>
using namespace std;

void swapByRef(int &a, int &b);
void swapByPtr(int *ptrA, int *ptrB);
void sum_sqrs(int *ptrA, int *ptrB, int *out, int *out2);

void swapByRef(int &a, int &b){
int temp;
temp = a;
a = b;
b = temp;
return;
}

void swapByPtr(int *ptrA, int *ptrB){
int temp;
temp = *ptrA;
*ptrA=*ptrB;
*ptrB=temp;
return;
}

void sum_sqrs(int *ptrA, int *ptrB, int *out, int *out2){
*out = (*ptrA)*(*ptrA) + (*ptrB)*(*ptrB);
*out2 = (*ptrA) + *ptrB;
return;
}


int main(){
int a,b,*ans, sum;
cout<<"Enter a,b: ";cin>>a>>b;
swapByRef(a,b);
cout<<"a,b: "<<a<<" , "<<b<<endl;
swapByPtr(&a, &b);
cout<<"a,b: "<<a<<" , "<<b<<endl;
sum_sqrs(&a,&b,ans, &sum);
cout<<"a*b: "<<*ans<<endl;
cout<<"a+b: "<<sum<<endl;
return 0;
}
