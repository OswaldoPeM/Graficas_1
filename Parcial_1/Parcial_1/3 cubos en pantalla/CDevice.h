#pragma once
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>

struct SimpleVertex
{
	XMFLOAT3 Pos;
	XMFLOAT2 Tex;
};
struct CBNeverChanges
{
	XMMATRIX mView;
};
struct CBChangeOnResize
{
	XMMATRIX mProjection;
};

struct CBChangesEveryFrame
{
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};

class CDevice
{
protected:
	ID3D11Device* g_pd3dDevice = NULL;
public:

	ID3D11Device* getDevice() { return g_pd3dDevice; }

	HRESULT CreateDeviceAndSwapChain(
		__in_opt IDXGIAdapter* pAdapter,
		D3D_DRIVER_TYPE DriverType,
		HMODULE Software,
		UINT Flags,
		__in_ecount_opt(FeatureLevels) CONST D3D_FEATURE_LEVEL* pFeatureLevels,
		UINT FeatureLevels,
		UINT SDKVersion,
		__in_opt CONST DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
		__out_opt IDXGISwapChain** ppSwapChain,
		__out_opt D3D_FEATURE_LEVEL* pFeatureLevel,
		__out_opt ID3D11DeviceContext** ppImmediateContext);

	HRESULT CreateRenderTargetView(
		ID3D11Texture2D *&pResource,
		__in_opt  const D3D11_RENDER_TARGET_VIEW_DESC *pDesc,
		__out_opt  ID3D11RenderTargetView **ppRTView);

	HRESULT CreateTexture2D(
		__in  const D3D11_TEXTURE2D_DESC *pDesc,
		__in_xcount_opt(pDesc->MipLevels * pDesc->ArraySize)  const D3D11_SUBRESOURCE_DATA *pInitialData,
		__out_opt  ID3D11Texture2D **ppTexture2D);

	HRESULT CreateDepthStencilView(
		__in  ID3D11Resource *pResource,
		__in_opt  const D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc,
		__out_opt  ID3D11DepthStencilView **ppDepthStencilView);

	HRESULT CreateVertexShader(
		__in  const void *pShaderBytecode,
		__in  SIZE_T BytecodeLength,
		__in_opt  ID3D11ClassLinkage *pClassLinkage,
		__out_opt  ID3D11VertexShader **ppVertexShader);

	HRESULT	CreateInputLayout(
		__in_ecount(NumElements)  const D3D11_INPUT_ELEMENT_DESC *pInputElementDescs,
		__in_range(0, D3D11_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT)  UINT NumElements,
		__in  const void *pShaderBytecodeWithInputSignature,
		__in  SIZE_T BytecodeLength,
		__out_opt  ID3D11InputLayout **ppInputLayout);

	HRESULT CreatePixelShader(
		__in  const void *pShaderBytecode,
		__in  SIZE_T BytecodeLength,
		__in_opt  ID3D11ClassLinkage *pClassLinkage,
		__out_opt  ID3D11PixelShader **ppPixelShader);

	HRESULT CreateBuffer(
		__in  const D3D11_BUFFER_DESC *pDesc,
		__in_opt  const D3D11_SUBRESOURCE_DATA *pInitialData,
		__out_opt  ID3D11Buffer **ppBuffer);

	HRESULT CreateShaderResourceViewFromFile(
		LPCWSTR                      pSrcFile, 
		D3DX11_IMAGE_LOAD_INFO      *pLoadInfo,
		ID3DX11ThreadPump*          pPump,
		ID3D11ShaderResourceView**            ppTexture,
		HRESULT*                    pHResult);

	HRESULT CreateSamplerState(
		__in  const D3D11_SAMPLER_DESC *pSamplerDesc,
		__out_opt  ID3D11SamplerState **ppSamplerState);

	ULONG Release() { return  g_pd3dDevice->Release();}

	CDevice();
	~CDevice();
};

