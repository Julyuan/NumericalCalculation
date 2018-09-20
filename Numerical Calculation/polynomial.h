#pragma once
#include"NAlib.h"
#include<vector>
#define MAXDEGREE 105

// 多项式类
class Polynomial {
private:
	// 多项式的系数矩阵
	double coefficients[MAXDEGREE];
	// 多项式的度
	int degree;

public:
	// 多项式的构造函数
	Polynomial();
	Polynomial(Polynomial& other);
	Polynomial(double coe[], int exp[], int num);
	// 通过零点坐标求解首一多项式
	Polynomial(double zero_points[], int num);
	// 解析求多项式
	Polynomial(char* str);
	
	// 多项式零点构造
	void Constructor(double zero_points[], int num);
	// 多项式的单项设置
	void SetTerm(int exp, double coe);
	// 多项式的度的调整
	void AdjustDegree();
	// 多项式的打印
	void Print();
	// 多项式清零
	void Clear();
	// 多项式在特定点的求值
	double Value(double x);

	// 首一多项式的获得
	Polynomial Monic();

	// 多项式的运算符重载
	Polynomial operator+(Polynomial& other);
	Polynomial operator-(Polynomial& other);
	Polynomial operator*(Polynomial& other);
	Polynomial operator*(double other);
	Polynomial operator/(double other);

	// 多项式的带余除法
	Polynomial div(Polynomial& other, Polynomial* reminder);
};

