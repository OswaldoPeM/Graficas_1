#pragma once

#include "Header.h"
class RInputLayout
{
#ifdef DX
	ID3D11InputLayout *m_VertexLayout;
#endif // DX

public:
	void* getIL() { return m_VertexLayout; }
	RInputLayout();
	~RInputLayout();
};

