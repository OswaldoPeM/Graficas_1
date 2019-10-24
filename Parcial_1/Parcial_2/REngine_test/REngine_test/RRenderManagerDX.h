#pragma once
#include "RRenderManager.h"
#include"RDevice.h"
class RRenderManagerDX :
	public RRenderManager
{
	RDevice *m_Device;
	ID3D11DeviceContext *m_InterfaceDevice;
	IDXGISwapChain *m_swapChain;
public:
	void* getDevice() { return m_Device; }
	void* getInterfaeDevice() { return m_InterfaceDevice; }
	void* getSwapChain() { return m_swapChain; }

	int
		CreateDeviceAndSwapChain
		(
			DeviceKey &key
		);
	
	virtual int
		CreateBuffer
		(
			RBuffer& buffer,
			void * device
		) override;

	virtual int
		CreateVertexShader
		(
			RProgramShader& programShadre,
			void * _p_device
		) override;

	virtual int
		CreateInputLayout
		(
			RProgramShader& programShadre,
			void * _p_device
		) override;

	virtual int
		CreatePixelShader
		(
			RProgramShader& programShadre,
			void * _p_device
		) override;

	 virtual ~RRenderManagerDX();
	 RRenderManagerDX();
};

