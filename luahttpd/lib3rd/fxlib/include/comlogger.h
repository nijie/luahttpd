//  Created by Nijie on 2009/08/24.
//  Copyright (c) 2009 Nijie. All rights reserved.
//

#ifndef __LOGGER_H_2009_0824__
#define __LOGGER_H_2009_0824__

#include <stdio.h>
#include "fxmeta.h"

class FxComLogger
{
public:
    FxComLogger();
    virtual ~FxComLogger();
    void            SetLogger(IFxLogger* pLogger);

    void            Critical(const char *format, ...);
    void            Info(const char *format, ...);
    void            Warn(const char *format, ...);
    void            Debug(const char *format, ...);

private:
    void            __Log(UINT32 dwLevel, const char *pszFormat, va_list argptr);

protected:    
    char*           m_aszLogPrefix[9];
    IFxLogger*      m_pLogger;
};

#endif  // __LOGGER_H_2009_0824__
