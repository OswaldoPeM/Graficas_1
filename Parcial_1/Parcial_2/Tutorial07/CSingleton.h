#pragma once
class CSingleton
{
	CSingleton();
	~CSingleton();
public:
	static CSingleton& getInstance();
};

