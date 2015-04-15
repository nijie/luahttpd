// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __UTILITY_H_NIJIE_2012_0905__
#define __UTILITY_H_NIJIE_2012_0905__

#include "fxtype.h"
#ifdef WIN32
#include <WinSock2.h>
#include <Windows.h>
#include <direct.h>
#else
#include <stdlib.h>
#endif
#include <string>
#include <vector>
#include <time.h>

using namespace std;

#define FILE_PATH 512
#ifdef WIN32
#define chdir _chdir
#define snprintf _snprintf
#endif

struct SConnectionInfo 
{
	string		strIP;
	UINT16		wPort;
	UINT32		uSendBufSize;
	UINT32		uRecvBufSize;
};

inline int SpiltString(const string& str, char c, vector<string>& vec) 
{ 
	vec.clear(); 
	int nBegin = -1;
	int nEnd = 0;
	int nCount = 0;

	while (true)
	{ 
		nEnd = (int)str.find(c, ++nBegin); 
		if (nEnd == string::npos)
		{
			break; 
		}

		vec.push_back(str.substr(nBegin, nEnd - nBegin)); 
		nCount++;
		nBegin = nEnd; 
	}
	vec.push_back(str.substr(nBegin, str.size() - nBegin)); 
	nCount++;
	return nCount;
}

inline int SpiltToInt(const string& str, char c, vector<UINT32>& vec) 
{ 
	vec.clear(); 
	int nBegin = -1;
	int nEnd = 0;
	int nCount = 0;

	while (true)
	{ 
		nEnd = (int)str.find(c, ++nBegin); 
		if (nEnd == string::npos)
		{
			break; 
		}

		vec.push_back(atoi(str.substr(nBegin, nEnd - nBegin).c_str())); 
		nCount++;
		nBegin = nEnd; 
	}
	vec.push_back(atoi(str.substr(nBegin, str.size() - nBegin).c_str())); 
	nCount++;
	return nCount;
}

inline UINT32 SvrIdStr2Int(const char* pszId)
{
	UINT32 uRet = 0;
	vector<string> vec;
	string str = pszId;
	int nCount = SpiltString(str, '-', vec);
	for (int i = 0; i < nCount; i++)
	{
		uRet <<= 8;	// 左移8位
		int v = atoi(vec[i].c_str());
		uRet += v;
	}
	return uRet;
}

inline int GetRandom(int start, int end)
{
	if (start == end)
	{
		return start;
	}

	int min = start > end ? end : start;
	int max = start > end ? start : end;
	return (rand()) % (max - min + 1) + min;
}

inline UINT8 AddState(UINT8 val1, UINT8 val2)
{
	return val1 | val2;
}

inline UINT16 AddState(UINT16 val1, UINT16 val2)
{
	return val1 | val2;
}

inline UINT32 AddState(UINT32 val1, UINT32 val2)
{
	return val1 | val2;
}

inline UINT8 DelState(UINT8 val1, UINT8 val2)
{
	return val1 & ~val2;
}

inline UINT16 DelState(UINT16 val1, UINT16 val2)
{
	return val1 & ~val2;
}

inline UINT32 DelState(UINT32 val1, UINT32 val2)
{
	return val1 & ~val2;
}

inline bool HasState(UINT8 val, UINT8 comp)
{
	UINT8 v = val & comp;
	if (v == comp)
	{
		return true;
	}
	return false;
}

inline bool HasState(UINT16 val, UINT16 comp)
{
	UINT16 v = val & comp;
	if (v == comp)
	{
		return true;
	}
	return false;
}

inline bool HasState(UINT32 val, UINT32 comp)
{
	UINT32 v = val & comp;
	if (v == comp)
	{
		return true;
	}
	return false;
}

#ifndef WIN32 
// 返回自系统开机以来的毫秒数（tick）  
unsigned long GetTickCount()  
{  
	struct timespec ts;  
	clock_gettime(CLOCK_MONOTONIC, &ts);  
	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);  
} 
#endif

inline UINT32 GetCurTime()
{
#ifdef WIN32
	return (UINT32)_time32(NULL);
#else
	return (UINT32)time(NULL);
#endif
}

inline const char* GetHttpTime(UINT32 uTime)
{
	static char szbuff[128];
	__time32_t t = (__time32_t)uTime;
	tm * gmTime = _gmtime32(&t);

	strftime(szbuff, 127, " %a, %d %b %Y %X GMT", gmTime);
	return szbuff;
}

inline UINT32 MakeU32(UINT16 hWord, UINT16 lWord)
{
	UINT32 ret = hWord;
	ret <<= 16;
	ret += lWord;
	return ret;
}

inline void ParseU32(UINT32 uValue, UINT16& hWord, UINT16& lWord)
{
	lWord = (UINT16)(uValue & 0xffff);
	hWord = (UINT16)(uValue >> 16);
}

inline UINT32 MakeTimeU32(tm& t)
{
	UINT32 time = (UINT32)mktime(&t);
	return time;
}

inline bool mbs2wcs(const char* pSrc, wchar_t* pdst, int count)
{
	int ret = ::MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, pSrc, -1, pdst, count);
	if (ret < count)
	{
		pdst[ret] = 0;
	}

	return true;
}

inline bool mbs2utf8(const char* pSrc, char* pdst, int count)
{
	wchar_t lpszW[4096] = {0};  
	int wlen = MultiByteToWideChar(CP_ACP, 0, pSrc, (int)strlen(pSrc), lpszW, 4095);  
	// convert an widechar string to utf8  
	int utf8Len = WideCharToMultiByte(CP_UTF8, 0, lpszW, wlen, pdst, count, NULL, NULL);  
	if (utf8Len < count)
	{
		pdst[utf8Len] = 0;
	}

	return true;
}

inline bool utf82mbs(const char* pSrc, char* pdst, int count)
{
	wchar_t lpszW[4096] = {0};  
	int wlen = MultiByteToWideChar(CP_UTF8, 0, pSrc, (int)strlen(pSrc), lpszW, 4095);  
	int ret = WideCharToMultiByte(CP_ACP,0,lpszW,wlen,pdst,count,NULL,NULL);
	if (ret < count)
	{
		pdst[ret] = 0;
	}
	return true;
}

inline bool wcs2mbs(const wchar_t* pSrc, char* pdst, int count)
{
	int ret = ::WideCharToMultiByte(CP_ACP, NULL, pSrc, -1, pdst, count, NULL, NULL);
	if (ret < count)
	{
		pdst[ret] = 0;
	}

	return true;
}

inline int bit2int(char *array,int strlen,int *mask,int last_iterator)
{
	int temp=0;
	for (int i = strlen-1; i >= 0; i--)
	{
		temp += (1 & (array[i] - '0')) * mask[last_iterator--];
	}
	return temp;
}

inline int countbit(int n)
{
	int count=0;
	while(n)
	{
		n = n & (n-1);
		++count;
	}
	return  count;
}

template <size_t size>
void copystr(char (&dst)[size], const char* src)
{
	strcpy_s(dst, src);
}

#endif	// __UTILITY_H_NIJIE_2012_0905__
