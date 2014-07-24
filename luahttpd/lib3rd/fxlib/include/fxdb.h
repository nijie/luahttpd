//  Created by Nijie on 2009/08/24.
//  Copyright (c) 2009 Nijie. All rights reserved.
//

#ifndef __FXDB_H_2009_0824__
#define __FXDB_H_2009_0824__

#include "version.h"
#include "fxmeta.h"

#define MAX_DBNAME_SIZE		            64
#define MAX_DBCHARACTSET_SIZE		    32

const char FXDB_MODULENAME[]        = "FXMySQLDB";

enum EFxDBCode
{
    FXDB_ERR_UNKNOWN    = -4,       // 未知错误
    FXDB_ERR_READER     = -3,       // 错误的数据结果参数
    FXDB_ERR_CONN       = -2,       // 链接错误
    FXDB_DISCONNECT     = -1,       // 断开链接
    FXDB_SUCCESS        = 0,        // 成功
    FXDB_NO_RESULT      = 1,        // 成功，无结果
    FXDB_HAS_RESULT     = 2         // 成功，有查询结果
};

struct SDBAccount{
    char                m_szHostName[MAX_DBNAME_SIZE];        
    char                m_szDBName[MAX_DBNAME_SIZE];          
    char                m_szLoginName[MAX_DBNAME_SIZE];       
    char                m_szLoginPwd[MAX_DBNAME_SIZE];        
	char                m_szCharactSet[MAX_DBCHARACTSET_SIZE];  
    UINT16              m_wConnPort;					          
};

struct SDBConnInfo
{    
    UINT32              m_dwDBId;           
	SDBAccount          m_stAccount; 
};

class IDataReader
{
public:
    virtual   ~IDataReader(){}
	
	virtual UINT32      GetRecordCount(void) = 0;
    
    virtual UINT32      GetFieldCount(void) = 0;
    
    virtual bool        GetFirstRecord(void) = 0;

    virtual bool        GetNextRecord(void) = 0;
	
    virtual const char* GetFieldValue(UINT32 dwIndex) = 0;
	
    virtual INT32       GetFieldLength(UINT32 dwIndex) = 0;
	
    virtual void        Release(void)=0;
};

class IDBConnection
{
public:	
    virtual   ~IDBConnection(){}

    virtual UINT32      EscapeString(const char* pszSrc, INT32 nSrcLen, char* pszDest, INT32 nDestLen) = 0;
    
	virtual INT32       Query(const char* pszSQL) = 0;
	
    virtual INT32       Query(const char* pszSQL, IDataReader** ppReader) = 0;
	
	virtual UINT32      GetLastError(void) = 0;
    
    virtual const char* GetLastErrorString(void) = 0;

	virtual UINT64		GetInsertId() = 0;
};

class IQuery 
{
public:
    virtual   ~IQuery(){}

    virtual INT32       GetDBId(void) = 0;
	
	virtual void        OnQuery(IDBConnection *poDBConnection) = 0;
	
    virtual void        OnResult(void) = 0;
	
    virtual void        Release(void) = 0;

	static UINT32		EscapeString(const char* pszSrc, INT32 nSrcLen, char* pszDest, INT32 nDestLen);
};

class IDBModule : public IFxMeta
{
public:
    virtual   ~IDBModule(){}

	virtual bool        Open(SDBConnInfo& DBInfo) = 0;
	
	virtual void        Close(UINT32 dwDBId) = 0;
    	
	virtual bool        AddQuery(IQuery *poQuery) = 0;
	
	virtual bool        Run(UINT32 dwCount = -1) = 0;
};

IDBModule *             FxDBGetModule();

typedef IDBModule *     (*PFN_FxDBGetModule)();

bool                    FxDBSetLogger(IFxLogger* poLogger, UINT32 dwLevel);

typedef bool            (*PFN_FxDBSetLogger)(IFxLogger* poLogger, UINT32 dwLevel);

#endif  // __FXDB_H_2009_0824__
