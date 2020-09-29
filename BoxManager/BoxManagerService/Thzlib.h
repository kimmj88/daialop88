// Thzlib.h: interface for the CThzlib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THZLIB_H__1FD8C754_6EEF_4C92_ADB0_55121ABA8687__INCLUDED_)
#define AFX_THZLIB_H__1FD8C754_6EEF_4C92_ADB0_55121ABA8687__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "zlibengn.h"

#define Z_PROGRESS	WM_USER+ 1000
#define Z_STATUS	WM_USER+ 1001

class CThzlib  :public ZlibEngine
{
protected:
	CWnd* m_pTarget;
public:
	CString	m_sStatus;
public:
	CThzlib( CWnd* pTarget = NULL );
	void InitZTarget( CWnd* pWnd );
	virtual ~CThzlib();

	void AbortProcess();
	virtual void progress( int nPercent );
	virtual void status( char* message );
};

#endif // !defined(AFX_THZLIB_H__1FD8C754_6EEF_4C92_ADB0_55121ABA8687__INCLUDED_)
