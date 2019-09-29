#pragma once
#include <xnamath.h>
struct SimpleVertex
{
	XMFLOAT4 Pos;
	XMFLOAT2 Tex;
};
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