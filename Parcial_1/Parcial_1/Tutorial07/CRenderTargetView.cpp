#include "CRenderTargetView.h"



ID3D11RenderTargetView ** CRenderTargetView::getRenderTargetView()
{
	return &ptr_RenderTargetView;
}

bool CRenderTargetView::Init()
{
	return false;
}

void CRenderTargetView::render()
{
}

void CRenderTargetView::update()
{
}

void CRenderTargetView::destroy()
{
	if (ptr_RenderTargetView)ptr_RenderTargetView->Release();
	delete this;
}

void CRenderTargetView::Release()
{
	ptr_RenderTargetView->Release();
}

CRenderTargetView::CRenderTargetView()
{
}


CRenderTargetView::~CRenderTargetView()
{
}
