#include "CInputLayout.h"



ID3D11InputLayout ** CInputLayout::getInputLayout()
{
	return &g_pVertexLayout;
}

D3D11_INPUT_ELEMENT_DESC* CInputLayout::getLayoutDesc()
{
	return layoutDesc;
}

UINT CInputLayout::getLayoutSize()
{
	return  ARRAYSIZE(layoutDesc);
}

void CInputLayout::setLayoutDesc(
	LPCSTR semanticName, 
	UINT SemanticIndex, 
	DXGI_FORMAT format, 
	UINT InputSlot,
	UINT alignedByteOffset,
	INPUT_CLASSIFICATION InputSlotClass,
	UINT InstanceDataStepRate)
{
	if (semanticName=="POSITION")
	{
		layoutDesc[0] = { semanticName,SemanticIndex,format,InputSlot,alignedByteOffset,(D3D11_INPUT_CLASSIFICATION)InputSlotClass,InstanceDataStepRate };
	}
	else if(semanticName=="TEXCOORD")
	{
		layoutDesc[1] = { semanticName,SemanticIndex,format,InputSlot,alignedByteOffset,(D3D11_INPUT_CLASSIFICATION)InputSlotClass,InstanceDataStepRate };
	}
}

void CInputLayout::destoy()
{
	if(g_pVertexLayout)g_pVertexLayout->Release();
	delete this;
}

CInputLayout::CInputLayout()
{
}


CInputLayout::~CInputLayout()
{
}
