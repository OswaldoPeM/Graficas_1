#include "RBuffer.h"
#include"RRenderManager.h"


bool RBuffer::init(BufferKey &DATA)
{
	m_description.clear();
	m_initData.clear();

	m_description	 = DATA.desc;
	m_initData		 = DATA.data;
#ifdef DX
	RRenderManager::CreateBuffer(*this);
#elif GL
	RDevice::getDevice().CreateBuffer(1,m_buffer);
#endif // DX|GL

	return true;
}

void RBuffer::render()
{
}

void RBuffer::update()
{
}

void RBuffer::destroy()
{
}

RBuffer::RBuffer()
{
}


RBuffer::~RBuffer()
{
}
