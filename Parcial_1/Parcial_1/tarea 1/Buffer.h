#pragma once
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include"FORMATO.h"

template<typename T>
class Buffer
{
	short* m_root;
	int m_format,m_formatStep,m_bufferSizeByte;
	int m_width, m_height;

public:
	bool init(int x, int y,int FORMATO);
	void set(int x, int y, T data);


	short* get(int x, int y);
	int getFormat() { return m_formatStep; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }


	void copy(Buffer<short> BUFFER);

	void printBuffer();

	Buffer();
	~Buffer();
};

template<typename T>
inline bool Buffer<T>::init(int x, int y, int FORMATO)
{
	if (FORMATO > 7)return false;
	m_format = FORMATO;
	m_width = x;
	m_height = y;
	switch (FORMATO)
	{
	case 0:
		m_bufferSizeByte = x * y * sizeof(short) * 4;
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 4;
		break;
	case 1:
		m_bufferSizeByte = x * y * sizeof(short) * 3;
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 3;
		break;
	case 2:
		m_bufferSizeByte = x * y * sizeof(short) * 2;
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 2;
		break;
	case 3:
		m_bufferSizeByte = x * y * sizeof(short);
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 1;
		break;
	case 4:
		m_bufferSizeByte = x * y * sizeof(short) * 4 * 2;
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 8;
		break;
	case 5:
		m_bufferSizeByte = x * y * sizeof(short) * 3 * 2;
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 6;
		break;
	case 6:
		m_bufferSizeByte = x * y * sizeof(short) * 2 * 2;
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 4;
		break;
	case 7:
		m_bufferSizeByte = x * y * sizeof(short) * 2;
		m_root = (short*)malloc(m_bufferSizeByte);
		m_formatStep = 2;
		break;
	default:
		break;
	}
	
	int ps = m_formatStep * m_width * m_height;
	
	for (int i = 0; i <ps; i++)
	{
		*(m_root + i) = i;
	}
	return true;
}

template<typename T>
inline void Buffer<T>::set(int x, int y, T data)
{
	*(m_root + (m_width * y) + (x)) = data;
}

template<typename T>
inline short* Buffer<T>::get(int x, int y)
{
	return (m_root + (m_width * y) + (x));
}

template<typename T>
inline void Buffer<T>::copy(Buffer<short> BUFFER)
{
	

}

template<typename T>
inline void Buffer<T>::printBuffer()
{
	int j = 0, sz = m_width * m_height;

	switch (m_format)
	{
	case 0:case 1:case 2:case 3:
		for (int i = 0; i < sz; i++)
		{
			std::cout << (*(m_root + i * m_formatStep)) << "-R ";
			std::cout << (*(m_root + i * m_formatStep + 1)) << "-G ";
			std::cout << (*(m_root + i * m_formatStep + 2)) << "-B ";
			std::cout << (*(m_root + i * m_formatStep + 3)) << "-A | ";
			if (j >= m_width - 1) {
				j = 0;
				std::cout << std::endl;
			}
			else {
				j++;
			}
		}
		break;
	case 4:case 5:case 6: case 7:
		float  f;
		for (int i = 0; i < sz; i++)
		{
			f = (float)*(m_root + i * m_formatStep);
			std::cout << f << " ";
			std::cout << (*(m_root + i * m_formatStep)) << "-R ";
			std::cout << (*(m_root + i * m_formatStep + 2)) << "-G ";
			std::cout << (*(m_root + i * m_formatStep + 4)) << "-B ";
			std::cout << (*(m_root + i * m_formatStep + 6)) << "-A | ";

			if (j >= m_width - 1) {
				j = 0;
				std::cout << std::endl;
			}

			else { j++; }
		}
		break;
	default:
		break;
	}
}

template<typename T>
inline Buffer<T>::Buffer()
{
}

template<typename T>
inline Buffer<T>::~Buffer()
{
	free(m_root);
}
