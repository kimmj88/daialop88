/************************************************************************
 *
 *	Copyright (c) 1997-2001, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: CachedoraService.cpp $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// CachedoraService.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MFLogger.h"
#include "BoxManagerService.h"
#include "BoxManagerDatabase.h"
#include "BoxManagerRemove.h"
#include "BoxManagerServiceVersion.h"
#include "DirectEx.h"
#include "MFMacro.h"

#import "C:\Program Files (x86)\Common Files\MSSoap\Binaries\mssoap30.dll" \
         exclude("IStream", "IErrorInfo", "ISequentialStream", "_LARGE_INTEGER", \
				 "_ULARGE_INTEGER", "tagSTATSTG", "_FILETIME")
using namespace MSSOAPLib30;


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DEF_LOG_FILENAME					("BoxManager")

/////////////////////////////////////////////////////////////////////////////
// CBoxManagerService

BEGIN_MESSAGE_MAP(CBoxManagerService, CWinApp)
	//{{AFX_MSG_MAP(CBoxManagerService)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// The one and only CBoxManagerService object

CBoxManagerService theApp;

/////////////////////////////////////////////////////////////////////////////
// CBoxManagerService construction

CBoxManagerService::CBoxManagerService()
	: CNTService(DEF_PANDORA_SERVICE_NAME, DEF_PANDORA_DISPLAY_NAME)
{
}

/////////////////////////////////////////////////////////////////////////////
// CBoxManagerService initialization

BOOL CBoxManagerService::InitInstance()
{
//	AfxGetModuleState()->m_dwVersion = 0x0601; // 20061026 yhy
	HRESULT hr = CoInitialize(NULL);
	CString strServiceDisplayName, strRegistryRootName, strConfigMutexName;
	
	m_pSystemInfoService = new CSystemInfo();
	
	if (m_pSystemInfoService->LoadSystemInfo())
	{
		m_pSystemInfoService->GetSystemInfo(strServiceDisplayName, NODE_SERVICE_DISPLAY_NAME);
		m_pSystemInfoService->GetSystemInfo(strRegistryRootName, NODE_REGISTRY_ROOT);
	
		if (!strServiceDisplayName.IsEmpty())
			m_lpDisplayName = strServiceDisplayName;
	}
	else
	{
		strRegistryRootName.Format("%s", "INFINITT RS");
	}
	
	if (FindWindow(NULL, "INFINITT BoxManager Configuration"))
		return FALSE;

	RegisterService(__argc, __argv);
	return FALSE;
}

int CBoxManagerService::ExitInstance() 
{
	CoUninitialize();
	
	return CWinApp::ExitInstance();
}

BOOL CBoxManagerService::InstallService()
{
	TCHAR szDependency[256];

	if (!m_pCfg->m_strServiceDependency.IsEmpty())
	{
		TCHAR* p = szDependency;
		TCHAR c;
		UINT nLength = m_pCfg->m_strServiceDependency.GetLength();

		UINT nIndex=0;		//20090309 NHS MODIFY
		for(nIndex = 0; nIndex < nLength; nIndex++)
		{
			c = m_pCfg->m_strServiceDependency.GetAt(nIndex);
			p[nIndex] = (m_pCfg->m_strServiceDependency.GetAt(nIndex) != ',') ? c : 0;
		}
		p[nIndex++] = 0;
		p[nIndex++] = 0;

		m_pszDependencies = szDependency;
	}
	return CNTService::InstallService();
}

void CBoxManagerService::Run(DWORD, LPTSTR *)
{
	HRESULT hr = CoInitialize(NULL);
	CString strConfigMutexName, strServiceMutexName;	
	CString strProfileFullPath;
	CString strProgramPath;
	CString strProgramPath1;
	CString strReleaseTime;
	CString strCompanyName;
	CString strProductName;

	int		nPos;
	int		nPoss;

	PANDORAINFO bi;

	GetModuleFileName(NULL, (LPTSTR)strProgramPath.GetBuffer(_MAX_PATH), _MAX_PATH);
	 strProgramPath.ReleaseBuffer();
	 if ((nPos = strProgramPath.ReverseFind('\\')) >= 0)
	 strProgramPath = strProgramPath.Left(nPos);
	 strProfileFullPath.Format("%s\\%sConfig.ini", strProgramPath, m_lpServiceName);

	strConfigMutexName.Format("/MUTEX/%s/Config", m_lpServiceName);
	strServiceMutexName.Format("/MUTEX/%s/Service", m_lpServiceName);

	m_pCfg = new CBoxManagerServiceConfig(m_lpServiceName, m_lpDisplayName, strConfigMutexName, strProfileFullPath);
	m_pLogger = new CMFLogger(m_pCfg->m_nLogLevel, m_pCfg->m_strLogDir, m_pCfg->m_strLogFilename);
	m_pDatabase = new CBoxManagerDatabase(m_pLogger);
	m_pRemover = new CBoxManagerRemove(m_pLogger);
	
	if(!CheckServiceDependency())
	{
		goto on_final;
	}

	GetModuleFileName(NULL, (LPTSTR)strProgramPath1.GetBuffer(_MAX_PATH), _MAX_PATH);
	strProgramPath1.ReleaseBuffer();
	if ((nPoss = strProgramPath1.ReverseFind('\\')) >= 0)
	{
		CFile		f;
		CFileStatus	status;
		CTime		tModify;

		if (f.Open(strProgramPath1, CFile::modeRead))
		{
			f.GetStatus(status);
			tModify = status.m_mtime;
			
			strReleaseTime.Format("%s", tModify.Format("%b %d, %Y"));
//			SetDlgItemText(IDC_STATIC_RELEASE_DATE, strReleaseTime);
			f.Close();
		}	
	}

	// Set SystemInfo
	

	if (m_pSystemInfoService->IsLoadSystemInfo())
	{	
		m_pSystemInfoService->GetSystemInfo(strCompanyName, NODE_COMPANY_NAME);
		m_pSystemInfoService->GetSystemInfo(strProductName, NODE_PRODUCTNAME);
	}
	else
	{
		strCompanyName.Format("%s", "INFINITT");
		strProductName.Format("%s", DEF_LOG_FILENAME);
	}

	// add suffix
	m_pLogger->SetLogFileSuffix("%Y%m%d");

	// set configuration
	

	// starting up...
	m_pLogger->LogMessage(3, LOG_INFO, "---------------------------------------------------------------------------------------------------");	
	m_pLogger->LogMessage(3, LOG_INFO, "%s Version %s Release Date: %s", strProductName, PANDORA_VERSION, strReleaseTime);


	m_pLogger->LogMessage(4, LOG_DEBUG, "Logger module loaded (%s)", m_pLogger->GetVersion());
	m_pLogger->LogMessage(4, LOG_DEBUG, "Database module loaded (%s)", m_pDatabase->GetVersion());
	m_pLogger->LogMessage(4, LOG_DEBUG, "Remover module loaded (%s)", m_pRemover->GetVersion());
	m_pLogger->LogMessage(3, LOG_INFO, "%s: begin", DEF_PANDORA_SERVICE_NAME);

	SetCurrentDirectory(strProgramPath);


	// open database
	ReportStatus(SERVICE_START_PENDING, 15000);
	if (!m_pDatabase->Open(DBINFO(m_pCfg->m_strDatabaseName, m_pCfg->m_strDatabaseUsername, m_pCfg->m_strDatabasePassword)))
	{
		EventLog(EVENTLOG_ERROR_TYPE, "database open failed: %s",  m_pDatabase->GetLastError());
		goto on_close_database;
	}
	EventLog(EVENTLOG_INFORMATION_TYPE, "database opened");

	bi.strSourceDir = m_pDatabase->m_strPublicSourceDir;
	bi.nInterval = m_pCfg->m_nInterVal;


	// start remover
	ReportStatus(SERVICE_START_PENDING, 15000);
	if (!m_pRemover->Start(m_pDatabase, &bi))
	{
		EventLog(EVENTLOG_ERROR_TYPE, "Remover start failed");
		goto on_stop_remover;
	}
/*
	// start remover
	ReportStatus(SERVICE_START_PENDING, 15000);
	if (!m_pRemover->Start(m_pDatabase, &bi))
	{
		EventLog(EVENTLOG_ERROR_TYPE, "remover start failed");
		goto on_stop_remover;
	}
*/	
	// main loop
	m_hStop = ::CreateEvent(0, TRUE, FALSE, strServiceMutexName);
	ReportStatus(SERVICE_RUNNING);
	while(::WaitForSingleObject(m_hStop, 10) != WAIT_OBJECT_0)
	{
		::Sleep(1000);		
	}
	if (m_hStop)
		::CloseHandle(m_hStop);

