#pragma once
#include "CBuffer.h"
class Buffer_32b;

class Buffer_8b :
	public CBuffer
{
	short* m_root=nullptr;
public:
	bool init(int x, int y,int FORMATO);
	void setData(int x, int y);
	void setData(int x, int y, short data);
	void* getData(int x, int y,int rgba);
	double getD(int x, int y, int rgba);

	void copy(CBuffer * BUF);

	void printBuffer();

	Buffer_8b();
	~Buffer_8b();
};

