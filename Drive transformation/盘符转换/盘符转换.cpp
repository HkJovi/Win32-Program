// �̷�ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>  
#include <Windows.h>  
#include <tchar.h>  
#include <stdio.h>  
int _tmain(int argc, _TCHAR * argv[])
{
	TCHAR drv = 0;
	TCHAR cDiskSymbol[] = _T("C:");
	for (drv = _T('C'); drv <= _T('Z'); drv++)
	{
		cDiskSymbol[0] = drv;
		{
			TCHAR szBuf[MAX_PATH] = { 0 };
			QueryDosDevice(cDiskSymbol, szBuf, MAX_PATH);
			_tprintf(_T("==== %s === %s  ===\n"), cDiskSymbol, szBuf);
		}
	}
	getchar();
	return 0;
}


