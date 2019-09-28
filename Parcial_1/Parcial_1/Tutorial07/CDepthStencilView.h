#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

class CDepthStencilView
{
	ID3D11Texture2D*		DepthStencil = NULL;
	ID3D11DepthStencilView* DepthStencilView = NULL;

	D3D11_TEXTURE2D_DESC descDepth;
	D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
public:
	ID3D11Texture2D**			getDepthStencil();
	ID3D11DepthStencilView**	getDepthStencilView();
	D3D11_TEXTURE2D_DESC*		getDescDepth();
	D3D11_DEPTH_STENCIL_VIEW_DESC* getDescDepthStencilView();

	bool init(UINT WIDTH, UINT HEIGHT);
	void render();
	void update();
	void destroy();

	CDepthStencilView();
	~CDepthStencilView();
};

