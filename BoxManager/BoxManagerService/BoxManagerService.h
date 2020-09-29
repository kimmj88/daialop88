/************************************************************************
 *
 *	Copyright (c) 1997-2001, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerService.h $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// BoxManagerService.h : main header file for the BoxManagerService application
//

#if !defined(AFX_CachedoraService_H__B724D9A3_8AD5_438B_B2F2_025E5C065E7B__INCLUDED_)
#define AFX_CachedoraService_H__B724D9A3_8AD5_438B_B2F2_025E5C065E7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "NTService.h"
#include "BoxManagerServiceConfig.h"

/////////////////////////////////////////////////////////////////////////////
// CBoxManagerService:
// See BoxManagerService.cpp for the implementation of this class
//

class CMFLogger;
class CBoxManagerDatabase;
class CBoxManagerRemove;
class CPandoraRemover;

class CBoxManagerService : public CWinApp, public CNTService
{
protected:
	HANDLE	m_hStop;

public:
	CBoxManagerServiceConfig*	m_pCfg;
	CBoxManagerDatabase*			m_pDatabase;
	CBoxManagerRemove*			m_pRemover;
	CSystemInfo*						m_pSystemInfoService;
	CMFLogger*							m_pLogger;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoxManagerService)
public:
	CBoxManagerService();
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBoxManagerService)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL InstallService();
	virtual void Run(DWORD, LPTSTR *);
	virtual void Stop();
	virtual BOOL ConfigureService();

	void EventLog(WORD nEventType, const char* pszFormat, ...);
	BOOL CheckServiceDependency(void);
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BoxManagerService_H__B724D9A3_8AD5_438B_B2F2_025E5C065E7B__INCLUDED_)
