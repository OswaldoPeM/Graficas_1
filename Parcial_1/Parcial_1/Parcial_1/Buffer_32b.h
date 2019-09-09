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

	Buffer_32b();
	~Buffer_32b();
};

