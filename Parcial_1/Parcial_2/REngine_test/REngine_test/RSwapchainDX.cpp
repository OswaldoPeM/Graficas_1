#include "RSwapchainDX.h"
#include "RTextureDX.h"
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

unsigned int RSwapchainDX::GetBuffer(SwChBuf & param, void* texture)
{
	
	RTexture* bBuffer =
		reinterpret_cast<RTexture*>(texture);
	bBuffer = new RTextureDX();

	return
		m_swapChain->GetBuffer
		(
			0,
			__uuidof(ID3D11Texture2D),
			(LPVOID*)bBuffer->getTexture()
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
