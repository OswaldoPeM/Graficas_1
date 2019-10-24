#pragma once
#include "Header.h"
class RSwapchain
{
#ifdef DX


		IDXGISwapChain* m_pSwapChain;
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

	HRESULT ResizeBuffer(
		UINT BufferCount,
		UINT Width,
		UINT Height,
		DXGI_FORMAT NewFormat,
		UINT SwapChainFlags);


	bool init(UINT WIDTH, UINT HEIGHT, HWND hWnd);
#endif // DEBUG
	RSwapchain();
	~RSwapchain();
};

