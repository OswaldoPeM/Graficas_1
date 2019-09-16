#pragma once
#include "CBuffer.h"
struct CBNeverChanges
{
	XMMATRIX mView;
};
struct CBChangeOnResize
{
	XMMATRIX mProjection;
};
struct CBChangesEveryFrame
{
	XMMATRIX mWorld;
	XMFLOAT4 vMeshColor;
};

class ConstBuffer :
	public CBuffer
{
public:
	ConstBuffer();
	~ConstBuffer();
};

