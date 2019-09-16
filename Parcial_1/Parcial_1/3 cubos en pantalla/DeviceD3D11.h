#pragma once
#include "CDevice.h"

class DeviceD3D11 :
	public CDevice
{
	D3D_DRIVER_TYPE                     g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL                   g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*                       g_pd3dDevice = NULL;
	ID3D11DeviceContext*                g_pImmediateContext = NULL;
	IDXGISwapChain*                     g_pSwapChain = NULL;
	ID3D11RenderTargetView*             g_pRenderTargetView = NULL;
	ID3D11Texture2D*                    g_pDepthStencil = NULL;
	ID3D11DepthStencilView*             g_pDepthStencilView = NULL;
	ID3D11VertexShader*                 g_pVertexShader = NULL;
	ID3D11PixelShader*                  g_pPixelShader = NULL;
	ID3D11InputLayout*                  g_pVertexLayout = NULL;
	ID3D11Buffer*                       g_pVertexBuffer = NULL;
	ID3D11Buffer*                       g_pIndexBuffer = NULL;
	ID3D11Buffer*                       g_pCBNeverChanges = NULL;
	ID3D11Buffer*                       g_pCBChangeOnResize = NULL;
	ID3D11Buffer*                       g_pCBChangesEveryFrame = NULL;
	ID3D11ShaderResourceView*           g_pTextureRV = NULL;
	ID3D11SamplerState*                 g_pSamplerLinear = NULL;

public:
	void *GetDevice();
	HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	HRESULT init(
		HWND					 &g_hWnd,
		XMMATRIX				 &g_World,
		XMMATRIX				 &g_View,
		XMMATRIX				 &g_Projection
	);

	DeviceD3D11();
	~DeviceD3D11();
};

