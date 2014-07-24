// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "CrashHelper.h"
// #include "ijl.h"

#include<process.h>
#include<Tlhelp32.h>
#include<DbgHelp.h>
#include <stdio.h>

#pragma comment(lib, "Dbghelp.lib")
// #pragma comment(lib, "ijl15.lib")

//////////////////////////////////////////////////////////////////
//异常处理线程
DWORD WINAPI CrashDumpThreadProc(LPVOID lpParamter)
{
	SetUnhandledExceptionFilter( (LPTOP_LEVEL_EXCEPTION_FILTER)CrashHelper::UnhandledExceptionFilterInProcess);

	CrashHelper::Instance()->DumpProgram( (_EXCEPTION_POINTERS*)lpParamter);

	return 0;
}

DWORD CrashHelper::ms_dwCreashThreadId;

//异常处理流程中的错语处理函数
LONG WINAPI CrashHelper::UnhandledExceptionFilterInProcess(_EXCEPTION_POINTERS* pExceptionInfo)
{
	//如果要异常处理过程中再发生异常,只有直接退出了
	return EXCEPTION_EXECUTE_HANDLER;
}

LONG WINAPI CrashHelper::UnhandledExceptionFilter(_EXCEPTION_POINTERS* pExceptionInfo)
{
	//发生异常时,尽量挂起此进程的其它线程,以免发生意外
	HANDLE hThreadList = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	THREADENTRY32 te = {0};
	te.dwSize = sizeof(THREADENTRY32);

	if (Thread32First(hThreadList, &te) )
	{
		typedef HANDLE (*FN_OpenThread_DEF)(DWORD dwDesiredAccess, BOOL bInheritHandle, DWORD dwThreadId);

		static HINSTANCE hModule = LoadLibraryA("kernel32.dll");
		static FN_OpenThread_DEF pfnOpenThread = NULL;
		if ( NULL != hModule && NULL == pfnOpenThread)
		{
			pfnOpenThread = (FN_OpenThread_DEF)GetProcAddress( hModule, "OpenThread");
		}

		do 
		{
			if (te.th32OwnerProcessID == GetCurrentProcessId() && te.th32ThreadID != GetCurrentThreadId())
			{
				if (NULL != pfnOpenThread)
				{
					HANDLE hThread = pfnOpenThread(THREAD_SUSPEND_RESUME, FALSE, te.th32ThreadID);
					if (hThread)
					{
						DWORD dwResult = SuspendThread(hThread);
						CloseHandle(hThread);
					}
				}
			}

		} while ( Thread32Next(hThreadList, &te));

	}
	CloseHandle(hThreadList);

	ms_dwCreashThreadId = GetCurrentThreadId();

	DWORD dwThread;
	HANDLE hThread = CreateThread( NULL, 0, CrashDumpThreadProc, (LPVOID)pExceptionInfo, 0, &dwThread);
	if(hThread)
	{
		CloseHandle(hThread);
	}
	else
	{
		ExitProcess(1);
	}

	// 挂起主线程
	SuspendThread(GetCurrentThread());

	return EXCEPTION_EXECUTE_HANDLER;
}

bool CrashHelper::Initalize()
{
	SetUnhandledExceptionFilter( UnhandledExceptionFilter);
	return true;
}

