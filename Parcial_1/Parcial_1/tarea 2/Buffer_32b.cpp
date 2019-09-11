#include "Buffer_32b.h"



bool Buffer_32b::init(int x, int y, int FORMATO)
{
	if (x <= 0 || y <= 0)return false;
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
	if (rgba >= m_formatStep) return;
	if (x <= 0 || y <= 0)return;
	if (x > m_width || y > m_height)return;

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
	return *(m_root + (m_width * y) + (x)+rgba) ;
}

void Buffer_32b::copy(CBuffer * BUF)
{
	float Xb, Yb;
	int X = BUF->getWidth(), Y = BUF->getHeight(),cordAy,cordAx;
	int pitch = m_width * m_formatStep;
	Xb = double(1.0f/ m_width);
	Yb = double(1.0f / m_height);
	short chor;
	for (int i = 1; i <=m_height; i++)
	{

		for (int j = 1; j <= m_width; j++)
		{
				cordAy = int(std::ceil(Yb*i*Y));
				cordAx = int(std::ceil(Xb*j*X));
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
			std::cout << (*(m_root + i * m_formatStep + k)) << canal.chanel[k] << ' ';
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
void Buffer_32b::clearBuffer()
{
	int sz = m_width * m_height*m_formatStep;
	for (int i = 0; i < sz; i++)
	{
		*(m_root + i) = 0;
	}
}

bool Buffer_32b::line(int x1, int y1, int x2, int y2)
{
	float x, y, dx, dy, step;
	int i;
	dx = (x2 - x1);
	dy = (y2 - y1);
	if (abs(dx) >= abs(dy))
		step = abs(dx);
	else
		step = abs(dy);
	dx = dx / step;
	dy = dy / step;
	x = x1;
	y = y1;
	i = 1;
	while (i <= step) {
		if (x > 0
			&& y>0
			&& y<m_height
			&& x<m_width) {
		setData(x, y, 1, 0);
		setData(x, y, 1, 1);
		setData(x, y, 1, 2);
		setData(x, y, 1, 3);
		}
		x = x + dx;
		y = y + dy;
		i = i + 1;
	}
	return true;
}

bool Buffer_32b::circle(int x, int y, int r)
{
	/*
codigo sacado de: https://www.geeksforgeeks.org/mid-point-circle-drawing-algorithm/
*/
	int X = r, Y = 0;
	setData(X + x, Y + y, 1, 0);
	setData(X + x, Y + y, 1, 1);
	setData(X + x, Y + y, 1, 2);
	setData(X + x, Y + y, 1, 3);

	if (r > 0)
	{
		for (int i = 0; i < m_formatStep; i++)
		{
			setData(-X + x, -Y + y, 1, i);
			setData(Y + x, X + y, 1, i);
			setData(-Y + x, -X + y, 1, i);
		}
	}


	int P = 1 - r;
	while (X > Y)
	{
		Y++;
		if (P <= 0)
			P = P + 2 * Y + 1;
		else
		{
			X--;
			P = P + 2 * Y - 2 * X + 1;
		}
		if (X < Y)
			break;

		for (int i = 0; i < m_formatStep; i++)
		{

			setData(X + x, Y + y, 1, i);
			setData(-X + x, Y + y, 1, i);
			setData(X + x, -Y + y, 1, i);
			setData(-X + x, -Y + y, 1, i);
		}
		if (X != Y)
		{
			for (int i = 0; i < m_formatStep; i++)
			{

				setData(Y + x, X + y, 1, i);
				setData(-Y + x, X + y, 1, i);
				setData(Y + x, -X + y, 1, i);
				setData(-Y + x, -X + y, 1, i);
			}
		}
	}
	return true;
}

Buffer_32b::Buffer_32b()
{
}


Buffer_32b::~Buffer_32b()
{
}
