#pragma once
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
class CComp
{
	int m_index;
public:

	virtual int getIndex() { return m_index; }
	virtual void setIndex(int index) { m_index = index; }

	virtual bool init()=0;
	virtual void render()=0;
	virtual void update()=0;
	virtual void destroy()=0;
	CComp();
	~CComp();
};

