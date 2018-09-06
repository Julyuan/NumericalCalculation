#pragma once
#include<vector>
#include"polynomial.h"

class Point {
	Point();
	Point(double x, double y);
	double x;
	double y;
};

class PointSet {
	std::vector<Point> pointSet;
	void Addpoint(double x, double y);
	void Addpoints(char* str);
	Polynomial Lagrange();

};