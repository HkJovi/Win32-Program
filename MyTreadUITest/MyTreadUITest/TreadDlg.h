#pragma once
#include "afxwin.h"



struct m_data //���ݲ���
{
	CStatic cont;
};

// CTreadDlg �Ի���

class CTreadDlg : public CDialog
{
	DECLARE_DYNAMIC(CTreadDlg)

public:
	CTreadDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTreadDlg();
	CWinThread * pWorkThread;
	static UINT MulThreadFunc(LPVOID lpParam); //����Ϊ��̬����ʹ�����ܹ�ʹ�øú���
	m_data data;

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
