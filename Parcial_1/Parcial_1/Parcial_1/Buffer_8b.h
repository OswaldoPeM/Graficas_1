#pragma once
#include "CBuffer.h"
class Buffer_32b;

class Buffer_8b :
	public CBuffer
{
	unsigned char* m_root=nullptr;
public:
	bool init(int x, int y,int FORMATO);
	void setData(int x, int y);
	void setData(int x, int y, double data,int rgba);
	void* getData(int x, int y,int rgba);
	double getD(int x, int y, int rgba);

	void copy(CBuffer * BUF);

	void printBuffer();
	bool line(int x1, int y1, int x2, int y2);
	void clearBuffer();

	Buffer_8b();
	~Buffer_8b();
};

