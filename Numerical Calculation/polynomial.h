#pragma once
#include"NAlib.h"
#include<vector>
#define MAXDEGREE 105

// ����ʽ��
class Polynomial {
private:
	// ����ʽ��ϵ������
	double coefficients[MAXDEGREE];
	// ����ʽ�Ķ�
	int degree;

public:
	// ����ʽ�Ĺ��캯��
	Polynomial();
	Polynomial(Polynomial& other);
	Polynomial(double coe[], int exp[], int num);
	// ͨ��������������һ����ʽ
	Polynomial(double zero_points[], int num);
	// ���������ʽ
	Polynomial(char* str);
	
	// ����ʽ��㹹��
	void Constructor(double zero_points[], int num);
	// ����ʽ�ĵ�������
	void SetTerm(int exp, double coe);
	// ����ʽ�Ķȵĵ���
	void AdjustDegree();
	// ����ʽ�Ĵ�ӡ
	void Print();
	// ����ʽ����
	void Clear();
	// ����ʽ���ض������ֵ
	double Value(double x);

	// ��һ����ʽ�Ļ��
	Polynomial Monic();

	// ����ʽ�����������
	Polynomial operator+(Polynomial& other);
	Polynomial operator-(Polynomial& other);
	Polynomial operator*(Polynomial& other);
	Polynomial operator*(double other);
	Polynomial operator/(double other);

	// ����ʽ�Ĵ������
	Polynomial div(Polynomial& other, Polynomial* reminder);
};

