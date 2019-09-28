#include "CSwapChain.h"



IDXGISwapChain ** CSwapChain::getSwapChain()
{
	return &g_pSwapChain;
}

HRESULT CSwapChain::GetBuffer(
	UINT Buffer,
	REFIID riid,
	void ** ppSurface)
{

	return g_pSwapChain->GetBuffer(Buffer, riid, ppSurface);
}

HRESULT CSwapChain::Present(UINT SyncInterval, UINT Flags)
{
	return g_pSwapChain->Present(SyncInterval, Flags);
}

bool CSwapChain::Init()
{
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
