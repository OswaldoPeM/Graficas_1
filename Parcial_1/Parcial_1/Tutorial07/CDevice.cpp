#include "CDevice.h"



HRESULT CDevice::CreateDeviceAndSwapChain(IDXGIAdapter * pAdapter,
	D3D_DRIVER_TYPE DriverType, 
	HMODULE Software,
	UINT Flags, 
	const D3D_FEATURE_LEVEL * pFeatureLevels,
	UINT FeatureLevels,
	UINT SDKVersion,
	const DXGI_SWAP_CHAIN_DESC * pSwapChainDesc,
	IDXGISwapChain ** ppSwapChain,
	D3D_FEATURE_LEVEL * pFeatureLevel,
	ID3D11DeviceContext ** ppImmediateContext)
{
	return D3D11CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels,
		D3D11_SDK_VERSION, pSwapChainDesc, ppSwapChain, &g_pd3dDevice, pFeatureLevel, ppImmediateContext);;
}

HRESULT CDevice::CreateRenderTargetView(
	ID3D11Texture2D *& pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC * pDesc,
	ID3D11RenderTargetView ** ppRTView)
{
	return g_pd3dDevice->CreateRenderTargetView(pResource, pDesc, ppRTView);
}

HRESULT CDevice::CreateTexture2D(const D3D11_TEXTURE2D_DESC * pDesc,
	__in_xcount_opt(pDesc -> MipLevels * pDesc -> ArraySize) const D3D11_SUBRESOURCE_DATA * pInitialData,
	ID3D11Texture2D ** ppTexture2D)
{
	return  g_pd3dDevice->CreateTexture2D(pDesc, pInitialData, ppTexture2D);
}

HRESULT CDevice::CreateDepthStencilView(
	ID3D11Resource * pResource,
	const D3D11_DEPTH_STENCIL_VIEW_DESC * pDesc,
	ID3D11DepthStencilView ** ppDepthStencilView)
{
	return g_pd3dDevice->CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
}

HRESULT CDevice::CreateVertexShader(
	const void * pShaderBytecode, 
	SIZE_T BytecodeLength,
	ID3D11ClassLinkage * pClassLinkage
	, ID3D11VertexShader ** ppVertexShader)
{
	return g_pd3dDevice->CreateVertexShader(pShaderBytecode, BytecodeLength,
		pClassLinkage, ppVertexShader);
}

HRESULT CDevice::CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC * pInputElementDescs,
	__in_range(0, D3D11_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT)UINT NumElements, 
	const void * pShaderBytecodeWithInputSignature,
	SIZE_T BytecodeLength, 
	ID3D11InputLayout ** ppInputLayout)
{
	return g_pd3dDevice->CreateInputLayout(pInputElementDescs, NumElements,
		pShaderBytecodeWithInputSignature,
		BytecodeLength, ppInputLayout);
}

HRESULT CDevice::CreatePixelShader(
	const void * pShaderBytecode,
	SIZE_T BytecodeLength,
	ID3D11ClassLinkage * pClassLinkage,
	ID3D11PixelShader ** ppPixelShader)
{
	return g_pd3dDevice->CreatePixelShader(pShaderBytecode, BytecodeLength,
		pClassLinkage, ppPixelShader);
}

HRESULT CDevice::CreateBuffer(
	const D3D11_BUFFER_DESC * pDesc,
	const D3D11_SUBRESOURCE_DATA * pInitialData,
	ID3D11Buffer ** ppBuffer)
{
	return g_pd3dDevice->CreateBuffer(pDesc, pInitialData, ppBuffer);
}

HRESULT CDevice::CreateShaderResourceViewFromFile(
	LPCWSTR pSrcFile, 
	D3DX11_IMAGE_LOAD_INFO * pLoadInfo, 
	ID3DX11ThreadPump * pPump, 
	ID3D11ShaderResourceView ** ppTexture, 
	HRESULT * pHResult)
{
	return D3DX11CreateShaderResourceViewFromFile(g_pd3dDevice, pSrcFile, 
		pLoadInfo, pPump, ppTexture, pHResult);
}

HRESULT CDevice::CreateSamplerState(
	const D3D11_SAMPLER_DESC * pSamplerDesc,
	ID3D11SamplerState ** ppSamplerState)
{
	return  g_pd3dDevice->CreateSamplerState(pSamplerDesc, ppSamplerState);
}

CDevice::CDevice()
{
}


CDevice::~CDevice()
{
}
