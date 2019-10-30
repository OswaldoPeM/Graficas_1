#include "RRenderManager.h"

#include "RDeviceInterface.h"
#include "RSwapchain.h"
#include "RTexture.h"
#include "RDevice.h"


RRenderManager::RRenderManager()
{
}

int RRenderManager::CreateDeviceAndSwapChain(RenderManagerDesc & desc)
{
	return Device->CreateDeviceAndSwapChain(desc);
}


RRenderManager::~RRenderManager()
{
}





int RRenderManager::CreateBuffer(RBuffer & buffer)
{

	Device->CreateBuffer(buffer);

//#ifdef GL
//	GLuint							*loc = (GLuint*)buffer.getBuffer();
//	GLsizei							sizeB = buffer.getDesc()->ByteWidth;
//	int								flag;
//	//convert DX FLAG to GL Flag
//	switch (buffer.getDesc()->BindFlags) {
//	case BIND_VERTEX_BUFFER:		flag = GL_ARRAY_BUFFER; break;
//	case BIND_INDEX_BUFFER:			flag = GL_ELEMENT_ARRAY_BUFFER; break;
//	case BIND_CONSTANT_BUFFER:		flag = GL_UNIFORM_BUFFER; break;
//	default:break;
//	}
//	
//	if (flag == GL_ARRAY_BUFFER || flag == GL_ELEMENT_ARRAY_BUFFER) {
//
//		// Generate an ID for the vertex buffer.
//		glGenBuffers(1, loc);
//
//		// Bind the vertex buffer and load the vertex (position, texture, and normal) data into the vertex buffer.
//		glBindBuffer(flag, *loc);
//		glBufferData(flag, sizeB, buffer.getData()->pSysMem, GL_STATIC_DRAW);
//	}
//
//	if (flag == GL_ARRAY_BUFFER) {
//		// Enable the four vertex array attributes.
//		glEnableVertexAttribArray(0);  // Vertex position.
//		glEnableVertexAttribArray(1);  // Texture coordinates.
//
//		// Specify the location and format of the position portion of the vertex buffer.
//		glBindBuffer(GL_ARRAY_BUFFER, *loc);
//		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);
//
//		// Specify the location and format of the texture coordinate portion of the vertex buffer.
//		glBindBuffer(GL_ARRAY_BUFFER, *loc);
//		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (unsigned char*)NULL + (4 * sizeof(float)));
//		
//		//disable atributes and disbind
//		glDisableVertexAttribArray(1);
//		glDisableVertexAttribArray(0);
//
//		glBindBuffer(GL_ARRAY_BUFFER, 0);
//	}
//	
//	//glBufferSubData(flag, 0, sizeB, buffer.getData()->pSysMem);
//
//#endif // GL

	return _OK;
}

int RRenderManager::CreateVertexShader(RProgramShader& shaderProgram)
{
	return Device->CreateVertexShader(shaderProgram);
}

int RRenderManager::CreateInputLayout(RProgramShader& programShader)
{
	return Device->CreateInputLayout(programShader);
}

int RRenderManager::CreatePixelShader(RProgramShader & shaderProgram)
{
	return Device->CreatePixelShader(shaderProgram);
}

int RRenderManager::CreateTexture2D(RDepthStencilView & Texture)
{
	return Device->CreateTexture2D(Texture);
}

int RRenderManager::CreateRenderTargetView(RRenderTargetView & renderTargetView)
{
	RTexture* backbuffer = nullptr;
	SwChBuf sw;
	SwapChain->GetBuffer(sw, backbuffer);
	int r = Device->CreateRenderTargetView(renderTargetView, backbuffer);
	if (backbuffer != nullptr) {
		backbuffer->destroy();
	}
	return r;
}

int RRenderManager::CreateDepthStencilView(RDepthStencilView & depthStencilView)
{
	return Device->CreateDepthStencilView(depthStencilView);
}

int RRenderManager::CreateSamplerState(RSamplerState & samplerState)
{
	return Device->CreateSamplerState(samplerState);
}

void RRenderManager::OMSetRenderTargets
(
	unsigned int NumViews,
	RRenderTargetView * ppRenderTargetViews,
	RDepthStencilView * pDepthStencilView
)
{
	InterfaceDeivice->OMSetRenderTargets
	(
		NumViews,
		ppRenderTargetViews,
		pDepthStencilView
	);
}

