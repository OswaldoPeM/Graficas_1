#include "Buffer_8b.h"



bool Buffer_8b::init(int x, int y,int FORMATO)
{
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

void Buffer_8b::setData(int x, int y, short data)
{
	*(m_root + (m_width * y) + (x)) = data;
}

short * Buffer_8b::getData(int x, int y)
{
	
	return (m_root + (m_width * y) + (x));
}

Buffer_8b::Buffer_8b()
{
}


Buffer_8b::~Buffer_8b()
{
	free(m_root);
}
