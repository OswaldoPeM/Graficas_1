#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

class CSwapChain
{
	IDXGISwapChain* g_pSwapChain;
	DXGI_SWAP_CHAIN_DESC sd;
public:
	
	IDXGISwapChain** getSwapChain();
	DXGI_SWAP_CHAIN_DESC* getSwapChainDesc();


	HRESULT  GetBuffer(
		UINT Buffer,
		__in  REFIID riid,
		__out  void **ppSurface);

	HRESULT  Present(
		UINT SyncInterval,
		UINT Flags);


	bool init(UINT WIDTH,UINT HEIGHT, HWND hWnd);
	void render();
	void update();
	void destroy();


	CSwapChain();
	~CSwapChain();
};

