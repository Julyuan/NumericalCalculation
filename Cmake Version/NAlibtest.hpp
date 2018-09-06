#pragma once

#include "NAlib.h"
#include <iostream>
void TestPolyAux() {

	double x[10];
	bool vis[10];

	memset(vis, 0, sizeof(vis));
	memset(x, 0, sizeof(x));

	double* a = new double;
	*a = 0.0;
	x[0] = 1;
	x[1] = 2;
	PolynomialConvertAuxiliary(x,vis,2,a,1,0,0);
	std::cout << *a << std::endl;
}

void TestExpression() {

//	double x = 10;
//	char s[] = "1/x";
//	printf("%lf\n",eval(s, x));
	char s[100];
	double x = 0, y = 0;
	memset(s,0,sizeof(s));
	printf("输入一个关于x的函数：\n");
	scanf("%s",s);
	printf("输入你想求该函数积分的区间：\n");
	scanf("%lf%lf",&x, &y);
	printf("函数f(x) = %s在区间的[%lf %lf]积分是%lf\n", s, x, y,Integral(s, x, y));
}