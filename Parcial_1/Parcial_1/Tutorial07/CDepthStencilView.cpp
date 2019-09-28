#include "CDepthStencilView.h"



ID3D11Texture2D ** CDepthStencilView::getDepthStencil()
{
	return &DepthStencil;
}

ID3D11DepthStencilView ** CDepthStencilView::getDepthStencilView()
{
	return &DepthStencilView;
}

D3D11_TEXTURE2D_DESC * CDepthStencilView::getDescDepth()
{
	return &descDepth;
}

D3D11_DEPTH_STENCIL_VIEW_DESC * CDepthStencilView::getDescDepthStencilView()
{
	return &descDSV;
}

bool CDepthStencilView::init(UINT WIDTH, UINT HEIGHT)
{
	ZeroMemory(&descDepth, sizeof(descDepth));
	descDepth.Width = WIDTH;
	descDepth.Height = HEIGHT;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;

	ZeroMemory(&descDSV, sizeof(descDSV));
	descDSV.Format = descDepth.Format;
	descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	descDSV.Texture2D.MipSlice = 0;

	return false;
}

void CDepthStencilView::render()
{
}

void CDepthStencilView::update()
{
}

void CDepthStencilView::destroy()
{
	if (DepthStencil)DepthStencil->Release();
	if (DepthStencilView)DepthStencilView->Release();
	delete this;
}

CDepthStencilView::CDepthStencilView()
{
}


CDepthStencilView::~CDepthStencilView()
{
}
