#pragma once
#include "Header.h"
class RSwapchain
{
protected:
	SWAP_CHAIN_DESC m_SwapChainDesc;
public:
	virtual void* getSwapChain() = 0;

	virtual unsigned int GetBuffer(SwChBuf& param) = 0;
	virtual unsigned int Present(SwChPr& param) = 0;
	virtual unsigned int ResizeBuffer(ReSzSCH& param) = 0;

	virtual bool init(SWAP_CHAIN_DESC& param) = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void destroy() = 0;

	RSwapchain();
	virtual ~RSwapchain();
};

