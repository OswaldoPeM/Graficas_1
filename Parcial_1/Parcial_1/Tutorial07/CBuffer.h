#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include "STRUCTS.h"

enum BFlags
{
	VERTEX= 0x1L,
	INDEX= 0x2L,
	CONSTANT= 0x4L,
};
class CBuffer
{
	ID3D11Buffer* ptr_buffer = NULL;
	D3D11_BUFFER_DESC bd;
	D3D11_SUBRESOURCE_DATA InitData;

public:
	bool Init(int size, BFlags FLAG, SimpleVertex *vertices);
	bool Init(int size, BFlags FLAG, WORD *indices);
	bool Init(int size, BFlags FLAG);
	void update();
	void render();
	void destroy();

	ID3D11Buffer **getBuffer();
	D3D11_BUFFER_DESC *getBufferDesc();
	D3D11_SUBRESOURCE_DATA *getInitData();


	CBuffer();
	~CBuffer();
};

