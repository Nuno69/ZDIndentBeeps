#pragma once
#include<windows.h>
#include<regex>

int WINAPI Init();
int WINAPI TextPreprocess(wchar_t* oldString, wchar_t* newString);