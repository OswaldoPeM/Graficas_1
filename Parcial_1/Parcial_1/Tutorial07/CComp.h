#pragma once
class CComp
{
public:
	virtual bool init()=0;
	virtual void render()=0;
	virtual void update()=0;
	virtual void destroy()=0;
	CComp();
	~CComp();
};

