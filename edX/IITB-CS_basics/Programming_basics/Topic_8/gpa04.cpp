#include<iostream>
using namespace std;

struct rational{
int numr;
int den;
};

void reduce(struct rational *irat, struct rational *orat);
bool isEqual(struct rational *num1, struct rational *num2);

void reduce(struct rational *irat, struct rational *orat){
int factor, temp;
factor = (irat->numr > irat->den)? irat->den:irat->numr;//smaller of the two
if((factor==1)||(factor==0)){return;}//nothing to reduce
//orat->numr= irat->numr;
//orat->den = irat->den;
while(factor>1){
temp=factor;
if(((orat->numr)%factor==0)&&((orat->den)%factor==0)){//found common factor
orat->numr/=factor;
orat->den/=factor;
temp = (orat->numr > orat->den)? orat->den:orat->numr;
}
if (temp<factor-1){factor=temp;}
else{factor--;}
}
return;
}

bool isEqual(struct rational *num1, struct rational *num2){
if((num1->numr==num2->numr)&&(num1->den==num2->den)){return true;}
return false;
}

//Program for checking two positive ratinoal numbers
int main(){

bool flagEqual=false;
rational *r1, *r2, *reduced_r1, *reduced_r2;

//take input of two rational numbers
r1 = new rational;
r2 = new rational;
reduced_r1= new rational;
reduced_r2 = new rational;

cout<<"Details of Num1:"<<endl;
cout<<"Numerator: ";
cin>>r1->numr;
reduced_r1->numr = r1->numr;

cout<<"Denominator: ";
cin>>r1->den;
reduced_r1->den=r1->den;

cout<<"Details of Num2:"<<endl;
cout<<"Numerator: ";
cin>>r2->numr;
reduced_r2->numr = r2->numr;

cout<<"Denominator: ";
cin>>r2->den;
reduced_r2->den = r2->den;

//reduce rationals
reduce(r1, reduced_r1);
reduce(r2, reduced_r2);
//print reduced rationals
cout<<"Reduced rat1: "<<reduced_r1->numr<<"/"<<reduced_r1->den<<endl;
cout<<"Reduced rat2: "<<reduced_r2->numr<<"/"<<reduced_r2->den<<endl;

//check if equal
flagEqual=isEqual(reduced_r1, reduced_r2);

//print info
if(flagEqual){
cout<<"Both rational numbers are equal"<<endl;}
else{cout<<"Both rational numbers are not equal"<<endl;}

return 0;
}