void RRenderManager::RSSetViewports
(
	unsigned int NumViewports,
	RViewport * pViewports
)
{
	InterfaceDeivice->RSSetViewports
	(
		NumViewports,
		pViewports
	);
}

void RRenderManager::IASetInputLayout(RInputLayout * pInputLayout)
{
	InterfaceDeivice->IASetInputLayout(pInputLayout);
}

void RRenderManager::IASetVertexBuffers
(
	unsigned int			StartSlot,
	unsigned int			NumBuffers,
	RBuffer *				ppVertexBuffers,
	const unsigned int *	pStrides,
	const unsigned int *	pOffsets
)
{
	InterfaceDeivice->IASetVertexBuffers
	(
		StartSlot,
		NumBuffers,
		ppVertexBuffers,
		pStrides,
		pOffsets
	);
}

void RRenderManager::IASetIndexBuffer
(
	RBuffer * pIndexBuffer,
	FORMAT Format,
	unsigned int Offset
)
{
	InterfaceDeivice->IASetIndexBuffer
	(
		pIndexBuffer,
		Format,
		Offset
	);
}

void RRenderManager::IASetPrimitiveTopology(PRIMITIVE_TOPOLOGY Topology)
{
	InterfaceDeivice->IASetPrimitiveTopology(Topology);
}

void RRenderManager::UpdateSubresource
(
	RBuffer * pDstResource,
	unsigned int DstSubresource, 
	RBOX * pDstBox, 
	void * pSrcData, 
	unsigned int SrcRowPitch, 
	unsigned int SrcDepthPitch
)
{
	InterfaceDeivice->UpdateSubresource
	(
		pDstResource,
		DstSubresource,
		pDstBox,
		pSrcData,
		SrcRowPitch,
		SrcDepthPitch
	);

}

void RRenderManager::ClearRenderTargetView
(
	RRenderTargetView * pRenderTargetView,
	float ColorRGBA[4]
)
{
	InterfaceDeivice->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
}

void RRenderManager::ClearDepthStencilView
(
	RDepthStencilView * pDepthStencilView,
	unsigned int ClearFlags, 
	float Depth, 
	unsigned char Stencil)
{
	InterfaceDeivice->ClearDepthStencilView
	(
		pDepthStencilView,
		ClearFlags, 
		Depth, 
		Stencil
	);
}

void RRenderManager::VSSetShader
(
	RVertexShader * pVertexShader
)
{
	InterfaceDeivice->VSSetShader(pVertexShader);
}

void RRenderManager::VSSetConstantBuffers
(
	unsigned int StartSlot,
	unsigned int NumBuffers,
	RBuffer * ppConstantBuffers
)
{
	InterfaceDeivice->VSSetConstantBuffers
	(
		StartSlot,
		NumBuffers,
		ppConstantBuffers
	);
}

void RRenderManager::PSSetShader(RPixelShader * pPixelShader)
{
	InterfaceDeivice->PSSetShader(pPixelShader);
}

void RRenderManager::PSSetConstantBuffers
(
	unsigned int StartSlot,
	unsigned int NumBuffer,
	RBuffer * ppConstantBuffers
)
{
	InterfaceDeivice->PSSetConstantBuffers
	(
		StartSlot,
		NumBuffer,
		ppConstantBuffers
	);
}

void RRenderManager::PSSetShaderResources
(
	unsigned int StartSlot,
	unsigned int NumViews, 
	RShaderResourceView * ppShaderResourceViews
)
{
	InterfaceDeivice->PSSetShaderResources
	(
		StartSlot, 
		NumViews, 
		ppShaderResourceViews
	);
}

void RRenderManager::PSSetSamplers
(
	unsigned int StartSlot,
	unsigned int NumSamplers,
	RSamplerState * ppSamplers
)
{
	InterfaceDeivice->PSSetSamplers
	(
		StartSlot,
		NumSamplers,
		ppSamplers
	);
}

void RRenderManager::DrawIndexed
(
	unsigned int IndexCount,
	unsigned int StartIndexLocation, 
	int BaseVertexLocation
)
{
	InterfaceDeivice->DrawIndexed
	(
		IndexCount,
		StartIndexLocation,
		BaseVertexLocation
	);
}

unsigned int RRenderManager::Present(SwChPr & param)
{
	return SwapChain->Present(param);
}

unsigned int RRenderManager::ResizeBuffer(ReSzSCH & param)
{
	return SwapChain->ResizeBuffer(param);
}

void RRenderManager::update()
{
}

void RRenderManager::render()
{
}

void RRenderManager::destroy()
{
}
