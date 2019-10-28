/********************************************************************/
/**
* @LC     16/10/2019
* @file   enumers.h
* @Author Oswaldo Perez Macias
* @date   16/10/2019
* @brief  enumers.h definition
* @bug	  No known bugs.
*/
/********************************************************************/
#pragma once
/**
	
*/

/**
	*Identifies expected resource use during rendering.
	The usage directly reflects whether a resource is 
	accessible by the CPU and/or the graphics processing unit (GPU).
*/
enum USAGE
{
	USAGE_DEFAULT	                      = 0,
	USAGE_IMMUTABLE                       = 1,
	USAGE_DYNAMIC	                      = 2,
	USAGE_STAGING	                      = 3
};

/**
	*Identifies how to bind a resource to the pipeline.
*/
enum BIND_FLAG {
	BIND_VERTEX_BUFFER		                      = 0x1L,
	BIND_INDEX_BUFFER		                      = 0x2L,
	BIND_CONSTANT_BUFFER	                      = 0x4L,
	BIND_SHADER_RESOURCE	                      = 0x8L,
	BIND_STREAM_OUTPUT		                      = 0x10L,
	BIND_RENDER_TARGET		                      = 0x20L,
	BIND_DEPTH_STENCIL		                      = 0x40L,
	BIND_UNORDERED_ACCESS	                      = 0x80L,
};

/**
	*Specifies the types of CPU access allowed for a resource.
*/
enum CPU_ACCESS_FLAG {
	CPU_ACCESS_WRITE,
	CPU_ACCESS_READ
};

/**
	*Identifies options for resources.
*/
enum RESOURCE_MISC_FLAG {
	RESOURCE_MISC_GENERATE_MIPS,
	RESOURCE_MISC_SHARED,
	RESOURCE_MISC_TEXTURECUBE,
	RESOURCE_MISC_DRAWINDIRECT_ARGS,
	RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS,
	RESOURCE_MISC_BUFFER_STRUCTURED,
	RESOURCE_MISC_RESOURCE_CLAMP,
	RESOURCE_MISC_SHARED_KEYEDMUTEX,
	RESOURCE_MISC_GDI_COMPATIBLE,
	RESOURCE_MISC_SHARED_NTHANDLE,
	RESOURCE_MISC_RESTRICTED_CONTENT,
	RESOURCE_MISC_RESTRICT_SHARED_RESOURCE,
	RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER,
	RESOURCE_MISC_GUARDED,
	RESOURCE_MISC_TILE_POOL,
	RESOURCE_MISC_TILED,
	RESOURCE_MISC_HW_PROTECTED
};

