#ifndef __CACHE_H_NIJIE_2015_0324__
#define __CACHE_H_NIJIE_2015_0324__

#include <string>
#include <tr1/unordered_map>

using namespace std::tr1;

using namespace std;

class Cache
{
public:
	Cache();
	~Cache();

	static Cache&	Instance();
	bool		init();
	void		uninit();

	void		setnn(unsigned int key, unsigned int val);
	unsigned int getnn(unsigned int key);

	void		setns(unsigned int key, const char* val);
	const char*	getns(unsigned int key);

	void		setsn(const char* key, unsigned int val);
	unsigned int getsn(const char* key);

	void		setss(const char* key, const char* val);
	const char* getss(const char* key);

private:
	unordered_map<unsigned int, unsigned int> m_mapnn;
	unordered_map<unsigned int, string> m_mapns;
	unordered_map<string, unsigned int> m_mapsn;
	unordered_map<string, string> m_mapss;
};

//////////////////////////////////////////////////////////////////////////
inline void		setnn(unsigned int key, unsigned int val)
{
	Cache::Instance().setnn(key, val);
}

inline unsigned int getnn(unsigned int key)
{
	return Cache::Instance().getnn(key);
}

inline void		setns(unsigned int key, const char* val)
{
	Cache::Instance().setns(key, val);
}

inline const char*	getns(unsigned int key)
{
	return Cache::Instance().getns(key);
}

inline void		setsn(const char* key, unsigned int val)
{
	Cache::Instance().setsn(key, val);
}

inline unsigned int getsn(const char* key)
{
	return Cache::Instance().getsn(key);
}

inline void		setss(const char* key, const char* val)
{
	Cache::Instance().setss(key, val);
}

inline const char* getss(const char* key)
{
	return Cache::Instance().getss(key);
}

#endif	// __CACHE_H_NIJIE_2015_0324__
