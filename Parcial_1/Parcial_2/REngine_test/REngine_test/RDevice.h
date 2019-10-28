#pragma once
#include"requerimientos.h"
//forward declaration
class RBuffer;
class RProgramShader;
class RTextureDX;
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
			RBuffer& buffer
		) = 0;

	virtual int
		CreateVertexShader
		(
			RProgramShader& programShader
		) = 0;

	virtual int
		CreateInputLayout
		(
			RProgramShader& programShader
		) = 0;

	virtual int
		CreatePixelShader
		(
			RProgramShader& programShader
		) = 0;

	virtual int
		CreateTexture2D
		(
			RDepthStencilView& Texture
		) = 0;

	virtual int
		CreateRenderTargetView
		(
			RRenderTargetView& renderTargetView,
			void* backbuffer
		) = 0;

	virtual int 
		CreateDepthStencilView
		(
			RDepthStencilView& depthStencilView
		) = 0;

	virtual int
		CreateSamplerState
		(
			RSamplerState& samplerState
		) = 0;

	RDevice();
	virtual ~RDevice();
};

