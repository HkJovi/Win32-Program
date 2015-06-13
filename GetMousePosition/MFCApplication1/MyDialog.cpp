// MyDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog �Ի���

IMPLEMENT_DYNAMIC(MyDialog, CDialog)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MyDialog::IDD, pParent)
	, m_str(_T("����"))
{
	
}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_str);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
	ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON2, &MyDialog::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &MyDialog::OnBnClickedButton3)
ON_EN_CHANGE(IDC_EDIT2, &MyDialog::OnChangeEdit2)
ON_WM_CREATE()
END_MESSAGE_MAP()


// MyDialog ��Ϣ�������


void MyDialog::OnBnClickedButton1()
{
	CString str;
	GetDlgItemText(IDC_EDIT1, str);
	MessageBox(str, _T("��ȡ�ı�"), MB_OK);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void MyDialog::OnMouseMove(UINT nFlags, CPoint point)
{
	SetTimer(1, 1, NULL);//��ʱ������ ��ʱ����ţ����ʱ�䣬�ص�����Ĭ��OnTimer

	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CWnd * pWnd = GetDlgItem(IDC_Posation1);
	CString str;
	str.Format(_T("X:%ld,Y:%ld"), point.x,point.y);
	pWnd->SetWindowTextW(str);

	CWnd * pWnd2 = GetDlgItem(IDC_Posation2);
	CString str2;
	CPoint point2;
	GetCursorPos(&point2);
	str2.Format(_T("X:%ld,Y:%ld"), point2.x, point2.y);
	pWnd2->SetWindowTextW(str2);


	CDialog::OnMouseMove(nFlags, point);
}


void MyDialog::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	this->SetCapture();
	CDialog::OnLButtonDown(nFlags, point);
}


void MyDialog::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	::ReleaseCapture();
	CDialog::OnLButtonUp(nFlags, point);
}


void MyDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CWnd * pWnd2 = GetDlgItem(IDC_Posation3);
	CString str2;
	CPoint point2;
	GetCursorPos(&point2);
	str2.Format(_T("X:%ld,Y:%ld"), point2.x, point2.y);
	pWnd2->SetWindowTextW(str2);
	CDialog::OnTimer(nIDEvent);
}


void MyDialog::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	KillTimer(1);
}




void MyDialog::OnBnClickedButton3()
{
	UpdateData();
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CWnd * pWnd = GetDlgItem(IDC_TEXT);
	MessageBox(m_str, _T("��ȡ�ı�"), MB_OK);
	pWnd->SetWindowTextW(m_str);
}


void MyDialog::OnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	UpdateData();
	CWnd * pWnd = GetDlgItem(IDC_TEXT);
	pWnd->SetWindowTextW(m_str);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


int MyDialog::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	// �޸Ĵ���ͼ��
	HICON hicon = AfxGetApp()->LoadIcon(IDI_ICON2);
	SetIcon(hicon,TRUE);
	SetIcon(hicon, FALSE);
	return 0;
}
