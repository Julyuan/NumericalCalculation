#include "polynomial.h"

Polynomial::Polynomial() {
	degree = 0;
	for (int i = 0; i < MAXDEGREE; i++)
		coefficients[i] = 0.0;
}

void Polynomial::AdjustDegree()
{
	for (int i = degree; i >= 0; i--) {
		if (!IsZero(coefficients[i])) {
			degree = i;
			return;
		}
	}
	degree = 0;
}

double Polynomial::Value(double x)
{
	double ans = coefficients[degree];
	for (int i = degree - 1; i >= 0; i--) {
		ans = ans * x + coefficients[i];
	}
	return ans;
}

Polynomial Polynomial::operator+(Polynomial & other)
{
	
	Polynomial ans;
	ans.degree = other.degree > degree ? other.degree : degree;

	for (int i = 0; i < ans.degree; i++) {
		ans.coefficients[i] = other.coefficients[i] + coefficients[i];
	}
	return ans;
}

Polynomial::Polynomial(double zero_points[], int n) {
	double* a = new double[n];

	for (int iter = 0; iter <= n; iter++) {

	}
}


Polynomial Polynomial::operator-(Polynomial & other)
{
	Polynomial ans;
	ans.degree = other.degree > degree ? other.degree : degree;

	for (int i = 0; i < ans.degree; i++) {
		ans.coefficients[i] = other.coefficients[i] - coefficients[i];
	}
	return ans;
}

Polynomial Polynomial::operator*(Polynomial & other)
{
	Polynomial ans;
	ans.degree = degree * other.degree;
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= other.degree; j++) {
			ans.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
		}
	}
	return ans;
}


Polynomial Polynomial::div(Polynomial & other, Polynomial * reminder)
{
	return Polynomial();
}


