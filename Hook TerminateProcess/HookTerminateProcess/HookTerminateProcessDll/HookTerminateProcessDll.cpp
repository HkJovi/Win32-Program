// HookTerminateProcess.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "APIHook.h"
#include "stdio.h" 

#define DllExport extern "C"__declspec(dllexport)

extern CAPIHook g_TerminateProcess;
extern CAPIHook g_OpenProcess;
extern CAPIHook g_MessageBoxA;
#pragma data_seg("Shared")
HHOOK g_hHook = NULL;
#pragma data_seg()
#pragma comment(linker,"/SECTION:Shared,RWS")

bool WINAPI Hook_TerminateProcess(HANDLE hProcess, UINT nExitCode)
{
	//typedef bool (WINAPI *PFNTERMINATEPROCESS)(HANDLE, UINT);
	//char szPathName[256];
	//::GetModuleFileName(NULL, szPathName, 256);
	//char sz[2048];
	//wsprintf(sz, "���̺�:%d   %s, ���̾��: %X, �˳�����: %d\n", ::GetCurrentProcess(), szPathName, hProcess, nExitCode);
	//COPYDATASTRUCT cds = { ::GetCurrentProcessId(), strlen(sz) + 1, sz };

	//if (::SendMessage(::FindWindow(NULL, "HookTerminateProcess1"), WM_COPYDATA, 0, (LPARAM)&cds) != -1)
	//{
	//	return ((PFNTERMINATEPROCESS)(PROC)g_TerminateProcess)(hProcess, nExitCode);
	//}
	MessageBox(NULL, "������ɱ������", "��ʾ", 0);
	return true;

}
CAPIHook g_TerminateProcess("kernel32.dll", "TerminateProcess", (PROC)Hook_TerminateProcess,TRUE);


HANDLE WINAPI Hook_OpenProcess(
	DWORD dwDesiredAccess,
	BOOL bInheritHandle,
	DWORD dwProcessId
	)
{
	MessageBox(NULL, "������ɱ������1", "��ʾ", 0);
	return NULL;
}

CAPIHook g_OpenProcess("kernel32.dll", "OpenProcess", (PROC)Hook_OpenProcess, TRUE);

int Hook_MessageBox(HWND hWnd,
	LPCTSTR lpText,
	LPCTSTR lpCaption,
	UINT uType
	)
{
	MessageBox(NULL, "������", "��ʾ", 0);
	return NULL;
}
CAPIHook g_MessageBox("USER32.dll", "MessageBoxA", (PROC)Hook_MessageBox, TRUE);


DllExport int SetSysHook(bool bInstall, DWORD dwThreadId);
//extern "C" HMODULE __declspec(dllexport)ModuleFromAddress(void *pv);
//DllExport LRESULT WINAPI GetMsgProc(int code, WPARAM wParam, LPARAM lParam);

static HMODULE ModuleFromAddress(void *pv)
{
	MEMORY_BASIC_INFORMATION mbi;
	if (::VirtualQuery(pv, &mbi, sizeof(mbi)) != 0)
	{
		return (HMODULE)mbi.AllocationBase;
	}
	return NULL;
}
static LRESULT WINAPI GetMsgProc(int code, WPARAM wParam, LPARAM lParam)
{
	return ::CallNextHookEx(g_hHook, code, wParam, lParam);
}


int  SetSysHook(bool bInstall, DWORD dwThreadId)
{
	bool bOk;
	if (bInstall)
	{
		g_hHook = ::SetWindowsHookEx(WH_GETMESSAGE, GetMsgProc, ModuleFromAddress(GetMsgProc), dwThreadId);
		bOk = (g_hHook != NULL);
	}
	else
	{
		::UnhookWindowsHookEx(g_hHook);
		bOk = (g_hHook == NULL);
	}
	return bOk;

}

