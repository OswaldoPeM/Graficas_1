#pragma once
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include"FORMATO.h"


class CBuffer
{
protected:
	int m_format, m_formatStep, m_bufferSizeByte;
	int m_width, m_height;

public:

	virtual bool init(int x, int y, int FORMATO);
	void set(int x, int y);


	short* get(int x, int y);
	int getFormat() { return m_formatStep; }
	int getWidth() { return m_width; }
	int getHeight() { return m_height; }


	virtual void copy(CBuffer* BUFFER);

	void printBuffer();

	CBuffer();
	~CBuffer();
};

