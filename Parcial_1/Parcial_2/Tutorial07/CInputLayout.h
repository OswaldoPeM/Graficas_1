#pragma once
#include<vector>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>

typedef enum INPUT_CLASSIFICATION
{
	INPUT_PER_VERTEX_DATA = 0,
	INPUT_PER_INSTANCE_DATA = 1
};


class CInputLayout
{
	ID3D11InputLayout* g_pVertexLayout = NULL;
	D3D11_INPUT_ELEMENT_DESC layoutDesc[2];

public:
	ID3D11InputLayout** getInputLayout();
	D3D11_INPUT_ELEMENT_DESC* getLayoutDesc();
	UINT getLayoutSize();

	void setLayoutDesc(
		LPCSTR semanticName,
		UINT SemanticIndex,
		DXGI_FORMAT format,
		UINT InputSlot,
		UINT alignedByteOffset,
		INPUT_CLASSIFICATION InputSlotClass,
		UINT InstanceDataStepRate);


	void destoy();

	CInputLayout();
	~CInputLayout();
};

