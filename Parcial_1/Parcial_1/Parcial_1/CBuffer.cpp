#include "CBuffer.h"


inline bool CBuffer::init(int x, int y, int FORMATO)
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

	for (int i = 0; i < ps; i++)
	{
		*(m_root + i) = i;
	}
	return true;
}


inline void CBuffer::set(int x, int y)
{
	*(m_root + (m_width * y) + (x));
}

inline short* CBuffer::get(int x, int y)
{
	return (m_root + (m_width * y) + (x));
}

inline void CBuffer::copy(CBuffer* BUFFER)
{


}

inline void CBuffer::printBuffer()
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

inline CBuffer::CBuffer()
{
}

inline CBuffer::~CBuffer()
{
}
