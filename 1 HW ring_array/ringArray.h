#pragma once



template<class T>
class RingArray
{
public:
	RingArray(int size) { arr = new T[size]; this->size = size; for (size_t i = 0; i < size; i++) arr[i] = 0; }
	RingArray(int size, T data)
	{
		arr = new T[size];
		this->size = size;
		for (int i = 0; i < size; i++) arr[i] = data;
	}
	RingArray() {};
	size_t GetSize() { return this->size; }

	T& operator[](int i)
	{
		return arr[i % size];
	}
private:
	T* arr;
	size_t size;
};