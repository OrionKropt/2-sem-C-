#pragma once

template<class T>
class RingArrayQueue
{
public:
	RingArrayQueue(int size)
	{ 
		arr = new T[size]; 
		this->size = size; 
		head = tail = 0; 
		for (size_t i = 0; i < size; i++) arr[i] = 0; 
	}
	
	void push(T data) 
	{ 
		if (head == size) head = 0;
		arr[head++] = data; 
	}
	T pop() 
	{ 
		if (tail == size) tail = 0;
		return arr[tail++];
	}

private:
	size_t head;
	size_t tail;
	T* arr;
	size_t size;
};