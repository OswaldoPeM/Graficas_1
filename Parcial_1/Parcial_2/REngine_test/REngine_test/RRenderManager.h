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
#include"requerimientos.h"
/**
	*forward declaration
*/
class RDepthStencilView;
class RRenderTargetView;
class RDeviceInterface;
class RProgramShader;
class RSamplerState;
class RSwapchain;
class RTexture;
class RDevice;
class RBuffer;
class RActor;


struct RManagerData
{
	RPoint WPos;
	RRect  WLen;
};

class RRenderManager 
	:public RModule<RRenderManager>
{
	RDevice* Device;
	RDeviceInterface* InterfaceDeivice;
	RSwapchain * SwapChain;
public:
	virtual ~RRenderManager();
	RRenderManager();
	virtual int 
		CreateDeviceAndSwapChain
		(
			RenderManagerDesc& desc
		);
	virtual int
		CreateBuffer
		(
			RBuffer& buffer
		);

	virtual int
		CreateVertexShader
		(
			RProgramShader& programShader
		);

	virtual int
		CreateInputLayout
		(
			RProgramShader& programShader
		);

	virtual int
		CreatePixelShader
		(
			RProgramShader& programShader
		);

	virtual int
		CreateTexture2D
		(
			RDepthStencilView& Texture
		);

	virtual int
		CreateRenderTargetView
		(
			RRenderTargetView& renderTargetView
		);

	virtual int
		CreateDepthStencilView
		(
			RDepthStencilView& depthStencilView
		);

	virtual int
		CreateSamplerState
		(
			RSamplerState& samplerState
		);

	virtual void
		OMSetRenderTargets
		(
			unsigned int NumViews,
			RRenderTargetView *ppRenderTargetViews,
			RDepthStencilView *pDepthStencilView
		);

	virtual void
		RSSetViewports
		(
			unsigned int NumViewports,
			RViewport *pViewports
		);

	virtual void
		IASetInputLayout
		(
			RInputLayout *pInputLayout
		);

	virtual void
		IASetVertexBuffers
		(
			unsigned int StartSlot,
			unsigned int NumBuffers,
			RBuffer *ppVertexBuffers,
			const unsigned int *pStrides,
			const unsigned int *pOffsets
		);

	virtual void
		IASetIndexBuffer
		(
			RBuffer *pIndexBuffer,
			FORMAT Format,
			unsigned int Offset
		);

	virtual void
		IASetPrimitiveTopology
		(
			PRIMITIVE_TOPOLOGY Topology
		);

	virtual void
		UpdateSubresource
		(
			RBuffer *pDstResource,
			unsigned int DstSubresource,
			RBOX *pDstBox,
			void *pSrcData,
			unsigned int SrcRowPitch,
			unsigned int SrcDepthPitch
		);

	virtual void
		ClearRenderTargetView
		(
			RRenderTargetView *pRenderTargetView,
			float ColorRGBA[4]
		);

	virtual void
		ClearDepthStencilView
		(
			RDepthStencilView *pDepthStencilView,
			unsigned int ClearFlags,
			float Depth,
			unsigned char Stencil
		);

	virtual void
		VSSetShader
		(
			RVertexShader *pVertexShader
		);

	virtual void VSSetConstantBuffers
	(
		unsigned int StartSlot,
		unsigned int NumBuffers,
		RBuffer  *ppConstantBuffers
	);

	virtual void
		PSSetShader
		(
			RPixelShader *pPixelShader
		);

	virtual void
		PSSetConstantBuffers
		(
			unsigned int StartSlot,
			unsigned int NumBuffer,
			RBuffer *ppConstantBuffers
		);

	virtual void
		PSSetShaderResources
		(
			unsigned int StartSlot,
			unsigned int NumViews,
			RShaderResourceView* ppShaderResourceViews
		);

	virtual void
		PSSetSamplers
		(
			unsigned int StartSlot,
			unsigned int NumSamplers,
			RSamplerState *ppSamplers
		);

	virtual void
		DrawIndexed
		(
			unsigned int IndexCount,
			unsigned int StartIndexLocation,
			int BaseVertexLocation
		);
	virtual unsigned int Present(SwChPr& param);
	virtual unsigned int ResizeBuffer(ReSzSCH& param);

	void update();
	void render();
	void destroy();

	unsigned int OnShutDown()
	{
		destroy();
		return 0;
	}
	unsigned int OnStartUp(void* _Desc)
	{
		RenderManagerDesc* key = reinterpret_cast<RenderManagerDesc*>(_Desc);
		//Instance().CreateDeviceAndSwapChain(*key);
		return 0;
	}
};

