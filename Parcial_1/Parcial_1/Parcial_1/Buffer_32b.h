#pragma once
#include "CBuffer.h"
class Buffer_32b:
	public CBuffer
{
	float *m_root;
public:
	Buffer_32b();
	~Buffer_32b();
};

