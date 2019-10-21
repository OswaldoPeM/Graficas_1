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
#include"RModule.h"
#include"RBuffer.h"
#include"RVertexShader.h"
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
	ID3D11Device *m_Device;
	ID3D11DeviceContext *m_InterfaceDevice;
	IDXGISwapChain *m_swapChain;

	static int CompileShaderFromFile(const wchar_t* szFileName, const char* szEntryPoint, const char* szShaderModel, ID3DBlob** ppBlobOut);
	static int CreateInputLayoutDescFromVertexShaderSignature(ID3DBlob* pShaderBlob, ID3D11VertexShader** vertexshader);
#endif // DX

public:
	void* getDevice() { return m_Device; }
	void* getInterfaeDevice() { return m_InterfaceDevice; }
	void* getSwapChain() { return m_swapChain; }

	int static CreateDeviceAndSwapChain(DeviceKey &key);
	int static CreateBuffer(RBuffer& buffer);
	int static CreateVertexShader(RVertexShader& vertexShader);
	int static CreateInputLayout(RVertexShader& vertexShader);

/*
	HRESULT CreateTexture2D();

	HRESULT CreateRenderTargetView();
	HRESULT CreateDepthStencilView();



	HRESULT CreatePixelShader();

	HRESULT CreateShaderResourceViewFromFile();

	HRESULT CreateSamplerState();

	ULONG Release() { return  m_Device->Release(); }
*/

	void destroy() {
	}

	void OnShutDown()
	{
		destroy();
	}
	void OnStartUp(void* _Desc)
	{
		DeviceKey* key =(DeviceKey*)_Desc;
		Instance().CreateDeviceAndSwapChain(*key);

	}
};

