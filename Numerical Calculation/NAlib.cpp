#include "NAlib.h"

//表达式解析函数，输入为一个关于x的表达式和x的值，返回值是表达式的结果(double) 
double eval(char s[], double x)
{
	char str[100];	//去除空格字符串 

	int i, j, k;	//循环控制变量 
	int lengthstr;	//修饰字符串的长度 

	double OperandStack[100];	//运算数的栈 
	char OperatorStack[100];	//运算符的栈 
	int OperatorPointer, OperandPointer;	//运算符和运算数的栈指针 

	int* lengthnum = (int*)malloc(sizeof(int));	//检测到的运算数的长度 
	int* CurrentPrecedence = (int*)malloc(sizeof(int));	//当前运算符的优先级 
	int* StackPrecedence = (int*)malloc(sizeof(int));	//栈顶运算符的优先级 
		
	//字符串初始化
	memset(str, 0, sizeof(str)); 
	//循环去除空格并得到字符串的长度 
	for(i = 0, lengthstr = 0; i < strlen(s); i++)
	{
		if(s[i] != ' ')
			str[lengthstr++] = s[i];
	}
	//栈顶指针的初始化 
	OperatorPointer = OperandPointer = 0;
	
	//扫描字符串函数 
	for(i = 0; i < strlen(str); i++)
	{
		//如果检测到一个数字，读取一个有理数 
		if(s[i] <= '9' && s[i] >= '0')
		{
			//调用ReadNumber函数，并把该数压到运算数栈中 
			double temp = ReadNumber(s+i, lengthnum);
			OperandStack[OperandPointer++] = temp;
			//对应扫描字符串的指针右移 
			i += *lengthnum;		
		}
		//如果读取字母，把该字母对应的数字压到运算数栈中 
		else if(s[i] == 'x' || s[i] == 'X')
		{
			OperandStack[OperandPointer++] = x;
		}
		//如果扫描到的是运算符，则需进行较为复杂的判断，先调用判断函数，并把运算符的优先级存到CurrentPrecedence中 
		else if(JudgeOperand(s[i], CurrentPrecedence))
		{
			// 
			if(*CurrentPrecedence > *StackPrecedence || OperatorPointer == 0)
			{
				OperatorStack[OperatorPointer++] = s[i];
			}
			else
			{
				while(*CurrentPrecedence <= *StackPrecedence && OperatorPointer > 0)
				{
					char Operator = GetOperator(OperatorStack, OperatorPointer);
				//	printf("Operator = %c s[i] = %c i = %d\n",Operator,s[i],i);
					if(Operator == '(' && s[i] == ')')
					{
						OperatorPointer--;
						break; 
					}
					double num1 = GetOperand(OperandStack, OperandPointer);
					if(OperandPointer > 0)
						OperandPointer--;
					if(OperatorPointer > 0)
						OperatorPointer--;
					double num2 = GetOperand(OperandStack, OperandPointer);
					if(OperandPointer > 0)
						OperandPointer--;
					double ans = Compute(Operator, num1, num2);
					OperandStack[OperandPointer++] = ans;
					JudgeOperand(OperatorStack[OperatorPointer-1], StackPrecedence);
				}
				if(s[i] != ')')
					OperatorStack[OperatorPointer++] = s[i];
			}
			*StackPrecedence = *CurrentPrecedence;
			if(OperatorStack[OperatorPointer-1] == '(')
				*StackPrecedence = 0;			
		}
	//	else if()
	}
	while(OperatorPointer > 0)
	{
		char Operator = GetOperator(OperatorStack, OperatorPointer);
		double num1 = GetOperand(OperandStack, OperandPointer);
		if(OperandPointer > 0)
			OperandPointer--;
		if(OperatorPointer > 0)
			OperatorPointer--;
		double num2 = GetOperand(OperandStack, OperandPointer);
//		printf("num1 = %lf, num2 = %lf, operator = %c\n",num1, num2, Operator);
		if(OperandPointer > 0)
			OperandPointer--;
		double ans = Compute(Operator, num1, num2);
//		printf("ans = %lf\n",ans);
		OperandStack[OperandPointer++] = ans;

	}	
	return  OperandStack[0];
 } 

char GetOperator(char stack[], int i)
{
	if(i<=0)
	{
		printf("你输入的表达式有误！\n");
	}
	else
	{
		return stack[--i];
	}
} 
 
double GetOperand(double stack[], int i)
{
	if(i<=0)
	{
		printf("你输入的表达式有误！\n");
	}
	else
	{
		return stack[--i];
	}
}