/**
	*Resource data formats, including fully-typed and typeless formats.
		A list of modifiers at the bottom of the page more fully describes
		each format type.
*/
enum FORMAT
{
	FORMAT_UNKNOWN                       = 0,
	FORMAT_R32G32B32A32_TYPELESS                       = 1,
	FORMAT_R32G32B32A32_FLOAT                       = 2,
	FORMAT_R32G32B32A32_UINT                       = 3,
	FORMAT_R32G32B32A32_SINT                       = 4,
	FORMAT_R32G32B32_TYPELESS                       = 5,
	FORMAT_R32G32B32_FLOAT                       = 6,
	FORMAT_R32G32B32_UINT                       = 7,
	FORMAT_R32G32B32_SINT                       = 8,
	FORMAT_R16G16B16A16_TYPELESS                       = 9,
	FORMAT_R16G16B16A16_FLOAT                       = 10,
	FORMAT_R16G16B16A16_UNORM                       = 11,
	FORMAT_R16G16B16A16_UINT                       = 12,
	FORMAT_R16G16B16A16_SNORM                       = 13,
	FORMAT_R16G16B16A16_SINT                       = 14,
	FORMAT_R32G32_TYPELESS                       = 15,
	FORMAT_R32G32_FLOAT                       = 16,
	FORMAT_R32G32_UINT                       = 17,
	FORMAT_R32G32_SINT                       = 18,
	FORMAT_R32G8X24_TYPELESS                       = 19,
	FORMAT_D32_FLOAT_S8X24_UINT                       = 20,
	FORMAT_R32_FLOAT_X8X24_TYPELESS                       = 21,
	FORMAT_X32_TYPELESS_G8X24_UINT                       = 22,
	FORMAT_R10G10B10A2_TYPELESS                       = 23,
	FORMAT_R10G10B10A2_UNORM                       = 24,
	FORMAT_R10G10B10A2_UINT                       = 25,
	FORMAT_R11G11B10_FLOAT                       = 26,
	FORMAT_R8G8B8A8_TYPELESS                       = 27,
	FORMAT_R8G8B8A8_UNORM                       = 28,
	FORMAT_R8G8B8A8_UNORM_SRGB                       = 29,
	FORMAT_R8G8B8A8_UINT                       = 30,
	FORMAT_R8G8B8A8_SNORM                       = 31,
	FORMAT_R8G8B8A8_SINT                       = 32,
	FORMAT_R16G16_TYPELESS                       = 33,
	FORMAT_R16G16_FLOAT                       = 34,
	FORMAT_R16G16_UNORM                       = 35,
	FORMAT_R16G16_UINT                       = 36,
	FORMAT_R16G16_SNORM                       = 37,
	FORMAT_R16G16_SINT                       = 38,
	FORMAT_R32_TYPELESS                       = 39,
	FORMAT_D32_FLOAT                       = 40,
	FORMAT_R32_FLOAT                       = 41,
	FORMAT_R32_UINT                       = 42,
	FORMAT_R32_SINT                       = 43,
	FORMAT_R24G8_TYPELESS                       = 44,
	FORMAT_D24_UNORM_S8_UINT                       = 45,
	FORMAT_R24_UNORM_X8_TYPELESS                       = 46,
	FORMAT_X24_TYPELESS_G8_UINT                       = 47,
	FORMAT_R8G8_TYPELESS                       = 48,
	FORMAT_R8G8_UNORM                       = 49,
	FORMAT_R8G8_UINT                       = 50,
	FORMAT_R8G8_SNORM                       = 51,
	FORMAT_R8G8_SINT                       = 52,
	FORMAT_R16_TYPELESS                       = 53,
	FORMAT_R16_FLOAT                       = 54,
	FORMAT_D16_UNORM                       = 55,
	FORMAT_R16_UNORM                       = 56,
	FORMAT_R16_UINT                       = 57,
	FORMAT_R16_SNORM                       = 58,
	FORMAT_R16_SINT                       = 59,
	FORMAT_R8_TYPELESS                       = 60,
	FORMAT_R8_UNORM                       = 61,
	FORMAT_R8_UINT                       = 62,
	FORMAT_R8_SNORM                       = 63,
	FORMAT_R8_SINT                       = 64,
	FORMAT_A8_UNORM                       = 65,
	FORMAT_R1_UNORM                       = 66,
	FORMAT_R9G9B9E5_SHAREDEXP                       = 67,
	FORMAT_R8G8_B8G8_UNORM                       = 68,
	FORMAT_G8R8_G8B8_UNORM                       = 69,
	FORMAT_BC1_TYPELESS                       = 70,
	FORMAT_BC1_UNORM                       = 71,
	FORMAT_BC1_UNORM_SRGB                       = 72,
	FORMAT_BC2_TYPELESS                       = 73,
	FORMAT_BC2_UNORM                       = 74,
	FORMAT_BC2_UNORM_SRGB                       = 75,
	FORMAT_BC3_TYPELESS                       = 76,
	FORMAT_BC3_UNORM                       = 77,
	FORMAT_BC3_UNORM_SRGB                       = 78,
	FORMAT_BC4_TYPELESS                       = 79,
	FORMAT_BC4_UNORM                       = 80,
	FORMAT_BC4_SNORM                       = 81,
	FORMAT_BC5_TYPELESS                       = 82,
	FORMAT_BC5_UNORM                       = 83,
	FORMAT_BC5_SNORM                       = 84,
	FORMAT_B5G6R5_UNORM                       = 85,
	FORMAT_B5G5R5A1_UNORM                       = 86,
	FORMAT_B8G8R8A8_UNORM                       = 87,
	FORMAT_B8G8R8X8_UNORM                       = 88,
	FORMAT_R10G10B10_XR_BIAS_A2_UNORM                       = 89,
	FORMAT_B8G8R8A8_TYPELESS                       = 90,
	FORMAT_B8G8R8A8_UNORM_SRGB                       = 91,
	FORMAT_B8G8R8X8_TYPELESS                       = 92,
	FORMAT_B8G8R8X8_UNORM_SRGB                       = 93,
	FORMAT_BC6H_TYPELESS                       = 94,
	FORMAT_BC6H_UF16                       = 95,
	FORMAT_BC6H_SF16                       = 96,
	FORMAT_BC7_TYPELESS                       = 97,
	FORMAT_BC7_UNORM                       = 98,
	FORMAT_BC7_UNORM_SRGB                       = 99,
	FORMAT_AYUV                       = 100,
	FORMAT_Y410                       = 101,
	FORMAT_Y416                       = 102,
	FORMAT_NV12                       = 103,
	FORMAT_P010                       = 104,
	FORMAT_P016                       = 105,
	FORMAT_420_OPAQUE                       = 106,
	FORMAT_YUY2                       = 107,
	FORMAT_Y210                       = 108,
	FORMAT_Y216                       = 109,
	FORMAT_NV11                       = 110,
	FORMAT_AI44                       = 111,
	FORMAT_IA44                       = 112,
	FORMAT_P8                       = 113,
	FORMAT_A8P8                       = 114,
	FORMAT_B4G4R4A4_UNORM                       = 115,

