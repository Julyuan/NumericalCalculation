#ifndef _MATRIX_H
#define _MATRIX_H

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include"vector.h"
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
	Vector ToVector();
	Matrix SubMatrix(int row, int column);
	static double** MatrixJoin(Matrix& a, Vector& b);
	static double** NewMatrix(int row, int column);
	static void DeleteMatrix(int row,  double** mat);
	void CopyToArray(double** mat);

	double GetNorm(int p);
	int GetRow();
	int GetColumn();
	void PrintMatrix();
	void SetMatrix();
	void SetAllElementsZero();
	void SetMatrix(char str[]);
	double Determinant();
	Vector LinearEquation(Vector& b, int mode);
	Vector LinearEquationDirectMethod(Vector& b);
	Vector LinearEquationIterativeMethod(Vector& b);
	Matrix InvMatrix();
	Matrix LUFactorization(int option);

	Matrix operator+(Matrix& other);
	Matrix operator*(Matrix& other);
	Matrix operator-(Matrix& other);
	Matrix& operator=(Matrix& other);
	Vector operator*(Vector& other);
	bool operator==(Matrix& other);
	double*& operator[](int index);
};


class PositiveDefiniteMatrix :public Matrix {
	bool Judge();
	Matrix LDLFactorization(int option);
	Matrix Choleskis();

};


#endif
