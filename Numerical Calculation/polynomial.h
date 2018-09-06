#pragma once
#include"NAlib.h"
#include<vector>
#define MAXDEGREE 105

class Polynomial {
private:
	double coefficients[MAXDEGREE];
	int degree;

public:
	Polynomial();
	Polynomial(Polynomial& other);
	Polynomial(double coe[], int exp[], int num);
	Polynomial(double zero_points[], int num);
	Polynomial(char* str);
	
	void SetTerm(int exp, double coe);
	void AdjustDegree();
	void Print();
	void Clear();
	double Value(double x);
	
	Polynomial operator+(Polynomial& other);
	Polynomial operator-(Polynomial& other);
	Polynomial operator*(Polynomial& other);
	Polynomial div(Polynomial& other, Polynomial* reminder);
};

