#pragma once
#include <iostream>
/// �������� ����� �������(���������) ��� ����� �� ������ 3 (����� 0, 1, 2)
/// � ��� ����:
/// ����:
///		������� �������
///		������ ������������
/// ������:
///		Print() +
///		����������� +
///		���� �� ������ (����� ���������� ������) +
///		���������� �������� �������� � ����� +
///		�������� ���� ����������� +
///		������� ���������� ���������
///		���������� �������������� ����������
///		����������� � ������� ���������� ����� (��-�������)
/// 


class Polynomial
{
public:

	Polynomial(int degree, int* arr);
	Polynomial(int degree);
	Polynomial(const Polynomial& other);
	Polynomial() { degree = 0; arr = new int[degree + 1] {0}; };
	void Init();
	void View();
	void SetMultiplier(int degree, int multiplier);
	double PointValue(const double& point);
	Polynomial operator+(const Polynomial& other);
	Polynomial operator-(const Polynomial& other);
	Polynomial& operator=(const Polynomial& other);
	void DivideIntoPolynomial(const Polynomial& divider, Polynomial& remainder);
	~Polynomial() { delete[] arr; }
private:
	int degree;
	int* arr;
	double Pow(const double& a, const int& b);
	void Copy(int* des, const int& size, int* source, const int& CopySize);
	void Shrink_to_fit();
};
