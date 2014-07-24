//  Created by Nijie on 2009/08/17.
//  Copyright (c) 2009 Nijie. All rights reserved.
//

#ifndef __FXBASE_H_2009_0817__
#define __FXBASE_H_2009_0817__

#include "version.h"

typedef signed char         INT8;
typedef unsigned char       UINT8;
typedef signed short        INT16;
typedef unsigned short      UINT16;
typedef signed int          INT32;
typedef unsigned int        UINT32;
typedef signed long long    INT64;
typedef unsigned long long  UINT64;
#ifndef NULL
#define NULL 0
#endif

typedef struct 
{
    UINT32 m_dwSec;     ///< seconds
    UINT32 m_dwUsec;    ///< microsecond(1/1,000,000 second)
}STimeVal;

class IFxMeta
{
public:
    virtual  ~IFxMeta(void){}

    virtual void            AddRef(void) = 0;

    virtual UINT32          QueryRef(void) = 0;

    virtual void            Release(void) = 0;

    virtual const char *    GetModuleName(void) = 0;
};

#define LOGLV_NONE          0x0000
#define LOGLV_DEBUG         0x0001
#define LOGLV_INFO          (0x0001<< 1)
#define LOGLV_WARN          (0x0001<< 2)
#define LOGLV_CRITICAL      (0x0001<< 3)

#define HALF_GIGA    512*1024*1024
class IFxLogger
{
public:
	virtual  ~IFxLogger(){}

    /*
    Function:       Initialize.
    Param:
        pszName:        Logfile name.
        dwMaxSize:      Max file size.
    */
    virtual  bool Init(const char* pszName, bool bThrdSafe = true, UINT32 dwMaxSize = HALF_GIGA) = 0;

    virtual  bool LogText(const char *pszLog) = 0;

    virtual  bool LogBinary(const UINT8 *pLog, UINT32 dwLen) = 0;

    virtual  void Release(void) = 0;
};

class IFxLock
{
public:
    virtual  ~IFxLock(){}

    virtual void            Lock() = 0;

    virtual void            UnLock() = 0;

    virtual void            Release() = 0;
};

class FxLockImp
{
public:
	explicit FxLockImp(IFxLock* locker): m_pLocker(locker) 
	{
		if (NULL != m_pLocker)
		{
			m_pLocker->Lock();
		}
	}
	~FxLockImp() 
	{
		if (NULL != m_pLocker)
		{
			m_pLocker->UnLock();
		}
		m_pLocker = NULL;
	}

private:
	IFxLock* m_pLocker;
};

#define FX_INFINITE		    0xffffffff

class IFxThread
{
public:
    virtual  ~IFxThread(){}

    virtual void            ThrdFunc() = 0;

    virtual void            Stop() = 0;
};

class IFxThreadHandler
{
public:
    virtual  ~IFxThreadHandler(){}

    virtual void            Resume(void) = 0;

    virtual void            Suspend() = 0;

    virtual void            Stop(void) = 0;

    virtual bool            Kill(UINT32 dwExitCode) = 0;

    virtual bool            WaitFor(UINT32 dwWaitTime = FX_INFINITE) = 0;

    virtual UINT32          GetThreadId(void) = 0;

    virtual IFxThread*      GetThread(void) = 0;

    virtual void            Release(void) = 0;
};

class IFxTimer
{
public:
    virtual ~IFxTimer(){}

    virtual bool            OnTimer(int nMicroSecond, UINT32 dwEventId)     = 0;
};

class IFxTimerHandler
{
public:
    virtual ~IFxTimerHandler(){}

    virtual bool            Init(IFxTimer* poTimer) = 0;
    virtual void            Uninit()    = 0;
    virtual bool            Run()       = 0;
    virtual void            Stop()      = 0;
    virtual bool            AddTimer(int nMicroSecond)  = 0;
    virtual bool            AddTimer(int nMicroSecond, UINT32 dwEventId)    = 0;
    virtual bool            DelTimer(int nMicroSecond, UINT32 dwEventId)    = 0;
    virtual void            Release()   = 0;
    virtual INT64           GetMicroSecond()    = 0;
    virtual void            Sleep(int nMicroSecond)     = 0;
    virtual void            WakeUp()    = 0;
};

IFxLock*                    FxCreateThreadLock();

IFxLock*                    FxCreateThreadFakeLock();

IFxThreadHandler*           FxCreateThreadHandler(IFxThread* poThread, bool bNeedWaitfor, bool bSuspend = false);

void                        FxMakeDaemonProcess();

void                        FxGetTimeEx(STimeVal* pstTime);

void                        FxSleep(UINT32 dwMilliseconds);

bool                        FxCreateDirectory(const char* pszDir);

IFxLogger*                  FxCreateLogger();

IFxTimerHandler*            FxCreateTimer(IFxTimer* poTimer);

#endif
