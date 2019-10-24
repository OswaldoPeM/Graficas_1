#pragma once

#include "CDevice.h"

class CDeviceDX11:
	public CDevice
{
public :
	unsigned int CreateDeviceAndSwapChain(
		IDXGIAdapter* pAdapter,
		D3D_DRIVER_TYPE DriverType,
		HMODULE Software,
		UINT Flags,
		CONST D3D_FEATURE_LEVEL* pFeatureLevels,
		UINT FeatureLevels,
		UINT SDKVersion,
		DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
		IDXGISwapChain** ppSwapChain,
		D3D_FEATURE_LEVEL* pFeatureLevel,
		ID3D11DeviceContext** ppImmediateContext);

	unsigned int 
		CreateRenderTargetView(
		ID3D11Texture2D *&pResource,
		const D3D11_RENDER_TARGET_VIEW_DESC *pDesc,
		ID3D11RenderTargetView **ppRTView);

	unsigned int
		CreateTexture2D(
		const D3D11_TEXTURE2D_DESC *pDesc,
		const D3D11_SUBRESOURCE_DATA *pInitialData,
		ID3D11Texture2D **ppTexture2D);

	unsigned int
		CreateDepthStencilView(
		ID3D11Resource *pResource,
		const D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc,
		ID3D11DepthStencilView **ppDepthStencilView);

	unsigned int
		CreateVertexShader(
		const void *pShaderBytecode,
		SIZE_T BytecodeLength,
		ID3D11ClassLinkage *pClassLinkage,
		ID3D11VertexShader **ppVertexShader);

	unsigned int
		CreateInputLayout(
		const D3D11_INPUT_ELEMENT_DESC *pInputElementDescs,
		UINT NumElements,
		const void *pShaderBytecodeWithInputSignature,
		SIZE_T BytecodeLength,
		ID3D11InputLayout **ppInputLayout);

	unsigned int
		CreatePixelShader(
		const void *pShaderBytecode,
		SIZE_T BytecodeLength,
		ID3D11ClassLinkage *pClassLinkage,
	    ID3D11PixelShader **ppPixelShader);

	unsigned int
		CreateBuffer(
		const D3D11_BUFFER_DESC *pDesc,
		const D3D11_SUBRESOURCE_DATA *pInitialData,
		ID3D11Buffer **ppBuffer);

	unsigned int
		CreateShaderResourceViewFromFile(
		LPCWSTR                      pSrcFile,
		D3DX11_IMAGE_LOAD_INFO      *pLoadInfo,
		ID3DX11ThreadPump*          pPump,
		ID3D11ShaderResourceView**            ppTexture,
		unsigned int*                    pHresult);

	unsigned int
		CreateSamplerState(
		const D3D11_SAMPLER_DESC *pSamplerDesc,
		ID3D11SamplerState **ppSamplerState);

};