double Compute(char symbol, double num1, double num2)
{
	double ans = 0;
	switch(symbol)
	{
	case '+': ans = num1 + num2;break;
	case '-': ans = num2 - num1;break;
	case '*': ans = num1 * num2;break;
	case '/': if(fabs(num2) < 1e-10){printf("除数不能为零！\n");}else{ans = num2/num1;}break;
	default: printf("运算符出错,该运算符为%c！\n",symbol); break;
	}
	return ans;
}

double ReadNumber(char s[], int* Length)
{
	// printf("127\n");
	int i, j, k;
	int length;
	for(length = 0; ; length++)
	{
		if((s[length] > '9' || s[length] < '0') && s[length] != '.')
			break;
	}
	char buffer[100];
	memset(buffer, 0, sizeof(buffer));
	for(i = 0; i < length; i++)
		buffer[i] = s[i];
	double ans = 0;
	sscanf(buffer, "%lf", &ans);
	
	*Length = length - 1; 
	return ans;
}

int JudgeOperand(char c, int* prior)
{
	int flag = 1;
	int temp = 0;
	switch(c)
	{
	case '+':temp = 1;break;
	case '-':temp = 1;break;
	case '*':temp = 2;break;
	case '/':temp = 2;break;
	case '^':temp = 3;break;
	case ')':temp = 0;break;
	case '(':temp = 4;break;
	default: flag = 0;break;
	}
	if(flag)
	{
		*prior = temp;
		return 1;
	}
	else
		return 0;
}

double Differential(char Expression[], double x)
{
	int i, j, k;
	int n = 10;
	double Answer[20][20]; 
	double Interval = 0.1;
	
	for(i = 0; i < 20; i++)
		for(j = 0; j < 20; j++)
			Answer[i][j] = 0.0;
	
	for(i = 1; i <= 10; i++)
	{
		Answer[i][1] = (1.0 * ((1 << (-1+i)) / Interval)) * (eval(Expression, x + Interval / (1<<i)) - eval(Expression, x - Interval / (1<<i)));
		for(j = 2; j <= i; j++)
			Answer[i][j] = Answer[i][j - 1] + (Answer[i][j - 1]  - Answer[i - 1][j - 1]) / (pow(4, j - 1) - 1);
	}
	
	return Answer[10][10];
}

double Integral(char Expression[], double start, double end)
{
	int i,j,k;
	int n = 10;
	double Answer[20][20];
	
	for(i = 0; i < 20; i++)
		for(j = 0; j < 20; j++)
			Answer[i][j] = 0.0;
	
	double S = start, E = end;
	double Interval = E - S;
	Answer[1][1] = Interval/2 * (eval(Expression, S) + eval(Expression, E));
	
	for(k = 2; k <= n; k++)
	{
		double sum = 0;																
		for(i = 1; i <= 1 << (k-2); i++)								
		{
			sum += eval(Expression, S + (i-0.5) * Interval);							
		}												
		Answer[k][1] = 0.5 * (Answer[k-1][1] + Interval * sum);					
		for(j = 2; j <= k; j++)						
			Answer[k][j] = Answer[k][j-1] + (Answer[k][j-1] - Answer[k-1][j-1]) / (pow(4, j-1) -1);
		Interval = Interval / 2;
	}	
	return Answer[n][n];		
	
}

double Bisection(char Expression[], double a, double b, double eps = 0.00001, int N = 100)
{
	double value1, value2, value3;
	value1 = value2 = value3 = 0.0;
	if(eval(Expression, a) * eval(Expression, b) > 0)
	{
		printf("该区间无法使用二分法求解！"); 
		return -1;
	}
	else
	{ 
		double c;
		value1 = eval(Expression, a);
		value2 = eval(Expression, b);
		while(!(b - a < eps || fabs((value1 + value2) / 2) < ZERO || !(N--)))
		{
			c = a + (b - a) / 2;
			value3 = eval(Expression, c);
			if(value2 * value3 > 0)
			{
				value2 = value3;
				b = c;
			}
			else
			{
				value1 = value3;
				a = c;
			}
		}
		return (b+a)/2;
	}
} 

double FixedPoint(char Expression[], double x, double eps = 0.0001, int N = 100)
{
	double x0 = 0.0;
	int i = 1;
	while(i <= N)
	{
		x = eval(Expression, x0) + x0;
		if(fabs(x - x0) < eps)
			return x;
		i = i + 1;
		x0 = x;
	}
	printf("不动点迭代没有收敛！\n");
	
	return -1;
}

