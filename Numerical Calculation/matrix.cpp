#include"matrix.h"

//int count = 0;

Matrix::Matrix()
{
	row = column = 0;
	mat = NULL;
	
}

Matrix::~Matrix()
{
	//count++;
	//std::cout << "调用析构函数 count = " << count << std::endl;
	DeleteMatrix(this->row, this->mat);
}

Matrix::Matrix(Matrix &other):row(other.row), column(other.column){
//	std::cout << "127" << std::endl;
	mat = NewMatrix(row, column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			mat[i][j] = other.mat[i][j];
		}
	}
}

Matrix::Matrix(int row, int column):row(row), column(column){
	mat = new double*[row];
	for(int i=0;i<row;i++)
	{
		mat[i] = new double[column];
		memset(mat[i],0,sizeof(mat[i]));
	}
}

double Matrix::MaxElement(int mode)
{
	double res = mode == 0 ? ABS(this->mat[0][0]) : mat[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			res = mode == 0 ? (ABS(mat[i][j]) > res ? ABS(mat[i][j]) : res) : (mat[i][j] > res ? mat[i][j] : res);
			std::cout << "i = " << i << ", j = " << j << std::endl;
			std::cout << "mat[i][j] = " << ABS(mat[i][j]) << " res = " << res << std::endl;
		}
	}
	std::cout << "final res = " << res << std::endl;
	return res;
}

Vector Matrix::ToVector()
{
	return Vector();
}

Matrix Matrix::SubMatrix(int row, int column)
{
	Matrix res(row, column);
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			res.mat[i][j] = 0;
		}
	}

	return res;
}

double ** Matrix::MatrixJoin(Matrix & a, Vector & b)
{	
	if (a.row != b.dimension) {
		std::cout << "矩阵和向量维数不匹配" << std::endl;
		return nullptr;
	}
	else {
		int res_row = a.row;
		int res_column = a.column + 1;
		double** res = NewMatrix(res_row, res_column);
		for (int i = 0; i < res_row; i++) {
			for (int j = 0; j < res_column; j++) {
				res[i][j] = j == res_column - 1 ? b[j] : a[i][j];
			}
		}
	}

}


double ** Matrix::NewMatrix(int row, int column)
{
	double** res;
	res = new double*[row];
	for (int i = 0; i<row; i++)
	{
		res[i] = new double[column];
		memset(res[i], 0, sizeof(res[i]));
	}
	return res;
}

void Matrix::DeleteMatrix(int row, double ** mat)
{
	for (int i = 0; i<row; i++) {
		delete[] mat[i];
	}
	delete[] mat;
}

void Matrix::CopyToArray(double ** mat)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			mat[i][j] = this->mat[i][j];
		}
	}
}


double Matrix::GetNorm(int p)
{
	if (p <= 0) {
		if (row != column)
			return 0;
		double sum = 0;
		for (int i = 0; i < row; i++) {
			double temp = 0;
			for (int j = 0; j < column; j++) {
				temp += ABS(mat[i][j]);
			}
			sum = temp > sum ? temp : sum;
		}
		return sum;
	}
	else if (p == 1) {
		return MaxElement();
	}
	else {
		std::cout << "范数无效" << std::endl;
		return -1;
	}
}

void Matrix::SetMatrix()
{
	DeleteMatrix(row, mat);

	printf("输入矩阵的行数和列数：\n");
	scanf("%d%d",&row,&column);
	
	mat = new double*[row];
	
	for(int i=0;i<row;i++){
		mat[i] = new double[column];
	}

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			scanf("%lf", &mat[i][j]);
		}
	}
}

void Matrix::SetAllElementsZero()
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			mat[i][j] = 0.0;
		}
	}
}