//on_stop_remover:
//	ReportStatus(SERVICE_STOP_PENDING, 15000);
//	m_pRemover->Stop();
//	EventLog(EVENTLOG_INFORMATION_TYPE, "remover stopped");

on_stop_remover:
	ReportStatus(SERVICE_STOP_PENDING, 15000);
	m_pRemover->Stop();
	EventLog(EVENTLOG_INFORMATION_TYPE, "BoxManager Service stopped");

on_close_database:
	ReportStatus(SERVICE_STOP_PENDING, 15000);
	m_pDatabase->Close();
	EventLog(EVENTLOG_INFORMATION_TYPE, "database closed : %s", m_pDatabase->GetDatabaseName());

on_final:
	m_pLogger->LogMessage(3, LOG_INFO, "%s: end", DEF_PANDORA_SERVICE_NAME);

	delete m_pRemover;
	delete m_pDatabase;
	delete m_pLogger;
	delete m_pCfg;

	CoUninitialize();
}

void CBoxManagerService::Stop()
{
	ReportStatus(SERVICE_STOP_PENDING, 15000);
	if (m_hStop)
		::SetEvent(m_hStop);
}

void CBoxManagerService::EventLog(WORD nEventType, const char* pszFormat, ...)
{
	va_list ap;
	char szMessage[1024];

	va_start(ap, pszFormat);
	vsprintf(szMessage, pszFormat, ap);
	va_end(ap);
	switch(nEventType)
	{
	case EVENTLOG_ERROR_TYPE :
		AddToMessageLog(szMessage, nEventType);
		m_pLogger->LogMessage(1, LOG_FAIL, "main: %s", szMessage);
		break;
	case EVENTLOG_WARNING_TYPE :
		AddToMessageLog(szMessage, nEventType);
		m_pLogger->LogMessage(2, LOG_WARN, "main: %s", szMessage);
		break;
	case EVENTLOG_INFORMATION_TYPE :
#ifdef	_DEBUG
		AddToMessageLog(szMessage, nEventType);
#endif
		m_pLogger->LogMessage(3, LOG_INFO, "main: %s", szMessage);
		break;
	default :
		break;
	}
}


