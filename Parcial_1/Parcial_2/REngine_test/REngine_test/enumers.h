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
	USAGE_DEFAULT = 0,
	USAGE_IMMUTABLE = 1,
	USAGE_DYNAMIC = 2,
	USAGE_STAGING = 3
};

/**
	*Identifies how to bind a resource to the pipeline.
*/
enum BIND_FLAG {
	BIND_VERTEX_BUFFER,
	BIND_INDEX_BUFFER,
	BIND_CONSTANT_BUFFER,
	BIND_SHADER_RESOURCE,
	BIND_STREAM_OUTPUT,
	BIND_RENDER_TARGET,
	BIND_DEPTH_STENCIL,
	BIND_UNORDERED_ACCESS,
	BIND_DECODER,
	BIND_VIDEO_ENCODER
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

enum result {
	_OK				= 0x00000000,	//Operation successful
	_NOTIMPL		= 0x80004001,	//Not implemented
	_NOINTERFACE	= 0x80004002,	//No such interface supported
	_POINTER		= 0x80004003,	//Pointer that is not valid
	_ABORT			= 0x80004004,	//Operation aborted
	_FAIL			= 0x80004005,	//Unspecified failure
	_UNEXPECTED		= 0x8000FFFF,	//Unexpected failure
	_ACCESSDENIED	= 0x80070005,	//General access denied error
	_HANDLE			= 0x80070006,	//Handle that is not valid
	_OUTOFMEMORY	= 0x8007000E,	//Failed to allocate necessary memory
	_INVALIDARG		= 0x80070057	//One or more arguments are not valid
};