	FORMAT_P208                       = 130,
	FORMAT_V208                       = 131,
	FORMAT_V408                       = 132,


	FORMAT_FORCE_UINT                       = 0xffffffff
};
/**
	*Flags indicating the method the raster uses to create an image on a surface.
*/
enum MODE_SCANLINE_ORDER
{
	MODE_SCANLINE_ORDER_UNSPECIFIED                       = 0,
	MODE_SCANLINE_ORDER_PROGRESSIVE                       = 1,
	MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST                       = 2,
	MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST                       = 3
};
/**
	*Flags indicating how an image is stretched to fit a given monitor's resolution.
*/
enum MODE_SCALING {
	MODE_SCALING_UNSPECIFIED                       = 0,
	MODE_SCALING_CENTERED                       = 1,
	MODE_SCALING_STRETCHED                       = 2
};
enum SWAP_EFFECT
{
	SWAP_EFFECT_DISCARD                       = 0,
	SWAP_EFFECT_SEQUENTIAL                       = 1,
	SWAP_EFFECT_FLIP_SEQUENTIAL                       = 3,
	SWAP_EFFECT_FLIP_DISCARD                       = 4
};
/**
	*Specifies how to access a resource used in a depth-stencil view.
*/
enum DSV_DIMENSION
{
	DSV_DIMENSION_UNKNOWN			                      = 0,
	DSV_DIMENSION_TEXTURE1D			                      = 1,
	DSV_DIMENSION_TEXTURE1DARRAY	                      = 2,
	DSV_DIMENSION_TEXTURE2D			                      = 3,
	DSV_DIMENSION_TEXTURE2DARRAY	                      = 4,
	DSV_DIMENSION_TEXTURE2DMS		                      = 5,
	DSV_DIMENSION_TEXTURE2DMSARRAY	                      = 6
};
enum TEXTURE_ADDRESS_MODE
{
	TEXTURE_ADDRESS_WRAP = 1,
	TEXTURE_ADDRESS_MIRROR = 2,
	TEXTURE_ADDRESS_CLAMP = 3,
	TEXTURE_ADDRESS_BORDER = 4,
	TEXTURE_ADDRESS_MIRROR_ONCE = 5
};
enum COMPARISON_FUNC
{
	COMPARISON_NEVER = 1,
	COMPARISON_LESS = 2,
	COMPARISON_EQUAL = 3,
	COMPARISON_LESS_EQUAL = 4,
	COMPARISON_GREATER = 5,
	COMPARISON_NOT_EQUAL = 6,
	COMPARISON_GREATER_EQUAL = 7,
	COMPARISON_ALWAYS = 8
};
enum FILTER
{
	FILTER_MIN_MAG_MIP_POINT = 0,
	FILTER_MIN_MAG_POINT_MIP_LINEAR = 0x1,
	FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x4,
	FILTER_MIN_POINT_MAG_MIP_LINEAR = 0x5,
	FILTER_MIN_LINEAR_MAG_MIP_POINT = 0x10,
	FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x11,
	FILTER_MIN_MAG_LINEAR_MIP_POINT = 0x14,
	FILTER_MIN_MAG_MIP_LINEAR = 0x15,
	FILTER_ANISOTROPIC = 0x55,
	FILTER_COMPARISON_MIN_MAG_MIP_POINT = 0x80,
	FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR = 0x81,
	FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x84,
	FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR = 0x85,
	FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT = 0x90,
	FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
	FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 0x94,
	FILTER_COMPARISON_MIN_MAG_MIP_LINEAR = 0x95,
	FILTER_COMPARISON_ANISOTROPIC = 0xd5
}
enum result {
	_OK				                      = 0x00000000,	//Operation successful
	_NOTIMPL		                      = 0x80004001,	//Not implemented
	_NOINTERFACE	                      = 0x80004002,	//No such interface supported
	_POINTER		                      = 0x80004003,	//Pointer that is not valid
	_ABORT			                      = 0x80004004,	//Operation aborted
	_FAIL			                      = 0x80004005,	//Unspecified failure
	_UNEXPECTED		                      = 0x8000FFFF,	//Unexpected failure
	_ACCESSDENIED	                      = 0x80070005,	//General access denied error
	_HANDLE			                      = 0x80070006,	//Handle that is not valid
	_OUTOFMEMORY	                      = 0x8007000E,	//Failed to allocate necessary memory
	_INVALIDARG		                      = 0x80070057	//One or more arguments are not valid
};
/**
	*Driver type options.
*/
enum DRIVER_TYPE
{
	DRIVER_TYPE_UNKNOWN                       = 0,
	DRIVER_TYPE_HARDWARE                       = (DRIVER_TYPE_UNKNOWN + 1),
	DRIVER_TYPE_REFERENCE                       = (DRIVER_TYPE_HARDWARE + 1),
	DRIVER_TYPE_NULL                       = (DRIVER_TYPE_REFERENCE + 1),
	DRIVER_TYPE_SOFTWARE                       = (DRIVER_TYPE_NULL + 1),
	DRIVER_TYPE_WARP                       = (DRIVER_TYPE_SOFTWARE + 1)
};

