#pragma once

#include"polynomial.h"


void TestPolynomial() {
	double a[5] = { 1.0,2.0,3.0,4.0,5.0 };
	Polynomial test(a, 5);
	test.Print();
}