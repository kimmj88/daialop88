/************************************************************************
 *
 *	Copyright (c) 1997-2001, Mediface Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerConfigDlg.h $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

#if !defined(AFX_CachedoraConfigDLG_H__CC315024_A029_4A31_903C_7ACE3667E004__INCLUDED_)
#define AFX_CachedoraConfigDLG_H__CC315024_A029_4A31_903C_7ACE3667E004__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// BoxManagerConfigDlg.h : header file
//

#include "PandoraResource.h"
#include "SystemInfo.h"

#ifdef	BSEXP
#define	BSCLASS					__declspec(dllexport)
#else
#define	BSCLASS					__declspec(dllimport)
#endif

/////////////////////////////////////////////////////////////////////////////
// CBoxManagerConfigDlg dialog

class BSCLASS CBoxManagerConfigDlg : public CDialog
{
// Construction
public:
	CBoxManagerConfigDlg(const char* pszDisplayName, CWnd* pParent = NULL);   // standard constructor
	CSystemInfo*	m_pSystemInfo;

// Dialog Data
	//{{AFX_DATA(CBoxManagerConfigDlg)
	enum { IDD = IDD_PANDORA_CONFIG };
	CString	m_strLogDir;
	CString	m_strLogFilename;
	CString	m_strDatabaseName;
	CString	m_strDatabasePassword;
	CString	m_strDatabaseUsername;
	CString m_strServiceDependency;
	int		m_nLogLevel;
	int		m_nInterVal;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBoxManagerConfigDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBoxManagerConfigDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAbout();
	afx_msg void OnButtonInstall();
	afx_msg void OnButtonSave();
	afx_msg void OnButtonShutdown();
	afx_msg void OnButtonStartup();
	afx_msg void OnButtonUninstall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	virtual void Install() {};
	virtual void Uninstall() {};
	virtual void Startup() {};
	virtual void Shutdown() {};
	virtual void Save() {};

	void OnButtonBrowse(CString& strDir);
	static int CALLBACK SetSelProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData);

public:
	virtual void	Update(void);
	void	UpdateInterface(void);
	virtual const char* GetVersion(void) = 0;
	virtual const char* GetBuildNumber(void) = 0;
	CString	m_strDisplayName;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BoxManagerConfigDLG_H__CC315024_A029_4A31_903C_7ACE3667E004__INCLUDED_)
