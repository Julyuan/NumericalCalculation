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


// ���ʽ�������� 
double eval(char s[], double x); 

// ���ַ����ж�ȡ���� 
double ReadNumber(char s[], int* Length);

// �������ж� 
int JudgeOperand(char c, int* prior);

// ��ȡ����� 
char GetOperator(char stack[], int i);
double GetOperand(double stack[], int i);
double Compute(char symbol, double num1, double num2);

//����ĳһ�㵼���ĺ��� 
double Differential(char Expression[], double x); 
//������һ��������ֵĺ��� 
double Integral(char Expression[], double start, double end);
//���ö��ַ���������� 
double Bisection(char Expression[], double a, double b, double eps, int N);
//���ò����㷨���������
 double FixedPoint(char Expression[], double x, double eps, int N); 
//����ţ�ٷ����������
double Newton(char Expression[], double x, double eps, int N); 
//���ø��߷���������� 
double Secant(char Expression[], double p0, double p1, double eps, int N);
//���ü��ٵ��������Ĳ����� 
double Steffensen(char Expression[], double p0, double eps, int N); 
//�����˹��Ԫ 
int GaussElimination(double** mat, int row, int column); 
//��˹��������
int GaussJordanMethod(double** a, int row, int column);
//�ж�һ�����Ƿ�Ϊ��
bool IsZero(double a);
//����ʽת���ĸ�������
int PolynomialConvertAuxiliary(double x[], bool vis[], int total, double* res, int n, int current, int guard);

#endif
