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
int RDeviceDX::CreateTexture2D(RDepthStencilView & depthStencilView)
{
	TEXTURE2D_DESC* tDesc =
		reinterpret_cast<TEXTURE2D_DESC*>(depthStencilView.getTextDesc());

	///copia de descripcion de textura
	D3D11_TEXTURE2D_DESC textDesc;
	textDesc.Width = tDesc->Width;
	textDesc.Height = tDesc->Height;
	textDesc.MipLevels = tDesc->MipLevels;
	textDesc.ArraySize = tDesc->ArraySize;
	textDesc.Format = (DXGI_FORMAT)tDesc->Format;
	textDesc.SampleDesc.Count = tDesc->SampleDesc.Count;
	textDesc.SampleDesc.Quality = tDesc->SampleDesc.Quality;
	textDesc.Usage = (D3D11_USAGE)tDesc->Usage;
	textDesc.BindFlags = tDesc->BindFlags;
	textDesc.CPUAccessFlags = tDesc->CPUAccessFlags;
	textDesc.MiscFlags = tDesc->MiscFlags;
	///copia de descripcion de textura

	ID3D11Texture2D* tex =
		reinterpret_cast<ID3D11Texture2D*>(depthStencilView.getTexture());

	return m_pDevice->CreateTexture2D(&textDesc, NULL, &tex);
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

	return m_pDevice->CreateRenderTargetView(tex, NULL, &RTV);
}

int RDeviceDX::CreateDepthStencilView(RDepthStencilView & depthStencilView)
{
	ID3D11Texture2D* tex =
		reinterpret_cast<ID3D11Texture2D*>(depthStencilView.getTexture());
	D3D11_DEPTH_STENCIL_VIEW_DESC DSVDesc;
	DEPTH_STENCIL_VIEW_DESC* dDesc = 
		reinterpret_cast<DEPTH_STENCIL_VIEW_DESC*>(depthStencilView.getDSVdesc());
	DSVDesc.Flags= dDesc->Flags;
	DSVDesc.Format=(DXGI_FORMAT) dDesc->Format;
	DSVDesc.ViewDimension= (D3D11_DSV_DIMENSION)dDesc->ViewDimension;
	DSVDesc.Texture2DArray.ArraySize= dDesc->ArraySize;
	DSVDesc.Texture2DArray.FirstArraySlice= dDesc->FirstArraySlice;
	DSVDesc.Texture2DArray.MipSlice = dDesc->MipSlice;

	ID3D11DepthStencilView* DSV =
		reinterpret_cast<ID3D11DepthStencilView*>(depthStencilView.getDSV());

	return m_pDevice->CreateDepthStencilView(tex, &DSVDesc, &DSV);
}

int RDeviceDX::CreateSamplerState(RSamplerState & samplerState)
{
	D3D11_SAMPLER_DESC sampDesc;
	ZeroMemory(&sampDesc, sizeof(sampDesc));
	sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
	sampDesc.MinLOD = 0;
	sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
	ID3D11SamplerState* sampler =
		reinterpret_cast<ID3D11SamplerState*>(samplerState.getSamplerLinear());
	return m_pDevice->CreateSamplerState(&sampDesc, &sampler);
}

RDeviceDX::RDeviceDX()
{
}


RDeviceDX::~RDeviceDX()
{
}
