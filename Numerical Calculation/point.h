#pragma once
#include<initializer_list>
#include<vector>
#include<algorithm>
#include"polynomial.h"
#include"matrix.h"

// 直角坐标点的类
class Point {
private:
	// 点的位置信息
	double x;
	double y;
	double differential;
public:

	// 点的构造函数
	Point();
	Point(double x, double y);
	Point(double x, double y, double d);
	bool operator<(Point &other);
	bool operator==(Point &other);
	double GetX();
	double GetY();
	void SetX(double x);
	void SetY(double y);
	double GetDiff();
};

// 直角坐标系上点的集合
class PointSet {
private:
	int number;
	std::vector<Point> pointSet;
	
public:
	PointSet();
	// 点排序（按照x坐标的大小）,为其他方法做铺垫
	void Sort();

	// 添加点
	void Addpoint(double x, double y);
	void Addpoints(std::initializer_list<double>lis);
	void Addpoints(char* str, int mode);
	// 拉格朗日插值
	Polynomial Lagrange();
	// 利维尔插值
	double Neville(double x);
	// 差分方程
	double DividedDifference(int start, int rank);
	// 牛顿插值
	Vector NewtonInterpolatory();
};