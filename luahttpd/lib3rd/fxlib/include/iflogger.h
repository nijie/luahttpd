//  Created by Nijie on 2014/08/15.
//  Copyright (c) 2014 Nijie. All rights reserved.
//

#ifndef __IFLOGGER_H_NIJIE_2014_0815__
#define __IFLOGGER_H_NIJIE_2014_0815__

#include "version.h"
#include "fxtype.h"

#define HALF_GIGA    512*1024*1024

class IFxLogger
{
public:
	virtual  ~IFxLogger(){}

    virtual  bool Init(const char* pszName, bool bThrdSafe = true, UINT32 dwMaxSize = HALF_GIGA) = 0;

    virtual  bool LogText(const char *pszLog) = 0;

    virtual  bool LogBinary(const UINT8 *pLog, UINT32 dwLen) = 0;

    virtual  void Release(void) = 0;
};

IFxLogger*                  FxCreateLogger();

#endif	// __IFLOGGER_H_NIJIE_2014_0815__
