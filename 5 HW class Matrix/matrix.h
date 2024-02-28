#pragma once

#include <iostream>

class Matrix
{
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
	friend std::istream& operator>> (std::istream& in, Matrix& matrix);
public:
	Matrix(const size_t& size);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other);
	void Set_ellement(unsigned int i, unsigned int j, int el);
	size_t GetSize() const;
	int Get_ellement(unsigned int i, unsigned int j) const;
	void View() const;
	

private:
	int* matrix;
	size_t size;
};

Matrix::Matrix(const size_t& size)
{
	this->size = size;
	matrix = new int[size * size];
}

Matrix::Matrix(const Matrix& other)
{
	if (this->size != other.size) return;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			this->matrix[i + j] = other.matrix[i + j];
	this->size = other.size;
}

inline Matrix::~Matrix()
{
	delete[] matrix;
}

 Matrix& Matrix::operator=(const Matrix& other)
{
	 for (int i = 0; i < size; i++)
		 for (int j = 0; j < size; j++)
			 this->matrix[i + j] = other.matrix[i + j];
	 return *this;
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix tempMatrix(this->size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			tempMatrix.matrix[i + j] = this->matrix[i + j] + other.matrix[i + j];
	return tempMatrix;
}

void Matrix::Set_ellement(unsigned int i, unsigned int j, int el)
{
	if (i > size || j > size) return;
	matrix[(i - 1) * size + j - 1] = el;
}

inline size_t Matrix::GetSize() const
{
	return this->size;
}

int Matrix::Get_ellement(unsigned int i, unsigned int j) const
{
	if (i > size || j > size) return -1;
	return matrix[(i - 1) * size + j - 1];
}

void Matrix::View() const
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << this->matrix[i*size + j] << " ";
		std::cout << std::endl;
	}
}

std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
	matrix.View();
	return out;
}

std::istream& operator>> (std::istream& in, Matrix& matrix)
{
	for (int i = 1; i <= matrix.GetSize(); i++)
		for (int j = 1; j <= matrix.GetSize(); j++)
		{
			int a;
			in >> a;
			matrix.Set_ellement(i, j, a);
		}
	return in;
}