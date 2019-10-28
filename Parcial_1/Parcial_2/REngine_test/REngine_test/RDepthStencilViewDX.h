#pragma once
#include "RDepthStencilView.h"
class ID3D11DepthStencilView;

class RDepthStencilViewDX :
	public RDepthStencilView
{
	ID3D11DepthStencilView* m_pDepthStencilView=nullptr;
public:
	virtual void* getDSV()override;
	virtual void* getDSVdesc()override;
	virtual void* getTexture()override;
	virtual void* getTextDesc()override;

	virtual bool inti(STENCIL_VIEW_DESC desc, TEXTURE2D_DESC tDesc)override;
	virtual void render()override;
	virtual void update() override;
	virtual void destroy() override;

	RDepthStencilViewDX();
	virtual ~RDepthStencilViewDX();
};

