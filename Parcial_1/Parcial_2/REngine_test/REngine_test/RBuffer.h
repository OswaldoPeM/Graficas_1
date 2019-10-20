/********************************************************************/
/**
* @LC     16/10/2019
* @file   RBuffer.h
* @Author Oswaldo Perez Macias
* @date   16/10/2019
* @brief  A buffer interface accesses a buffer resource,
		  which is unstructured memory. Buffers typically store vertex or index data.
* @bug	  No known bugs.
*/
/********************************************************************/
#pragma once

/**
	*Incudes
*/
#include "Header.h"	

class RBuffer
{
#ifdef DX
	ID3D10Buffer* buffer;
#elif GL
	unsigned int buffer;
#endif // DX

	BUFFER_DESC m_description;
	SUBRESOURCE_DATA m_initData;
public:

	bool init(BUFFER_DESC &desc, SimpleVertex *vertices);
	void render();
	void update();
	void destroy();

#ifdef DX

#elif GL 
	
#endif // DX|GL

	RBuffer();
	~RBuffer();
};

