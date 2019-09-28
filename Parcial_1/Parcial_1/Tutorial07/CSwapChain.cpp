#include "CSwapChain.h"



IDXGISwapChain ** CSwapChain::getSwapChain()
{
	return &g_pSwapChain;
}

DXGI_SWAP_CHAIN_DESC * CSwapChain::getSwapChainDesc()
{
	return &sd;
}

HRESULT CSwapChain::GetBuffer(
	UINT Buffer,
	REFIID riid,
	void ** ppSurface)
{

	return g_pSwapChain->GetBuffer(Buffer, riid, ppSurface);
}

HRESULT CSwapChain::Present(
	UINT SyncInterval,
	UINT Flags)
{
	return g_pSwapChain->Present(SyncInterval, Flags);
}

bool CSwapChain::init(UINT WIDTH, UINT HEIGHT, HWND hWnd)
{

	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = WIDTH;
	sd.BufferDesc.Height = HEIGHT;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	return false;
}

void CSwapChain::render()
{
}

void CSwapChain::update()
{
}

void CSwapChain::destroy()
{
	if(g_pSwapChain) g_pSwapChain->Release();
	delete this;
}

CSwapChain::CSwapChain()
{
}


CSwapChain::~CSwapChain()
{
}
