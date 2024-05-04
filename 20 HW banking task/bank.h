#pragma once
#include <unordered_map>
#include <string>
#include <fstream>


//#include <iostream>

class Bank
{
public:
	Bank();
	void read_file(const std::string& file_name);
	void write_file(const std::string& file_name);
	void find_accounts_by_first_figure(int figure);
	~Bank();

private:

	void sort_accounts();

	std::unordered_map<std::string, std::pair<std::string, int>> accounts;
	std::string* correct_accounts;
	int size;
};