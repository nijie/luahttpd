// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __EXELOGGER_H_NIJIE_2012_0907__
#define __EXELOGGER_H_NIJIE_2012_0907__
#include "fxmeta.h"

#define LOGGER_NAME_LEN 50

enum EExeLogLvl
{
    EXE_LOG_NONE = -1,
    EXE_LOG_DBG_INF,
    EXE_LOG_USR_INF,
    EXE_LOG_USR_IMP,
    EXE_LOG_USR_CRT,
    EXE_LOG_SYS_CRT,
    EXE_LOG_MAX,
};

class ExeLogger
{
public:
    static bool Init(const char* pszName, int nLvl, bool bOutputDbgString = false);
    static void UnInit(void);
    static void ChangeLvl(int nLvl);

	static void Log(int nLvl, const char* pszFunction, int nLine, const char* pFmt, ...);
private:
private:
    static IFxLogger* m_pLogger;
    static int m_nLvl;
    static bool m_bOutputDbgString;
    static IFxLock* m_pLock;
    static bool m_bInit;
};

#ifdef WIN32
#else
#define __FUNCTION__ __FILE__
#endif

#define DBG_INFO(pFmt, ...)        ExeLogger::Log(EXE_LOG_DBG_INF, __FUNCTION__, __LINE__, pFmt, ##__VA_ARGS__)  // 调试信息
#define USR_INFO(pFmt, ...)        ExeLogger::Log(EXE_LOG_USR_INF, __FUNCTION__, __LINE__, pFmt, ##__VA_ARGS__)  // 用户信息
#define USR_IMPORTANT(pFmt, ...)   ExeLogger::Log(EXE_LOG_USR_IMP, __FUNCTION__, __LINE__, pFmt, ##__VA_ARGS__)  // 玩家名\t重要信息
#define USR_CRITICAL(pFmt, ...)    ExeLogger::Log(EXE_LOG_USR_CRT, __FUNCTION__, __LINE__, pFmt, ##__VA_ARGS__)  // 玩家名\t错误信息
#define SYS_CRITICAL(pFmt, ...)    ExeLogger::Log(EXE_LOG_SYS_CRT, __FUNCTION__, __LINE__, pFmt, ##__VA_ARGS__)  // 系统信息

#endif //__EXELOGGER_H_NIJIE_2012_0907__

