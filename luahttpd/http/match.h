// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#ifndef __MATCH_H_NIJIE_2013_1120__
#define __MATCH_H_NIJIE_2013_1120__

#include <vector>

using namespace std;

typedef unsigned char MTYPE;

#define NO_MATCH_CHAR  0

class MatchTree
{
public:
	MatchTree(char k, MTYPE v = NO_MATCH_CHAR)
	{
		m_k = k;
		m_v = v;
		m_vec.clear();
	}

	~MatchTree()
	{
		int nCount = (int)m_vec.size();
		for (int i = 0; i < nCount; ++i)
		{
			MatchTree* pTree = m_vec[i];
			if (NULL != pTree)
			{
				delete pTree;
			}
		}
		m_vec.clear();
	}

	bool	add(const char* psz, MTYPE v = NO_MATCH_CHAR)
	{
		if (NULL == psz)
		{
			return false;
		}

		const char k = *psz;
		if (0 == k)
		{
			return false;
		}

		bool bNext = false;
		if (*(psz + 1) != 0)
		{
			bNext = true;
		}

		if (!bNext)
		{
			m_v = v;
			return true;
		}

		MatchTree* node = NULL;

		int nCount = (int)m_vec.size();
		for (int i = 0; i < nCount; ++i)
		{
			node = m_vec[i];
			if (node == NULL)
			{
				return false;
			}
			if (node->get() == k)
			{
				return node->add(psz + 1, v);
			}
		}

		node = new MatchTree(k);
		if (NULL == node)
		{
			return false;
		}

		m_vec.push_back(node);
		return node->add(psz + 1, v);
	}

	MTYPE	find(const char*& pszBuf)
	{
		if (NULL == pszBuf)
		{
			return NO_MATCH_CHAR;
		}

		const char k = *pszBuf;
		++pszBuf;
		if (*(pszBuf) == 0)
		{
			return m_v;
		}

		MTYPE v = NO_MATCH_CHAR;
		int nCount = (int)m_vec.size();
		for (int i = 0; i < nCount; ++i)
		{
			MatchTree* pTree = m_vec[i];
			if (NULL == pTree)
			{
				continue;
			}

			if (pTree->get() == k)
			{
				v = pTree->find(pszBuf);
				break;
			}
		}

		if (NO_MATCH_CHAR == v)
		{
			return m_v;
		}
		return v;
	}

	char	get()
	{
		return m_k;
	}

private:
	char	m_k;
	MTYPE	m_v;
	vector<MatchTree*>	m_vec;
};


#endif	// __MATCH_H_NIJIE_2013_1120__