void Matrix::SetMatrix(char str[]){
	std::vector<double> temp;
	int length = strlen(str);
	bool flag;
	int nrow, ncol;
	
	nrow = ncol = 0;
	flag = false; 
	int* len = new int;
	for(int i=0;i<length;i++){
	//	printf("127\n");
		if(str[i]<='9' && str[i]>='0' || str[i] == '-'){
			ncol += 1;
			double num = str[i]=='-' ? ReadNumber(&(str[i+1]), len) :ReadNumber(&(str[i]), len);
			i += *len;
			if (str[i] == '-') {
				i++;
				num *= -1;
			}
			temp.push_back(num);
			continue;
		}
		else if(str[i]==';'){
			nrow += 1; 
		//	printf("ncol = %d\n", ncol);

			if(flag==false){
				flag = true;
				this->column = ncol;
			}
			else if(ncol != this->column){
				std::cout<<"你的矩阵好像有、问题，每一行的数目不一样"<<std::endl;
				return;
			}
			ncol = 0;
		}
		else if(str[i]==']'){
			nrow += 1;
			this->row = nrow;
			if (flag == false) {
				flag = true;
				this->column = ncol;
			}
			else if (ncol != this->column) {
				std::cout << "你的矩阵好像有、问题，每一行的数目不一样" << std::endl;
				return;
			}
			ncol = 0;
			break;
		}
	}
	
	mat = NewMatrix(row, column);

	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < column; j++)
		{
			mat[i][j] = temp[i*column + j];
		}
	}
	
	delete len;
}

double Matrix::Determinant()
{
	if(this->row != this->column)
	{
		printf("该矩阵的行列式不存在!\n");
		return -1;
	}
	int i, j, k;
	int temprow = this->row;
	int tempcolumn = this->column;
	double** tempmat = NewMatrix(temprow, tempcolumn);
	
	for(i = 0; i < this->row; i++)
	{
		for(j = 0; j < this->column; j++)
		{
			tempmat[i][j] = this->mat[i][j];
		}
	}
	//GaussJordanMethod(tempmat, row, column + 1);
	GaussElimination(tempmat, row, column + 1); 
	double ans = 1.0;
	for(i = 0; i < this->row; i++)
		ans *= tempmat[i][i];
	return ans;
}

//只适用于所有特征根是单根的情况
double Matrix::PowerMethod(Vector* res,Vector * Eigenvector = NULL)
{
	int N = 100;
	int n = this->row;
	double TOL = 0.00001;
	res = new Vector(this->row);
	Vector y;
	if (Eigenvector == NULL) {
		res = Eigenvector;
	}
	else {
		for (int i = 0; i < n; i++) {
			res->vec[i] = double(rand() % 100 - 50);
		}
	}

	double eigenValue;
	
	int k = 1;
	bool flag = false;
	*res = *res / res->Norm(2);
	while (k <= N) {
		y = *this * (*res);
		eigenValue = res->dot(y);
		if (IsZero(y.Norm(2))) {
			
			break;
		}
		double error = (*res - (y / y.Norm(2))).Norm(2);
		if (error < TOL) {
			return eigenValue;
		}
	}

	std::cout << "迭代超出，思想出了问题" << std::endl;
	return -1;
}

// 线性方程组求解方法
Vector Matrix::LinearEquation(Vector & b, int mode = 0)
{
	if (mode == 0) {
		return LinearEquationDirectMethod(b);
	}
	else {
		return LinearEquationIterativeMethod(b);
	}
}


// 利用直接的方法解线性方程组
Vector Matrix::LinearEquationDirectMethod(Vector & b)
{

	Vector res(b);
	int n = this->GetRow();
	res.SetAllElementsZero();
	double** mat = MatrixJoin(*this, b);
	GaussElimination(mat, this->GetRow(), this->GetColumn() + 1);
	res.vec[n - 1] = mat[n - 1][n] / mat[n - 1][n - 1];
	for (int i = n - 2; i >= 0; i--) {
		double sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum += mat[i][j] * b.vec[j];
		}
		res.vec[i] = (mat[i][n] - sum) / mat[i][i];
	}
	return res;
}

