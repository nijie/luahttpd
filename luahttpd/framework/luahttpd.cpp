// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
// lhttpd.cpp : 定义控制台应用程序的入口点。
//
#ifdef WIN32
#include <WinSock2.h>
#include "CrashHelper.h"
#endif
#include "stdafx.h"
#include "exelogger.h"
#include "serverwork.h"
#include "utility.h"

int main()
{
#ifdef WIN32
	CrashHelper::Instance()->Initalize();

	__try
#endif
	{
		srand(GetTickCount());
		ExeLogger::Init("GameServer", EXE_LOG_DBG_INF);

		if (!ServerWork::Instance().init())
		{
			SYS_CRITICAL("ServerWork Init Failed!");
			printf("ServerWork Init Failed!");
			return 1;
		}

		ServerWork::Instance().run();

		ServerWork::Instance().uninit();
	}
#ifdef WIN32
	__except(GetExceptionCode() == STATUS_STACK_OVERFLOW ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH)
	{
		CrashHelper::Instance()->DumpProgram(NULL);
		return 0;
	}
#endif
	return 0;
}

