#pragma once
#include<stdlib.h>
#include<iostream>

template<typename T>
class Buffer
{
	T* A = nullptr;
	int W, H;

public:
	void init(int x, int y);
	void set(int x, int y, T data);

	T get(int x, int y);

	void printBuffer();

	Buffer();
	~Buffer();
};

template<typename T>
inline void Buffer<T>::init(int x, int y)
{
	W = x;
	H = y;
	A = (T*)malloc(x * y * sizeof(T));
	for (int i = 0; i < W*H; i++)
	{
		*(A + i) = i;
	}
}

template<typename T>
inline void Buffer<T>::set(int x, int y, T data)
{
	int pitch = W * sizeof(T);
	*(A + (pitch * y) + (x * sizeof(T))) = data;
}

template<typename T>
inline T Buffer<T>::get(int x, int y)
{

	return *(A + (W * y) + (x));
}

template<typename T>
inline void Buffer<T>::printBuffer()
{
	int j = 0, sz = W * H;
	for (int i = 0; i < sz; i++)
	{
		std::cout << *(A + i) << " ";
		if (j >= W-1) {
			j = 0;
			std::cout << std::endl;
		}
		else {
			j++;
		}
	}
}

template<typename T>
inline Buffer<T>::Buffer()
{
}

template<typename T>
inline Buffer<T>::~Buffer()
{
	free(A);
}
