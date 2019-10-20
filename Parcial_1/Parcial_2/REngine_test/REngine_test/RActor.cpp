#include "RActor.h"



void RActor::addComp(RComponent * comp)
{
	m_componentes.push_back(*&comp);
}

void RActor::destroyComp(int index)
{
	m_componentes[index]->destroy();
	m_componentes.erase(m_componentes.begin() + index);
}

bool RActor::init()
{
	return false;
}

void RActor::render()
{
}

void RActor::update()
{
}

void RActor::destroy()
{
}

RActor::RActor()
{
}


RActor::~RActor()
{
}
