#include "RSwapchain.h"


IDXGISwapChain ** RSwapchain::getSwapChain()
{
	return &m_pSwapChain;
}

DXGI_SWAP_CHAIN_DESC * RSwapchain::getSwapChainDesc()
{
	return &sd;
}

HRESULT RSwapchain::GetBuffer(
	UINT Buffer,
	REFIID riid,
	void ** ppSurface)
{

	return m_pSwapChain->GetBuffer(Buffer, riid, ppSurface);
}

HRESULT RSwapchain::Present(
	UINT SyncInterval,
	UINT Flags)
{
	return m_pSwapChain->Present(SyncInterval, Flags);
}

HRESULT RSwapchain::ResizeBuffer(
	UINT BufferCount,
	UINT Width,
	UINT Height,
	DXGI_FORMAT NewFormat,
	UINT SwapChainFlags)
{
	return m_pSwapChain->ResizeBuffers(BufferCount, Width, Height, NewFormat, SwapChainFlags);
}

bool RSwapchain::init(UINT WIDTH, UINT HEIGHT, HWND hWnd)
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
RSwapchain::RSwapchain()
{
}


RSwapchain::~RSwapchain()
{
}
