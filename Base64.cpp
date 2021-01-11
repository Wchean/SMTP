// Base64.cpp: implementation of the Base64 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SMTP.h"
#include "Base64.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



string Base64::Encode(const unsigned char *str, int length)
{
		//编码表
	const char EncodeTable[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	//返回值
	string strEncode;

	unsigned char Tmp[3]={0};
	int LineLength=0,L=length/3;

	for(int i=0;i<L;++i)
	{
        Tmp[0] = *str++;
        Tmp[1] = *str++;
        Tmp[2] = *str++;

        strEncode+= EncodeTable[Tmp[0] >> 2];
        strEncode+= EncodeTable[((Tmp[0] << 4) | (Tmp[1] >> 4)) & 0x3F];
        strEncode+= EncodeTable[((Tmp[1] << 2) | (Tmp[2] >> 6)) & 0x3F];
        strEncode+= EncodeTable[Tmp[2] & 0x3F];
		if(LineLength+=4,LineLength==76) 
		{
			strEncode+="\r\n";
			LineLength=0;
		}
	}

	//对剩余数据进行编码
	int Mod=length % 3;
	if(Mod==1)
	{
        Tmp[0] = *str++;
        strEncode+= EncodeTable[(Tmp[0] & 0xFC) >> 2];//	取前6位，最高位补2个0
        strEncode+= EncodeTable[((Tmp[0] & 0x03) << 4)];//取后2位，补6个0
        strEncode+= "==";
	}
	else if(Mod==2)
	{
		Tmp[0] = *str++;
		Tmp[1] = *str++;
		strEncode+= EncodeTable[(Tmp[0] & 0xFC) >> 2];
		strEncode+= EncodeTable[((Tmp[0] & 0x03) << 4) | ((Tmp[1] & 0xF0) >> 4)];
		strEncode+= EncodeTable[((Tmp[1] & 0x0F) << 2)];
		strEncode+= "=";
	}
	
	return strEncode;
}

string Base64::Decode(const char *str, int length, int &outlength)
{
	//解码表
	const char DecodeTable[] =
	{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		62, // '+'
		0, 0, 0,
		63, // '/'
		52, 53, 54, 55, 56, 57, 58, 59, 60, 61, // '0'-'9'
		0, 0, 0, 0, 0, 0, 0,
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,
		13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, // 'A'-'Z'
		0, 0, 0, 0, 0, 0,
		26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, // 'a'-'z'
	};

	//返回值
	string strDecode;

    int nValue;
    int i= 0;
 
    while (i < length)
    {
        if (*str != '\r' && *str!='\n')
        {
            nValue = DecodeTable[*str++] << 18;
            nValue += DecodeTable[*str++] << 12;	//拼接两个，有效位为24-19，18-13
			strDecode+=(nValue & 0x00FF0000) >> 16;
            outlength++;
 
            if (*str != '=')
            {
                nValue += DecodeTable[*str++] << 6;
				strDecode+=(nValue & 0x0000FF00) >> 8;
                outlength++;
 
                if (*str != '=')
                {
                    nValue += DecodeTable[*str++];
					strDecode+=nValue & 0x000000FF;
                    outlength++;
                }
            }
            i += 4;
        }
        else// 回车换行,跳过
        {
            str++;
            i++;
        }
     }
	return strDecode;
}

