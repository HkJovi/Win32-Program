
// MFCApplication1.h : MFCApplication1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// MFCApp:
// �йش����ʵ�֣������ MFCApplication1.cpp
//

class MFCApp : public CWinApp
{
public:
	MFCApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��

public:
	DECLARE_MESSAGE_MAP()
};

extern MFCApp theApp;
