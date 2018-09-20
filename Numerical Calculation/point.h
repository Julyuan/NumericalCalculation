#pragma once
#include<initializer_list>
#include<vector>
#include<algorithm>
#include"polynomial.h"
#include"matrix.h"

// ֱ����������
class Point {
private:
	// ���λ����Ϣ
	double x;
	double y;
	double differential;
public:

	// ��Ĺ��캯��
	Point();
	Point(double x, double y);
	Point(double x, double y, double d);
	bool operator<(Point &other);
	bool operator==(Point &other);
	double GetX();
	double GetY();
	double GetDiff();
};

// ֱ������ϵ�ϵ�ļ���
class PointSet {
private:
	int number;
	std::vector<Point> pointSet;
	
public:
	PointSet();
	// �����򣨰���x����Ĵ�С��,Ϊ�����������̵�
	void Sort();

	// ��ӵ�
	void Addpoint(double x, double y);
	void Addpoints(std::initializer_list<double>lis);
	void Addpoints(char* str, int mode);
	// �������ղ�ֵ
	Polynomial Lagrange();
	// ��ά����ֵ
	double Neville(double x);
	// ��ַ���
	double DividedDifference(int start, int rank);
	// ţ�ٲ�ֵ
	Vector NewtonInterpolatory();
};