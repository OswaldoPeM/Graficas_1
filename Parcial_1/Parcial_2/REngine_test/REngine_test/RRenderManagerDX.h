#pragma once
#include"RRenderManager.h"

class RDevice;
class ID3D11DeviceContext;
class IDXGISwapChain;

class RRenderManagerDX :
	public RRenderManager
{
	RDevice *m_Device;
	ID3D11DeviceContext *m_InterfaceDevice;
	IDXGISwapChain *m_swapChain;
public:
	//void* getDevice() { return m_Device; }
	//void* getInterfaeDevice() { return m_InterfaceDevice; }
	//void* getSwapChain() { return m_swapChain; }

	int
		CreateDeviceAndSwapChain
		(
			DeviceKey &key
		);
	
	virtual int
		CreateBuffer
		(
			RBuffer& buffer
		) override;

	virtual int
		CreateVertexShader
		(
			RProgramShader& programShadre
		) override;

	virtual int
		CreateInputLayout
		(
			RProgramShader& programShadre
		) override;

	virtual int
		CreatePixelShader
		(
			RProgramShader& programShadre
		) override;

	 virtual ~RRenderManagerDX();
	 RRenderManagerDX();
};

