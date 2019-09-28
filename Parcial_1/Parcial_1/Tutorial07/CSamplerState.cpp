#include "CSamplerState.h"



ID3D11SamplerState ** CSamplerState::getSamplerLinear()
{
	return &g_pSamplerLinear;
}

void CSamplerState::destroy()
{
	if (g_pSamplerLinear) g_pSamplerLinear->Release();
	delete this;
}

CSamplerState::CSamplerState()
{
}


CSamplerState::~CSamplerState()
{
}
