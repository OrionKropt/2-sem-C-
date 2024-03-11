#include "polynomial.h"

Polynomial::Polynomial(int degree, int* Ptemp)
{
	this->degree = degree;
	this->arr = new int[degree + 1];
	for (int i = 0; i <= degree; ++i)
		arr[degree-i] = Ptemp[i];
}

Polynomial::Polynomial(int degree)
{
	this->degree = degree;
	arr = new int[degree+1] {0};
}

Polynomial::Polynomial(const Polynomial& other)
{
	this->degree = other.degree;
	if (this->arr != nullptr) delete[] this->arr;
	this->arr = new int[this->degree + 1];
	Copy(this->arr, this->degree + 1, other.arr, this->degree + 1);
}

void Polynomial::Init()
{
	std::cout << "Enter polynomial degree: ";
	std::cin >> this->degree;
	arr = new int[degree+1];
	std::cout << "Enter " << degree << " multipliers:\n";
	for (int i = 0; i <= degree; ++i)
		std::cin >> arr[degree-i];
}

void Polynomial::View()
{
	if (degree == 0 && arr[0] == 0)
	{
		std::cout << 0 << std::endl;
		return;
	}
	for (int i = degree; i >= 0; --i)
	{
		if (arr[i] != 0)
		{
			if (arr[i] > 0 && i != degree)
				std::cout << "+ ";
			if (arr[i] != 1 || i == 0)
				std::cout << arr[i];
			if (i != 0)
				std::cout << 'x';
			if (i > 1 )
				std::cout << "^" << i << ' ';
		}
	}
	std::cout << std::endl;
;
}

void Polynomial::SetMultiplier(int degree, int multiplier)
{
	arr[degree] = multiplier;
}

double Polynomial::PointValue(const double& point)
{
	double out = 0;
	for (int i = 0; i <= degree; ++i)
		out += Pow(point, i) * arr[i];
	return out;
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
	if (this->degree < other.degree)
	{
		delete[] this->arr;
		this->arr = new int[other.degree + 1] {0};
	}
	this->degree = other.degree;
	Copy(this->arr, this->degree + 1, other.arr, this->degree + 1);
	return *this;
}

void Polynomial::DivideIntoPolynomial(const Polynomial& divider, Polynomial& remainder)
{
	if (this->degree < divider.degree)
	{
		remainder = divider;
		*this = Polynomial(0);
		return;
	}

	int* ans = new int[this->degree+1] {0};
	int* CurrentPol = new int[this->degree+1] {0};
	Copy(CurrentPol, this->degree + 1, this->arr, this->degree + 1);
	int CurrentDegree = this->degree;
	while (CurrentDegree >= divider.degree)
	{
		int temp = CurrentDegree;
		int WorkDividerDegree = divider.degree;
		while (WorkDividerDegree >= 0)
		{
			int i;
			for (i = 1; i < 3 && divider.arr[WorkDividerDegree] * i < CurrentPol[CurrentDegree]; ++i) {}
			if (CurrentPol[CurrentDegree] > 0)
				ans[CurrentDegree - WorkDividerDegree] = (divider.arr[WorkDividerDegree] > 0) ?
				(i * divider.arr[WorkDividerDegree]) : (divider.arr[WorkDividerDegree] * -i);
			else
				ans[CurrentDegree - WorkDividerDegree] = !(divider.arr[WorkDividerDegree] > 0) ?
				(divider.arr[WorkDividerDegree] * i) : (divider.arr[WorkDividerDegree] * -i);

			CurrentPol[CurrentDegree] -= ans[CurrentDegree - WorkDividerDegree];
			--WorkDividerDegree;
			--CurrentDegree;
		}
		CurrentDegree = 0;
		for (int i = 1; i < temp; ++i) if (CurrentPol[i] != 0) ++CurrentDegree;
	}
	remainder = Polynomial(CurrentDegree, CurrentPol);
	delete[]this->arr;
	this->arr = ans;
	Shrink_to_fit();
	delete[]CurrentPol;
}



Polynomial Polynomial::operator+(const Polynomial& other)
{
	int tempDegree = (this->degree > other.degree) ?
		this->degree : other.degree;
	Polynomial pol(tempDegree);
	for (int i = 0; i <= tempDegree; i++)
	{
		if (i <= this->degree)
			if (i <= other.degree) pol.arr[i] = this->arr[i] + other.arr[i];
			else pol.arr[i] = this->arr[i];
		else pol.arr[i] = other.arr[i];
	}
	return pol;
}

Polynomial Polynomial::operator-(const Polynomial& other)
{
	int tempDegree = (this->degree > other.degree) ?
		this->degree : other.degree;
	Polynomial pol(tempDegree);
	for (int i = 0; i <= tempDegree; i++)
	{
		if (i <= this->degree)
			if (i <= other.degree) pol.arr[i] = this->arr[i] - other.arr[i];
			else pol.arr[i] = this->arr[i];
		else pol.arr[i] = -other.arr[i];
	}
	return pol;
}

double Polynomial::Pow(const double& a, const int& b)
{
	if (b == 0) return 1;
	if (b % 2 == 0) return  Pow(a, b / 2) * Pow(a, b / 2);

	return a * Pow(a, (b - 1) / 2) * Pow(a, (b - 1) / 2);
}

void Polynomial::Copy(int* des, const int& size, int* source, const int& CopySize)
{
	int SizeInBytes = sizeof(int) * CopySize;
	memcpy_s(des, SizeInBytes, source, SizeInBytes);
}

void Polynomial::Shrink_to_fit()
{
	if (arr[degree] == 0)
	{
		int count = 1; 
		for (int i = degree; i > 1; --i)
		{
			if (arr[i] == arr[i - 1]) ++count;
			else break;
		}
		int* arr = new int[degree + 1 - count];
		degree -= count;
		Copy(arr, degree + 1, (this->arr + count-1), degree + 1);
		delete[] this->arr;
		this->arr = arr;
	}
}
