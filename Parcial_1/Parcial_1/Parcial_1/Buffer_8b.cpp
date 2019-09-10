#include "Buffer_8b.h"



bool Buffer_8b::init(int x, int y,int FORMATO)
{
	m_format = FORMATO;
	m_width = x;
	m_height = y;

	switch (FORMATO)
	{
	case 0:
		m_bufferSizeByte = x * y * sizeof(unsigned char) * 4;
		m_root = (unsigned char*)malloc(m_bufferSizeByte);
		m_formatStep = 4;
		break;
	case 1:
		m_bufferSizeByte = x * y * sizeof(unsigned char) * 3;
		m_root = (unsigned char*)malloc(m_bufferSizeByte);
		m_formatStep = 3;
		break;
	case 2:
		m_bufferSizeByte = x * y * sizeof(unsigned char) * 2;
		m_root = (unsigned char*)malloc(m_bufferSizeByte);
		m_formatStep = 2;
		break;
	case 3:
		m_bufferSizeByte = x * y * sizeof(unsigned char);
		m_root = (unsigned char*)malloc(m_bufferSizeByte);
		m_formatStep = 1;
		break;
	default:
		break;
	}

	int ps = m_formatStep * m_width * m_height;

	for (int i = 0; i < ps; i++)
	{
		*(m_root + i) = i;
	}
	return true;
}

void Buffer_8b::setData(int x, int y)
{
}

void Buffer_8b::setData(int x, int y, double data,int rgba)
{
	*(m_root + (m_width * y*m_formatStep) + (x*m_formatStep)+rgba) = data;
}

void * Buffer_8b::getData(int x, int y,int rgba)
{
	return (m_root + (m_width * y) + (x)+rgba);
}

double Buffer_8b::getD(int x, int y, int rgba)
{
	x--;
    y--;

	return (*(m_root + (m_width * y*m_formatStep) + (x*m_formatStep) + rgba));
}



void Buffer_8b::copy(CBuffer * BUF)
{
	clearBuffer();
	float Xb, Yb;
	int X = BUF->getWidth(), Y = BUF->getHeight(), cordAy, cordAx;
	int pitch = m_width * m_formatStep;
	Xb = double(1.0f / m_width);
	Yb = double(1.0f / m_height);
	short chor;
	for (int i = 1; i <= m_height; i++)
	{

		for (int j = 1; j <= m_width; j++)
		{
			cordAy = int(std::ceil(Yb*i*Y));
			cordAx = int(std::ceil(Xb*j*X));
			for (int k = 0; k < m_formatStep || k < BUF->getFormat(); k++)
			{
				chor = unsigned char(BUF->getD(cordAx, cordAy, k));
				(*(m_root + (((i - 1) * pitch) + ((j - 1)*m_formatStep) + k))) = chor;
			}

		}
	}
}


void Buffer_8b::printBuffer()
{
	int j = 0, sz = m_width * m_height;
	for (int i = 0; i < sz; i++)
	{
		for (int k = 0; k < m_formatStep; k++)
		{
		std::cout << int(*(m_root + i * m_formatStep+k)) << "-";
		}
		std::cout << " | ";
		if (j >= m_width - 1) {
			j = 0;
			std::cout << std::endl;
		}
		else {
			j++;
		}
	}
}

void Buffer_8b::clearBuffer()
{
	int sz = m_width * m_height*m_formatStep;
	for (int i = 0; i < sz; i++)
	{
		*(m_root + i) = 0;
	}
}

Buffer_8b::Buffer_8b():
	m_root(nullptr)
{
}


Buffer_8b::~Buffer_8b()
{
	free(m_root);
}
