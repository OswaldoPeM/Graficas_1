#include "CBuffer.h"



bool CBuffer::init(int size, BFlags FLAG, SimpleVertex * vertices)
{
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(SimpleVertex) * size;
	bd.BindFlags = FLAG;//solo almacena vertices
	bd.CPUAccessFlags = 0;

	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;

	return true;
}

bool CBuffer::init(int size, BFlags FLAG, WORD * indices)
{

	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(WORD) * size;
	bd.BindFlags = FLAG;
	bd.CPUAccessFlags = 0;
	
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = indices;

	return true;
}

bool CBuffer::init(int size, BFlags FLAG)
{

	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = size;
	bd.BindFlags = FLAG;
	bd.CPUAccessFlags = 0;

	
	ZeroMemory(&InitData, sizeof(InitData));
	return true;
}

void CBuffer::update()
{
}

void CBuffer::render()
{
}

void CBuffer::destroy()
{
	if (ptr_buffer)ptr_buffer->Release();
	if (this)delete this;
}

ID3D11Buffer ** CBuffer::getBuffer()
{
	return &ptr_buffer;
}

D3D11_BUFFER_DESC * CBuffer::getBufferDesc()
{
	return &bd;
}

D3D11_SUBRESOURCE_DATA * CBuffer::getInitData()
{
	return &InitData;
}

CBuffer::CBuffer()
{
}


CBuffer::~CBuffer()
{
	if (ptr_buffer)ptr_buffer->Release();
}
