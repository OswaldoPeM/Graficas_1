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
			RBuffer& buffer,
			RDevice * device
		) override;

	virtual int
		CreateVertexShader
		(
			RProgramShader& programShader,
			RDevice * _p_device
		) override;

	virtual int
		CreateInputLayout
		(
			RProgramShader& programShader,
			RDevice * _p_device
		) override;

	virtual int
		CreatePixelShader
		(
			RProgramShader& programShader,
			RDevice * _p_device
		) override;

	virtual int
		CreateTexture2D
		(
			RTexture2D& Texture,
			RDevice * _p_device
		) override;

	virtual int
		CreateRenderTargetView
		(
			RRenderTargetView& renderTargetView,
			RDevice * _p_device
		) override;

	virtual int
		CreateDepthStencilView
		(
			RDepthStencilView& depthStencilView,
			RDevice * _p_device
		) override;

	virtual int
		CreateSamplerState
		(
			RSamplerState& samplerState,
			RDevice * _p_device
		) override;
	RDeviceDX();
	~RDeviceDX();
};

