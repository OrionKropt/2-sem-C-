///////
///////  1. space invader Timus 2099 ������ (������)
///////  
///////  2. Timus 1444 (��������)
/////// 
///////  �������� �� ��� ����� � ��� ������ ����� � ������������
/////// ����� ���� Point, Scene -> ��������� ���� � ������ ��� ������� ������
/////// ���� ������ ������ ��� ����� ������, ����� �� ��������� �� ���� ����� �� �������� ��������
/////// �� ����� ����� ����� ����������� ������� �������� ����� ��� ���������������
/////// 
/////// �������� �� ���� ������ � ������� ��������� � ��������� � ������� �����������
/////// 
/////// 3. �������� ����� ������� (���������) ��� ����� �� ������ 3 ( ����� 0, 1, 2)
/////// � ��� ����:
/////// ����:
///////		������� �������
///////		������ ������������
/////// ������:
///////		Print()
///////		�����������
///////		���� �� ������ (����� ���������� ������)
///////		���������� �������� �������� � �����
///////		�������� ���� �����������
///////		������� ���������� ���������
///////		���������� �������������� ����������
///////		����������� � ������� ���������� ����� (��-�������)
/////// 
/////// 
/////// 
/////// 
//
#include <iostream>
#include "polynomial.h"
using namespace std;


int main()
{
	int* arr = new int[4] {1, 2, 2, 2};
	int* arr2 = new int[2] {1, 2};
	Polynomial pol(3, arr);
	Polynomial pol1(1, arr2);
	//pol.Init();
	pol.View();
	//pol1.Init();
	pol1.View();
	Polynomial pol2 = pol + pol1;
	cout << "pol + pol2 = ";
	pol2.View();
	//Polynomial pol(2);
	//cout << "PointValue() ";
	//cout << pol.PointValue(2) << endl;

	Polynomial remainder;
	pol.DivideIntoPolynomial(pol1, remainder);
	cout << "pol" << endl;
	pol.View();
	cout << "reminder" << endl;
	remainder.View();
	return 0;
}


//
  