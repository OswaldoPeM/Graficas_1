#pragma once
#include <d3d11.h>
#include <d3dx11.h>
class CInterfaceDevice
{
	ID3D11DeviceContext *g_pImmediateContext = NULL;
public:
	ID3D11DeviceContext **getInterface();

	void OMSetRenderTargets(
		__in_range(0, D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT)  UINT NumViews,
		__in_ecount_opt(NumViews)  ID3D11RenderTargetView *const *ppRenderTargetViews,
		__in_opt  ID3D11DepthStencilView *pDepthStencilView);

	void RSSetViewports(
		__in_range(0, D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE)  UINT NumViewports,
		__in_ecount_opt(NumViewports)  const D3D11_VIEWPORT *pViewports);

	void IASetInputLayout(
		__in_opt  ID3D11InputLayout *pInputLayout);

	void IASetVertexBuffers(
		__in_range(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
		__in_range(0, D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumBuffers,
		__in_ecount(NumBuffers)  ID3D11Buffer *const *ppVertexBuffers,
		__in_ecount(NumBuffers)  const UINT *pStrides,
		__in_ecount(NumBuffers)  const UINT *pOffsets);

	void IASetIndexBuffer(
		__in_opt  ID3D11Buffer *pIndexBuffer,
		__in  DXGI_FORMAT Format,
		__in  UINT Offset);

	void IASetPrimitiveTopology(
		__in  D3D11_PRIMITIVE_TOPOLOGY Topology);

	void UpdateSubresource(
		__in  ID3D11Resource *pDstResource,
		__in  UINT DstSubresource,
		__in_opt  const D3D11_BOX *pDstBox,
		__in  const void *pSrcData,
		__in  UINT SrcRowPitch,
		__in  UINT SrcDepthPitch);

	void ClearRenderTargetView(
		__in  ID3D11RenderTargetView *pRenderTargetView,
		__in  const FLOAT ColorRGBA[4]);

	void ClearDepthStencilView(
		__in  ID3D11DepthStencilView *pDepthStencilView,
		__in  UINT ClearFlags,
		__in  FLOAT Depth,
		__in  UINT8 Stencil);

	void VSSetShader(
		__in_opt  ID3D11VertexShader *pVertexShader,
		__in_ecount_opt(NumClassInstances)  ID3D11ClassInstance *const *ppClassInstances,
		UINT NumClassInstances);

	void VSSetConstantBuffers(
		__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
		__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffers,
		__in_ecount(NumBuffers)  ID3D11Buffer *const *ppConstantBuffers);

	void  PSSetShader(
		__in_opt  ID3D11PixelShader *pPixelShader,
		__in_ecount_opt(NumClassInstances)  ID3D11ClassInstance *const *ppClassInstances,
		UINT NumClassInstances);

	void  PSSetConstantBuffers(
		__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - 1)  UINT StartSlot,
		__in_range(0, D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT - StartSlot)  UINT NumBuffer,
		__in_ecount(NumBuffers)  ID3D11Buffer *const *ppConstantBuffers);

	void  PSSetShaderResources(
		__in_range(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - 1)  UINT StartSlot,
		__in_range(0, D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT - StartSlot)  UINT NumViews,
		__in_ecount(NumViews)  ID3D11ShaderResourceView *const *ppShaderResourceViews);

	void  PSSetSamplers(
		__in_range(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - 1)  UINT StartSlot,
		__in_range(0, D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT - StartSlot)  UINT NumSamplers,
		__in_ecount(NumSamplers)  ID3D11SamplerState *const *ppSamplers);

	void DrawIndexed(
		__in  UINT IndexCount,
		__in  UINT StartIndexLocation,
		__in  INT BaseVertexLocation);

	void ClearState(){ if (g_pImmediateContext) g_pImmediateContext->ClearState(); }
	void Release() { if (g_pImmediateContext) g_pImmediateContext->Release(); }

	void destroy();
	

	CInterfaceDevice();
	~CInterfaceDevice();
};

