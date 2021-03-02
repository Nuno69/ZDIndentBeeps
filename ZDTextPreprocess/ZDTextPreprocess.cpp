#include "ZDTextPreprocess.h"
UINT g_enabled;
UINT g_basefreq;
UINT g_hzperspace;
UINT g_beeplength;
int WINAPI Init()
{
	g_enabled = GetPrivateProfileIntW(L"set", L"enabled", 0, L"c:\\set.ini");
	g_basefreq = GetPrivateProfileIntW(L"set", L"basefreq", 240, L"c:\\set.ini");
	g_hzperspace = GetPrivateProfileIntW(L"set", L"hzperspace", 30, L"c:\\set.ini");
	g_beeplength = GetPrivateProfileIntW(L"set", L"beeplength", 100, L"C:\\set.ini");
	Beep((DWORD)g_basefreq, (DWORD)g_beeplength);
	return 1;
}

int WINAPI TextPreprocess(wchar_t* oldString, wchar_t* newString)
{
	auto l_messagelength = wcslen(oldString);
	DWORD l_numofspaces = 0;
	DWORD l_finalbeepfrequency = 0;
	for (size_t i = 0; i = l_messagelength; i++)
	{
		if (isspace((int)oldString[i]) == 0)
		{
			break;
		}
		else
		{
			l_numofspaces += 1;
		}
	}
	if (l_numofspaces == 0)
	{
		return 0;
	}
	else
	{
		l_finalbeepfrequency = g_basefreq + l_numofspaces * g_hzperspace;
		Beep(l_finalbeepfrequency, g_beeplength);
		return 0;
	}
}