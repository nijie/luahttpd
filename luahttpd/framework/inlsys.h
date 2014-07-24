// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __INLSYS_H_NIJIE_2012_0906__
#define __INLSYS_H_NIJIE_2012_0906__

#ifdef WIN32

#include <stdio.h>
#include <tchar.h>

#include <hash_map>
using namespace stdext;

#else

#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h> 
#include <signal.h> 
#include <sys/time.h>
#include <errno.h>
#include <arpa/inet.h>
//#include <sys/socket.h>
//#include <netinet/in.h>

#include <ext/hash_map>
using namespace __gnu_cxx;
#endif

#endif	// __INLSYS_H_NIJIE_2012_0906__
