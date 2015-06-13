
// iniEncayptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "iniEncaypt.h"
#include "iniEncayptDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define C1 52845
#define C2 22719
// CiniEncayptDlg dialog



CiniEncayptDlg::CiniEncayptDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CiniEncayptDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CiniEncayptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SOURCESTRING, m_tb_sString);
	DDX_Control(pDX, IDC_EDIT_DESTINATIONGSTRING, m_tb_dString);
}

BEGIN_MESSAGE_MAP(CiniEncayptDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ENCRYPT, &CiniEncayptDlg::OnBnClickedBtnEncrypt)
	ON_BN_CLICKED(IDC_BTN_DECRYPT, &CiniEncayptDlg::OnBnClickedBtnDecrypt)
	ON_BN_CLICKED(IDC_BTN_INPUT, &CiniEncayptDlg::OnBnClickedBtnInput)
	ON_BN_CLICKED(IDC_BTN_OUTPUT, &CiniEncayptDlg::OnBnClickedBtnOutput)
END_MESSAGE_MAP()


// CiniEncayptDlg message handlers

BOOL CiniEncayptDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CiniEncayptDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CiniEncayptDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CiniEncayptDlg::OnBnClickedBtnEncrypt()
{
	// TODO: Add your control notification handler code here
	CString S;
	m_tb_sString.GetWindowText(S);
	WORD key = 1314;//key
	CString result = Encrypt(S, key);//����
	m_tb_dString.SetWindowText(result);
}


void CiniEncayptDlg::OnBnClickedBtnDecrypt()
{
	// TODO: Add your control notification handler code here
	CString S;
	m_tb_dString.GetWindowText(S);
	WORD key = 1314;//key
	CString result = Decrypt(S, key);//����
	m_tb_sString.SetWindowText(result);
}

CString Encrypt(CString S, WORD Key) // ���ܺ���
{
	CString Result, str;
	int i, j;

	Result = S; // ��ʼ������ַ���
	for (i = 0; i < S.GetLength(); i++) // ���ζ��ַ����и��ַ����в���
	{
		Result.SetAt(i, S.GetAt(i) ^ (Key >> 8)); // ����Կ��λ�����ַ����
		Key = ((WORD)Result.GetAt(i) + Key)*C1 + C2; // ������һ����Կ
	}
	S = Result; // ������
	Result.Empty(); // ������
	for (i = 0; i < S.GetLength(); i++) // �Լ��ܽ������ת��
	{
		j = (WORD)S.GetAt(i); // ��ȡ�ַ�
		// ���ַ�ת��Ϊ������ĸ����
		str = "12"; // ����str����Ϊ2
		str.SetAt(0, 256 + j / 26);//���ｫ65�Ĵ���������256�����ľͻ�����룬Ч�����ã���Ӧ�ģ����ܴ�Ҫ��Ϊ��ͬ����
		str.SetAt(1, 256 + j % 26);
		Result += str;
	}
	return Result;
}


CString Decrypt(CString S, WORD Key) // ���ܺ���
{
	CString Result, str;
	int i, j;

	Result.Empty(); // ������
	for (i = 0; i < S.GetLength() / 2; i++) // ���ַ���������ĸһ����д���
	{
		j = (((WORD)S.GetAt(2 * i) - 256) * 26);//��Ӧ�ģ����ܴ�Ҫ��Ϊ��ͬ����

		j += (WORD)S.GetAt(2 * i + 1) - 256;
		str = "1"; // ����str����Ϊ1
		str.SetAt(0, j);
		Result += str; // ׷���ַ�����ԭ�ַ���
	}
	S = Result; // �����м���
	for (i = 0; i < S.GetLength(); i++) // ���ζ��ַ����и��ַ����в���
	{
		Result.SetAt(i, (WORD)S.GetAt(i) ^ (Key >> 8)); // ����Կ��λ�����ַ����
		Key = ((WORD)S.GetAt(i) + Key)*C1 + C2; // ������һ����Կ
	}
	return Result;
}

void CiniEncayptDlg::OnBnClickedBtnInput()
{
	// TODO: Add your control notification handler code here
	CString strPath;
	GetModuleFileName(NULL, strPath.GetBuffer(MAX_PATH), MAX_PATH);
	strPath.ReleaseBuffer();
	strPath = strPath.Mid(0,strPath.ReverseFind('\\'));
	strPath.Append(_T("\\Mstsc.ini"));
	CFile file;
	if (!file.Open(strPath, CFile::modeReadWrite | CFile::shareDenyWrite , NULL))
	{
		MessageBox(L"δ�ҵ�Mstsc.ini!", L"��ʾ", MB_OK|MB_ICONINFORMATION);
	}
	else
	{
		CString buffer;
		DWORD len = (DWORD)file.GetLength();
		file.SeekToBegin();
		file.Read(buffer.GetBuffer((len + 1)/2), len);
		buffer.ReleaseBuffer();
		m_tb_dString.SetWindowText(buffer);
		file.Close();
	}
}


void CiniEncayptDlg::OnBnClickedBtnOutput()
{
	// TODO: Add your control notification handler code here
	CString strPath;
	GetModuleFileName(NULL, strPath.GetBuffer(MAX_PATH), MAX_PATH);
	strPath.ReleaseBuffer();
	strPath = strPath.Mid(0, strPath.ReverseFind('\\'));
	strPath.Append(_T("\\Mstsc.ini"));
	CFile file;
	file.Open(strPath, CFile::modeReadWrite | CFile::shareDenyWrite | CFile::modeCreate , NULL);
	CStringW buffer;
	m_tb_dString.GetWindowText(buffer);
	file.Write(buffer.GetBuffer(buffer.GetLength() * sizeof(WCHAR) + 2), buffer.GetLength());
	file.Flush();
	file.Close();
}
