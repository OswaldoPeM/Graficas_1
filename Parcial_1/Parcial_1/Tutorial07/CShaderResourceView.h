#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

class CShaderResourceView
{
	ID3D11ShaderResourceView* g_pTextureRV=NULL;
public:

	ID3D11ShaderResourceView** getTextureRV();

	void destoy();

	CShaderResourceView();
	~CShaderResourceView();
};

