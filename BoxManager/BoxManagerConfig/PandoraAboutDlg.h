/************************************************************************
 *
 *	Copyright (c) 1997-2001, Mediface Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: PandoraAboutDlg.h $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

#if !defined(AFX_PANDORAABOUTDLG_H__A915AD71_4A20_4A0B_A5CF_00CCFB6C7341__INCLUDED_)
#define AFX_PANDORAABOUTDLG_H__A915AD71_4A20_4A0B_A5CF_00CCFB6C7341__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PandoraAboutDlg.h : header file
//

#include "PandoraResource.h"

/////////////////////////////////////////////////////////////////////////////
// CPandoraAboutDlg dialog

class CPandoraAboutDlg : public CDialog
{
// Construction
public:
	CPandoraAboutDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPandoraAboutDlg)
	enum { IDD = IDD_CACHEDORA_ABOUT };
	CString	m_strVersion;
	CString	m_strCopyRight;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPandoraAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPandoraAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PANDORAABOUTDLG_H__A915AD71_4A20_4A0B_A5CF_00CCFB6C7341__INCLUDED_)
