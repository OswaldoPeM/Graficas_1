#include "CInterfaceDevice.h"



ID3D11DeviceContext ** CInterfaceDevice::getInterface()
{
	return &g_pImmediateContext;
}

void CInterfaceDevice::OMSetRenderTargets(
	__in_range(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)UINT NumViews,
	ID3D11RenderTargetView * const * ppRenderTargetViews,
	ID3D11DepthStencilView * pDepthStencilView)
{
	g_pImmediateContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
}

void CInterfaceDevice::RSSetViewports(
	__in_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)UINT NumViewports,
	const D3D11_VIEWPORT * pViewports)
{
	g_pImmediateContext->RSSetViewports(NumViewports, pViewports);
}

void CInterfaceDevice::IASetInputLayout(
	ID3D11InputLayout * pInputLayout)
{
	g_pImmediateContext->IASetInputLayout(pInputLayout);
}

void CInterfaceDevice::IASetVertexBuffers(
	__in_range(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)UINT StartSlot,
	__in_range(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)UINT NumBuffers,
	ID3D11Buffer * const * ppVertexBuffers,
	const UINT * pStrides,
	const UINT * pOffsets)
{
	g_pImmediateContext->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void CInterfaceDevice::IASetIndexBuffer(
	ID3D11Buffer * pIndexBuffer, 
	DXGI_FORMAT Format,
	UINT Offset)
{
	g_pImmediateContext->IASetIndexBuffer(pIndexBuffer, Format, Offset);
}

void CInterfaceDevice::IASetPrimitiveTopology(
	D3D11_PRIMITIVE_TOPOLOGY Topology)
{
	g_pImmediateContext->IASetPrimitiveTopology(Topology);
}

void CInterfaceDevice::UpdateSubresource(
	ID3D11Resource * pDstResource,
	UINT DstSubresource,
	const D3D11_BOX * pDstBox,
	const void * pSrcData,
	UINT SrcRowPitch, 
	UINT SrcDepthPitch)
{
	g_pImmediateContext->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}

void CInterfaceDevice::ClearRenderTargetView(
	ID3D11RenderTargetView * pRenderTargetView,
	const FLOAT ColorRGBA[4])
{
	g_pImmediateContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
}

void CInterfaceDevice::ClearDepthStencilView(
	ID3D11DepthStencilView * pDepthStencilView,
	UINT ClearFlags,
	FLOAT Depth,
	UINT8 Stencil)
{
	g_pImmediateContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
}

void CInterfaceDevice::VSSetShader(
	ID3D11VertexShader * pVertexShader, 
	ID3D11ClassInstance * const * ppClassInstances, 
	UINT NumClassInstances)
{
	g_pImmediateContext->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
}

void CInterfaceDevice::VSSetConstantBuffers(
	__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)UINT StartSlot,
	__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)UINT NumBuffers,
	ID3D11Buffer * const * ppConstantBuffers)
{
	g_pImmediateContext->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void CInterfaceDevice::PSSetShader(ID3D11PixelShader * pPixelShader, ID3D11ClassInstance * const * ppClassInstances, UINT NumClassInstances)
{
	g_pImmediateContext->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
}

void CInterfaceDevice::PSSetConstantBuffers(
	__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)UINT StartSlot,
	__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)UINT NumBuffer,
	ID3D11Buffer * const * ppConstantBuffers)
{
	g_pImmediateContext->PSSetConstantBuffers(StartSlot, NumBuffer, ppConstantBuffers);
}

void CInterfaceDevice::PSSetShaderResources(
	__in_range(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)UINT StartSlot,
	__in_range(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)UINT NumViews, 
	ID3D11ShaderResourceView * const * ppShaderResourceViews)
{
	g_pImmediateContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void CInterfaceDevice::PSSetSamplers(
	__in_range(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)UINT StartSlot,
	__in_range(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)UINT NumSamplers,
	ID3D11SamplerState * const * ppSamplers)
{
	g_pImmediateContext->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void CInterfaceDevice::DrawIndexed(
	UINT IndexCount,
	UINT StartIndexLocation,
	INT BaseVertexLocation)
{
	g_pImmediateContext->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
}

CInterfaceDevice::CInterfaceDevice()
{
}



CInterfaceDevice::~CInterfaceDevice()
{
}
