#pragma once
#include<vector>
#include"polynomial.h"

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
	int number;
	std::vector<Point> pointSet;
	void Addpoint(double x, double y);
	void Addpoints(char* str);
	Polynomial Lagrange();

};