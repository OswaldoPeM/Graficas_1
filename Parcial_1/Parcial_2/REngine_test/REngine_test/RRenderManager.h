#pragma once
#include"RBuffer.h"
#include"RModule.h"
struct RManagerData
{
	RPoint WPos;
	RRect  WLen;
};

class RRenderManager :
	public RModule< RRenderManager>
{
#ifdef DX
	ID3D11Device* m_Device = NULL;
#endif // DX

public:
	RRenderManager();
	~RRenderManager();
};

