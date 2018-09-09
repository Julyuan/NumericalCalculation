#ifndef _MATRIX_H
#define _MATRIX_H

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include"NAlib.h"

class Matrix
{
public:
	double** mat;
	int row, column;
	
public:	
	Matrix();
	~Matrix();
	Matrix(Matrix &other);
	Matrix(int row, int column);
	Matrix SubMatrix(int row, int column);
	static double** NewMatrix(int row, int column);
	static void DeleteMatrix(int row,  double** mat);
	void CopyToArray(double** mat);

	int GetRow();
	int GetColumn();
	void PrintMatrix();
	void SetMatrix();
	void SetAllElementsZero();
	void SetMatrix(char str[]);
	double Determinant();
	Matrix InvMatrix();
	Matrix LUFactorization(int option);

	Matrix operator+(Matrix& other);
	Matrix operator*(Matrix& other);
	Matrix operator-(Matrix& other);
	Matrix& operator=(Matrix& other);
	double* operator[](int index);
};


class PositiveDefiniteMatrix :public Matrix {
	bool Judge();
	Matrix LDLFactorization(int option);
	Matrix Choleskis();

};


#endif
