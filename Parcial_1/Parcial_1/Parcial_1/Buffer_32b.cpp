#include "Buffer_32b.h"



bool Buffer_32b::init(int x, int y, int FORMATO)
{
	m_format = FORMATO;
	m_width = x;
	m_height = y;
	switch (FORMATO)
	{
	case 4:
		m_bufferSizeByte = x * y * sizeof(float) * 4;
		m_root = (float*)malloc(m_bufferSizeByte);
		m_formatStep = 4;
		break;
	case 5:
		m_bufferSizeByte = x * y * sizeof(float) * 3;
		m_root = (float*)malloc(m_bufferSizeByte);
		m_formatStep = 3;
		break;
	case 6:
		m_bufferSizeByte = x * y * sizeof(float) * 2;
		m_root = (float*)malloc(m_bufferSizeByte);
		m_formatStep = 2;
		break;
	case 7:
		m_bufferSizeByte = x * y * sizeof(float);
		m_root = (float*)malloc(m_bufferSizeByte);
		m_formatStep = 1;
		break;
	default:
		break;
	}

	int ps = m_formatStep * m_width * m_height;

	for (int i = 0; i < ps; i++)
	{
		*(m_root + i) = 0;
	}

	return true;
}

void Buffer_32b::setData(int x, int y, double data,int rgba)
{
	*(m_root + (m_width * y*m_formatStep) + (x*m_formatStep)+rgba) = data;
}

void * Buffer_32b::getData(int x, int y,int rgba)
{
	return (m_root + (m_width * y) + (x)+rgba);
}

double Buffer_32b::getD(int x, int y, int rgba)
{
	x--; 
	y--;
	return *(m_root + (m_width * y) + (x)+rgba);
}

void Buffer_32b::copy(CBuffer * BUF)
{
	float Xb, Yb;
	int X = BUF->getWidth(), Y = BUF->getHeight(),cordAy,cordAx;
	int pitch = m_width * m_formatStep;
	Xb = float(1.0f/ m_width);
	Yb = float(1.0f / m_height);
	short chor;
	for (int i = 1; i <=m_height; i++)
	{

		for (int j = 1; j <= m_width; j++)
		{
				cordAy = int(std::round(Yb*i*Y));
				cordAx = int(std::round(Xb*j*X));
			for (int k = 0; k < m_formatStep || k < BUF->getFormat(); k++)
			{
				chor = short(BUF->getD(cordAx, cordAy, k));
				(*(m_root +( ((i-1) * pitch) + ((j-1)*m_formatStep )+ k))) = chor;
			}

		}
	}
}

void Buffer_32b::printBuffer()
{
	int j = 0, sz = m_width * m_height;
	for (int i = 0; i < sz; i++)
	{
		for (int k = 0; k < m_formatStep; k++)
		{
			std::cout << (*(m_root + i * m_formatStep + k)) << "-";
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

Buffer_32b::Buffer_32b()
{
}


Buffer_32b::~Buffer_32b()
{
}
