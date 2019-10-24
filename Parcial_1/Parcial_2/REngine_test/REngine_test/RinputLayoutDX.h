#pragma once
#include "RInputLayout.h"
class ID3D11InputLayout;
class RinputLayoutDX :
	public RInputLayout
{
	ID3D11InputLayout* m_pInputLayout;
public:
	virtual void* getIL() override;

	virtual bool init(INPUT_ELEMENT_DESC desc) override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;
	RinputLayoutDX();
	virtual ~RinputLayoutDX();
};

