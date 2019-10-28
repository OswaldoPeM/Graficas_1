#pragma once
#include "RRenderTargetView.h"
class ID3D11RenderTargetView;

class RRenderTargetViewDX :
	public RRenderTargetView
{
	ID3D11RenderTargetView* m_RenderTargetView;
public:

	virtual void* getRenderTargetView()override;

	virtual bool init()override;
	virtual void render()override;
	virtual void update()override;
	virtual void destroy()override;

	RRenderTargetViewDX();
	~RRenderTargetViewDX();
};

