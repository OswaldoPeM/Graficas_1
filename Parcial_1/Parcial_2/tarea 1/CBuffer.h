#pragma once
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include"FORMATO.h"
struct rgba {
	char chanel[4] = {
		'R',
		'G',
		'B',
		'A' };
};

class CBuffer
{
protected:
	int m_format, m_formatStep, m_bufferSizeByte;
	int m_width, m_height;
	rgba canal;
public:

	virtual bool init(int x, int y, int FORMATO) = 0;
	virtual void setData(int x, int y, double data, int rgba) = 0;


	virtual void* getData(int x, int y,int rgba)=0;
	virtual double getD(int x, int y, int rgba) = 0;
	virtual int getFormat() { return m_formatStep; }
	virtual int getWidth() { return m_width; }
	virtual int getHeight() { return m_height; }

	virtual void copy(CBuffer* BUFFER)=0;
	virtual void printBuffer() = 0;
	virtual void clearBuffer() = 0;

	CBuffer();
	~CBuffer();
};

