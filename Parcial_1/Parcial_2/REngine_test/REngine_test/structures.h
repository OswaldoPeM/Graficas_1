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

struct RATIONAL {
	unsigned int Numerator;
	unsigned int Denominator;
};

struct SAMPLE_DESC {
	unsigned int Count;
	unsigned int Quality;
};
/**
	*Describes a display mode.
*/
struct MODE_DESC {
	unsigned int                     Width;
	unsigned int                     Height;
	RATIONAL            RefreshRate;
	FORMAT              Format;
	MODE_SCANLINE_ORDER ScanlineOrdering;
	MODE_SCALING        Scaling;
};


/**
	*DESC
*/
////////////////////////////////////////////////////////////////////////////////////
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
struct SAMPLE_DESC
{
	unsigned int Count;
	unsigned int Quality;
};
/**
	*Describes a 2D texture.
*/
struct TEXTURE2D_DESC {
	unsigned int             Width;
	unsigned int             Height;
	unsigned int             MipLevels;
	unsigned int             ArraySize;
	FORMAT					 Format;
	SAMPLE_DESC				 SampleDesc;
	USAGE					 Usage;
	unsigned int             BindFlags;
	unsigned int             CPUAccessFlags;
	unsigned int             MiscFlags;
};
/**
	*Describes a swap chain.
*/
struct SWAP_CHAIN_DESC
{
	MODE_DESC BufferDesc;
	SAMPLE_DESC SampleDesc;
	unsigned int BufferUsage;
	unsigned int BufferCount;
	HWND OutputWindow;
	bool Windowed;
	SWAP_EFFECT SwapEffect;
	unsigned int Flags;
};

////////////////////////////////////////////////////////////////////////////////////////

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

/**
	*Describes multi-sampling parameters for a resource.
*/



struct DEPTH_STENCIL_VIEW_DESC {
	DSV_DIMENSION		viewDimension;
	FORMAT				format;
	UINT                mipSlice;
	UINT                firstArraySlice;
	UINT                arraySize;
	UINT                flags;
};
/**
	*init parameters
*/
struct BufferKey {
	BUFFER_DESC			desc;
	SUBRESOURCE_DATA	data; 
};
struct DeviceKey {
	void* pAdapter=NULL;
	DRIVER_TYPE DriverType;
	HMODULE Software=NULL;
	unsigned int Flags;
	const FEATURE_LEVEL *pFeatureLevels;
	unsigned int FeatureLevels;
	unsigned int SDKVersion=7;// = D3D11_SDK_VERSION;
	const SWAP_CHAIN_DESC * pSwapChainDesc;
	//void ** ppSwapChain;
	FEATURE_LEVEL * pFeatureLevel;
	//void ** ppImmediateContext;
};
/**
	*Defines the dimensions of a viewport.
	float[6]{
	 TopLeftX,
	 TopLeftY,
	 Width,
	 Height,
	 MinDepth,
	 MaxDepth,
	 }

*/
struct VIEWPORT
{
	float TopLeftX;
	float TopLeftY;
	float Width;
	float Height;
	float MinDepth;
	float MaxDepth;
};