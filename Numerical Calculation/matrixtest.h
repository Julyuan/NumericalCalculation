#ifndef _MATRIX_TEST_H
#define _MATRIX_TEST_H

#include "matrix.h"

void TestMatrix(){
	Matrix a,b, c,d,e,f;
	a.SetMatrix("[1 1 0 3;2 1 -1 1;3 -1 -1 2;-1 2 3 -1]");
	a.PrintMatrix();
//	b = a.InvMatrix();

	b = a.LUFactorization(1);
	c = a.LUFactorization(2);

	b.PrintMatrix();
	c.PrintMatrix();

//	std::cout << a[0][0] << std::endl;
	//std::cout << std::endl;
	//b.SetMatrix("[1,1,1;1,1,1;1,1,1]");
	//b.PrintMatrix();
	//std::cout << b.column<< " "<< b.row<<std::endl;
	//c = (a + b);
	//d = (a - b);
	//e = (a*b);

	//c.PrintMatrix();
	//d.PrintMatrix();
	//e.PrintMatrix();
//	std::cout << "a的行列式：" << a.Determinant() << std::endl;
	//std::cout << std::endl;
}







#endif
