#pragma once
#include"enumers.h"


/**
	*float[4] {x, y, z, w }
*/
struct RVec4f
{
	float x;
	float y;
	float z;
	float w;
};

/**
	float[2] {x, y}
*/
struct RVec2f
{
	float x;
	float y;
};

/**
	* {RVec4f,RVec2f} 
	{Pos:{x, y, z, w },
	Tex:{x, y}}
*/
struct SimpleVertex
{
	RVec4f Pos;
	RVec2f Tex;
};

struct CBNeverChanges
{
	glm::mat4 mView;
};

struct CBChangeOnResize
{
	glm::mat4 mProjection;
};

struct CBChangesEveryFrame
{
	glm::mat4 mWorld;
	RVec4f vMeshColor;
};

struct BUFFER_DESC
{
	unsigned int ByteWidth;
	USAGE Usage;
	unsigned int BindFlags;
	unsigned int CPUAccessFlags;
	unsigned int MiscFlags;
	unsigned int StructureByteStride;
	void clear() { memset(this, 0, sizeof(this)); }
};

/**
	*Specifies data for initializing a subresource.
*/
struct SUBRESOURCE_DATA
{
	const void *pSysMem;
	unsigned int SysMemPitch;
	unsigned int SysMemSlicePitch;
	void clear() { memset(this, 0, sizeof(this)); }
};
/**
	*Buffer init parameters
*/
struct BufferKey {
	BUFFER_DESC			desc;
	SUBRESOURCE_DATA	data; 
};
/**
	*Cordenates at space.
	long {x,y}
*/
struct RPoint {
	long x;
	long y;
};
/**
	*size of a rectangle
	long{width, height}
*/
struct RRect {
	long width;
	long height;
};

struct D3D11_TEXTURE2D_DESC {
	unsigned int             Width;
	unsigned int             Height;
	unsigned int             MipLevels;
	unsigned int             ArraySize;
	DXGI_FORMAT      Format;
	DXGI_SAMPLE_DESC SampleDesc;
	D3D11_USAGE      Usage;
	unsigned int             BindFlags;
	unsigned int             CPUAccessFlags;
	unsigned int             MiscFlags;
};