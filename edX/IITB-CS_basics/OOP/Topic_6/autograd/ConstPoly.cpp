/* CPP file for class implementation of Polynomial
 */

#include "Polynomial.h"
#include "ConstPoly.h"

//ConstPoly
ConstPoly::ConstPoly(int x):Polynomial(0){
		coeff[0]=x;
		}

Polynomial ConstPoly::grad(){
		Polynomial *p;
		p = new Polynomial(0);
		p->coeff[0]=0;
		return *p;}
