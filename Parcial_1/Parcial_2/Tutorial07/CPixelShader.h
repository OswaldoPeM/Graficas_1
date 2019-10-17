#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

class CPixelShader
{
	ID3D11PixelShader*       ptr_PixelShader = NULL;

public:

	ID3D11PixelShader** getPixelShader();

	void destroy();

	CPixelShader();
	~CPixelShader();
};

