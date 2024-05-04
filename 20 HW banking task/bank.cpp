#include "bank.h"

Bank::Bank() : size(0), correct_accounts(nullptr)
{
	
}

void Bank::read_file(const std::string& file_name)
{
	std::fstream fin(file_name);
	std::string surname, number;
	int sum;
	if (!fin.is_open()) return;
	while (!fin.eof())
	{
		fin >> surname >> number >> sum;
		//std::cout << surname << ' ' << number << sum << std::endl;
		accounts.emplace(number, make_pair(surname, sum));
		++size;
	}
	correct_accounts = new std::string[size];
	fin.close();
}

void Bank::write_file(const std::string& file_name)
{
	
	std::ofstream fout(file_name);
	if (!fout.is_open()) return;
	if (size == 0)
	{
		fout << "There are no such accounts.";
		return;
	}
	sort_accounts();
	for (int i = 0; i < size; ++i)
	{
		auto [surname, sum] = accounts[correct_accounts[i]];
		fout << surname << ' ' << correct_accounts[i] << ' ' << sum << std::endl;
	}
	fout.close();
}

void Bank::find_accounts_by_first_figure(int figure)
{
	int i = 0;
	for (auto& a : accounts)
	{
		std::string number = a.first;
		auto [surname, sum] = a.second;
		//std::cout << number[0] - '0' << "fig = " << figure << std::endl;
		if (number[0] - '0' == figure)
			correct_accounts[i++] = number;
	}
	size = i;
}

Bank::~Bank()
{
	if (correct_accounts != nullptr) delete[] correct_accounts;
}

void Bank::sort_accounts()
{
	for (int i = 0; i < size - 1; ++i)
	{
		int Max = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (accounts[correct_accounts[j]].second > accounts[correct_accounts[Max]].second) Max = j;
		}
		swap(correct_accounts[i], correct_accounts[Max]);
	}
}
