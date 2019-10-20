#include "RBuffer.h"



bool RBuffer::init(BUFFER_DESC &desc,SimpleVertex *vertices)
{
	m_description.clear();
	m_initData.clear();

	m_description = desc;
	m_initData.pSysMem = vertices;
#ifdef DX
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
