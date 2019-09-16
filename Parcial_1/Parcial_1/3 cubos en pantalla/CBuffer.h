#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <xnamath.h>

class CBuffer
{
public:
	ID3D11Buffer* ptr_buffer = nullptr;
	CBuffer();
	~CBuffer();
};

