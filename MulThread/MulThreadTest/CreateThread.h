#pragma once
#include "afxcmn.h"


// CCreateThread dialog
struct m_data //���ݲ���
	{
		BOOL b;
		CProgressCtrl	m_pro; //����ӵ��ռ�
	};

class CCreateThread : public CDialog
{
	DECLARE_DYNAMIC(CCreateThread)

public:
	BOOL check;
	m_data m_d;
	CWinThread* pThread;
public:
	static UINT MulThreadFunc(LPVOID lpParam); //����Ϊ��̬����ʹ�����ܹ�ʹ�øú���

public:
	CCreateThread(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCreateThread();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	CProgressCtrl m_pro;
public:
	afx_msg void OnPaint();
};
