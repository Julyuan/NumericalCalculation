#include"vector.h"	

Vector::Vector() {
	dimension = 0;
	vec = nullptr;
}

Vector::Vector(int dim) {
	dimension = dim;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = 0.0;
	}
}

double Vector::Norm(int dim)
{
	if (dim < 1) {
		double res = vec[0];
		for (int i = 1; i < dim; i++) {
			res = res < vec[i] ? vec[i] : res;
		}
		return res;
	}
	else {
		double res = 0;
		for (int i = 0; i < dim; i++) {
			res += pow(vec[i], (double)dim);
		}
		return pow(res, 1.0 / dim);
	}
	
}

double * Vector::NewVector(int dimension)
{
	if (dimension <= 0) {
		std::cout << "向量维数出错，请仔细检查" << std::endl;
		return nullptr;
	}
	else {
		return new double[dimension];
	}
}

void Vector::DeleteVector(double * vec)
{
	if (vec == nullptr) {
		std::cout << "释放无效的空指针" << std::endl;
	}
	else {
		delete[]vec;
	}
}

void Vector::SetVector(std::initializer_list<double> lis)
{
	int count = 0;
	this->vec = new double[lis.size()];
	for (auto iter : lis) {
		vec[count++] = iter;
	}
}

Vector::Vector(double a[], int dim) {
	dimension = dim;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = a[i];
	}
}

Vector::Vector(Vector& other) {
	this->dimension = other.dimension;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = other.vec[i];
	}
}

Vector::Vector(char * str)
{
	std::vector<double> temp;
	int length = strlen(str);
	bool flag;
	int ndim, dim;

	ndim = 0;
	flag = false;
	int* len = new int;
	for (int i = 0; i<length; i++) {
		if (str[i] <= '9' && str[i] >= '0' || str[i] == '-') {
			ndim += 1;
			double num = str[i] == '-' ? ReadNumber(&(str[i + 1]), len) : ReadNumber(&(str[i]), len);
			i += *len;
			if (str[i] == '-') {
				i++;
				num *= -1;
			}
			temp.push_back(num);
			continue;
		}
		//else if (str[i] == ';') {
		//	nrow += 1;
		//	//	printf("ncol = %d\n", ncol);

		//	if (flag == false) {
		//		flag = true;
		//		this->column = ncol;
		//	}
		//	else if (ncol != this->column) {
		//		std::cout << "你的矩阵好像有、问题，每一行的数目不一样" << std::endl;
		//		return;
		//	}
		//	ncol = 0;
		//}
		else if (str[i] == ')') {
			break;
		}
	}

	dim = ndim;
	vec = NewVector(dim);
	for (int i = 0; i < dim; i++)
	{
		vec[i] = temp[i];
	}

	delete len;
}

Vector::Vector(std::initializer_list<double> lis)
{
	SetVector(lis);
}

void Vector::SetAllElementsZero()
{
	for (int i = 0; i < dimension; i++)
		vec[i] = 0.0;
}

double Vector::dot(const Vector & other)
{
	double ans = 0;
	if (this->dimension != other.dimension) {
		std::cout << "向量维数不同" << std::endl;
		return ans;
	}
	else {
		for (int i = 0; i < dimension; i++) {
			ans += vec[i] * other.vec[i];
		}
	}
	return ans;
}

void Vector::PrintVector()
{
	std::cout << "[";
	for (int i = 0; i < this->dimension; i++) {
		if (i != dimension - 1)
			std::cout << vec[i] << " ,";
		else
			std::cout << vec[i];
	}
	std::cout << "]" << std::endl;

}

Vector Vector::operator-()
{
	Vector res(*this);
	for (int i = 0; i < dimension; i++) {
		res.vec[i] *= -1;
	}
	return res;
}

Vector Vector::operator-(Vector & other)
{
	Vector res(this->dimension);
	if (this->dimension != other.dimension) {
		std::cout << "向量维数不一致，运算无效" << std::endl;
		return res;
	}
	else {
		for (int i = 0; i < res.dimension; i++) {
			res.vec[i] = this->vec[i] - other.vec[i];
		}
		return res;
	}
}

Vector Vector::operator+(Vector & other)
{
	return *this - (-other);
}

Vector Vector::operator=(const Vector & other)
{
	dimension = other.dimension;
	vec = new double[dimension];
	for (int i = 0; i < dimension; i++) {
		vec[i] = other.vec[i];
	}
	return *this;
}

Vector Vector::operator/(double other)
{
	Vector res(*this);
	if (IsZero(other)) {
		std::cout << "除数不能为0" << std::endl;
	}
	else {
		for (int i = 0; i < dimension; i++) {
			res.vec[i] /= other;
		}
	}
	return res;
}

double& Vector::operator[](int index)
{
	return vec[index];
}

