//����:
//�������, ����� ������ � ����� ������
//���� ��������� ����� ������� � �����
//� ������ ���� ����� �������� ������ ���������� ��� ����� ��������� �� �������� ����� �������������� �� �������� ���� ������
//
//���� ����� ��� �� �������� �� ����
//��� ������� �������� ����� � ������

#include <iostream>
#include "bank.h"



using namespace std;


int main()
{
	Bank bank;
	bank.read_file("input.txt");
	int  a = 10;
	while (a > 9 || a < 0)
	{
		cout << "Enter first figure in bank account: ";
		cin >> a;
		if (a > 9 || a < 0) cout << "Error\n Enter correct figure\n\n";
	}
	bank.find_accounts_by_first_figure(a);
	bank.write_file("output.txt");

	return 0;
}