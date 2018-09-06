#include"vector.h"	



Vector::Vector() {
	dimension = 0;
	vec = nullptr;
}

Vector::Vector(int dim) {
	dimension = dim;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = 0.0;
	}
}

Vector::Vector(double a[], int dim) {
	dimension = dim;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = a[i];
	}
}

Vector::Vector(Vector& other) {
	*this = other;
}

Vector::Vector(char * str)
{
}

void Vector::SetAllElementsZero()
{
	for (int i = 0; i < dimension; i++)
		vec[i] = 0.0;
}

double Vector::dot(const Vector & other)
{
	double ans = 0;
	if (this->dimension != other.dimension) {
		std::cout << "����ά����ͬ" << std::endl;
		return ans;
	}
	else {
		for (int i = 0; i < dimension; i++) {
			ans += vec[i] * other.vec[i];
		}
	}
	return ans;
}

Vector Vector::operator*(Matrix & other)
{
	if (other.GetColumn() != dimension) {
		std::cout << "����������ƥ�䣬�޷����" << std::endl;
		return *this;
	}
	else {
		Vector ans(other.GetRow());
		ans.SetAllElementsZero();

		for (int i = 0; i < other.GetRow(); i++) {
			for (int j = 0; j < dimension; j++) {
				ans.vec[i] += other[i][j] * this->vec[j];
			}
		}
	}
	return Vector();
}

Vector Vector::operator=(const Vector & other)
{
	dimension = other.dimension;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = other.vec[i];
	}
	return *this;
}

double Vector::operator[](int index)
{
	return vec[index];
}

