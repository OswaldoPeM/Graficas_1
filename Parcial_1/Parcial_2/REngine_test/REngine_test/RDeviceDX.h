#pragma once
#include "RDevice.h"
class ID3D11Device;

class RDeviceDX :
	public RDevice
{
	ID3D11Device * m_pDevice;
public:
	virtual void* getDevice()override;

	virtual int
		CreateBuffer
		(
			RBuffer& buffer
		) override;

	virtual int
		CreateVertexShader
		(
			RProgramShader& programShader
		) override;

	virtual int
		CreateInputLayout
		(
			RProgramShader& programShader
		) override;

	virtual int
		CreatePixelShader
		(
			RProgramShader& programShader
		) override;

	virtual int
		CreateTexture2D
		(
			RDepthStencilView& Texture
		) override;

	virtual int
		CreateRenderTargetView
		(
			RRenderTargetView& renderTargetView,
			void* backbuffer
		) override;

	virtual int
		CreateDepthStencilView
		(
			RDepthStencilView& depthStencilView
		) override;

	virtual int
		CreateSamplerState
		(
			RSamplerState& samplerState
		) override;
	RDeviceDX();
	virtual ~RDeviceDX();
};

