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
		*(m_root + i) = i;
	}

	return true;
}

void Buffer_32b::setData(int x, int y)
{
	*(m_root + (m_width * y) + (x));
}

void * Buffer_32b::getData(int x, int y,int rgba)
{
	return (m_root + (m_width * y) + (x)+rgba);
}

double Buffer_32b::getD(int x, int y, int rgba)
{
	return *(m_root + (m_width * y) + (x)+rgba) / FLT_MAX;
}

void Buffer_32b::copy(CBuffer * BUF)
{
	float Xb = 1 / BUF->getWidth(), Yb = 1 / BUF->getHeight();
	int X = BUF->getWidth(), Y = BUF->getHeight();
	short chor;
	for (int i = 0; i < Y; i++)
	{

		for (int j = 0; j < X; j++)
		{
			for (int k = 0; k < m_formatStep || k < BUF->getFormat(); k++)
			{
				(*(m_root + int(std::round(Yb*i*m_width))*Y + int(std::round(Xb*j*m_height) + k))) = (short)BUF->getD(j, i, k) * FLT_MAX;
			}

		}
	}
}

Buffer_32b::Buffer_32b()
{
}


Buffer_32b::~Buffer_32b()
{
}
