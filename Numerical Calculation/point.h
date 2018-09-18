#pragma once
#include<vector>
#include"polynomial.h"
#include"matrix.h"

class Point {
private:
	double x;
	double y;
	double differential;
public:
	Point();
	Point(double x, double y);
	Point(double x, double y, double d);
	double GetX();
	double GetY();
	double GetDiff();
};

class PointSet {
private:
	int number;
	std::vector<Point> pointSet;
	
public:
	PointSet();
	void Addpoint(double x, double y);
	void Addpoints(char* str, int mode);
	Polynomial Lagrange();
	double Neville(double x);

};