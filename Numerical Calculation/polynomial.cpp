#include "polynomial.h"

Polynomial::Polynomial() {
	degree = 0;
	coefficients = nullptr;
}

double Polynomial::Value(double x)
{
	double ans = coefficients[degree];
	for (int i = degree - 1; i >= 0; i--) {
		ans = ans * x + coefficients[i];
	}

	return ans;
}
