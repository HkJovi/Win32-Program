
// Leave Messages.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLeaveMessagesApp: 
// �йش����ʵ�֣������ Leave Messages.cpp
//

class CLeaveMessagesApp : public CWinApp
{
public:
	CLeaveMessagesApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLeaveMessagesApp theApp;