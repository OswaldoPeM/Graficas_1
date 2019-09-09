#include "Buffer_8b.h"



bool Buffer_8b::init(int x, int y,int FORMATO)
{
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

	return *(m_root + (m_width * y*m_formatStep) + (x*m_formatStep)+rgba);
}



void Buffer_8b::copy(CBuffer * BUF)
{
	float Xb = 1 / BUF->getWidth(), Yb = 1 / BUF->getHeight();
	int X=BUF->getWidth(), Y=BUF->getHeight();
	short chor;
	for (int i = 0; i < Y; i++)
	{

		for (int j = 0; j < X; j++)
		{
			for (int k = 0; k < m_formatStep||k<BUF->getFormat(); k++)
			{
				(*(m_root + int(std::round(Yb*i*m_width))*Y + int(std::round(Xb*j*m_height) + k))) = (short)BUF->getD(j,i,k) * SHRT_MAX;
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
		std::cout << (*(m_root + i * m_formatStep+k)) << "-";
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

Buffer_8b::Buffer_8b():
	m_root(nullptr)
{
}


Buffer_8b::~Buffer_8b()
{
	free(m_root);
}
