#pragma once
#include"NAlib.h"
#include<vector>
#define MAXDEGREE 105

class Polynomial {
	double coefficients[MAXDEGREE];
	int degree;
	Polynomial();
	Polynomial(double coe[], int exp[], int num);
	Polynomial(char* str);
	

	void AdjustDegree();
	double Value(double x);
	
	Polynomial operator+(Polynomial& other);
	Polynomial operator-(Polynomial& other);
	Polynomial operator*(Polynomial& other);
	Polynomial div(Polynomial& other, Polynomial* reminder);
};

