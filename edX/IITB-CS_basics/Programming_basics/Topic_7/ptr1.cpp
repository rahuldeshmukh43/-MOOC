#include<iostream>
using namespace std;

int main(){
int a,*ptrA;
float b, *ptrB;
char c, *ptrC;
cout<<"int a: ";cin>>a;
cout<<"float b: ";cin>>b;
cout<<"char c: ";cin>>c;
ptrA=&a; ptrB=&b; ptrC=&c;
cout<<"ptrA: "<<ptrA<<" *ptrA:"<<*ptrA<<endl;
cout<<"ptrB: "<<ptrB<<" *ptrB:"<<*ptrB<<endl;
cout<<"ptrC: "<<(void *) ptrC<<" *ptrC:"<<*ptrC<<endl;
return 0;
}