// 利用迭代的方法求解线性方程组
Vector Matrix::LinearEquationIterativeMethod(Vector & b)
{
	Vector res;
	if (0 == 1) {
		printf("该矩阵无法由迭代求解");
	}
	else {
		double TOL = 0.001;
		int N = 100, n = row;
		int k = 0;
		Vector XO(res.dimension);
		Vector x(XO);
		XO.SetAllElementsZero();
		while (k < N) {
			for (int i = 0; i < n; i++) {
				double sum = 0;
				for (int j = 0; j < n; j++) {
					if (j == i)
						continue;
					else {
						sum += mat[i][j] * XO[j];
					}
				}
				x[i] = (b[i] - sum) / mat[i][i];
			}
			if ((x - XO).Norm(0) < TOL)
				return x;
			k = k + 1;
			XO = x;
		}
	}
	printf("Maximum number of iterations exceeded");
	return b;
}

// void GaussElimination(double a[MaxRowNumber][MaxColumnNumber], int row, int column)
// 矩阵现在只能求一范数和无穷范数
//double Matrix::GetNorm(int p)
//{
//	// 无穷范数
//	if (p == 0) {
//
//		return 0.0;
//	}
//
//	// 一范数
//	else if (p == 1) {
//
//		return 0.0;
//	}
//}

int Matrix::GetRow()
{
	return this->row;
}

int Matrix::GetColumn()
{
	return this->column;
}

