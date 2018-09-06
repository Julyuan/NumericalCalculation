#include "polynomial.h"

Polynomial::Polynomial() {
	degree = 0;
	for (int i = 0; i < MAXDEGREE; i++)
		coefficients[i] = 0.0;
}

Polynomial::Polynomial(Polynomial & other)
{
	degree = other.degree;
	for (int i = MAXDEGREE; i >= 0; i--) {
		this->coefficients[i] = other.coefficients[i];
	}
}

Polynomial::Polynomial(double coe[], int exp[], int num)
{
	degree = num;
	for (int i = 0; i < num; i++) {
		this->coefficients[exp[i]] = coe[i];
	}
}

void Polynomial::SetTerm(int exp, double coe)
{
	degree = exp > degree ? exp : degree;
	coefficients[exp] = coe;
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

void Polynomial::Print()
{
	this->AdjustDegree();
	for (int i = this->degree; i >= 0; i--) {
		if (i == this->degree && i!=0) {
			if (!IsOne(coefficients[i])) {
				printf("%lfx^%d", coefficients[i], i);
			}
			else {
				printf("x^%d", i);
			}
		}
		else if (i != 0) {
			if (IsZero(coefficients[i]))
				continue;
			else {
				if (!IsOne(coefficients[i])) {
					if (coefficients[i] > 0) {
						printf(" + %lfx^%d", coefficients[i], i);
					}
					else {
						printf(" - %lfx^%d", -coefficients[i], i);
					}
				}
				else {
					if (coefficients[i] > 0) {
						printf(" + x^%d", i);
					}
					else {
						printf(" + x^%d", i);
					}
				}
			}
		}
		else {
			if (coefficients[i] > 0) {
				printf(" + %lf", coefficients[i]);
			}
			else {
				printf(" - %lf", -coefficients[i]);
			}
		}
	}
	printf("\n");
}

void Polynomial::Clear()
{
	degree = 0;
	for (int i = 0; i < MAXDEGREE; i++)
		coefficients[i] = 0;
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
	//double* a = new double[n];

	//for (int iter = 0; iter <= n; iter++) {
	//	a[iter] = 0.0;
	//}
	// 这里可以用快速傅里叶变换优化，不过暂时写不出来。。。
	this->Clear();
	this->SetTerm(0,1.0);
	this->Print();
	for (int i = 0; i < n; i++) {
		Polynomial temp;
		//temp.coefficients[0] = -1 * zero_points[i];
		//temp.coefficients[1] = 1;
		temp.SetTerm(0, -1.0*zero_points[i]);
		temp.SetTerm(1, 1);
		*this = *this * temp;
		this->Print();
	}
}

Polynomial::Polynomial(char * str)
{
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
	Polynomial ans(*this);
	ans.degree = degree + other.degree;
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= other.degree; j++) {
			ans.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
		}
	}
	ans.AdjustDegree();
	return ans;
}


Polynomial Polynomial::div(Polynomial & other, Polynomial * reminder)
{
	return Polynomial();
}


