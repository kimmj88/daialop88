/************************************************************************
 *
 *	Copyright (c) 1997-2001, Mediface Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerConfigDlg.cpp $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// BoxManagerConfigDlg.cpp : implementation file
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
// CBoxManagerConfigDlg dialog

CBoxManagerConfigDlg::CBoxManagerConfigDlg(const char* pszDisplayName, CWnd* pParent /*=NULL*/)
	: CDialog(CBoxManagerConfigDlg::IDD, pParent)
{
	
	m_strDisplayName = pszDisplayName;
	//{{AFX_DATA_INIT(CBoxManagerConfigDlg)
	m_strLogDir = _T("");
	m_strLogFilename = _T("");
	m_strDatabaseName = _T("");
	m_strDatabasePassword = _T("");
	m_strDatabaseUsername = _T("");
	m_strServiceDependency = _T("");
	m_nLogLevel = -1;
	m_nInterVal = 5;
	//}}AFX_DATA_INIT
}


void CBoxManagerConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBoxManagerConfigDlg)
	DDX_Text(pDX, IDC_EDIT_LOG_DIR, m_strLogDir);
	DDX_Text(pDX, IDC_EDIT_LOG_FILENAME, m_strLogFilename);
	DDX_Text(pDX, IDC_EDIT_DATABASE_NAME, m_strDatabaseName);
	DDX_Text(pDX, IDC_EDIT_DATABASE_PASSWORD, m_strDatabasePassword);
	DDX_Text(pDX, IDC_EDIT_DATABASE_USERNAME, m_strDatabaseUsername);
	DDX_Text(pDX, IDC_EDIT_INTERVAL, m_nInterVal);
	DDX_CBString(pDX, IDC_COMBO_SERVICE_DEPENDENCY, m_strServiceDependency);
	DDX_CBIndex(pDX, IDC_COMBO_LOG_LEVEL, m_nLogLevel);
	
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBoxManagerConfigDlg, CDialog)
	//{{AFX_MSG_MAP(CBoxManagerConfigDlg)
	ON_BN_CLICKED(IDC_BUTTON_ABOUT, OnButtonAbout)
	ON_BN_CLICKED(IDC_BUTTON_INSTALL, OnButtonInstall)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, OnButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_SHUTDOWN, OnButtonShutdown)
	ON_BN_CLICKED(IDC_BUTTON_STARTUP, OnButtonStartup)
	ON_BN_CLICKED(IDC_BUTTON_UNINSTALL, OnButtonUninstall)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBoxManagerConfigDlg message handlers

void CBoxManagerConfigDlg::Update()
{
	UpdateData(TRUE);
}

void CBoxManagerConfigDlg::UpdateInterface(void)
{
	UpdateData(FALSE);
}

/////////////////////////////////////////////////////////////////////////////

BOOL CBoxManagerConfigDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_BOXMANAGER);
	SetIcon(hIcon, TRUE);
	SetIcon(hIcon, FALSE);

	m_pSystemInfo = new CSystemInfo();
	if (m_pSystemInfo->LoadSystemInfo())
	{
		CRect rctWindow;
		CString strTitle;
//		HBITMAP hSolutionBitmap = NULL;
		
		//m_pSystemInfo->GetSystemInfo(strTitle, NODE_TITLE);
//		m_pSystemInfo->GetSystemInfo(hSolutionBitmap, NODE_SOLUTIONLOGO);
		
		//SetWindowText(strTitle);
		SetWindowText(m_strDisplayName + " Administrator");
		//m_imgSolutionLogo.SetBitmap(hSolutionBitmap);
	}
	else
	{
		SetWindowText(m_strDisplayName + " Administrator");
		//SetWindowText("STARPACS Media Exporter Administratorr");
	}

	UpdateInterface();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CBoxManagerConfigDlg::OnButtonInstall() 
{
	UpdateData(TRUE);
	Install();
}

void CBoxManagerConfigDlg::OnButtonUninstall() 
{
	UpdateData(TRUE);
	Uninstall();
}
void CBoxManagerConfigDlg::OnButtonStartup() 
{
	Update();
	Startup();
}
void CBoxManagerConfigDlg::OnButtonShutdown() 
{
	Update();
	Shutdown();
}

void CBoxManagerConfigDlg::OnButtonSave() 
{
	Update();
	Save();
}

void CBoxManagerConfigDlg::OnButtonAbout() 
{
	CPandoraAboutDlg dlgAbout;

	dlgAbout.DoModal();
}

void CBoxManagerConfigDlg::OnButtonBrowse(CString& strDir)
{
	char szFolder[MAX_PATH];
	LPMALLOC pMalloc;
	LPITEMIDLIST pidl;
	BROWSEINFO bi;

    bi.hwndOwner = m_hWnd;
    bi.pidlRoot = NULL;
    bi.lpszTitle = "Please specify a folder";
    bi.pszDisplayName = NULL;
    bi.ulFlags = BIF_RETURNONLYFSDIRS;
    bi.lpfn = SetSelProc;
    bi.lParam = (LPARAM)(LPCSTR)strDir;
	
	pidl = SHBrowseForFolder(&bi);

	if (pidl == NULL)
		return;
	
	SHGetPathFromIDList(pidl, szFolder);

	if (SHGetMalloc(&pMalloc) != NOERROR)
		return;

	pMalloc->Free(pidl);
	pMalloc->Release();
	
	strDir.Format("%s", szFolder);
	
	UpdateInterface();
	
	return;
}

/*--------------------------------------------------------------------------------------------
	callback function for loading directory selection
--------------------------------------------------------------------------------------------*/

int CALLBACK CBoxManagerConfigDlg::SetSelProc(HWND hWnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	if (uMsg == BFFM_INITIALIZED)
	{
		::SendMessage( hWnd, BFFM_SETSELECTION, TRUE, lpData );
	}

	return 0;
}

