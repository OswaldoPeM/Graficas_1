#pragma once
#include "RDepthStencilView.h"
class ID3D11DepthStencilView;

class RDepthStencilViewDX :
	public RDepthStencilView
{
	ID3D11DepthStencilView* m_pDepthStencilView=nullptr;
public:
	virtual void* getDSV()override;

	virtual bool inti(STENCIL_VIEW_DESC desc)override;
	virtual void render()override;
	virtual void update() override;
	virtual void destroy() override;
	RDepthStencilViewDX();
	~RDepthStencilViewDX();
};
