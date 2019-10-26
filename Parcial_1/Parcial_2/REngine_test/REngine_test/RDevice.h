#pragma once
#include"requerimientos.h"
//forward declaration
class RBuffer;
class RProgramShader;
class RTexture2D;
class RRenderTargetView;
class RDepthStencilView;
class RSamplerState;

class RDevice
{
public:

	virtual void* getDevice()=0;

	virtual int
		CreateBuffer
		(
			RBuffer& buffer,
			RDevice * device
		) = 0;

	virtual int
		CreateVertexShader
		(
			RProgramShader& programShader,
			RDevice * _p_device
		) = 0;

	virtual int
		CreateInputLayout
		(
			RProgramShader& programShader,
			RDevice * _p_device
		) = 0;

	virtual int
		CreatePixelShader
		(
			RProgramShader& programShader,
			RDevice * _p_device
		) = 0;

	virtual int
		CreateTexture2D
		(
			RTexture2D& Texture,
			RDevice * _p_device
		) = 0;

	virtual int
		CreateRenderTargetView
		(
			RRenderTargetView& renderTargetView,
			RDevice * _p_device
		) = 0;

	virtual int 
		CreateDepthStencilView
		(
			RDepthStencilView& depthStencilView,
			RDevice * _p_device
		) = 0;

	virtual int
		CreateSamplerState
		(
			RSamplerState& samplerState,
			RDevice * _p_device
		) = 0;

	RDevice();
	virtual ~RDevice();
};

