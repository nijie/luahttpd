#ifndef __FDB_H_NIJIE_2015_0324__
#define __FDB_H_NIJIE_2015_0324__

#include "leveldb.h"

class FDB
{
public:
	FDB();
	~FDB();

	static FDB&	Instance();
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
	leveldb::DB*			m_db;
	leveldb::ReadOptions	m_readOpt;
	leveldb::WriteOptions	m_writeOpt;
};

//////////////////////////////////////////////////////////////////////////
inline void		fsetnn(unsigned int key, unsigned int val)
{
	FDB::Instance().setnn(key, val);
}

inline unsigned int fgetnn(unsigned int key)
{
	return FDB::Instance().getnn(key);
}

inline void		fsetns(unsigned int key, const char* val)
{
	FDB::Instance().setns(key, val);
}

inline const char*	fgetns(unsigned int key)
{
	return FDB::Instance().getns(key);
}

inline void		fsetsn(const char* key, unsigned int val)
{
	FDB::Instance().setsn(key, val);
}

inline unsigned int fgetsn(const char* key)
{
	return FDB::Instance().getsn(key);
}

inline void		fsetss(const char* key, const char* val)
{
	FDB::Instance().setss(key, val);
}

inline const char* fgetss(const char* key)
{
	return FDB::Instance().getss(key);
}

#endif	// __FDB_H_NIJIE_2015_0324__
