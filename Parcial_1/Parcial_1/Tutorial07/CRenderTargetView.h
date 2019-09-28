#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
class CRenderTargetView
{
	ID3D11RenderTargetView* ptr_RenderTargetView;
public:

	ID3D11RenderTargetView** getRenderTargetView();

	bool Init();
	void render();
	void update();
	void destroy();

	CRenderTargetView();
	~CRenderTargetView();
};

