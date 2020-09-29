#pragma once


class CProc
{
	CString m_strDatabase;
	CString m_strUser;
	CString m_strPassword;

	CMutex	m_mtxDatabase;
	void*	m_sqlSessionContext;
	CString	m_strSessionName;
	BOOL	m_bIsDBOpen;

public:
	CProc();
	virtual ~CProc();

	BOOL OpenDatabase();

protected:

};


