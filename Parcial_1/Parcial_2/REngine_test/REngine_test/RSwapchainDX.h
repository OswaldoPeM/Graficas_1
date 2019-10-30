#pragma once
#include "RSwapchain.h"
class IDXGISwapChain;

class RSwapchainDX :
	public RSwapchain
{
	IDXGISwapChain* m_swapChain;
public:
	virtual void* getSwapChain()override;

	virtual unsigned int GetBuffer(SwChBuf& param, void* texture) override;
	virtual unsigned int Present(SwChPr& param) override;
	virtual unsigned int ResizeBuffer(ReSzSCH& param) override;

	virtual bool init(SWAP_CHAIN_DESC& param) override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;

	RSwapchainDX();
	virtual ~RSwapchainDX();
};

