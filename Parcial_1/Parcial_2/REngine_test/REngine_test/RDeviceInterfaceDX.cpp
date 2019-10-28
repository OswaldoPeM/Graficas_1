#include "RShaderResourceViewDX.h"
#include "RRenderTargetViewDX.h"
#include "RDepthStencilViewDX.h"
#include "RDeviceInterfaceDX.h"
#include "RSamplerStateDX.h"
#include "RinputLayoutDX.h"
#include "RViewportDX.h"
#include "RBufferDX.h"

#include <d3dcompiler.h>
#include <d3dx11.h>
#include <d3d11.h>




RDeviceInterfaceDX::RDeviceInterfaceDX()
{
}


RDeviceInterfaceDX::~RDeviceInterfaceDX()
{
}

void * RDeviceInterfaceDX::getInterfaceDevice()
{
	return reinterpret_cast<void*>(InterfaceDevice);
}

void RDeviceInterfaceDX::OMSetRenderTargets
(
	unsigned int NumViews,
	RRenderTargetView * ppRenderTargetViews,
	RDepthStencilView * pDepthStencilView
)
{
	ID3D11RenderTargetView* RTV = 
		reinterpret_cast<ID3D11RenderTargetView*>
		(ppRenderTargetViews->getRenderTargetView());
	ID3D11DepthStencilView* DSV = 
		reinterpret_cast<ID3D11DepthStencilView*>
		(pDepthStencilView->getDSV());

	InterfaceDevice->OMSetRenderTargets
	(
		NumViews,
		&RTV,
		DSV
	);
}

void RDeviceInterfaceDX::RSSetViewports
(
	unsigned int NumViewports, 
	RViewport * pViewports
)
{
	D3D11_VIEWPORT* VP = 
		reinterpret_cast<D3D11_VIEWPORT*>(pViewports->getViewport());

	InterfaceDevice->RSSetViewports
	(
		NumViewports,
		VP
	);
}

void RDeviceInterfaceDX::IASetInputLayout(RInputLayout * pInputLayout)
{
	ID3D11InputLayout* ILO = 
		reinterpret_cast<ID3D11InputLayout*>(pInputLayout->getIL());

	InterfaceDevice->IASetInputLayout(ILO);
}

void RDeviceInterfaceDX::IASetVertexBuffers
(
	unsigned int StartSlot,
	unsigned int NumBuffers,
	RBuffer * ppVertexBuffers, 
	const unsigned int * pStrides,
	const unsigned int * pOffsets
)
{
	ID3D11Buffer* buf = 
		static_cast<ID3D11Buffer*>(ppVertexBuffers->getBuffer());

	InterfaceDevice->IASetVertexBuffers(
		StartSlot,
		NumBuffers,
		&buf,
		pStrides,
		pOffsets
	);
}

void RDeviceInterfaceDX::IASetIndexBuffer
(
	RBuffer * pIndexBuffer,
	FORMAT Format,
	unsigned int Offset
)
{
	ID3D11Buffer* buf = 
		reinterpret_cast<ID3D11Buffer*> (pIndexBuffer->getBuffer());
	DXGI_FORMAT form = 
		static_cast<DXGI_FORMAT> (Format);

	InterfaceDevice->IASetIndexBuffer(buf, form,Offset);
}

void RDeviceInterfaceDX::IASetPrimitiveTopology(PRIMITIVE_TOPOLOGY Topology)
{
	D3D10_PRIMITIVE_TOPOLOGY topo =
		static_cast<D3D10_PRIMITIVE_TOPOLOGY>(Topology);

	InterfaceDevice->IASetPrimitiveTopology(topo);
}

void RDeviceInterfaceDX::UpdateSubresource
(
	RBuffer * pDstResource,
	unsigned int DstSubresource,
	RBOX * pDstBox, 
	void * pSrcData,
	unsigned int SrcRowPitch,
	unsigned int SrcDepthPitch)
{
	ID3D11Buffer* buf = static_cast<ID3D11Buffer*>(pDstResource->getBuffer());
	D3D11_BOX* box = NULL;

	InterfaceDevice->UpdateSubresource
	(
		buf,
		DstSubresource,
		box,
		pSrcData,
		SrcRowPitch,
		SrcDepthPitch
	);
}

void RDeviceInterfaceDX::ClearRenderTargetView
(
	RRenderTargetView * pRenderTargetView,
	float ColorRGBA[4]
)
{
	ID3D11RenderTargetView* RTV =
		static_cast<ID3D11RenderTargetView*>(pRenderTargetView->getRenderTargetView());

	InterfaceDevice->ClearRenderTargetView(RTV, ColorRGBA);
}

void RDeviceInterfaceDX::ClearDepthStencilView
(
	RDepthStencilView * pDepthStencilView,
	unsigned int ClearFlags,
	float Depth,
	unsigned char Stencil
)
{
	ID3D11DepthStencilView* DSV =
		reinterpret_cast<ID3D11DepthStencilView*>
		(pDepthStencilView->getDSV());

	InterfaceDevice->ClearDepthStencilView(DSV, ClearFlags, Depth, Stencil);
}

void RDeviceInterfaceDX::VSSetShader(RVertexShader * pVertexShader)
{
	ID3D11VertexShader *VShader = 
		reinterpret_cast<ID3D11VertexShader*>(pVertexShader);

	InterfaceDevice->VSSetShader(VShader, NULL, 0);
}

void RDeviceInterfaceDX::VSSetConstantBuffers
(
	unsigned int StartSlot,
	unsigned int NumBuffers, 
	RBuffer * ppConstantBuffers
)
{
	ID3D11Buffer* buf =
		static_cast<ID3D11Buffer*>(ppConstantBuffers->getBuffer());

	InterfaceDevice->VSSetConstantBuffers(StartSlot, NumBuffers, &buf);
}

void RDeviceInterfaceDX::PSSetShader(RPixelShader * pPixelShader)
{
	ID3D11PixelShader* PS =
		reinterpret_cast<ID3D11PixelShader*> (pPixelShader);

	InterfaceDevice->PSSetShader(PS, NULL, 0);
}

void RDeviceInterfaceDX::PSSetConstantBuffers
(
	unsigned int StartSlot,
	unsigned int NumBuffer,
	RBuffer * ppConstantBuffers
)
{
	ID3D11Buffer* buf =
		static_cast<ID3D11Buffer*>(ppConstantBuffers->getBuffer());

	InterfaceDevice->PSSetConstantBuffers(StartSlot, NumBuffer, &buf);
}

void RDeviceInterfaceDX::PSSetShaderResources
(
	unsigned int StartSlot,
	unsigned int NumViews,
	RShaderResourceView * ppShaderResourceViews
)
{
	ID3D11ShaderResourceView* SRV =
		reinterpret_cast<ID3D11ShaderResourceView*> 
		(ppShaderResourceViews->getResourceView());

	InterfaceDevice->PSSetShaderResources(StartSlot, NumViews, &SRV);
}

void RDeviceInterfaceDX::PSSetSamplers
(
	unsigned int StartSlot,
	unsigned int NumSamplers,
	RSamplerState * ppSamplers
)
{
	ID3D11SamplerState* Sampler =
		reinterpret_cast<ID3D11SamplerState*>(ppSamplers->getSamplerLinear());

	InterfaceDevice->PSSetSamplers(StartSlot, NumSamplers, &Sampler);
}

void RDeviceInterfaceDX::DrawIndexed
(
	unsigned int IndexCount,
	unsigned int StartIndexLocation,
	int BaseVertexLocation
)
{
	InterfaceDevice->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
}
