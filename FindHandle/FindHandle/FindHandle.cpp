// FindHandle.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Core.h"
#include <iostream>
#include <string.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	NTQUERYSYSTEMINFORMATION NtQuerySystemInformatuion = (NTQUERYSYSTEMINFORMATION)GetProcAddress(GetModuleHandle(_T("ntdll.dll")), "NtQuerySystemInformation");
	NTDUPLICATEOBJECT NtDuplicateObject = (NTDUPLICATEOBJECT)GetProcAddress(GetModuleHandle(_T("ntdll.dll")), "NtDuplicateObject");
	NTQUERYOBJECT NtQueryObject = (NTQUERYOBJECT)GetProcAddress(GetModuleHandle(_T("ntdll.dll")), "NtQueryObject");
	
	NTSTATUS status;
	HANDLE hProcess;  //Դ���̾��
	HANDLE hDupHandle; //���Ƶľ��
	ULONG ulPID = 772;  //Ҫ���ʵ�PID
	PSYSTEM_HANDLE_INFORMATION pSystemHandleInfo;   //�����Ϣ
	ULONG ulSystemHandleInfoSize = 0x10000;  //64K
	ULONG ulObjectTypeInfoSize = 0x1000;
	ULONG ulObjectNameInfoSize = 0x1000;

	if (NtQueryObject == NULL || NtDuplicateObject == NULL || NtQuerySystemInformatuion == NULL)
	{
		cout << "GetProcAddress filed!" << ulPID << endl;
	}
	setlocale(LC_ALL, "chs");
	pSystemHandleInfo = (PSYSTEM_HANDLE_INFORMATION)malloc(ulSystemHandleInfoSize);

	if (!(hProcess = OpenProcess(PROCESS_DUP_HANDLE, FALSE, ulPID)))    //Դ���̾��
	{
		cout << "Could not open PID : " << ulPID << endl;
		system("pause");
		return 1;
	}

	while ((status = NtQuerySystemInformatuion(SystemHandleInformation, pSystemHandleInfo, ulSystemHandleInfoSize, &ulSystemHandleInfoSize)) == STATUS_INFO_LENGTH_MISMATCH)  //��ȡ�����Ϣ
	{
		pSystemHandleInfo = (PSYSTEM_HANDLE_INFORMATION)realloc(pSystemHandleInfo, ulSystemHandleInfoSize);
	} 

	if (!NT_SUCCESS(status))
	{
		cout << "NtQuerySystemInformation failed!" << endl;
		system("pause");
		return 1;
	}

	for (ULONG i = 0; i < pSystemHandleInfo->NumberOfHandles; i++)
	{
		SYSTEM_HANDLE_TABLE_ENTRY_INFO handle_info = pSystemHandleInfo->Handles[i];

		if (handle_info.UniqueProcessId != ulPID)
		{
			continue;
		}

		if (!NT_SUCCESS(NtDuplicateObject(hProcess, (HANDLE)handle_info.HandleValue, GetCurrentProcess(), &hDupHandle, 0, 0,0)))  //Dump�������ǰ����
		{
			printf("[%#x] Error!\n", handle_info.HandleValue);
			CloseHandle(hDupHandle);
			continue;
		}
		ulObjectTypeInfoSize = 0x1000;
		PPUBLIC_OBJECT_TYPE_INFORMATION pObjectTypeInfo = (PPUBLIC_OBJECT_TYPE_INFORMATION)malloc(ulObjectTypeInfoSize);
		while ((status = NtQueryObject(hDupHandle, ObjectTypeInformation,pObjectTypeInfo,ulObjectTypeInfoSize,&ulObjectTypeInfoSize)) == STATUS_INFO_LENGTH_MISMATCH)  //���в�ѯ
		{
			pObjectTypeInfo = (PPUBLIC_OBJECT_TYPE_INFORMATION)realloc(pObjectTypeInfo, ulObjectTypeInfoSize);
		}
		if (!NT_SUCCESS(status))
		{
			continue;
		}
		ulObjectNameInfoSize = 0x1000;
		PPUBLIC_OBJECT_NAME_INFORMATION pObjectNameInfo = (PPUBLIC_OBJECT_NAME_INFORMATION)malloc(ulObjectNameInfoSize);
		while ((status = NtQueryObject(hDupHandle, ObjectNameInformation, pObjectNameInfo, ulObjectNameInfoSize, &ulObjectNameInfoSize)) == STATUS_INFO_LENGTH_MISMATCH)  //���в�ѯ
		{
			pObjectNameInfo = (PPUBLIC_OBJECT_NAME_INFORMATION)realloc(pObjectNameInfo, ulObjectNameInfoSize);
		}
		if (!NT_SUCCESS(status))
		{
			printf(
				"[%#x] %.*S: (could not get name)\n",
				handle_info.HandleValue,
				pObjectTypeInfo->TypeName.Length / 2,
				pObjectTypeInfo->TypeName.Buffer
				);
			free(pObjectTypeInfo);
			free(pObjectNameInfo);
			CloseHandle(hDupHandle);
			continue;
		}

		if (pObjectNameInfo->Name.Length)
		{
			wstring name(pObjectNameInfo->Name.Buffer);
			wstring type(pObjectTypeInfo->TypeName.Buffer);
			if ((name.find(L"Adele - Skyfall.mp3") !=string::npos ))    //static const size_t npos = -1;  find����ֵ��������������ԱȽ���npos��ϵ
			{
				NtDuplicateObject(hProcess, (HANDLE)handle_info.HandleValue, GetCurrentProcess(), &hDupHandle, 0, 0, DUPLICATE_SAME_ACCESS | DUPLICATE_CLOSE_SOURCE);  //�ر�Դ���
				continue;
			}
			printf(
				"[%#x] %.*S: %.*S\n",
				handle_info.HandleValue,
				pObjectTypeInfo->TypeName.Length/2,
				pObjectTypeInfo->TypeName.Buffer,
				pObjectNameInfo->Name.Length/2,
				pObjectNameInfo->Name.Buffer
				);
		}
		else
		{
			/* Print something else. */
			printf(
				"[%#x] %.*S: (unnamed)\n",
				handle_info.HandleValue,
				pObjectTypeInfo->TypeName.Length / 2,
				pObjectTypeInfo->TypeName.Buffer
				);
		}
		free(pObjectTypeInfo);
		free(pObjectNameInfo);
		CloseHandle(hDupHandle);
	}

	free(pSystemHandleInfo);
	CloseHandle(hProcess);
	system("pause");
	return 0;
}

