#pragma once
#include"Header.h"
class RPixelShader
{
#ifdef DX
	ID3D11PixelShader * m_pPixelShader;
#endif
public:
#ifdef DX
	ID3D11PixelShader ** getPS() { return &m_pPixelShader; }
#endif
	RPixelShader();
	~RPixelShader();
};

