#pragma once
#include "afxwin.h"


// CheckCodeDlg �Ի���

class CheckCodeDlg : public CDialog
{
	DECLARE_DYNAMIC(CheckCodeDlg)

public:
	CheckCodeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CheckCodeDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtCheckCode;
	CImage m_image;
	afx_msg void OnPaint();
	virtual void OnOK();
};
