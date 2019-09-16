#pragma once
#include "CBuffer.h"

struct SimpleVertex
{
	XMFLOAT3 Pos;
	XMFLOAT2 Tex;
};

class VBuffer :
	public CBuffer
{
public:
	VBuffer();
	~VBuffer();
};

