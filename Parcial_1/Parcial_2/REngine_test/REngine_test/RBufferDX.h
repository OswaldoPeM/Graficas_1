#pragma once
#include "RBuffer.h"
class ID3D11Buffer;

class RBufferDX :
	public RBuffer
{
	ID3D11Buffer* m_pBuffer;
public:
	virtual void* getBuffer() override;

	virtual bool init(BufferKey &desData)override;
	virtual void render()override;
	virtual void update()override;
	virtual void destroy()override;
	RBufferDX();
	virtual ~RBufferDX();
};