BOOL CBoxManagerService::ConfigureService()
{
	CString strConfigMutexName, strServiceName;
	CString strProfileFullPath;
	CString strProgramPath;
	int	nPos;

	strConfigMutexName.Format("/MUTEX/%s/Config2", m_lpServiceName);
	strServiceName.Format("%s/Config", m_lpServiceName);
	
	GetModuleFileName(NULL, (LPTSTR)strProgramPath.GetBuffer(_MAX_PATH), _MAX_PATH);
	strProgramPath.ReleaseBuffer();
	if ((nPos = strProgramPath.ReverseFind('\\')) >= 0)
	strProgramPath = strProgramPath.Left(nPos);
	strProfileFullPath.Format("%s\\%sConfig.ini", strProgramPath, m_lpServiceName);

	m_pCfg = new CBoxManagerServiceConfig(m_lpServiceName, m_lpDisplayName, strConfigMutexName, strProfileFullPath);
	m_pLogger = new CMFLogger(m_pCfg->m_nLogLevel, m_pCfg->m_strLogDir, m_pCfg->m_strLogFilename);

	// add suffix
	m_pLogger->SetLogFileSuffix("%Y%m%d");

	m_pCfg->DoModal();

	delete m_pLogger;
	delete m_pCfg;

	if(m_pSystemInfoService != NULL)
		delete m_pSystemInfoService;

	return FALSE;
}
BOOL CBoxManagerService::CheckServiceDependency(void)
{
	int nAttrCount = 0, nIndex = 0, nWaitCnt;
	char* pArgs[10];
	TCHAR szErr[256];
	const int MAX_COUNT = 300;
	static char *szSrvStatMsg[] = {"", 
		"Stopped",                  //SERVICE_STOPPED
		"Starting..",				//SERVICE_START_PENDING
		"Stopping..",				//SERVICE_STOP_PENDING
		"Started",                  //SERVICE_RUNNING
		"Resuming..",				//SERVICE_CONTINUE_PENDING 
		"Pausing..",				//SERVICE_PAUSE_PENDING
		"Paused"                    //SERVICE_PAUSED
	};

	if(m_pCfg->m_strServiceDependency.IsEmpty()){
		return TRUE;
	}

	nAttrCount = getarg(TO_PCHAR(m_pCfg->m_strServiceDependency), ',', pArgs, 10);
	m_ssStatus.dwWaitHint = 9000;

	while(nIndex < nAttrCount){
		SERVICE_STATUS ssStatus;
		SC_HANDLE schSCManager = ::OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);
		if(schSCManager){
			SC_HANDLE schService = ::OpenService(schSCManager, pArgs[nIndex], SERVICE_ALL_ACCESS);
			nWaitCnt = 0;
			if(schService){
				while(::QueryServiceStatus(schService, &ssStatus)){
					m_pLogger->LogMessage(4, LOG_DEBUG, "service dependency: '%s' - %s (count:%d/%d).", pArgs[nIndex], szSrvStatMsg[ssStatus.dwCurrentState], nWaitCnt, MAX_COUNT);
					if(ssStatus.dwCurrentState == SERVICE_RUNNING)			break;
					else if(ssStatus.dwCurrentState == SERVICE_STOPPED)		::StartService(schService, 0, 0);
					else if(ssStatus.dwCurrentState == SERVICE_PAUSED)		::ControlService(schService, SERVICE_CONTROL_CONTINUE, &ssStatus);
					else{
						Sleep(1000);
						if(++nWaitCnt >= MAX_COUNT){
							EventLog(EVENTLOG_ERROR_TYPE, "%s(service name: %s) start failed(timeout).", GetLastErrorText(szErr,256), pArgs[nIndex]);
							return FALSE;
						}
					}
				}
				CloseServiceHandle(schService);
			}else{
				EventLog(EVENTLOG_ERROR_TYPE, "%s(service name: %s) start failed(not exist service name).", GetLastErrorText(szErr,256), pArgs[nIndex]);
				return FALSE;
			}
			CloseServiceHandle(schSCManager);
		}
		nIndex++;
	}
	return TRUE;
}