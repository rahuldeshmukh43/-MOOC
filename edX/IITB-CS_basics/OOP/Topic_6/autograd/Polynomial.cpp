/* CPP file for class implementation of Polynomial
 */

#include<iostream>
#include<cstring>
#include "Polynomial.h"


//Polynomial
Polynomial::Polynomial():Polynomial(0){}
Polynomial::Polynomial(int x):order(x){
	int i;
	coeff = new float[order+1];
	for(i=0;i<=order;i++){coeff[i]=0;}}

Polynomial Polynomial::operator+(const Polynomial &p){
	int i;
	Polynomial *newpoly;
	if(p.order<=order){//simple addition
	newpoly = new Polynomial(order);
	for(i=0;i<=p.order;i++){
		newpoly->coeff[i]= coeff[i]+ p.coeff[i];}
	for(;i<=order;i++){newpoly->coeff[i]=coeff[i];}
	}
	else{
	newpoly = new Polynomial(p.order);
	for(i=0;i<=order;i++){
		newpoly->coeff[i]= coeff[i] + p.coeff[i];}
	for(;i<=p.order;i++){newpoly->coeff[i] = p.coeff[i];}	
	}
	return *newpoly;
	}
	
Polynomial Polynomial::operator-(const Polynomial &p){
	int i;
	Polynomial *newpoly;
	if(p.order<=order){
	newpoly = new Polynomial(order);
	for(i=0;i<=p.order;i++){
		newpoly->coeff[i]=coeff[i]-p.coeff[i];}
	for(;i<=order;i++){newpoly->coeff[i]=coeff[i];}
	}
	else{
	newpoly = new Polynomial(p.order);
	for(i=0;i<=order;i++){
		newpoly->coeff[i]=coeff[i]-p.coeff[i];}
	for(;i<=p.order;i++){newpoly->coeff[i]=-1*p.coeff[i];}	
	}
	return *newpoly;
	}

Polynomial Polynomial::operator*(const Polynomial &p){
	int i,j,neworder = order+p.order;
	Polynomial *newPoly;

	newPoly = new Polynomial(neworder);
	for(i=0;i<=order;i++){
	for(j=0;j<=p.order;j++){
	newPoly->coeff[i+j] += coeff[i]*p.coeff[j];
	}}
	return *newPoly;
	}
	//sth for division
	
Polynomial Polynomial::grad(){//computes gradient of poly
	int i;
	Polynomial *gradPoly;
	gradPoly = new Polynomial(order-1);
	for(i=1;i<=order;i++){
	gradPoly->coeff[i-1] = i*coeff[i];}
	return *gradPoly;
	}


//PrimaryPoly
PrimaryPoly::PrimaryPoly():Polynomial(1){
		coeff[1]=1;
		}

void printPoly(const Polynomial &p){
int i;
printf("(");
for(i=0;i<=p.order;i++){
//if(p.coeff[i]!=0){
if(i==0){printf("%3.2f + ",p.coeff[i]);continue;}
if(p.coeff[i]!=0){
if(i!=p.order){printf("%3.2f*x^%d + ",p.coeff[i],i);continue;}
printf("%3.2f*x^%d",p.coeff[i],i);
}
}
printf(")\n");
return;
}

