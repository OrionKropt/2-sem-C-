#pragma once

#include <iostream>

class Matrix
{
	friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
	friend std::istream& operator>> (std::istream& in, Matrix& matrix);
public:
	Matrix(const size_t& col, const size_t& row);
	Matrix(const Matrix& other);
	~Matrix();
	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other);
	void Set_ellement(unsigned int i, unsigned int j, int el);
	size_t GetCol() const;
	size_t GetRow() const;
	int Get_ellement(unsigned int i, unsigned int j) const;
	void View() const;
	

private:
	int* matrix;
	size_t col;
	size_t row;
};

Matrix::Matrix(const size_t& col, const size_t& row)
{
	this->col = col;
	this->row = row;
	matrix = new int[row * col];
}

Matrix::Matrix(const Matrix& other)
{
	if (this->row != other.row || this->col != other.col) return;
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			this->matrix[i * row + j] = other.matrix[i * row + j];
	this->row = other.row;
	this->col = other.col;
}

inline Matrix::~Matrix()
{
	delete[] matrix;
}

 Matrix& Matrix::operator=(const Matrix& other)
{
	 if (this->row != other.row || this->col != other.col) return *this;
	 for (int i = 0; i < col; i++)
		 for (int j = 0; j < row; j++)
			 this->matrix[i * row + j] = other.matrix[i * row + j];
	 return *this;
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix tempMatrix(this->col, this->row);
	for (int i = 0; i < col; i++)
		for (int j = 0; j < row; j++)
			tempMatrix.matrix[i * row + j] = this->matrix[i * row + j] + other.matrix[i * row + j];
	return tempMatrix;
}

void Matrix::Set_ellement(unsigned int i, unsigned int j, int el)
{
	if (i > col || j > row) return;
	matrix[i * row + j] = el;
}

 size_t Matrix::GetCol() const
{
	return this->col;
}

 size_t Matrix::GetRow() const
 {
	 return this->row;
 }

int Matrix::Get_ellement(unsigned int i, unsigned int j) const
{
	if (i > col || j > row) return -1;
	return matrix[i * row + j];
}

void Matrix::View() const
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
			std::cout << this->matrix[i * row + j] << " ";
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
	for (int i = 0; i < matrix.GetCol(); i++)
		for (int j = 0; j < matrix.GetRow(); j++)
		{
			int a;
			in >> a;
			matrix.Set_ellement(i, j, a);
		}
	return in;
}