#pragma once
#include"NAlib.h"

class Vector {
public:
	double* vec;
	int dimension;
	Vector();
	Vector(double a[], int dim);
	Vector(Vector& other);
	Vector(char* str);
	Vector(int dim);
	double Norm(int dimension);
	~Vector() {
		delete[] vec;
	}
	void SetAllElementsZero();

	double dot(const Vector& other);

	Vector operator-();
	Vector operator-(Vector& other);
	Vector operator+(Vector& other);
	Vector operator=(const Vector& other);
	Vector operator/(double other);
	double& operator[](int index);


};