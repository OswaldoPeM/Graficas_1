#pragma once
#include"requerimientos.h"

class RShaderResourceView;
class RRenderTargetView;
class RDepthStencilView;
class RVertexShader;
class RSamplerState;
class RInputLayout;
class RPixelShader;
class RViewport;
class RBuffer;

class RDeviceInterface
{
public:

	virtual void
		OMSetRenderTargets
		(
			unsigned int NumViews,
			RRenderTargetView *ppRenderTargetViews,
			RDepthStencilView *pDepthStencilView
		) = 0;

	virtual void
		RSSetViewports
		(
			unsigned int NumViewports,
			RViewport *pViewports
		) = 0;

	virtual void
		IASetInputLayout
		(
			RInputLayout *pInputLayout
		) = 0;

	virtual void
		IASetVertexBuffers
		(
			unsigned int StartSlot,
			unsigned int NumBuffers,
			RBuffer *ppVertexBuffers,
			const unsigned int *pStrides,
			const unsigned int *pOffsets
		) = 0;

	virtual void
		IASetIndexBuffer
		(
			RBuffer *pIndexBuffer,
			FORMAT Format,
			unsigned int Offset
		) = 0;

	virtual void
		IASetPrimitiveTopology
		(
			PRIMITIVE_TOPOLOGY Topology
		) = 0;

	virtual void
		UpdateSubresource
		(
			RBuffer *pDstResource,
			unsigned int DstSubresource,
			RBOX *pDstBox,
			void *pSrcData,
			unsigned int SrcRowPitch,
			unsigned int SrcDepthPitch
		) = 0;

	virtual void
		ClearRenderTargetView
		(
			RRenderTargetView *pRenderTargetView,
			float ColorRGBA[4]
		) = 0;

	virtual void
		ClearDepthStencilView
		(
			RDepthStencilView *pDepthStencilView,
			unsigned int ClearFlags,
			float Depth,
			unsigned char Stencil
		) = 0;

	virtual void
		VSSetShader
		(
			RVertexShader *pVertexShader
		) = 0;

	virtual void VSSetConstantBuffers
	(
		unsigned int StartSlot,
		unsigned int NumBuffers,
		RBuffer  *ppConstantBuffers
	) = 0;

	virtual void
		PSSetShader
		(
			RPixelShader *pPixelShader
		) = 0;

	virtual void
		PSSetConstantBuffers
		(
			unsigned int StartSlot,
			unsigned int NumBuffer,
			RBuffer *ppConstantBuffers
		) = 0;

	virtual void
		PSSetShaderResources
		(
			unsigned int StartSlot,
			unsigned int NumViews,
			RShaderResourceView* ppShaderResourceViews
		) = 0;

	virtual void
		PSSetSamplers
		(
			unsigned int StartSlot,
			unsigned int NumSamplers,
			RSamplerState *ppSamplers
		) = 0;

	virtual void
		DrawIndexed
		(
			unsigned int IndexCount,
			unsigned int StartIndexLocation,
			int BaseVertexLocation
		) = 0;

	RDeviceInterface();
	~RDeviceInterface();
};

