// Created by Nijie on 2014.07.23.
// Copyright (c) 2014 Nijie. All rights reserved.
// Use of this source code is governed by a GPL-2 license that can be found in the LICENSE file. 
//
#include "coder.h"
#include <string>

/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
**********/
// "liveMedia"
// Copyright (c) 1996-2010 Live Networks, Inc.  All rights reserved.
// Base64 encoding and decoding
// implementation


static char base64DecodeTable[256];
static const char base64EecodeTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

extern const char* Base64Encode(const char* pSrc)
{
	static char base64out[8092];
	base64out[0] = 0;
	if (pSrc == NULL)
	{
		return base64out;
	}

	int inlen = strlen(pSrc);
	unsigned int numOrig24BitValues = inlen/3;
	bool havePadding = inlen > numOrig24BitValues*3;
	bool havePadding2 = inlen == numOrig24BitValues*3 + 2;
	unsigned const numResultBytes = 4*(numOrig24BitValues + havePadding);
	if (numResultBytes >= 8091)
	{
		return base64out;
	}

	// Map each full group of 3 input bytes into 4 output base-64 characters:
	unsigned i;
	for (i = 0; i < numOrig24BitValues; ++i) 
	{
		base64out[4*i+0] = base64EecodeTable[(pSrc[3*i]>>2)&0x3F];
		base64out[4*i+1] = base64EecodeTable[(((pSrc[3*i]&0x3)<<4) | (pSrc[3*i+1]>>4))&0x3F];
		base64out[4*i+2] = base64EecodeTable[((pSrc[3*i+1]<<2) | (pSrc[3*i+2]>>6))&0x3F];
		base64out[4*i+3] = base64EecodeTable[pSrc[3*i+2]&0x3F];
	}

	// Now, take padding into account.  (Note: i == numOrig24BitValues)
	if (havePadding) 
	{
		base64out[4*i+0] = base64EecodeTable[(pSrc[3*i]>>2)&0x3F];
		if (havePadding2)
		{
			base64out[4*i+1] = base64EecodeTable[(((pSrc[3*i]&0x3)<<4) | (pSrc[3*i+1]>>4))&0x3F];
			base64out[4*i+2] = base64EecodeTable[(pSrc[3*i+1]<<2)&0x3F];
		} 
		else 
		{
			base64out[4*i+1] = base64EecodeTable[((pSrc[3*i]&0x3)<<4)&0x3F];
			base64out[4*i+2] = '=';
		}
		base64out[4*i+3] = '=';
	}

	base64out[numResultBytes] = 0;
	return base64out;
}

extern const char* Base64Decode(const char* pDst)
{
	static char base64out[8092];
	base64out[0] = 0;
	if (pDst == NULL)
	{
		return base64out;
	}

	static bool haveInitedBase64DecodeTable = false;
	if (!haveInitedBase64DecodeTable)
	{
		int i;
		for (i = 0; i < 256; ++i) base64DecodeTable[i] = (char)0x80;
		// default value: invalid

		for (i = 'A'; i <= 'Z'; ++i) base64DecodeTable[i] = 0 + (i - 'A');
		for (i = 'a'; i <= 'z'; ++i) base64DecodeTable[i] = 26 + (i - 'a');
		for (i = '0'; i <= '9'; ++i) base64DecodeTable[i] = 52 + (i - '0');
		base64DecodeTable[(unsigned char)'+'] = 62;
		base64DecodeTable[(unsigned char)'/'] = 63;
		base64DecodeTable[(unsigned char)'='] = 0;

		haveInitedBase64DecodeTable = true;
	}

	int k = 0;
	int jMax = strlen(pDst) - 3;
	// in case "in" is not a multiple of 4 bytes (although it should be)
	for (int j = 0; j < jMax; j += 4) 
	{
		if (k + 3 >= 8091)
		{
			base64out[0] = 0;
			return base64out;
		}
		unsigned char inTmp[4], outTmp[4];
		for (int i = 0; i < 4; ++i) 
		{
			inTmp[i] = pDst[i+j];
			outTmp[i] = base64DecodeTable[inTmp[i]];
			if ((outTmp[i]&0x80) != 0)
			{
				outTmp[i] = 0; // pretend the input was 'A'
			}
		}

		base64out[k++] = (outTmp[0]<<2) | (outTmp[1]>>4);
		base64out[k++] = (outTmp[1]<<4) | (outTmp[2]>>2);
		base64out[k++] = (outTmp[2]<<6) | outTmp[3];
	}

	base64out[k] = 0;

	return base64out;
}
