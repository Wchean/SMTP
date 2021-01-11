// Base64.h: interface for the Base64 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASE64_H__065F6C58_8C79_4840_8C6F_571F68CEC0DA__INCLUDED_)
#define AFX_BASE64_H__065F6C58_8C79_4840_8C6F_571F68CEC0DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<string>
using namespace std;
class Base64  
{
public:
	string Decode(const char* str,int length,int& outlength);
	string Encode(const unsigned char* str,int length);

};

#endif // !defined(AFX_BASE64_H__065F6C58_8C79_4840_8C6F_571F68CEC0DA__INCLUDED_)
