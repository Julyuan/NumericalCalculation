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

void Polynomial::Constructor(double zero_points[], int num)
{
	this->Clear();
	this->SetTerm(0, 1.0);
	//this->Print();
	//for (int i = 0; i < num; i++) {
	//	std::cout << zero_points[i] << " ";
	//}
	//std::cout << std::endl;
	for (int i = 0; i < num; i++) {
		Polynomial temp;
		//temp.coefficients[0] = -1 * zero_points[i];
		//temp.coefficients[1] = 1;
		temp.SetTerm(0, -zero_points[i]);
		temp.SetTerm(1, 1.0);
		//std::cout << "temp = ";
		//temp.Print();
		*this = *this * temp;
		//this->Print();
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
	if (this->degree == 0) {
		std::cout << coefficients[0] << std::endl;
		return;
	}
	for (int i = this->degree; i >= 0; i--) {
		if (i == this->degree && i!=0) {
			if (!IsOne(coefficients[i])) {
				//printf("%lfx^%d", coefficients[i], i);
				std::cout << coefficients[i] << "x^" << i;
			}
			else {
				//printf("x^%d", i);
				std::cout << "x^" << i;
			}
		}
		else if (i != 0) {
			if (IsZero(coefficients[i]))
				continue;
			else {
				if (!IsOne(coefficients[i])) {
					if (coefficients[i] > 0) {
						//printf(" + %lfx^%d", coefficients[i], i);
						if(i!=1)
							std::cout << " + " << coefficients[i] << "x^" << i;
						else
							std::cout << " + " << coefficients[i] << "x";
					}
					else {
						//printf(" - %lfx^%d", -coefficients[i], i);
						if(i!=1)
							std::cout << " - " << -coefficients[i] << "x^" << i;
						else
							std::cout << " - " << -coefficients[i] << "x";
					}
				}
				else {
					if (coefficients[i] > 0) {
						//printf(" + x^%d", i);
						std::cout << " + x^" << i;
					}
					else {
						//printf(" + x^%d", i);
						std::cout << " - x^" << i;
					}
				}
			}
		}
		else {
			if (IsZero(coefficients[i]))
				continue;
			if (coefficients[i] > 0) {
				//printf(" + %lf", coefficients[i]);
				std::cout << " + " << coefficients[i];
			}
			else {
				//printf(" - %lf", -coefficients[i]);
				std::cout << " - " << -coefficients[i];
			}
		}
	}
//	printf("\n");
	std::cout << std::endl;
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

Polynomial Polynomial::Monic()
{
	Polynomial res(*this);
	res.AdjustDegree();
	res = res / res.coefficients[res.degree];
	return res;
}

Polynomial Polynomial::operator+(Polynomial & other)
{
	
	Polynomial ans;
	ans.degree = other.degree > degree ? other.degree : degree;

	for (int i = 0; i <= ans.degree; i++) {
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
	Constructor(zero_points, n);
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
	ans.Clear();
	ans.degree = degree + other.degree;
	for (int i = 0; i <= degree; i++) {
		for (int j = 0; j <= other.degree; j++) {
			ans.coefficients[i + j] += this->coefficients[i] * other.coefficients[j];
		}
	}
	ans.AdjustDegree();
	return ans;
}

Polynomial Polynomial::operator*(double other)
{
	Polynomial res(*this);
	res = res / (1.0 / other);
	return res;
}

Polynomial Polynomial::operator/(double other)
{
	Polynomial res(*this);
	if (IsZero(other)) {
		std::cout << "除数是0，你有丶问题口巴?" << std::endl;
		return res;
	}
	else {
		for (int i = 0; i <= degree; i++) {
			res.coefficients[i] /= other;
		}
	}
	return res;
}


Polynomial Polynomial::div(Polynomial & other, Polynomial * reminder)
{
	return Polynomial();
}


