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
#include"RProgramShader.h"
/**
	*forward declaration
*/


struct DeviceKey {
	void* pAdapter = nullptr;
	DRIVER_TYPE DriverType;
	void* Software = nullptr;
	unsigned int Flags;
	const FEATURE_LEVEL *pFeatureLevels;
	unsigned int FeatureLevels;
	unsigned int SDKVersion = 7;// = D3D11_SDK_VERSION;
	SWAP_CHAIN_DESC * pSwapChainDesc;
	//void* pSwapChainDesc = nullptr;
	//void ** ppSwapChain;
	FEATURE_LEVEL * pFeatureLevel;
	//void ** ppImmediateContext;
};


struct RManagerData
{
	RPoint WPos;
	RRect  WLen;
};

class RRenderManager 
	:public RModule<RRenderManager>
{
#ifdef DX
	ID3D11DeviceContext *m_InterfaceDevice;
	IDXGISwapChain *m_swapChain;
#endif // DX

public:
	virtual ~RRenderManager();
	RRenderManager();

	virtual void* getDevice() = 0;
	virtual void* getInterfaeDevice() = 0;
	virtual void* getSwapChain() = 0;

	virtual int  
		CreateBuffer
		(
			RBuffer& buffer,
			void * device
		);
	virtual int 
		CreateVertexShader
		(
			RProgramShader& programShadre,
			void * _p_device
		);
	virtual int 
		CreateInputLayout
		(
			RProgramShader& programShadre,
			void * _p_device
		);
	virtual int 
		CreatePixelShader
		(
			RProgramShader& programShadre,
			void * _p_device
		);

/*
	HRESULT CreateTexture2D();

	HRESULT CreateRenderTargetView();
	HRESULT CreateDepthStencilView();




	HRESULT CreateShaderResourceViewFromFile();

	HRESULT CreateSamplerState();

	ULONG Release() { return  m_Device->Release(); }
*/

	void destroy() {
	}

	unsigned int OnShutDown()
	{
		destroy();
		return 0;
	}
	unsigned int OnStartUp(void* _Desc)
	{
		DeviceKey* key = (DeviceKey*)_Desc;
		//Instance().CreateDeviceAndSwapChain(*key);
		return 0;
	}
};