double Newton(char Expression[], double x, double eps = 0.001, int N = 100)
{
	double x0 = 0.0;
	int i = 1;
	while(i <= N)
	{
		x = x0 - eval(Expression, x0)/Differential(Expression, x0);
		if(fabs(x - x0) < eps)
			return x;
		i = i + 1;
		x0 = x;
	}
	printf("牛顿法迭代没有收敛！\n");
	
	return -1;
}

double Secant(char Expression[], double p0, double p1, double eps = 0.0001, int N = 100)
{
	int i;
	double p, q0, q1;
	
	i = 2;
	q0 = eval(Expression, p0);
	q1 = eval(Expression, p1);
	
	while(i <= N)
	{
		p = p1 - q1 * (p1 - p0) / (q1 - q0);
		if(fabs(p - p1) < eps)
			return p;
		
		i = i + 1;
		p0 = p1;
		q0 = q1;
		p1 = p;
		q1 = eval(Expression, p);
	}
	
	printf("割线法迭代没有收敛！\n");
	return -1;
}

double Steffensen(char Expression[], double p0, double eps = 0.0001, int N = 100)
{
	int i = 1;
	double p, p1, p2;
	while(i <= N)
	{
		p1 = eval(Expression, p0);
		p2 = eval(Expression, p1);
		
		p = p0 - (p1 - p0) * (p1 - p0) / (p2 - 2*p1 + p0);
		if(fabs(p0 - p) < eps)
			return p;
			
		i = i + 1;
		p0 = p;
	}
	
	printf("Steffensen法没有收敛！\n");
}

int GaussElimination(double** a, int row, int column)
{
	int i, j, k, p;
	int n = row;
	
	for (i = 0; i < n - 1; i++)
	{
		for (p = i; p < n; p++)
		{
			if (a[p][i] != 0)
				break;
		}
		if (p == n)
		{
			printf("高斯消元没有唯一的解！ error code = -1\n");
			return FALSE;
		}
		if (p != i)
		{
			for (k = i; k < column; k++)
			{
				double temp = a[p][k];
				a[p][k] = a[i][k];
				a[i][k] = temp;
			}
		}

		for (j = i + 1; j < n; j++)
		{
			double m = a[j][i] / a[i][i];
			for (k = i; k <= column - 1; k++)
			{
				a[j][k] -= m * a[i][k];
			}
		}
	}

	//printf("%lf\n", a[n - 1][n - 1]);
	if (ABS(a[n - 1][n - 1]) < ZERO)
	{
		printf("高斯消元没有唯一的解！error code = -2\n");
		return FALSE;
	}

	//printf("结果矩阵:\n");
	//for (i = 0; i < row; i++) {
	//	for (j = 0; j < column; j++) {
	//		printf("%lf ", a[i][j]);
	//	}
	//	printf("\n");
	//}
	return TRUE;
}

int GaussJordanMethod(double** a, int row, int column) {
	int i, j, k, p;
	int n = row;

	for (i = 0; i < n; i++)
	{
		for (p = i; p < n; p++)
		{
			if (a[p][i] != 0)
				break;
		}
		if (p == n)
		{
			printf("高斯消元没有唯一的解！ error code = -1\n");
			return FALSE;
		}
		if (p != i)
		{
			for (k = i; k < column; k++)
			{
				double temp = a[p][k];
				a[p][k] = a[i][k];
				a[i][k] = temp;
			}
		}

		for (j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			double m = a[j][i] / a[i][i];
			for (k = i; k < column; k++)
			{
				a[j][k] -= m * a[i][k];
			}
		}
	}

	//printf("\n结果矩阵:\n");
	//for (i = 0; i < row; i++) {
	//	for (j = 0; j < column; j++) {
	//		printf("%lf ", a[i][j]);
	//	}
	//	printf("\n");
	//}

	return TRUE;
}

bool IsZero(double a)
{
	return a*a < ZERO;
}

bool IsOne(double a)
{
	return (a-1)*(a-1) < ZERO;
}

int PolynomialConvertAuxiliary(double x[], bool vis[], int total, double * res, int n, int current, int guard)
{
	if (current + total - 1 - guard < n)
		return 1;
	if (current == n) {
		double sum = 1.0;
		for (int i = 0; i < total; i++) {
			if (vis) {
				sum *= x[i];
			}
		}
		*res += n % 2 == 0 ? sum : -sum;
		return 1;
	}
	else {
		for (int i = guard; i < total; i++) {
			if (!vis[i]) {
				vis[i] = 1;
				PolynomialConvertAuxiliary(x,vis,total, res, n,current+1,i+1);
				vis[i] = 0;
			}			
		}
	}
	return 1;
}

