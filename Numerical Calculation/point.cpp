#include"point.h"

Point::Point(double x, double y) :x(x), y(y) {

}

double Point::GetX()
{
	return this->x;
}

double Point::GetY()
{
	return this->y;
}

Point::Point() {
	x = y = 0.0;
}

void PointSet::Addpoint(double x, double y)
{
	Point temp(x, y);
	this->pointSet.push_back(temp);
}

void PointSet::Addpoints(char * str)
{

}

Polynomial PointSet::Lagrange()
{
	Polynomial P;
	Polynomial* L = new Polynomial[number+1];
	for (int i = 0; i <= number; i++) {
		double* arr = new double[number];
		for (int j = 0; j < number; j++) {
			arr[j] = i <= j ? pointSet[j].GetX() : pointSet[j+1].GetX();
		}
		L[i].Constructor(arr, number);
		double divisor = 1.0;
		double xk = pointSet[i].GetX();
		for (int j = 0; j < number; j++) {
			divisor = divisor * (xk - i <= j ? pointSet[j].GetX() : pointSet[j + 1].GetY());
		}
		P = P + L[i] * pointSet[i].GetY() / divisor;
		delete[] arr;
	}

	delete[] L;
	return P;
}
