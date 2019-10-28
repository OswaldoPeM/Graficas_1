#pragma once
#include "RSamplerState.h"
class ID3D11SamplerState;
class RSamplerStateDX :
	public RSamplerState
{
	ID3D11SamplerState* m_samplerLinear;
public:
	virtual void* getSamplerLinear() override;
	virtual void* getSamplerDesc()override;

	virtual bool init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void destroy() override;

	RSamplerStateDX();
	virtual ~RSamplerStateDX();
};

