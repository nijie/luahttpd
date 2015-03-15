// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include <time.h>
#include <stdio.h>
#include <string.h>
#ifdef WIN32
#include <Windows.h>
#else
#include <stdarg.h>
#endif
#include "exelogger.h"

IFxLogger* ExeLogger::m_pLogger = NULL;
int ExeLogger::m_nLvl = EXE_LOG_NONE;
bool ExeLogger::m_bOutputDbgString = false;
IFxLock* ExeLogger::m_pLock = NULL;
bool ExeLogger::m_bInit = false;

#define TMP_LOG_LEN 409600

const char* pPrefixes[] = 
{
    "DBG_INF",
    "USR_INF",
    "USR_IMP",
    "USR_CRT",
    "SYS_CRT",
};

void flog(const char* txt)
{
	USR_CRITICAL(txt);
}

bool ExeLogger::Init( const char* pszName, int nLvl, bool bOutputDbgString )
{
    if (m_bInit)
    {
        return false;
    }

    if (NULL != m_pLock)
    {
        return false;
    }
    m_pLock = FxCreateThreadLock();

    if (NULL != m_pLogger)
    {
        return false;
    }

    if ((nLvl > EXE_LOG_MAX) && (nLvl <= EXE_LOG_NONE))
    {
        return false;
    }
    m_nLvl = nLvl;
    m_bOutputDbgString = bOutputDbgString;

    m_pLogger = FxCreateLogger();
    if (NULL == m_pLogger)
    {
        return false;
    }

    bool bRet = m_pLogger->Init(pszName, false);
    if (bRet)
    {
       m_bInit = true; 
    }
    return bRet;
}

void ExeLogger::Log( int nLvl, const char* pszFunction, int nLine, const char* pFmt, ... )
{
    if (!m_bInit)
    {
        return;
    }
	if (m_nLvl > nLvl)
	{
		return;
	}

    FxLockImp oLockImp(m_pLock);
    static char szLog[TMP_LOG_LEN] = {0};
    int nNowLen = 0;
    int nTimeLen = 0;

    va_list arglist;
    va_start(arglist, pFmt);
#ifdef WIN32 // Windows下可以打印到DebugView
    if (m_bOutputDbgString)
    {
        time_t tmNow;
        tm sTm = {0};
        time(&tmNow);
        int nErrCode = localtime_s(&sTm, &tmNow);
        if (0 != nErrCode)
        {
            printf("[%s] localtime fail, error code: %d.\n", __FUNCTION__, nErrCode);
            return;
        }
        sTm.tm_year += 1900;
        sTm.tm_mon += 1;

		_snprintf(szLog, TMP_LOG_LEN - 1, "[%02d:%02d:%02d]\t[%d:%s]\t[%s:%d]\t", 
            sTm.tm_hour, sTm.tm_min, sTm.tm_sec, 
			nLvl, pPrefixes[nLvl], pszFunction, nLine);

        nNowLen = (int)strlen(szLog);
        _vsprintf_s_l(szLog + nNowLen, TMP_LOG_LEN - nNowLen, pFmt, NULL, arglist);
        nNowLen = (int)strlen(szLog);
        szLog[nNowLen] = '\n';
        szLog[nNowLen + 1] = '\0';
        // OutputDebugString(szLog);
		printf(szLog);
		nTimeLen = 10;// 这个长度是指上面的时间所占用的长度
    }
	else
#endif
	{
#ifdef WIN32
		_snprintf(szLog, TMP_LOG_LEN - 1, "[%d:%s]\t[%s:%d]\t", nLvl, pPrefixes[nLvl], pszFunction, nLine);
        nNowLen = (int)strlen(szLog);
        vsprintf_s(szLog + nNowLen, TMP_LOG_LEN - nNowLen, pFmt, arglist);
#else
		snprintf(szLog, TMP_LOG_LEN - 1, "[%d:%s]\t[%s:%d]\t", nLvl, pPrefixes[nLvl], pszFunction, nLine);
        nNowLen = (int)strlen(szLog);
        vsnprintf(szLog + nNowLen, TMP_LOG_LEN - nNowLen, pFmt, arglist);
#endif
        nNowLen = (int)strlen(szLog);
	}

	if (0 != nTimeLen)
	{
		memmove(szLog, szLog + nTimeLen, nNowLen - nTimeLen);
		szLog[nNowLen - nTimeLen] = '\0';
	}

	nNowLen = (int)strlen(szLog);
	for (int i = 0; i < nNowLen; i += 1000)
	{
		if (nNowLen - i < 1000)
		{
			m_pLogger->LogText(szLog + i);
		}
		else
		{
			char szTemp[1004] = {0};
			memcpy(szTemp, szLog + i, 1000);
			m_pLogger->LogText(szTemp);
		}
	}
    va_end(arglist);
}

void ExeLogger::UnInit( void )
{
	if (false == m_bInit)
	{
		return;
	}

    if (NULL != m_pLogger)
    {
        m_pLogger->Release();
    }
    if (NULL != m_pLock)
    {
        delete m_pLock;
    }
	m_pLogger = NULL;
	m_nLvl = EXE_LOG_NONE;
	m_bOutputDbgString = false;
	m_pLock = NULL;
	m_bInit = false;
}

void ExeLogger::ChangeLvl(int nLvl)
{
    if ((nLvl > EXE_LOG_MAX) && (nLvl <= EXE_LOG_NONE))
    {
        return;
    }
    m_nLvl = nLvl;
}
