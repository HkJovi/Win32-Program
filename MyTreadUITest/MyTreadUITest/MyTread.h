#pragma once



// CMyTread

class CMyTread : public CWinThread
{
	DECLARE_DYNCREATE(CMyTread)

protected:
	CMyTread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyTread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


