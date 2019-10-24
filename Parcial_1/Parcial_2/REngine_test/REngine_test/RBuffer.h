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
#include "requerimientos.h"

class RBuffer
{
#ifdef DX
	ID3D10Buffer* m_buffer;
#elif GL
	unsigned int* m_buffer;
#endif // DX

protected:
	BUFFER_DESC m_description;
	SUBRESOURCE_DATA m_initData;
public:
	virtual void* getBuffer() = 0;

	virtual BUFFER_DESC *getDesc() { return &m_description; }
	virtual SUBRESOURCE_DATA *getData() { return &m_initData; }

	virtual bool init(BufferKey &DATA)=0;
	virtual void render()=0;
	virtual void update()=0;
	virtual void destroy()=0;


	RBuffer();
	~RBuffer();
};

