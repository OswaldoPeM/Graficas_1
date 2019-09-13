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
	ID3D11DeviceContext* g_pImmediateContext = NULL;

public:
	virtual void* GetDevice() = 0;
	virtual HRESULT init(
		HWND					 &g_hWnd,
		D3D_DRIVER_TYPE			 &g_driverType,
		IDXGISwapChain			*&g_pSwapChain,
		D3D_FEATURE_LEVEL		 &g_featureLevel,
		ID3D11RenderTargetView	*&g_pRenderTargetView,
		ID3D11Texture2D		    *&g_pDepthStencil,
		ID3D11DepthStencilView	*&g_pDepthStencilView,
		ID3D11InputLayout		*&g_pVertexLayout,
		ID3D11VertexShader		*&g_pVertexShader,
		ID3D11PixelShader		*&g_pPixelShader,
		ID3D11Buffer			*&g_pVertexBuffer,
		ID3D11Buffer			*&g_pIndexBuffer,
		ID3D11Buffer			*&g_pCBNeverChanges,
		ID3D11Buffer			*&g_pCBChangeOnResize,
		ID3D11Buffer			*&g_pCBChangesEveryFrame,
		ID3D11ShaderResourceView*&g_pTextureRV,
		ID3D11SamplerState		*&g_pSamplerLinear,
		XMMATRIX				 &g_World,
		XMMATRIX				 &g_View,
		XMMATRIX				 &g_Projection
	) = 0;
	CDevice();
	~CDevice();
};

