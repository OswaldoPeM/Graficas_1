/********************************************************************/
/**
* @LC     16/10/2019
* @file   RBuffer.h
* @Author Oswaldo Perez Macias
* @date   16/10/2019
* @brief  A m_buffer interface accesses a m_buffer resource,
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
	ID3D10Buffer* m_buffer;
#elif GL
	unsigned int* m_buffer;
#endif // DX

	BUFFER_DESC m_description;
	SUBRESOURCE_DATA m_initData;
public:

	void* getBuffer() { return m_buffer; }
	BUFFER_DESC *getDesc() { return &m_description; }
	SUBRESOURCE_DATA *getData() { return &m_initData; }

	bool init(BufferKey &DATA);
	void render();
	void update();
	void destroy();

#ifdef DX

#elif GL 
	
#endif // DX|GL

	RBuffer();
	~RBuffer();
};

