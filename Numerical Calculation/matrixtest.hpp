#ifndef _MATRIX_TEST_H
#define _MATRIX_TEST_H

#include "matrix.h"

void TestMatrix(){
	Matrix a,b, c,d,e,f,g;
	std::cout << "打印矩阵测试" << std::endl;
	a.SetMatrix("[1 1 0 3;2 1 -1 1;3 -1 -1 2;-1 2 3 -1]");
	a.PrintMatrix();
//	b = a.InvMatrix();

	b = a.LUFactorization(1);
	c = a.LUFactorization(2);

	std::cout << std::endl;
	std::cout << "矩阵LU分解测试" << std::endl;
	b.PrintMatrix();
	c.PrintMatrix();

	std::cout << std::endl;
	d.SetMatrix("[1 2 -1;0 3 -1;5 -1 1]");
	std::cout << "矩阵范数测试" << std::endl;
	std::cout << "矩阵的1范数:" << d.GetNorm(1)<< std::endl;
	std::cout << "矩阵的无穷范数" << d.GetNorm()<< std::endl;


	std::cout << "矩阵直接解方程测试" << std::endl;
	e.SetMatrix("[1 1 0 3;2 1 -1 1;3 -1 -1 2;-1 2 3 -1]");
	double jly[4];
	jly[0] = 4;
	jly[1] = 1;
	jly[2] = -3;
	jly[3] = 4;
	Vector va(jly,4), vb;
	va.PrintVector();
	vb = e.LinearEquation(va);
	vb.PrintVector();
	std::cout << "L, U矩阵解方程测试" << std::endl;
	f.SetMatrix("[1 1 0 3;2 1 -1 1;3 -1 -1 2;-1 2 3 -1]");
	f.LUFactorization(0).PrintMatrix();
	f.LUFactorization(1).PrintMatrix();

	std::cout << "矩阵迭代解方程测试" << std::endl;

	g.SetMatrix("[10 -1 2 0; -1 11 -1 3; 2 -1 10 -1; 0 3 -1 8]");
	//Vector temp(6,25,-11,15);
	
	//g.LinearEquationIterativeMethod(temp);

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
