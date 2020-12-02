#include<iostream>
using namespace std;
//function declarations
int rec_enc(int q1, int q2);
int power(int base, int exp);

//function: recursively encode using q1,q2 value
//PRE:1<= m,n <=10
int rec_enc(int m, int n){
	if(m==1 && n==1){return 6;}
	if((m>1)&&(n>1)){
	return 2*rec_enc(m-1,n); //exhaust m
	}
	else{//exhaust n
	return 3*rec_enc(m,n-1);
	}
}
//POST: return 2^m*3^n

//PRE: 1<=exp<=10
//     base > 0
//function: recursively compute power using base and exponent
int power(int base, int exp){
	if(exp==1){return base;}
	else{return base*power(base, exp-1);}
}
//POST: returns int 1<= base^exp <= 2^31 -1

//Program to compute the encoding of q1,q2 marks of N students
int main(){
	int N,i,q1,q2, coded;
	//read N
	cout<<"Enter the number of students: ";cin>>N;
	for(i=0;i<N;i++){//loop for each student
		cout<<"Enter q1,q2 marks for student #"<<i+1<<": ";
		cin>>q1>>q2;
		//compute cipher
		coded = rec_enc(q1,q2);
		{//print info
		cout<<"i:"<<i+1<<" ";
		cout<<"q1,q2:"<<q1<<","<<q2<<" ";
		cout<<"coded:"<<coded<<endl;		
		}
	}
	return 0;
}
