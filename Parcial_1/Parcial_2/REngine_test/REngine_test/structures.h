#pragma once
#include"enumers.h"


/**
	*float {x, y, z, w }
*/
struct Rvertex4f
{
	float x;
	float y;
	float z;
	float w;
};

/**
	float{x, y}
*/
struct Rvertex2f
{
	float x;
	float y;
};

/**
	* {Rvertex4f,Rvertex2f} 
	{Pos:{x, y, z, w },
	Tex:{x, y}}
*/
struct SimpleVertex
{
	Rvertex4f Pos;
	Rvertex2f Tex;
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
	Rvertex4f vMeshColor;
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