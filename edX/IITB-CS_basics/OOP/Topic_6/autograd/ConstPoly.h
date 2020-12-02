/* Header file for class def of polynomial
 */

#ifndef CONST_H
#define CONS_H
#include "Polynomial.h"

class ConstPoly:public Polynomial{
	public:
		ConstPoly(int x);
		Polynomial grad();
};

#endif

