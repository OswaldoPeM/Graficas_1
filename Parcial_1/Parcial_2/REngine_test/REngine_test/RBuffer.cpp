#include "RBuffer.h"
#include"RRenderManager.h"


BUFFER_DESC * RBuffer::getDesc()
{
	return &m_description;
}

SUBRESOURCE_DATA * RBuffer::getData()
{
	return &m_initData;
}

bool RBuffer::init(BufferDesc &DATA)
{
	m_description.clear();
	m_initData.clear();

	m_description	 = DATA.desc;
	m_initData		 = DATA.data;

	RRenderManager::Instance().CreateBuffer(*this);
	return true;
}


RBuffer::RBuffer()
{
}


RBuffer::~RBuffer()
{
}
