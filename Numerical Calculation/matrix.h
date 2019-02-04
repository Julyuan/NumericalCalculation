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
	// ������������
	double** mat;

	// ���������������
	int row, column;

public:
	// ����Ĺ��캯��
	Matrix();	// Ĭ�Ϲ��캯��
	Matrix(Matrix &other);	// �������캯��
	Matrix(int row, int column);	// ȷ���������������Ĺ��캯��

	double MaxElement(int mode = 0);	//��ȡ����������Ԫ�أ�mode = 0�������ֵ�������ǷǾ���ֵ
	// ����Ĺ��캯��
	~Matrix();

	// ������Ϊһ����ת��������
	Vector ToVector();

	// �����������ض����Ӿ���
	Matrix SubMatrix(int row, int column);
	
	// ��������ƴ�ӣ���һ������ƴ�ӵ�һ��������Ҳ࣬�����¾���
	static double** MatrixJoin(Matrix& a, Vector& b);

	// ����һ�������������ض��Ķ�ά����
	static double** NewMatrix(int row, int column);	
	// ɾ��һ����ά����
	static void DeleteMatrix(int row,  double** mat);
	
	// ��һ����ά��������ݿ����������������
	void CopyToArray(double** mat);

	// �������ķ���
	double GetNorm(int p = 0);
	
	// ��þ��������
	int GetRow();

	// ��þ��������
	int GetColumn();

	// ��ӡ���������
	void PrintMatrix();

	// ����ʽ���þ���
	void SetMatrix();

	// �������ά���������ȫ�����0
	void SetAllElementsZero();

	// �����ַ������þ���
	void SetMatrix(char str[]);
	
	// ���󵥸�Ԫ�صĸ�ֵ
	void SetElement(int row, int column, double value);

	// ���㷽�������ʽ
	double Determinant();

	// ����power method������ֵ��������ֵ��ȱ����ֻ�����ڵ��������
	double PowerMethod(Vector*res, Vector* Eigenvector);

	// ������Է����飬�����ַ���
	Vector LinearEquation(Vector& b, int mode = 0);
	Vector LinearEquationDirectMethod(Vector& b);
	Vector LinearEquationIterativeMethod(Vector& b);
	
	// ��������
	Matrix InvMatrix();

	// ����LU�ֽ�
	Matrix LUFactorization(int option);

	// ������ص����������
	Matrix operator+(Matrix& other);
	Matrix operator*(Matrix& other);
	Matrix operator-(Matrix& other);
	Matrix& operator=(Matrix& other);
	Vector operator*(Vector& other);
	bool operator==(Matrix& other);

	// ����Ԫ�ط��ʷ�
	double*& operator[](int index);
};


class PositiveDefiniteMatrix :public Matrix {
	bool Judge();
	Matrix LDLFactorization(int option);
	Matrix Choleskis();

};


#endif
