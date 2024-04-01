#include <iostream>
#include <string>
using namespace std;



template<typename T>
void bubble_sort(T* arr, const int& size);

template<typename T>
void bubble_sort(T* arr, const int& size, bool (*comp)(T, T)); // C-style

template<typename T>
void print_arr(T* arr, const int& size);

class Cat
{
public:
	Cat() : _name("name"), _age(0), _weight(0) {}
	Cat(const char* name, const int age, const int weight) : _age(age), _weight(weight), _name(name) {}
	friend ostream& operator<<(ostream& out, const Cat& cat)
	{
		out << "Name: " << cat._name << endl;
		out << "Age: " << cat._age << endl;
		out << "Weight: " << cat._weight << endl;
		return out;
	}
	Cat& operator=(const Cat& other)
	{
		this->_age = other._age;
		this->_weight = other._weight;
		this->_name = other._name;
		return *this;
	}

	bool operator>(const Cat& other)
	{
		if (this->_age == other._age)
		{
			if (this->_weight == other._weight)
			{
				return this->_name > other._name;
			}
			else return this->_weight > other._weight;
		}
		else return this->_age > other._age;
	}
	
	bool operator<(const Cat& other)
	{
		return !operator>(other);
	}

	bool operator== (const Cat & other)
	{
		return this->_age == other._age && this->_weight == other._weight && this->_name == other._name;
	}

	bool operator!= (const Cat& other)
	{
		return !operator==(other);
	}

private:
	string _name;
	int _age;
	int _weight;

};

int main()
{
	Cat cats[] = { Cat("Barsik", 2, 4), Cat("Arkadiy", 7, 2), Cat("Motya", 5, 1) };
	int* arr = new int[10] { 0, 1, 4, 9, 7, 6, 5 };
	bubble_sort(cats, 3);
	print_arr(cats, 3);
	return 0;
}

template<typename T>
void bubble_sort(T* arr, const int& size)
{
	if (arr == nullptr) return;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

template<typename T>
void bubble_sort(T* arr, const int& size, bool (*comp)(T, T))
{
	if (arr == nullptr) return;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j)
		{
			if (comp(arr[j], arr[j + 1])) swap(arr[j], arr[j + 1]);
		}
	}
}

template<typename T>
void print_arr(T* arr, const int& size)
{
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}