/* Header file for class def of polynomial
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial{
	public:
	int order;//order of polynomial: highest pos power
	float* coeff;
	
	Polynomial();	

	Polynomial(int x);

	Polynomial operator+(const Polynomial &p);
	
	Polynomial operator-(const Polynomial &p);

	Polynomial operator*(const Polynomial &p);
	//sth for division
	
	virtual Polynomial grad();
};

class PrimaryPoly:public Polynomial{
	public:
		PrimaryPoly();
};

void printPoly(const Polynomial &p);

#endif
