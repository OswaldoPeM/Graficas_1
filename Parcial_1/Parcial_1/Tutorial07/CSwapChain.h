#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

class CSwapChain
{
	IDXGISwapChain* g_pSwapChain;
public:
	
	IDXGISwapChain **getSwapChain();

	HRESULT  GetBuffer(
		UINT Buffer,
		__in  REFIID riid,
		__out  void **ppSurface);

	HRESULT  Present(
		UINT SyncInterval,
		UINT Flags);

	bool Init();
	void render();
	void update();
	void destroy();


	CSwapChain();
	~CSwapChain();
};

