// MyTread.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyTreadUITest.h"
#include "MyTread.h"
#include "TreadDlg.h"


// CMyTread

IMPLEMENT_DYNCREATE(CMyTread, CWinThread)

CMyTread::CMyTread()
{
}

CMyTread::~CMyTread()
{
}

BOOL CMyTread::InitInstance()
{
	// TODO:    �ڴ�ִ���������̳߳�ʼ��
	CTreadDlg *dlg =new CTreadDlg;
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(SW_SHOW);
	return TRUE;
}

int CMyTread::ExitInstance()
{
	// TODO:    �ڴ�ִ���������߳�����
	delete this;
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyTread, CWinThread)
END_MESSAGE_MAP()


// CMyTread ��Ϣ�������
