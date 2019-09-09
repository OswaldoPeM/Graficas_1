#pragma once
#include "CBuffer.h"
class Buffer_8b :
	public CBuffer
{
	short* m_root;
public:
	bool init(int x, int y,int FORMATO);
	void setData(int x, int y, short data);
	 
	short* getData(int x, int y);

	void copy(CBuffer * BUF);

	Buffer_8b();
	~Buffer_8b();
};

