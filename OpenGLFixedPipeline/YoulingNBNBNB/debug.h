#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <consoleapi.h>

//��������̨���е����õķ���
void InitConsole() {
	AllocConsole(); 
	freopen("CONOUT$", "w", stdout);
}