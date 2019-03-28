// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __SESSION_H_NIJIE_2014_0603__
#define __SESSION_H_NIJIE_2014_0603__

#include "json/json.h"
#include <string>
#include "fxtype.h"

using namespace std;

struct SSessionTime
{
	unsigned int	uCreateTime;
	unsigned int	uDestroyTime;
};

class Session
{
public:
	Session();
	~Session();

	bool			init(uint64 sid);
	void			reset();

	uint64			getSId();

	bool			loadData(const char* pData, unsigned int len);
	string			getData();
	void			setDestroyTime(unsigned int uTime);
	bool			canClear(unsigned int interval);

	void			save();

	// export begin
	unsigned int	getDestroyTime();
	void			setKeepTime(unsigned int uTime);
	bool			set(const char* pKey, const char* pVal);
	const char*		get(const char* pKey);
	const char*		id();
	unsigned int	getId();
	// export end

private:
	uint64			m_sid;
	int				m_interval;	// 保存时间间隔

	bool			m_bDirty;	// 是否有脏数据
	unsigned int	m_uDestroyTime; // 销毁时间
	Json::Value		m_value;
};

#endif	// __SESSION_H_NIJIE_2014_0603__
