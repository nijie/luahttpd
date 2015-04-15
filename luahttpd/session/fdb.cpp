#include "fdb.h"
#include "config.h"
#include "exelogger.h"

FDB::FDB()
{
	m_db = NULL;
}

FDB::~FDB()
{

}

FDB& FDB::Instance()
{
	static FDB s_o;
	return s_o;
}

bool FDB::init()
{
	string& strdir = Config::Instance().getFDBDir();

	leveldb::Options options;
	options.create_if_missing = true;
	options.write_buffer_size = 64 * 1024* 1024;
	string dbname = "fdb";
	leveldb::Status status = leveldb::DB::Open(options, strdir + dbname, &m_db);
	if (!status.ok())
	{
		SYS_CRITICAL("Open fdb DB failed!");
		leveldb::RepairDB(strdir + dbname, options);
		return false;
	}

	return true;
}

void FDB::uninit()
{
	if (m_db)
	{
		delete m_db;
		m_db = NULL;
	}
}

void FDB::setnn(unsigned int key, unsigned int val)
{
	leveldb::Status ret = m_db->Put(m_writeOpt, key, val);
	if (!ret.ok())
	{
		SYS_CRITICAL("save session failed, %u = %u", key, val);
	}
}

unsigned int FDB::getnn(unsigned int key)
{
	string strData;
	leveldb::Status ret = m_db->Get(m_readOpt, key, &strData);
	if (ret.ok())
	{
		UINT32 len = (UINT32)strData.size();
		if (len != sizeof(UINT32))
		{
			return 0;
		}

		return *(UINT32*)strData.c_str();
	}
	return 0;
}

void FDB::setns(unsigned int key, const char* val)
{
	if (NULL == val)
	{
		return;
	}

	leveldb::Status ret = m_db->Put(m_writeOpt, key, val);
	if (!ret.ok())
	{
		SYS_CRITICAL("save session failed, %u = %s", key, val);
	}
}

const char* FDB::getns(unsigned int key)
{
	static  string strData;
	leveldb::Status ret = m_db->Get(m_readOpt, key, &strData);
	if (ret.ok())
	{
		if (strData.empty())
		{
			return "";
		}

		return strData.c_str();
	}
	return "";
}

void FDB::setsn(const char* key, unsigned int val)
{
	if (key == NULL)
	{
		return;
	}

	leveldb::Status ret = m_db->Put(m_writeOpt, key, val);
	if (!ret.ok())
	{
		SYS_CRITICAL("save session failed, %s = %u", key, val);
	}
}

unsigned int FDB::getsn(const char* key)
{
	if (NULL == key)
	{
		return 0;
	}

	string strData;
	leveldb::Status ret = m_db->Get(m_readOpt, key, &strData);
	if (ret.ok())
	{
		UINT32 len = (UINT32)strData.size();
		if (len != sizeof(UINT32))
		{
			return 0;
		}

		return *(UINT32*)strData.c_str();
	}
	return 0;
}

void FDB::setss(const char* key, const char* val)
{
	if (key == NULL || val == NULL)
	{
		return;
	}

	leveldb::Status ret = m_db->Put(m_writeOpt, key, val);
	if (!ret.ok())
	{
		SYS_CRITICAL("save session failed, %s = %s", key, val);
	}
}

const char* FDB::getss(const char* key)
{
	if (NULL == key)
	{
		return "";
	}

	static string strData;
	leveldb::Status ret = m_db->Get(m_readOpt, key, &strData);
	if (ret.ok())
	{
		if (strData.empty())
		{
			return "";
		}

		return strData.c_str();
	}
	return "";
}

