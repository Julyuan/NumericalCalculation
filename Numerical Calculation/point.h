#pragma once
#include<vector>
#include"polynomial.h"
#include"matrix.h"

class Point {
private:
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	double GetX();
	double GetY();
};

class PointSet {
private:
	int number;
	std::vector<Point> pointSet;
	
public:
	PointSet();
	void Addpoint(double x, double y);
	void Addpoints(char* str);
	Polynomial Lagrange();
	double Neville(double x);

};