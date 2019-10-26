#include "RBuffer.h"
#include"RRenderManager.h"


bool RBuffer::init(BufferKey &DATA)
{
	m_description.clear();
	m_initData.clear();

	m_description	 = DATA.desc;
	m_initData		 = DATA.data;

	RRenderManager::Instance().CreateBuffer(*this, RRenderManager::InstancePtr()->getDevice());
	return true;
}


RBuffer::RBuffer()
{
}


RBuffer::~RBuffer()
{
}