// 打印矩阵
void Matrix::PrintMatrix()
{
	for(int i = 0; i < this->row; i++)
	{
		for(int j = 0; j < this->column; j++)
		{
			printf("%lf ",this->mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// 求解逆矩阵
Matrix Matrix::InvMatrix()
{
	Matrix ans(*this);

	if (row != column) {
		printf("矩阵行列不匹配!\n");
		return ans;
	}

	double** auxiliary = NewMatrix(row, 2 * column);

	CopyToArray(auxiliary);

	for (int i = 0; i < row; i++) {
		for (int j = column; j < column*2; j++) {
			auxiliary[i][j] = i+column==j;
		}
	}

	GaussJordanMethod(auxiliary, row, column * 2);
	for (int i = 0; i < row; i++) {
		if (ABS(auxiliary[i][i]) > ZERO) {
			double temp = auxiliary[i][i];
			for (int j = 0; j < column; j++) {
				auxiliary[i][j+column] /= temp;
			}
		}
		else {
			printf("这个矩阵思想出了问题!\n");
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			ans[i][j] = auxiliary[i][j + column];
		}
	}
	return ans;
}

// 矩阵LU分解
Matrix Matrix::LUFactorization(int choose = 1)
{
	Matrix lower(*this), upper(*this);
	lower.SetAllElementsZero();
	upper.SetAllElementsZero();

	int i, j, k,n = row;

	if (IsZero(mat[0][0])) {
		printf("mat[0][0] = %lf\n", mat[0][0]);
		printf("该矩阵不可分解! error code -1\n");
		return lower;
	}

	lower[0][0] = 1.0;
	upper[0][0] = mat[0][0];
	
	for (j = 1; j < n; j++) {
		upper[0][j] = mat[0][j] / lower[0][0];
		lower[j][0] = mat[j][0] / upper[0][0];
	}

	for (i = 1; i < n - 1; i++) {
		double temp = mat[i][i];
		for (k = 0; k <= i - 1; k++) {
			temp -= lower[i][k] * upper[k][i];
		}
		if (IsZero(temp)) {
			printf("该矩阵不可分解! error code -2\n");
			return lower;
		}

		lower[i][i] = 1;
		upper[i][i] = temp;

		for (j = i + 1; j < n; j++) {
			double temp1 = mat[i][j], temp2 = mat[j][i];
			for (k = 0; k < i; k++) {
				temp1 -= lower[i][k] * upper[k][j];
				temp2 -= lower[j][k] * upper[k][i];
			}
			upper[i][j] = temp1 / lower[i][i];
			lower[j][i] = temp2 / upper[i][i];
		}

		temp = mat[n - 1][n - 1];
		for (k = 0; k < n - 1; k++) {
			temp -= lower[n - 1][k] * upper[k][n - 1];
		}

		if (IsZero(temp)) {
			printf("提示，该矩阵是奇异的\n");
		}
		else {
			lower[n - 1][n - 1] = 1;
			upper[n - 1][n - 1] = temp;
		}
	}

	return choose==1 ? lower:upper;
}

Matrix Matrix::operator+(Matrix& other){
	Matrix res(this->row, this->column);
	
	if(this->row!=other.row || this->column != other.column){
		std::cout << "两个矩阵行列不匹配" << std::endl;
	}
		
	for(int i=0;i<this->row;i++){
		for(int j=0;j<this->column;j++){
			res.mat[i][j] = mat[i][j] + other.mat[i][j];
		}
	}	

	//res.PrintMatrix();
	return res;
}

Matrix Matrix::operator-(Matrix& other){
	Matrix res(this->row, this->column);
	for(int i=0;i<this->row;i++){
		for(int j=0;j<this->column;j++){
			res.mat[i][j] = mat[i][j] - other.mat[i][j];
		}
	}	
	
	return res;
}

Matrix & Matrix::operator=(Matrix & other)
{
	//std::cout << "调用赋值" << std::endl;
	// TODO: 在此处插入 return 语句
	this->row = other.row;
	this->column = other.column;
	mat = NewMatrix(row, column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			mat[i][j] = other.mat[i][j];
		}
	}
	return *this;
}

bool Matrix::operator==(Matrix & other)
{
	if(this->column!=other.column || this->row!=other.row)
		return false;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (IsZero(mat[i][j] - other.mat[i][j]) == false)
				return false;
		}
	}

	return true;
}

double *& Matrix::operator[](int index)
{
	return this->mat[index];
}

Matrix Matrix::operator*(Matrix& other){
	Matrix res(this->row, other.column);
	
	for(int i=0;i<this->row;i++){
		for(int j=0;j<other.column;j++){
			for (int k = 0; k < this->column; k++) {
				if (k == 0)
					res.mat[i][j] = 0;
				res.mat[i][j] += mat[i][k] * other.mat[k][j];
			}
		}
	}	
	return res;
}

bool PositiveDefiniteMatrix::Judge()
{
	if (row != column)
		return false;
	for (int i = 0; i < row; i++) {
		Matrix temp = this->SubMatrix(row, column);
		if (temp.Determinant() < 0.0) {
			return false;
		}
	}

	return true;
}

Matrix PositiveDefiniteMatrix::LDLFactorization(int option = 0)
{
	Matrix L(*this), D(*this);
	L.SetAllElementsZero();
	D.SetAllElementsZero();

	int n = this->row;
	double* v = new double[n];
	if (!this->Judge()) {
		std::cout << "该矩阵不可分解" << std::endl;
		return *this;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) 
			v[j] = L.mat[i][j] * D.mat[j][j];
		double sum = 0.0;
		for (int j = 0; j < i; j++)
			sum += L[i][j] * v[j];
		D.mat[i][i] = this->mat[i][i] - sum;
		sum = 0.0;
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < i; k++) {
				sum += L[j][k] * v[k];
			}
			L.mat[j][i] = (this->mat[j][i] - sum) / D[i][i];
		}
	}

	delete[] v;
	return option == 0 ? L:D;
}

Matrix PositiveDefiniteMatrix::Choleskis()
{
	Matrix a = LDLFactorization(0);
	Matrix b = LDLFactorization(1);
	for (int i = 0; i < row; i++) {
		a.mat[i][i] = sqrt(b.mat[i][i]);
	}

	return a;
}

Vector Matrix::operator*(Vector & other)
{
	if (GetColumn() != other.dimension) {
		std::cout << "矩阵向量不匹配，无法相乘" << std::endl;
		return other;
	}
	else {
		Vector ans(GetRow());
		ans.SetAllElementsZero();

		for (int i = 0; i < GetRow(); i++) {
			for (int j = 0; j < other.dimension; j++) {
				ans.vec[i] += this->mat[i][j] * other.vec[j];
			}
		}
		return ans;
	}
	
}
