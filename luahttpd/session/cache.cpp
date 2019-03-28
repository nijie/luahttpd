#include "cache.h"

Cache::Cache()
{

}

Cache::~Cache()
{

}

Cache& Cache::Instance()
{
	static Cache so;
	return so;
}

bool Cache::init()
{
	m_mapns.clear();
	m_mapsn.clear();
	m_mapnn.clear();
	m_mapss.clear();

	return true;
}

void Cache::uninit()
{

}

void Cache::setnn(unsigned int key, unsigned int val)
{
	m_mapnn[key] = val;
}

unsigned int Cache::getnn(unsigned int key)
{
	unordered_map<unsigned int, unsigned int>::iterator it = m_mapnn.find(key);
	if (it == m_mapnn.end())
	{
		return 0;
	}
	return it->second;
}

void Cache::setns(unsigned int key, const char* val)
{
	if (val == NULL)
	{
		return;
	}
	m_mapns[key] = val;
}

const char* Cache::getns(unsigned int key)
{
	unordered_map<unsigned int, string>::iterator it = m_mapns.find(key);
	if (it == m_mapns.end())
	{
		return "";
	}
	return it->second.c_str();
}

void Cache::setsn(const char* key, unsigned int val)
{
	if (NULL == key)
	{
		return;
	}
	m_mapsn[key] = val;
}

unsigned int Cache::getsn(const char* key)
{
	if (NULL == key)
	{
		return 0;
	}
	unordered_map<string, unsigned int>::iterator it = m_mapsn.find(key);
	if (it == m_mapsn.end())
	{
		return 0;
	}
	return it->second;
}

void Cache::setss(const char* key, const char* val)
{
	if (NULL == key || NULL == val)
	{
		return;
	}
	m_mapss[key] = val;
}

const char* Cache::getss(const char* key)
{
	if (NULL == key)
	{
		return 0;
	}
	unordered_map<string, string>::iterator it = m_mapss.find(key);
	if (it == m_mapss.end())
	{
		return 0;
	}
	return it->second.c_str();
}
