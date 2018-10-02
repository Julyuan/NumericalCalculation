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

	double MaxElement(int mode = 0);	//获取矩阵中最大的元素，mode = 0代表绝对值，否则是非绝对值
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
	double GetNorm(int p = 0);
	
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

	// 解析字符串设置矩阵
	void SetMatrix(char str[]);
	
	// 计算方阵的行列式
	double Determinant();

	// 利用power method求解绝对值最大的特征值，缺陷是只适用于单根的情况
	double PowerMethod(Vector*res, Vector* Eigenvector);

	// 求解线性方程组，有两种方法
	Vector LinearEquation(Vector& b, int mode);
	Vector LinearEquationDirectMethod(Vector& b);
	Vector LinearEquationIterativeMethod(Vector& b);
	
	// 求解逆矩阵
	Matrix InvMatrix();

	// 矩阵LU分解
	Matrix LUFactorization(int option);

	// 矩阵相关的运算符重载
	Matrix operator+(Matrix& other);
	Matrix operator*(Matrix& other);
	Matrix operator-(Matrix& other);
	Matrix& operator=(Matrix& other);
	Vector operator*(Vector& other);
	bool operator==(Matrix& other);

	// 矩阵元素访问符
	double*& operator[](int index);
};


class PositiveDefiniteMatrix :public Matrix {
	bool Judge();
	Matrix LDLFactorization(int option);
	Matrix Choleskis();

};


#endif
