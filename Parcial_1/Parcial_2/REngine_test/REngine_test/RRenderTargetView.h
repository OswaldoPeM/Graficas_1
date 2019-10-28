#pragma once
class RRenderTargetView
{
public:
	virtual void* getRenderTargetView() = 0;

	virtual bool init()=0;
	virtual void render() = 0;
	virtual void update()=0;
	virtual void destroy()=0;

	RRenderTargetView();
	virtual ~RRenderTargetView();
};

