#pragma once
#include"NAlib.h"
#include<vector>
#include<initializer_list>

// 自定义向量类
class Vector {
public:
	// 向量存储数组
	double* vec;
	// 向量维数
	int dimension;
	
	// 向量构造函数
	Vector();
	Vector(double a[], int dim);
	Vector(Vector& other);
	Vector(char* str);
	Vector(std::initializer_list<double>lis);
	Vector(int dim);

	// 向量范数求解
	double Norm(int dimension);

	double* NewVector(int dimension);
	void DeleteVector(double* vec);
	void SetVector(std::initializer_list<double>lis);
	// 向量析构函数
	~Vector() {
		delete[] vec;
	}

	// 向量元素清零
	void SetAllElementsZero();
	// 向量点积
	double dot(const Vector& other);
	// 向量打印
	void PrintVector();

	// 关于向量的运算符重载
	Vector operator-();
	Vector operator-(Vector& other);
	Vector operator+(Vector& other);
	Vector operator=(const Vector& other);
	Vector operator/(double other);
	double& operator[](int index);


};