bool CrashHelper::DumpProgram( _EXCEPTION_POINTERS * pExceptionInfo )
{
	char szFileName[64];
	SYSTEMTIME st;
	::GetLocalTime(&st);
	sprintf_s( szFileName, 64, ".\\%04d-%02d-%02d-%02d-%02d-%02d.dmp", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond );

	MINIDUMP_EXCEPTION_INFORMATION		sException;
	if(pExceptionInfo)
	{
		sException.ClientPointers	= TRUE;
		sException.ThreadId			= ms_dwCreashThreadId ? ms_dwCreashThreadId : GetCurrentThreadId();
		sException.ExceptionPointers = pExceptionInfo;
	}

	HANDLE hFile = CreateFileA( szFileName, GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if( hFile == NULL )
	{
		return false;
	}

	BOOL b = MiniDumpWriteDump(
		GetCurrentProcess(),
		GetCurrentProcessId(),
		hFile,
		(MINIDUMP_TYPE)(MiniDumpWithFullMemory),	//MiniDumpFilterMemory
		(pExceptionInfo ? &sException : NULL),
		NULL,
		NULL
		);

	CloseHandle(hFile);

	ExitProcess(1);

    return (TRUE == b) ? true : false;
}

/*
bool CrashHelper::ScreenShot(const char* pszFileName)
{
	HDC hSrcDC, hMemDC;
	HBITMAP hBitmap, hOldBitmap;

	hSrcDC = CreateDC("DISPLAY", NULL, NULL, NULL);
	if (hSrcDC == NULL)
	{
		return false;
	}

	int nMaxWidth = GetDeviceCaps(hSrcDC, HORZRES);
	int nMaxHeight = GetDeviceCaps(hSrcDC, VERTRES);

	hMemDC = CreateCompatibleDC(hSrcDC);
	if (hMemDC == NULL)
	{
		DeleteDC(hSrcDC);
		return false;
	}

	hBitmap = CreateCompatibleBitmap(hSrcDC, nMaxWidth, nMaxHeight);
	if (hBitmap == NULL)
	{
		DeleteDC(hSrcDC);
		DeleteDC(hMemDC);
		return false;
	}

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	bool bResult = BitBlt(hMemDC, 0, 0, nMaxWidth, nMaxHeight, hSrcDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBitmap);

	DeleteDC(hSrcDC);
	DeleteDC(hMemDC);

	if (!bResult)
	{	
		DeleteObject(hBitmap);
		return false;
	}

	void* pBuf = malloc(nMaxWidth * nMaxHeight * 3);
	BITMAPINFO bmi;
	memset( &bmi, 0, sizeof(bmi));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = nMaxWidth;
	bmi.bmiHeader.biHeight = -nMaxHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 24;
	bmi.bmiHeader.biCompression = BI_RGB;

	HDC hdc = GetDC(NULL);
	int nResult = GetDIBits(hdc, hBitmap, 0, nMaxHeight, pBuf, &bmi, DIB_RGB_COLORS);
	ReleaseDC(NULL, hdc);
	DeleteObject(hBitmap);

	if (nResult < nMaxHeight)
	{
		free(pBuf);
		return false;
	}

	// 压缩成JPG
	JPEG_CORE_PROPERTIES sJPGOptions;
	ZeroMemory( &sJPGOptions, sizeof(sJPGOptions) );
	if( ijlInit( &sJPGOptions ) != IJL_OK )
	{ 
		free(pBuf); 
		return false; 
	}

	sJPGOptions.DIBColor		= IJL_BGR;
	sJPGOptions.DIBChannels		= 3;
	sJPGOptions.DIBWidth		= nMaxWidth;
	sJPGOptions.DIBHeight		= nMaxHeight;
	sJPGOptions.DIBBytes		= (unsigned char *)pBuf;

	sJPGOptions.JPGColor		= IJL_YCBCR;
	sJPGOptions.JPGChannels		= 3;
	sJPGOptions.JPGWidth		= nMaxWidth;
	sJPGOptions.JPGHeight		= nMaxHeight;
	sJPGOptions.jquality		= 50;
	sJPGOptions.JPGSubsampling	= IJL_411;
	sJPGOptions.JPGSizeBytes	= nMaxWidth*nMaxHeight*3+100;

	void *pScreenShot = malloc(sJPGOptions.JPGSizeBytes);
	sJPGOptions.JPGBytes		= (unsigned char *)(pScreenShot);

	if( ijlWrite( &sJPGOptions, IJL_JBUFF_WRITEWHOLEIMAGE ) != IJL_OK )
	{
		free(pBuf);
		free(pScreenShot);
		return false;
	}
	int iJPGSize = sJPGOptions.JPGSizeBytes;
	ijlFree(&sJPGOptions);
	free(pBuf);


	//写文件
	FILE * f = fopen(pszFileName,"wb");
	fwrite(pScreenShot,1,iJPGSize,f);
	fclose(f);


	free(pScreenShot);

	return true;
}
*/
