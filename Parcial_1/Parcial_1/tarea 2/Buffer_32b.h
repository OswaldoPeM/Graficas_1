#pragma once
#include "CBuffer.h"
class Buffer_8b;

class Buffer_32b:
	public CBuffer
{
	float *m_root=nullptr;
public:
	bool init(int x, int y, int FORMATO);

	void setData(int x, int y, double data,int rgba);

	void* getData(int x, int y,int rgba);
	double getD(int x, int y, int rgba);

	void copy(CBuffer * BUF);
	void printBuffer();

	void clearBuffer();
	bool line(int x1, int y1, int x2, int y2);
	bool circle(int x, int y, int r);

	Buffer_32b();
	~Buffer_32b();
};

