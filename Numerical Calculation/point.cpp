#include"point.h"

Point::Point(double x, double y) :x(x), y(y),differential(0) {

}

Point::Point(double x, double y, double d): x(x), y(y), differential(d){

}

bool Point::operator<(Point & other)
{
	return this->x < other.x;
}

bool Point::operator==(Point & other)
{
	return IsZero((this->x-other.x)) && IsZero(this->y - other.y);
}

double Point::GetX()
{
	return this->x;
}

double Point::GetY()
{
	return this->y;
}

void Point::SetX(double x)
{
	this->x = x;
}

void Point::SetY(double y)
{
	this->y = y;
}

void Point::PrintPoint()
{
	std::cout << "(" << this->GetX() << " ," << this->GetY() << ")";
}

double Point::GetDiff()
{
	return this->differential;
}



Point::Point() {
	x = y = this->differential = 0.0;
}

PointSet::PointSet()
{
	number = 0;
}

double PointSet::SumOfPowerN(int n)
{
	double res = 0.0;
	for (int i = 0; i < this->number; i++) {
		res += pow(pointSet[i].GetX(), (double)n);
	}
	return res;
}

void PointSet::Sort()
{
	std::sort(pointSet.begin(), pointSet.end());
}

void PointSet::Clear()
{
	number = 0;
	pointSet.clear();
}

void PointSet::Addpoint(double x, double y)
{
	Point temp(x, y);
	this->pointSet.push_back(temp);
	number++;
}

void PointSet::Addpoints(std::initializer_list<double> lis)
{
	Point temp;
	int count = 0;
	for (auto i : lis) {
		if (count % 2 == 0) {
			temp.SetX(i);
		}
		else {
			temp.SetY(i);
			Point tmp(temp);
			this->pointSet.push_back(tmp);
		}

		count++;
	}
}

void PointSet::Addpoints(char * str, int mode = 0)
{
	std::vector<double> elements;

	int *len = new int;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] <= '9' && str[i] >= '0' || str[i] == '-') {
			double res = ReadNumber(str + i, len);
			elements.push_back(res);
			i += *len;
		}
	}


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
		}
		L[i].Constructor(arr, number);
		
		double divisor = 1.0;
		double xk = pointSet[i].GetX();
		for (int j = 0; j < number; j++) {
			divisor = divisor * (xk - (i > j ? pointSet[j].GetX() : pointSet[j + 1].GetX()));
		}
		P = P + L[i] * pointSet[i].GetY() / divisor;
		delete[] arr;
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
			Q[i][j] = Q[i][j-1]*(x - this->pointSet[i - j].GetX()) - (x - pointSet[i].GetX())*Q[i - 1][j - 1];
			Q[i][j] /= (pointSet[i].GetX()-this->pointSet[i - j].GetX());
		}
	}
	double res = Q[n][n];
	Matrix::DeleteMatrix(1 + n, Q);
	return res;
}

double PointSet::DividedDifference(int start, int rank)
{
	if (rank == 0) {
		return pointSet[start].GetY();
	}
	else {
		return (DividedDifference(start + 1, rank - 1) - DividedDifference(start, rank - 1)) / (pointSet[start + 1].GetX() - pointSet[start].GetX());
	}
	return 0.0;
}

Vector PointSet::NewtonInterpolatory()
{
	double** F = Matrix::NewMatrix(this->number,this->number);
	for (int i = 0; i < this->number; i++) {
		F[i][0] = pointSet[i].GetY();
	}

	for (int i = 1; i < this->number; i++) {
		for (int j = 1; j < this->number; j++) {
			F[i][j] = (F[i][j - 1] - F[i - 1][j - 1]) / (pointSet[i].GetX() - pointSet[i - j].GetX());
		}
	}
	Vector res;
	for (int i = 0; i < this->number; i++) {
		res.vec[i] = F[i][i];
	}
	Matrix::DeleteMatrix(this->number, F);
	return res;
}

Vector PointSet::LeastSquaresPolynomial(int degree)
{
	if (degree >= this->number) {
		std::cout << "阶数过高，拟合出错"<< std::endl;
		return Vector();
	}
	else {
		Matrix* mat = new Matrix(this->number, this->number);
		for (int i = 0; i < this->number; i++) {
			for (int j = 0; j < this->number; j++) {
				mat->SetElement(i, j, this->SumOfPowerN(i + j));
			}
		}
		Vector vec;
		for (int i = 0; i < degree; i++) {
			double v = 0.0;
			for (int j = 0; j < this->number; j++)
				v += pointSet[j].GetY()*pow(pointSet[j].GetX(), i);
			vec.vec[i] = v;
		}
		Vector res = mat->LinearEquationDirectMethod(vec);
		return res;
	}
}

void PointSet::PrintPointSet()
{
	std::cout << "[";
	for (auto iter : this->pointSet) {
		iter.PrintPoint();
	}
	std::cout<<"]"<<std::endl;
}

