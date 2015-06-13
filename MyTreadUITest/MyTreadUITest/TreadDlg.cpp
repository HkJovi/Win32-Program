// TreadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyTreadUITest.h"
#include "TreadDlg.h"
#include "afxdialogex.h"


// CTreadDlg �Ի���

IMPLEMENT_DYNAMIC(CTreadDlg, CDialog)

CTreadDlg::CTreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTreadDlg::IDD, pParent)
{

}

CTreadDlg::~CTreadDlg()
{
}

void CTreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_count, data.cont);
}


BEGIN_MESSAGE_MAP(CTreadDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CTreadDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTreadDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CTreadDlg ��Ϣ�������


void CTreadDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	pWorkThread = AfxBeginThread(MulThreadFunc, &data, 0, 0, 4);
	pWorkThread->ResumeThread();
}


UINT CTreadDlg::MulThreadFunc(LPVOID lpParam)
{
	m_data * pData = (m_data *)lpParam;
	CString temp;
	for (int i = 0; i < 999; i++)
	{
		temp.Format(_T("%d"), i);
		pData->cont.SetWindowText(temp);
		Sleep(100);
	}
	ExitThread(0);
	return 0;
}

void CTreadDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	pWorkThread->SuspendThread();
}
