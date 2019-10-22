#include "RRenderManager.h"




RRenderManager::RRenderManager()
{
}


RRenderManager::~RRenderManager()
{
}



int RRenderManager::CreateDeviceAndSwapChain(DeviceKey & key)
{
#ifdef DX
	D3D11CreateDeviceAndSwapChain(
		NULL,
		(D3D_DRIVER_TYPE)key.DriverType,
		(HMODULE)key.Software,
		key.Flags,
		(const D3D_FEATURE_LEVEL*)key.pFeatureLevels,
		key.FeatureLevels,
		key.SDKVersion,
		(DXGI_SWAP_CHAIN_DESC*)key.pSwapChainDesc,
		&Instance().m_swapChain,
		&Instance().m_Device,
		(D3D_FEATURE_LEVEL*)key.pFeatureLevel,
		&Instance().m_InterfaceDevice
	);
#endif // DX

	return _OK;
}

int RRenderManager::CreateBuffer(RBuffer & buffer)
{

#ifdef DX
	/*Instance().m_Device->CreateBuffer(
		(D3D11_BUFFER_DESC*)buffer.getDesc(),
		(D3D11_SUBRESOURCE_DATA*)buffer.getData(),
		(ID3D11Buffer**)buffer.getBuffer());*/
#endif // DX
#ifdef GL
	GLuint							*loc = (GLuint*)buffer.getBuffer();
	GLsizei							sizeB = buffer.getDesc()->ByteWidth;
	int								flag;
	//convert DX FLAG to GL Flag
	switch (buffer.getDesc()->BindFlags) {
	case BIND_VERTEX_BUFFER:		flag = GL_ARRAY_BUFFER; break;
	case BIND_INDEX_BUFFER:			flag = GL_ELEMENT_ARRAY_BUFFER; break;
	case BIND_CONSTANT_BUFFER:		flag = GL_UNIFORM_BUFFER; break;
	default:break;
	}

	if (flag == GL_ARRAY_BUFFER || flag == GL_ELEMENT_ARRAY_BUFFER) {

		// Generate an ID for the vertex buffer.
		glGenBuffers(1, loc);

		// Bind the vertex buffer and load the vertex (position, texture, and normal) data into the vertex buffer.
		glBindBuffer(flag, *loc);
		glBufferData(flag, sizeB, buffer.getData()->pSysMem, GL_STATIC_DRAW);
	}
	if (flag == GL_ARRAY_BUFFER) {
		// Enable the four vertex array attributes.
		glEnableVertexAttribArray(0);  // Vertex position.
		glEnableVertexAttribArray(1);  // Texture coordinates.

		// Specify the location and format of the position portion of the vertex buffer.
		glBindBuffer(GL_ARRAY_BUFFER, *loc);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), 0);

		// Specify the location and format of the texture coordinate portion of the vertex buffer.
		glBindBuffer(GL_ARRAY_BUFFER, *loc);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(SimpleVertex), (unsigned char*)NULL + (3 * sizeof(float)));
	}

	//glBufferSubData(flag, 0, sizeB, buffer.getData()->pSysMem);

#endif // GL

	return _OK;
}

int RRenderManager::CreateVertexShader(RVertexShader & vertexShader)
{
	/*Instance().m_Device->CreateVertexShader(
		vertexShader.getBlob()->GetBufferPointer(),
		vertexShader.getBlob()->GetBufferSize(),
		NULL, (ID3D11VertexShader**)vertexShader.getVertexShader());*/
	return 0;
}

int RRenderManager::CreateInputLayout(RVertexShader& vertexShader)
{
	/*Instance().m_Device->CreateInputLayout(
		&vertexShader.getVecILDesc()[0],
		vertexShader.getVecILDesc().size(),
		vertexShader.getBlob()->GetBufferPointer(),
		vertexShader.getBlob()->GetBufferSize(),
		vertexShader.getInputLayout()
	);*/
	return 0;
}
