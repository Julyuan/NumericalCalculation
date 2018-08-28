#ifndef _NAlib_h
#define _NAlib_h

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>


#define ABS(a) a > 0 ? a : -a
#define ZERO 1e-12
#define TRUE 1
#define FALSE 0
#define MaxRowNumber 1000
#define MaxColumnNumber 1000


// 表达式解析函数 
double eval(char s[], double x); 

// 从字符串中读取数字 
double ReadNumber(char s[], int* Length);

// 运算数判断 
int JudgeOperand(char c, int* prior);

// 读取运算符 
char GetOperator(char stack[], int i);
double GetOperand(double stack[], int i);
double Compute(char symbol, double num1, double num2);

//求函数某一点导数的函数 
double Differential(char Expression[], double x); 
//求函数在一个区间积分的函数 
double Integral(char Expression[], double start, double end);
//利用二分法求函数的零点 
double Bisection(char Expression[], double a, double b, double eps, double N);
//利用不动点法求函数的零点
 double FixedPoint(char Expression[], double x, double eps, int N); 
//利用牛顿法求函数的零点
double Newton(char Expression[], double x, double eps, int N); 
//利用割线法求函数的零点 
double Secant(char Expression[], double p0, double p1, double eps, int N);
//利用加速迭代求函数的不动点 
double Steffensen(char Expression[], double p0, double eps, int N); 
//矩阵高斯消元 
int GaussElimination(double** mat, int row, int column); 
//高斯若当方法
int GaussJordanMethod(double** a, int row, int column);

bool IsZero(double a);

#endif