/**
	*Describes the set of features targeted BY device.
*/
enum FEATURE_LEVEL
{
	FEATURE_LEVEL_9_1                       = 0x9100,
	FEATURE_LEVEL_9_2                       = 0x9200,
	FEATURE_LEVEL_9_3                       = 0x9300,
	FEATURE_LEVEL_10_0                       = 0xa000,
	FEATURE_LEVEL_10_1                       = 0xa100,
	FEATURE_LEVEL_11_0                       = 0xb000,
	FEATURE_LEVEL_11_1                       = 0xb100,
	FEATURE_LEVEL_12_0                       = 0xc000,
	FEATURE_LEVEL_12_1                       = 0xc100
};

enum INPUT_CLASSIFICATION
{
	INPUT_PER_VERTEX_DATA                       = 0,
	INPUT_PER_INSTANCE_DATA                       = 1
};

enum PRIMITIVE_TOPOLOGY
{
	PRIMITIVE_TOPOLOGY_UNDEFINED = 0,
	PRIMITIVE_TOPOLOGY_POINTLIST = 1,
	PRIMITIVE_TOPOLOGY_LINELIST = 2,
	PRIMITIVE_TOPOLOGY_LINESTRIP = 3,
	PRIMITIVE_TOPOLOGY_TRIANGLELIST = 4,
	PRIMITIVE_TOPOLOGY_TRIANGLESTRIP = 5,
	PRIMITIVE_TOPOLOGY_LINELIST_ADJ = 10,
	PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ = 11,
	PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ = 12,
	PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ = 13,
	PRIMITIVE_TOPOLOGY_1_CONTROL_POINT_PATCHLIST = 33,
	PRIMITIVE_TOPOLOGY_2_CONTROL_POINT_PATCHLIST = 34,
	PRIMITIVE_TOPOLOGY_3_CONTROL_POINT_PATCHLIST = 35,
	PRIMITIVE_TOPOLOGY_4_CONTROL_POINT_PATCHLIST = 36,
	PRIMITIVE_TOPOLOGY_5_CONTROL_POINT_PATCHLIST = 37,
	PRIMITIVE_TOPOLOGY_6_CONTROL_POINT_PATCHLIST = 38,
	PRIMITIVE_TOPOLOGY_7_CONTROL_POINT_PATCHLIST = 39,
	PRIMITIVE_TOPOLOGY_8_CONTROL_POINT_PATCHLIST = 40,
	PRIMITIVE_TOPOLOGY_9_CONTROL_POINT_PATCHLIST = 41,
	PRIMITIVE_TOPOLOGY_10_CONTROL_POINT_PATCHLIST = 42,
	PRIMITIVE_TOPOLOGY_11_CONTROL_POINT_PATCHLIST = 43,
	PRIMITIVE_TOPOLOGY_12_CONTROL_POINT_PATCHLIST = 44,
	PRIMITIVE_TOPOLOGY_13_CONTROL_POINT_PATCHLIST = 45,
	PRIMITIVE_TOPOLOGY_14_CONTROL_POINT_PATCHLIST = 46,
	PRIMITIVE_TOPOLOGY_15_CONTROL_POINT_PATCHLIST = 47,
	PRIMITIVE_TOPOLOGY_16_CONTROL_POINT_PATCHLIST = 48,
	PRIMITIVE_TOPOLOGY_17_CONTROL_POINT_PATCHLIST = 49,
	PRIMITIVE_TOPOLOGY_18_CONTROL_POINT_PATCHLIST = 50,
	PRIMITIVE_TOPOLOGY_19_CONTROL_POINT_PATCHLIST = 51,
	PRIMITIVE_TOPOLOGY_20_CONTROL_POINT_PATCHLIST = 52,
	PRIMITIVE_TOPOLOGY_21_CONTROL_POINT_PATCHLIST = 53,
	PRIMITIVE_TOPOLOGY_22_CONTROL_POINT_PATCHLIST = 54,
	PRIMITIVE_TOPOLOGY_23_CONTROL_POINT_PATCHLIST = 55,
	PRIMITIVE_TOPOLOGY_24_CONTROL_POINT_PATCHLIST = 56,
	PRIMITIVE_TOPOLOGY_25_CONTROL_POINT_PATCHLIST = 57,
	PRIMITIVE_TOPOLOGY_26_CONTROL_POINT_PATCHLIST = 58,
	PRIMITIVE_TOPOLOGY_27_CONTROL_POINT_PATCHLIST = 59,
	PRIMITIVE_TOPOLOGY_28_CONTROL_POINT_PATCHLIST = 60,
	PRIMITIVE_TOPOLOGY_29_CONTROL_POINT_PATCHLIST = 61,
	PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST = 62,
	PRIMITIVE_TOPOLOGY_31_CONTROL_POINT_PATCHLIST = 63,
	PRIMITIVE_TOPOLOGY_32_CONTROL_POINT_PATCHLIST = 64,
};