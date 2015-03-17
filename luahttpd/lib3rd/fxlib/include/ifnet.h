//  Created by Nijie on 2009/09/01.
//  Copyright (c) 2009 Nijie. All rights reserved.
//

#ifndef __IFNET_H_2009_0901__
#define __IFNET_H_2009_0901__

#ifdef WIN32
#include <WinSock2.h>

#ifdef   FXN_DLLCLASS
#define  DLLCLASS_DECL           __declspec(dllexport)   
#else
#define  DLLCLASS_DECL           __declspec(dllexport)   
#endif

#ifdef FXN_STATICLIB
#undef  DLLCLASS_DECL
#define DLLCLASS_DECL
#endif

#else
#define SOCKET UINT32
#define DLLCLASS_DECL
#define INVALID_SOCKET UINT32(-1)
#endif

#include "version.h"
#include "fxtype.h"

class FxConnection;

#define LINUX_NETTHREAD_COUNT   2   // linux默认网络线程数,Windows默认采用cpu个数的2倍
#define MAX_CONNECTION_COUNT    1024
#define MAX_NETEVENT_PERSOCK    1024

enum ENetErrCode{
    NET_RECVBUFF_ERROR  = -7,
    NET_CONNECT_FAIL    = -6,
    NET_SYSTEM_ERROR    = -5, 
    NET_RECV_ERROR      = -4, 
    NET_SEND_ERROR      = -3, 
    NET_SEND_OVERFLOW   = -2,
    NET_PACKET_ERROR    = -1,
    NET_SUCCESS         = 0
};

enum ESessionOpt
{
    ESESSION_SENDLINGER = 1,    // 发送延迟，直到成功，或者30次后，默认不打开
	ESESSION_TCP_NODELAY,		// TCP 选项，是否启用Nagle算法，默认关闭，即启用了Magle算法
	ESESSION_RELEASE_LOWBUFF,	// 释放底层buff，可以不释放以便重复利用，调用此接口是为了解决有些连接Buff比较大，数量又比较少的情况
};

enum ENetOpt
{
    ENET_MAX_CONNECTION = 1,    // 最大连接数
    ENET_MAX_TOTALEVENT,        // 每个Socket的最大事件数量
};

class DLLCLASS_DECL FxSession	// 网络连接会话类
{
public:
    FxSession();
    virtual ~FxSession();

    virtual void        OnConnect(void) = 0;						// 网络连接成功回调接口

    virtual void        OnClose(void) = 0;							// 网络连接关闭、断开回调接口

    virtual void        OnError(UINT32 dwErrorNo) = 0;				// 网络连接错误回调接口

    virtual void        OnRecv(const char* pBuf, UINT32 dwLen) = 0;	// 网络连接消息接收回调接口

    virtual void        Release(void) = 0;							// 该会话类释放回调接口，以便达到内存哪里分配，哪里释放的要求

    virtual char*       GetRecvBuf() = 0;							// 获得会话接收缓冲内存回调接口

    virtual UINT32      GetRecvSize() = 0;							// 获得会话接收缓冲内存大小回调接口

    virtual const char* GetRemoteIPStr();							// 获得网络连接对方ip地址接口

    virtual UINT32      GetRemotePort();							// 获得网络连接对方端口接口

    virtual bool        Send(const char* pBuf,UINT32 dwLen);		// 网络连接发送接口

    virtual void        Close(void);								// 关闭该网络连接会话接口

    virtual bool        Reconnect(void);							// 重连

    virtual bool        IsConnected(void);							// 判断是否连接上

    virtual void        Init(FxConnection* poConnection);

    virtual bool        SetSessionOpt(ESessionOpt eOpt, bool bSetting);	// 设置属性接口

    virtual FxConnection*   GetConnection(void);

private:
    FxConnection*        m_poConnection;
};

// 会话工厂类
class IFxSessionFactory
{
public:
	virtual ~IFxSessionFactory() {}

	// 创建会话虚接口
    virtual FxSession*   CreateSession() = 0;
};

class IFxNet
{
public:
    virtual ~IFxNet() {}

	// 设置全局属性
    virtual bool        SetNetOpt(ENetOpt eOpt, int nValue) = 0;
    
	// 初始化
	virtual bool        Init(int nThread = 1) = 0;

	// 消息处理主循环
    virtual bool        Run(UINT32 dwCount) = 0;

	// 释放
    virtual void        Release() = 0;

	// 连接
    virtual SOCKET      Connect(FxSession* poSession, UINT32 dwIP, UINT16 wPort, UINT32 dwRecvSize, UINT32 dwSendSize, bool bReconnect = false, bool bHead = true, int nEventPerSocket = MAX_NETEVENT_PERSOCK) = 0;
    
	// 监听
	virtual bool        Listen(IFxSessionFactory* poFactory, UINT32 dwIP, UINT16 wPort, UINT32 dwRecvSize, UINT32 dwSendSize, bool bHead = true, int nEventPerSocket = MAX_NETEVENT_PERSOCK) = 0;

private:

};

IFxNet* FxNetGetModule();

typedef IFxNet* (*PFN_FxNetGetModule)();


#endif  // __IFNET_H_2009_0901__

