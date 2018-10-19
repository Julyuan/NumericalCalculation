#pragma once
#include"NAlib.h"
#include<vector>
#include<initializer_list>

// �Զ���������
class Vector {
public:
	// �����洢����
	double* vec;
	// ����ά��
	int dimension;
	
	// �������캯��
	Vector();
	Vector(double a[], int dim);
	Vector(Vector& other);
	Vector(char* str);
	Vector(std::initializer_list<double>lis);
	Vector(int dim);

	// �����������
	double Norm(int dimension);

	double* NewVector(int dimension);
	void DeleteVector(double* vec);
	void SetVector(std::initializer_list<double>lis);
	// ������������
	~Vector() {
		delete[] vec;
	}

	// ����Ԫ������
	void SetAllElementsZero();
	// �������
	double dot(const Vector& other);
	// ������ӡ
	void PrintVector();

	// �������������������
	Vector operator-();
	Vector operator-(Vector& other);
	Vector operator+(Vector& other);
	Vector operator=(const Vector& other);
	Vector operator/(double other);
	double& operator[](int index);


};