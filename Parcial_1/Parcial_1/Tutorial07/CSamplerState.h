#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

class CSamplerState
{
	ID3D11SamplerState* g_pSamplerLinear = NULL;
public:

	ID3D11SamplerState**	getSamplerLinear();

	void destroy();
	CSamplerState();
	~CSamplerState();
};

