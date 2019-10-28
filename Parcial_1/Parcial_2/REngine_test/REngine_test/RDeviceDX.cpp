#include "RShaderResourceViewDX.h"
#include "RRenderTargetViewDX.h"
#include "RDepthStencilViewDX.h"
#include "RProgramShaderDX.h"
#include "RSamplerStateDX.h"
#include "RinputLayoutDX.h"
#include "RViewportDX.h"
#include "RTextureDX.h"
#include "RBufferDX.h"
#include "RDeviceDX.h"

#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>


void * RDeviceDX::getDevice()
{
	return reinterpret_cast<void*>(m_pDevice);
}

int RDeviceDX::CreateBuffer(RBuffer & buffer)
{
	ID3D11Buffer* buf =
		reinterpret_cast<ID3D11Buffer*>(buffer.getBuffer());
	D3D11_BUFFER_DESC bd;
	D3D11_SUBRESOURCE_DATA InitData;

	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = (D3D11_USAGE)buffer.getDesc()->Usage;
	bd.ByteWidth = buffer.getDesc()->ByteWidth;
	bd.BindFlags = buffer.getDesc()->BindFlags;
	bd.CPUAccessFlags = buffer.getDesc()->CPUAccessFlags;

	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = buffer.getData()->pSysMem;

	return m_pDevice->CreateBuffer(&bd, &InitData, &buf);
}

int RDeviceDX::CreateVertexShader(RProgramShader& programShader)
{
	ID3D10Blob* Blob = 
		reinterpret_cast<ID3D10Blob*>(programShader.getBlob());
	ID3D11VertexShader* VertexShader =
		reinterpret_cast<ID3D11VertexShader*>(programShader.getVertexShader());
	return m_pDevice->CreateVertexShader
	(
		Blob->GetBufferPointer(), 
		Blob->GetBufferSize(),
		NULL,
		&VertexShader
	);
}

int RDeviceDX::CreateInputLayout(RProgramShader & programShader)
{

	RPixelShader* VertexShader =
		reinterpret_cast<RPixelShader*>(programShader.getPixelShader());
	ID3D10Blob* Blob =
		reinterpret_cast<ID3D10Blob*>(programShader.getBlob());
	RInputLayout* InputL =
		reinterpret_cast<RInputLayout*>(programShader.getInputLayout());
	ID3D11InputLayout* VertexLayout =
		reinterpret_cast<ID3D11InputLayout*>(InputL->getIL());
	std::vector<INPUT_ELEMENT_DESC> InLaOutDesc = InputL->getInputLayoutDesc();
	std::vector<D3D11_INPUT_ELEMENT_DESC> inputLayoutDesc;
	for (unsigned int i = 0; i < InLaOutDesc.size(); i++)
	{
		D3D11_INPUT_ELEMENT_DESC temp;
		temp.SemanticName = InLaOutDesc[i].SemanticName;
		temp.SemanticIndex = InLaOutDesc[i].SemanticIndex;
		temp.Format = (DXGI_FORMAT)InLaOutDesc[i].Format;
		temp.InputSlot = InLaOutDesc[i].InputSlot;
		temp.AlignedByteOffset = InLaOutDesc[i].AlignedByteOffset;
		temp.InputSlotClass = (D3D11_INPUT_CLASSIFICATION)InLaOutDesc[i].InputSlotClass;
		temp.InstanceDataStepRate = InLaOutDesc[i].InstanceDataStepRate;
		inputLayoutDesc.push_back(temp);
	}

	return m_pDevice->CreateInputLayout
	(
		&inputLayoutDesc[0],
		inputLayoutDesc.size(),
		Blob->GetBufferPointer(),
		Blob->GetBufferSize(),
		&VertexLayout
	);
}

int RDeviceDX::CreatePixelShader(RProgramShader & programShader)
{
	ID3D10Blob* Blob =
		reinterpret_cast<ID3D10Blob*>(programShader.getBlob());
	ID3D11PixelShader* PixelShader =
		reinterpret_cast<ID3D11PixelShader*>(programShader.getPixelShader());

	return m_pDevice->CreatePixelShader
	(
		Blob->GetBufferPointer(),
		Blob->GetBufferSize(),
		NULL,
		&PixelShader
	);
}
//cambiar funcion de device por create texture 2d quitar textura de depth stencil
int RDeviceDX::CreateTexture2D(RDepthStencilView & Stencilview)
{
	ID3D11Texture2D* tex = 
		reinterpret_cast<ID3D11Texture2D*>(Stencilview.getTexture());
	ID3D11RenderTargetView* RTV =
		reinterpret_cast<ID3D11RenderTargetView*>(Stencilview.getDSV());

	return m_pDevice->CreateRenderTargetView
	(
		tex,
		NULL, 
		&RTV
	);
}

int RDeviceDX::CreateRenderTargetView
(
	RRenderTargetView & renderTargetView,
	void* backbuffer
)
{
	ID3D11Texture2D* tex =
		reinterpret_cast<ID3D11Texture2D*>(backbuffer);
	ID3D11RenderTargetView* RTV =
		reinterpret_cast<ID3D11RenderTargetView*>(renderTargetView.getRenderTargetView());

	return m_pDevice->CreateRenderTargetView
	(
		tex,
		NULL,
		&RTV
	);
}

RDeviceDX::RDeviceDX()
{
}


RDeviceDX::~RDeviceDX()
{
}
