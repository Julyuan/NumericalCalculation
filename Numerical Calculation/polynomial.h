#pragma once
#include"NAlib.h"

class Polynomial {
	double* coefficients;
	int degree;
	Polynomial();
	Polynomial(double coe[], int exp[], int num);
	Polynomial(char* str);

	double Value(double x);
	
	Polynomial operator+(Polynomial& other);
	Polynomial operator-(Polynomial& other);
	Polynomial operator*(Polynomial& other);
	Polynomial div(Polynomial& other, Polynomial* reminder);
};

