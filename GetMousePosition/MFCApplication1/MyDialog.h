#pragma once


// MyDialog �Ի���

class MyDialog : public CDialog
{
	DECLARE_DYNAMIC(MyDialog)

public:
	MyDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MyDialog();

// �Ի�������
	enum { IDD = IDD_MyDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	CString m_str;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnChangeEdit2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
