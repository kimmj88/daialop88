/************************************************************************
 *
 *	Copyright (c) 1997-2001, Mediface Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: PandoraAboutDlg.cpp $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// PandoraAboutDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BoxManagerConfigDlg.h"
#include "PandoraAboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPandoraAboutDlg dialog


CPandoraAboutDlg::CPandoraAboutDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPandoraAboutDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPandoraAboutDlg)
	m_strVersion = _T("");
	m_strCopyRight = _T("");
	//}}AFX_DATA_INIT
}


void CPandoraAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPandoraAboutDlg)
	DDX_Text(pDX, IDC_VERSION, m_strVersion);
	DDX_Text(pDX, IDC_COPYRIGHT, m_strCopyRight);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPandoraAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CPandoraAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPandoraAboutDlg message handlers

BOOL CPandoraAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CBoxManagerConfigDlg* pCfg = (CBoxManagerConfigDlg*)GetParent();

	if (pCfg->m_pSystemInfo->IsLoadSystemInfo())
	{	
		CString strProductName, strCopyRight;

		pCfg->m_pSystemInfo->GetSystemInfo(strProductName, NODE_PRODUCTNAME);
		pCfg->m_pSystemInfo->GetSystemInfo(strCopyRight, NODE_COPYRIGHT);

		m_strVersion.Format("%s Version %s", strProductName, pCfg->GetVersion());
		m_strCopyRight.Format("%s", strCopyRight);
		SetWindowText(_T("About ") + strProductName);
	}
	else
	{		
		m_strVersion.Format("INFINITT BoxManager Express Version %s", pCfg->GetVersion());
		m_strCopyRight = _T("Copyright (C) 1999-2005, INFINITT Co., Ltd.\nAll Rights Reserved\nhttp://www.infinitt.com");	
	}

	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
