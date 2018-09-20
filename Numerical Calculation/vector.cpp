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

double Vector::Norm(int dim)
{
	if (dim < 1) {
		double res = vec[0];
		for (int i = 1; i < dim; i++) {
			res = res < vec[i] ? vec[i] : res;
		}
		return res;
	}
	else {
		double res = 0;
		for (int i = 0; i < dim; i++) {
			res += pow(vec[i], (double)dim);
		}
		return pow(res, 1.0 / dim);
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
	this->dimension = other.dimension;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = other.vec[i];
	}
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
		std::cout << "向量维数不同" << std::endl;
		return ans;
	}
	else {
		for (int i = 0; i < dimension; i++) {
			ans += vec[i] * other.vec[i];
		}
	}
	return ans;
}

Vector Vector::operator-()
{
	Vector res(*this);
	for (int i = 0; i < dimension; i++) {
		res.vec[i] *= -1;
	}
	return res;
}

Vector Vector::operator-(Vector & other)
{
	Vector res(this->dimension);
	if (this->dimension != other.dimension) {
		std::cout << "向量维数不一致，运算无效" << std::endl;
		return res;
	}
	else {
		for (int i = 0; i < res.dimension; i++) {
			res.vec[i] = this->vec[i] - other.vec[i];
		}
		return res;
	}
}

Vector Vector::operator+(Vector & other)
{
	return *this - (-other);
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

Vector Vector::operator/(double other)
{
	Vector res(*this);
	if (IsZero(other)) {
		std::cout << "除数不能为0" << std::endl;
	}
	else {
		for (int i = 0; i < dimension; i++) {
			res.vec[i] /= other;
		}
	}
	return res;
}

double& Vector::operator[](int index)
{
	return vec[index];
}

