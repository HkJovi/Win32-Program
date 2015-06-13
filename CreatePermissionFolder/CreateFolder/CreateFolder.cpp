// CreateFolder.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
void main(void)
{
	SECURITY_ATTRIBUTES sa;  //���ļ��йصİ�ȫ�ṹ
	SECURITY_DESCRIPTOR sd;  //����һ��SD
	BYTE aclBuffer[1024];
	PACL pacl = (PACL)&aclBuffer; //����һ��ACL��������1024
	BYTE sidBuffer[100];
	PSID psid = (PSID)&sidBuffer;  //����һ��SID��������100
	DWORD sidBufferSize = 100;
	char domainBuffer[80];
	DWORD domainBufferSize = 80;
	SID_NAME_USE snu;
	HANDLE file;
	//��ʼ��һ��SD
	InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
	//��ʼ��һ��ACL
	InitializeAcl(pacl, 1024, ACL_REVISION);
	//����һ���û�hchen����ȡ���û���SID
	LookupAccountName(0, "Guest", psid,
		&sidBufferSize, domainBuffer,
		&domainBufferSize, &snu);
	//���ø��û���Access-Allowed��ACE����Ȩ��Ϊ������Ȩ�ޡ�
	AddAccessAllowedAce(pacl, ACL_REVISION, GENERIC_WRITE, psid);
	//��ACL���õ�SD��
	SetSecurityDescriptorDacl(&sd, TRUE, pacl, FALSE);

	//��SD�ŵ��ļ���ȫ�ṹSA��
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = FALSE;
	sa.lpSecurityDescriptor = &sd;

	//�����ļ�
	file = CreateFile("D:\\testfile",
		0, 0, &sa, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 0);
	CloseHandle(file);
	system("pause");
}
