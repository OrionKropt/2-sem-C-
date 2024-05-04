//Дано:
//Фамилия, номер вклада и сумма вклада
//есть несколько таких строчек в файле
//В другой файл нужно записать спсиок вкладчиков чей номер начинатся на заданную цирфу отсоритровнный по убыванию сумм вклада
//
//Если таких нет то сообщить об этом
//Для решения написать класс и методы

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