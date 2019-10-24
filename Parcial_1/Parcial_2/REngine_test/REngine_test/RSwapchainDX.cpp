#include "RSwapchainDX.h"
#include <d3d11.h>
#include <d3dx11.h>




RSwapchainDX::RSwapchainDX()
{
}


RSwapchainDX::~RSwapchainDX()
{
}

void * RSwapchainDX::getSwapChain()
{
	return reinterpret_cast<void*>(m_swapChain);
}

unsigned int RSwapchainDX::GetBuffer(SwChBuf & param)
{
	const IID riid
	{ 
		param.riid.Data1 ,
		param.riid.Data2 ,
		param.riid.Data3 ,
		*param.riid.Data4 
	};

	return
		m_swapChain->GetBuffer
		(
			param.Buffer,
			riid, 
			param.ppSurface
		);
}

unsigned int RSwapchainDX::Present(SwChPr & param)
{
	return
		m_swapChain->Present
		(
			param.SyncInterval,
			param.Flags
		);
}

unsigned int RSwapchainDX::ResizeBuffer(ReSzSCH & param)
{
	return
		m_swapChain->ResizeBuffers
		(
			param.BufferCount, 
			param.Width, 
			param.Height,
			static_cast<DXGI_FORMAT>(param.NewFormat),
			param.SwapChainFlags
		);
}

bool RSwapchainDX::init(SWAP_CHAIN_DESC & param)
{
	m_SwapChainDesc.clear();
	m_SwapChainDesc = param;


	return true;
}

void RSwapchainDX::render()
{
}

void RSwapchainDX::update()
{
}

void RSwapchainDX::destroy()
{
}
