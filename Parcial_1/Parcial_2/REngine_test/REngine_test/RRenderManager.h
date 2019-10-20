/********************************************************************/
/**
* @LC     16/10/2019
* @file   RRenderManager.h
* @Author Oswaldo Perez Macias
* @date   16/10/2019
* @brief  RRenderManager.h class definition
* @bug	  No known bugs.
*/
/********************************************************************/
#pragma once
#include"RBuffer.h"
#include"RModule.h"
/**
	*forward declaration
*/


struct RManagerData
{
	RPoint WPos;
	RRect  WLen;
};

class RRenderManager :
	public RModule< RRenderManager>
{
	RRenderManager();
	~RRenderManager();
#ifdef DX
	ID3D11Device* m_Device = NULL;
#endif // DX

public:
	int static CreateBuffer(RBuffer& buffer);

	/*HRESULT CreateDeviceAndSwapChain();

	HRESULT CreateRenderTargetView();

	HRESULT CreateTexture2D();

	HRESULT CreateDepthStencilView();

	HRESULT CreateVertexShader();

	HRESULT	CreateInputLayout();

	HRESULT CreatePixelShader();

	HRESULT CreateShaderResourceViewFromFile();

	HRESULT CreateSamplerState();

	ULONG Release() { return  m_Device->Release(); }

	void destroy();*/
};

