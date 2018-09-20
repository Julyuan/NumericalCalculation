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
	// 保存矩阵的数组
	double** mat;

	// 矩阵的行数、列数
	int row, column;

public:
	// 矩阵的构造函数
	Matrix();	// 默认构造函数
	Matrix(Matrix &other);	// 拷贝构造函数
	Matrix(int row, int column);	// 确定矩阵行数列数的构造函数

	// 矩阵的构造函数
	~Matrix();

	// 将列数为一矩阵转化成向量
	Vector ToVector();

	// 行数、列数特定的子矩阵
	Matrix SubMatrix(int row, int column);
	
	// 矩阵向量拼接，将一个向量拼接到一个矩阵的右侧，返回新矩阵
	static double** MatrixJoin(Matrix& a, Vector& b);

	// 生成一个行数、列数特定的二维数组
	static double** NewMatrix(int row, int column);

	// 删除一个二维数组
	static void DeleteMatrix(int row,  double** mat);
	
	// 将一个二维数组的内容拷贝到矩阵的数组中
	void CopyToArray(double** mat);

	// 计算矩阵的范数
	double GetNorm(int p);
	
	// 获得矩阵的行数
	int GetRow();

	// 获得矩阵的列数
	int GetColumn();

	// 打印矩阵的内容
	void PrintMatrix();

	// 交互式设置矩阵
	void SetMatrix();

	// 将矩阵二维数组的内容全部设成0
	void SetAllElementsZero();

	// 
	void SetMatrix(char str[]);
	
	// 计算方阵的行列式
	double Determinant();
	double PowerMethod(Vector*res, Vector* Eigenvector);
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
