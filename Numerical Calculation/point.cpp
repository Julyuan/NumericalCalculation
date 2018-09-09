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

PointSet::PointSet()
{
	number = 0;
}

void PointSet::Addpoint(double x, double y)
{
	Point temp(x, y);
	this->pointSet.push_back(temp);
	number++;
}

void PointSet::Addpoints(char * str)
{

}

Polynomial PointSet::Lagrange()
{
	Polynomial P;
	Polynomial* L = new Polynomial[number+1];
	int number = this->number - 1;
	for (int i = 0; i <= number; i++) {
		double* arr = new double[number];
		for (int j = 0; j < number; j++) {
			arr[j] = i > j ? pointSet[j].GetX() : pointSet[j+1].GetX();
			//std::cout << arr[j] << " ";
		}
		//std::cout << std::endl;
		L[i].Constructor(arr, number);
		//std::cout << "L = ";
		//L[i].Print();
		double divisor = 1.0;
		double xk = pointSet[i].GetX();
		for (int j = 0; j < number; j++) {
			divisor = divisor * (xk - (i > j ? pointSet[j].GetX() : pointSet[j + 1].GetX()));
		}
		//std::cout << "divisor = " << divisor << std::endl;
		P = P + L[i] * pointSet[i].GetY() / divisor;
		delete[] arr;
		//P.Print();
	}

	delete[] L;
	return P;
}

double PointSet::Neville(double x)
{
	int n = this->number - 1;
	double** Q = Matrix::NewMatrix(1+n,1+n);
	for (int i = 0; i <= n; i++) {
		Q[i][0] = this->pointSet[i].GetY();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			Q[i][j] = (x - this->pointSet[i - j].GetX()) - (x - pointSet[i].GetX())*Q[i - 1][j - 1];
			Q[i][j] /= (pointSet[i].GetX()-this->pointSet[i - j].GetX());
		}
	}

	return 0.0;
}

