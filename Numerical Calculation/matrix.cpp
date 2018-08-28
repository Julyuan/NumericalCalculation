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

// void GaussElimination(double a[MaxRowNumber][MaxColumnNumber], int row, int column)

int Matrix::GetRow()
{
	return this->row;
}

int Matrix::GetColumn()
{
	return this->column;
}

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

Matrix Matrix::InvMatrix()
{
	Matrix ans(*this);

	if (row != column) {
		printf("矩阵行列不匹配!\n");
		return ans;
	}

	double** auxiliary = NewMatrix(row, 2 * column);

	//for (int i = 0; i < row; i++) {
	//	for (int j = 0; j < column; j++) {
	//		auxiliary[i][j] = mat[i][j];
	//	}
	//}
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

double * Matrix::operator[](int index)
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
