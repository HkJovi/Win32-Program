// MulThreadTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMulThreadTestApp:
// �йش����ʵ�֣������ MulThreadTest.cpp
//

class CMulThreadTestApp : public CWinApp
{
public:
	CMulThreadTestApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMulThreadTestApp theApp;