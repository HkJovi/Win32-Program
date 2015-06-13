// CheckCodeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Leave Messages.h"
#include "CheckCodeDlg.h"
#include "afxdialogex.h"
#include "Leave MessagesDlg.h"

// CheckCodeDlg �Ի���

IMPLEMENT_DYNAMIC(CheckCodeDlg, CDialog)

CheckCodeDlg::CheckCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CheckCodeDlg::IDD, pParent)
{

}

CheckCodeDlg::~CheckCodeDlg()
{
}

void CheckCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edtCheckCode);
}


BEGIN_MESSAGE_MAP(CheckCodeDlg, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CheckCodeDlg ��Ϣ�������


void CheckCodeDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	m_image.Draw(dc.m_hDC, 0, 0);
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}


void CheckCodeDlg::OnOK()
{
	// TODO:  �ڴ����ר�ô����/����û���
	CLeaveMessagesDlg * parent = (CLeaveMessagesDlg*)GetParent();
	CString str;
	this->m_edtCheckCode.GetWindowText(str);//��ȡ��ǰ�Ӵ��ڱ༭���е�ֵ
	parent->strCheckCode=str;//�ѵ�ǰ�༭���е�ֵ�ش���������
	CDialog::OnOK();
}
