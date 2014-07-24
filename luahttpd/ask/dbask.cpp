// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//

#include "dbask.h"
#include "serverwork.h"
#include "exelogger.h"
#include "utility.h"
#include "../script/luascript.h"

DBAsk::DBAsk()
	: LuaAsk(LUA_ASK_MYSQL)
{
	memset(&m_baseSN, 0, sizeof(m_baseSN));
	m_sn = -1;
	m_bMakeSN = false;

	m_bNeedResult = false;
	m_nResult = 0;
	m_pResult = NULL;
}

DBAsk::~DBAsk()
{
	if (NULL != m_pResult)
	{
		m_pResult->Release();
		m_pResult = NULL;
	}
}

INT32 DBAsk::GetDBId(void)
{
	if (!m_bMakeSN)
	{
		if (m_sn < 0)
		{
			m_sn = GetRandom(0, m_baseSN.wCount - 1);
		}
		else
		{
			if (m_sn >= m_baseSN.wCount)
			{
				m_sn = 0;
			}
		}

		m_sn = m_baseSN.nBaseSN + m_sn;
		m_bMakeSN = true;
	}
	return m_sn;
}

bool DBAsk::setSN(int sn)
{
	m_sn = sn;
	return true;
}

void DBAsk::OnQuery(IDBConnection *poDBConnection)
{
	if (m_bNeedResult)
	{
		m_nResult = poDBConnection->Query(m_strSQL.c_str(), &m_pResult);
	}
	else
	{
		m_nResult = poDBConnection->Query(m_strSQL.c_str());
	}

	if (0 > m_nResult)
	{
		SYS_CRITICAL("Select Error [%s]", poDBConnection->GetLastErrorString());
	}
}

void DBAsk::OnResult(void)
{
	if (!m_bNeedResult)
	{
		return;
	}

	// 脚本回调
	bool bRet = m_nResult < 0 ? false : true;
	HttpHandler* pHttp = getHandler();
	if (NULL == pHttp)
	{
		return;
	}

	LuaScript::Instance().callBackFunc(*pHttp, *this, bRet);
}

void DBAsk::Release(void)
{
	if (NULL != m_pResult)
	{
		m_pResult->Release();
		m_pResult = NULL;
	}
}

bool DBAsk::setSQL(const char* pDBName, const char* pSql)
{
	if (NULL == pDBName || NULL == pSql)
	{
		return false;
	}

	SDBMysqlSN* pSN = ServerWork::Instance().getBaseMysqlSN(pDBName);
	if (NULL == pSN)
	{// 没有找到对应的数据库连接
		SYS_CRITICAL("can not find dbname [%s]", pDBName);
		return false;
	}

	m_baseSN = *pSN;
	m_strSQL = pSql;

	return true;
}

void DBAsk::setNeedResult(bool bNeedResult)
{
	m_bNeedResult = bNeedResult;
}

unsigned int DBAsk::count()
{
	if (NULL == m_pResult)
	{
		return 0;
	}

	return m_pResult->GetRecordCount();
}

bool DBAsk::begin()
{
	if (NULL == m_pResult)
	{
		return false;
	}

	return m_pResult->GetFirstRecord();
}

bool DBAsk::next()
{
	if (NULL == m_pResult)
	{
		return false;
	}

	return m_pResult->GetNextRecord();
}

const char* DBAsk::get(unsigned int dwIndex)
{
	if (NULL == m_pResult)
	{
		return "";
	}

	const char* pRet = m_pResult->GetFieldValue(dwIndex);
	if (NULL == pRet)
	{
		return "";
	}

	return pRet;
}

int DBAsk::getSize(unsigned int dwIndex)
{
	if (NULL == m_pResult)
	{
		return 0;
	}

	return m_pResult->GetFieldLength(dwIndex);
}
