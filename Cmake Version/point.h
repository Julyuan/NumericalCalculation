#pragma once
#include<vector>

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


};