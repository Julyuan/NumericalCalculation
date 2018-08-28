#pragma once
#include"matrix.h"

class Vector {
public:
	double* vec;
	int dimension;
	Vector();
	Vector(double a[], int dim);
	Vector(Vector& other);
	Vector(int dim);
	~Vector() {
		delete[] vec;
	}
	void SetAllElementsZero();

	double dot(const Vector& other);

	Vector operator*(Matrix& other);
	Vector operator=(const Vector& other);
	double operator[](int index);
};