#include "CSingleton.h"



CSingleton::CSingleton()
{
}


CSingleton::~CSingleton()
{
}

CSingleton & CSingleton::getInstance()
{
	static CSingleton instance;
	return instance;
}
