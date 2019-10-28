#pragma once
#include "RDeviceInterface.h"

class ID3D11DeviceContext;

class RDeviceInterfaceDX :
	public RDeviceInterface
{
	ID3D11DeviceContext *InterfaceDevice;
public:
	void* getInterfaceDevice();

	virtual void
		OMSetRenderTargets
		(
			unsigned int NumViews,
			RRenderTargetView *ppRenderTargetViews,
			RDepthStencilView *pDepthStencilView
		) override;

	virtual void
		RSSetViewports
		(
			unsigned int NumViewports,
			RViewport *pViewports
		) override;

	virtual void
		IASetInputLayout
		(
			RInputLayout *pInputLayout
		) override;

	virtual void
		IASetVertexBuffers
		(
			unsigned int StartSlot,
			unsigned int NumBuffers,
			RBuffer *ppVertexBuffers,
			const unsigned int *pStrides,
			const unsigned int *pOffsets
		) override;

	virtual void
		IASetIndexBuffer
		(
			RBuffer *pIndexBuffer,
			FORMAT Format,
			unsigned int Offset
		) override;

	virtual void
		IASetPrimitiveTopology
		(
			PRIMITIVE_TOPOLOGY Topology
		) override;

	virtual void
		UpdateSubresource
		(
			RBuffer *pDstResource,
			unsigned int DstSubresource,
			RBOX *pDstBox,
			void *pSrcData,
			unsigned int SrcRowPitch,
			unsigned int SrcDepthPitch
		) override;

	virtual void
		ClearRenderTargetView
		(
			RRenderTargetView *pRenderTargetView,
			float ColorRGBA[4]
		) override;

	virtual void
		ClearDepthStencilView
		(
			RDepthStencilView *pDepthStencilView,
			unsigned int ClearFlags,
			float Depth,
			unsigned char Stencil
		) override;

	virtual void
		VSSetShader
		(
			RVertexShader *pVertexShader
		) override;

	virtual void VSSetConstantBuffers
	(
		unsigned int StartSlot,
		unsigned int NumBuffers,
		RBuffer *ppConstantBuffers
	) override;

	virtual void
		PSSetShader
		(
			RPixelShader *pPixelShader
		) override;

	virtual void
		PSSetConstantBuffers
		(
			unsigned int StartSlot,
			unsigned int NumBuffer,
			RBuffer *ppConstantBuffers
		) override;

	virtual void
		PSSetShaderResources
		(
			unsigned int StartSlot,
			unsigned int NumViews,
			RShaderResourceView* ppShaderResourceViews
		) override;

	virtual void
		PSSetSamplers
		(
			unsigned int StartSlot,
			unsigned int NumSamplers,
			RSamplerState *ppSamplers
		) override;

	virtual void
		DrawIndexed
		(
			unsigned int IndexCount,
			unsigned int StartIndexLocation,
			int BaseVertexLocation
		) override;
	RDeviceInterfaceDX();
	~RDeviceInterfaceDX();
};

