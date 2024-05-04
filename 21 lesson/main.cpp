#include <iostream>
#include <cmath>

using namespace std;


// ��
// 1. ������� ����� ������. ����� ��������� ��������� ���, ���������� ��� ������������,
// ���� ������������ �� ������� ����� �����������
// � ������ ������ ���� ����� ������� ���������� ����� �����������, ����� ������� �� ������  �������
// 2. ���������� ��� ����� ��������� �� ������ ����� ����� ��� �������� ���� ��� ��������� ��� ���
//
// 3. ������ ���������. � ��� ���� ������� ���� ����� ����� � ����� �������� ����� 0 �� ������� ����������
//


double intel();

double f(double x) { return sin(x); }

double Square(double(*) (double), double, double, double);



int main()

{
	double a, b, h;
	cin >> a >> b >> h;
	cout << Square(f, a, b, h);


/*
	for (i)
		for(j)
			for(k)
				for(t)
					for(h)
						for(r)
							for(c)
								for(f)
							for (c)
						for (r)
					for (h)
				for (t)
			for (k)
		for (j)
	for (i)
*/


	// ��������� �������� ������� � ������� ��������
	// ������ ������ ������� � ������� ����� ���� �������
	// ����� ������  (�������� �� ���� ��� ������)
	return 0;
}

double Square(double (*F) (double x), double a, double b, double h)
{
	double sum = (F(a) + F(b)) / 2;
	for (double i = a; i <= b; i += h)
	{
		sum += F(a);
	}
	return sum * h;
}