
// Leave MessagesDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "Http.h"
#include "CheckCodeDlg.h"

// CLeaveMessagesDlg �Ի���
class CLeaveMessagesDlg : public CDialogEx
{
// ����
public:
	CLeaveMessagesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LEAVEMESSAGES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedbtngetmsg();
	CEdit m_edtGetMsg;
	CEdit m_edtName;
	CEdit m_edtsenMsg;
	CString strRadomUrl;
	CString strCheckCode;
	CString strMaxID;  //��ȡ������Ϣ��ʶ��
	afx_msg void OnBnClickedbtnsendmsg();
	afx_msg void OnBnClickedbtnrefresh();
	BOOL m_bConneted;
};
