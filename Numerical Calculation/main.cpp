#include <iostream>
#include<Windows.h>
#include "NAlib.h"
#include"matrixtest.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//	double x = 10;
	//	char s[] = "1/x";
	//	printf("%lf\n",eval(s, x));
	//char s[100];
	//double x = 0, y = 0;
	//memset(s,0,sizeof(s));
	//printf("输入一个关于x的函数：\n");
	//scanf("%s",s);
	//printf("输入你想求该函数积分的区间：\n");
	//scanf("%lf%lf",&x, &y);
	//printf("函数f(x) = %s在区间的[%lf %lf]积分是%lf\n", s, x, y,Integral(s, x, y));
	TestMatrix();
	system("pause");
	return 0;
}
