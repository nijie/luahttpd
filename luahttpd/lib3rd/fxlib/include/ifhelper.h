//  Created by Nijie on 2014/08/15.
//  Copyright (c) 2014 Nijie. All rights reserved.
//

#ifndef __IFHELPER_H_NIJIE_2014_0813__
#define __IFHELPER_H_NIJIE_2014_0813__

#include "version.h"
#include "fxtype.h"

#ifdef WIN32
typedef void *HANDLE;
#endif

class IFxLock
{
public:
    virtual  ~IFxLock(){}

    virtual void		Lock() = 0;
    virtual void        UnLock() = 0;
    virtual void        Release() = 0;
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

class FxThread
{
public:
	FxThread(bool bNeedWaitfor = true);
    virtual  ~FxThread();

    virtual void        CallBack() = 0;
    virtual void		Stop(void) = 0;	// 正常退出

    void				Resume(void);
    void				Suspend();
	bool				Start(bool bSuspend = false);
    bool				Kill(UINT32 dwExitCode); // 非法关闭
    bool				WaitFor(UINT32 dwWaitTime = FX_INFINITE);
    UINT32				GetThreadId(void);

private:
	static unsigned int __stdcall __StaticThreadFunc(void *arg);

private:
	bool                    m_bNeedWaitfor;
#ifdef WIN32
	HANDLE                  m_handle;			
	UINT32 		            m_dwThreadId;
#else
	pthread_t	            m_oPthread;
#endif
};

IFxLock*                    FxCreateThreadLock();

IFxLock*                    FxCreateThreadFakeLock();

void                        FxSleep(UINT32 dwTimeTick);

bool                        FxCreateDirectory(const char* pszDir);

#endif	// __IFHELPER_H_NIJIE_2014_0813__
