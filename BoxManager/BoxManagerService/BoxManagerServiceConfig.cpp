/************************************************************************
 *
 *	Copyright (c) 2003, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: CachedoraServiceConfig.cpp $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

#include "BoxManagerServiceConfig.h"
#include "BoxManagerService.h"
#include "BoxManagerServiceVersion.h"
#include "MFregist.h"
#include "MFNetUtil.h"
#include "DirectEx.h"

// general properties
#define	SECTION_GENERAL						("General")
#define	PROP_REGISTRATION_NO				("RegistrationNo")
#define PROP_REGISTRATION_TYPE				("RegistrationType")

// database properties
#define	SECTION_SERVER						_T("Server")
#define PROP_DATABASE						_T("Database")
#define PROP_USERNAME						_T("UserName")
#define PROP_PASSWORD						_T("Password")

// job properties
#define SECTION_JOB							_T("Job")
#define PROP_SOURCE_DIR						_T("SourceDir")
#define PROP_STORE_DIR						_T("StoreDir")


// logger properties
#define	SECTION_LOGGER						("Logger")
#define	PROP_LOG_LEVEL						("LogLevel")
#define PROP_LOG_FILENAME					("LogFilename")
#define	PROP_LOG_DIR							("LogDir")

// Delete properties
#define	SECTION_SERVICE						("Delete")
#define	PROP_DEPENDENCY					("Dependency")
#define  PROP_INTERVAL						("Interval")

///////////////////////////////////////////////////////////////////////////////////////////////

// general properties
#define DEF_REGISTRATION_TYPE				(0)

// database properties
#define	DEF_SERVER_DATABASE					_T("SPECTRA")
#define	DEF_SERVER_USERNAME					_T("spectra")
#define	DEF_SERVER_PASSWORD					(Encrypt(_T("artceps")))

// job properties
#define DEF_REMOVE_DAY						(10)

// logger properties
#define	DEF_LOG_DIR							("\\Log")
#define DEF_LOG_FILENAME					("BoxManager")
#define	DEF_LOG_LEVEL						(1) 

// delete properties
#define	DEF_INTERVAL							(1440)
#define	DEF_SVC_DEPENDENCY						_T("LanmanWorkstation")

CBoxManagerServiceConfig::CBoxManagerServiceConfig(const char* pszServiceName, const char* pszDisplayName, const char* pszMutexName, const char* pszRegistryRootName)
	: CBoxManagerConfigDlg(pszDisplayName)
	, CRegLocalConfig(NULL, pszRegistryRootName)
	, m_mtxConfig(FALSE, pszMutexName)
{
	// Get System Info
	CSingleLock sgl(&m_mtxConfig, TRUE);
	
	CString strDefaultDirectory;
	strDefaultDirectory.Format("%s", _T("C:\\IPACS_CX"));
	m_pSystemInfo = new CSystemInfo();
	CBoxManagerService* pApp = (CBoxManagerService*)AfxGetApp();
	if (pApp->m_pSystemInfoService->IsLoadSystemInfo())
	{
		pApp->m_pSystemInfoService->GetSystemInfo(strDefaultDirectory, NODE_DEFAULT_DIRECTORY_ROOT);

		if (strDefaultDirectory.IsEmpty())
			strDefaultDirectory.Format("%s", _T("C:\\IPACS_CX"));
	}

	m_strDisplayName = pszDisplayName;
	// database properties
	m_strDatabaseName = GetProfileString(SECTION_SERVER, PROP_DATABASE, DEF_SERVER_DATABASE);
	m_strDatabaseUsername = GetProfileString(SECTION_SERVER, PROP_USERNAME, DEF_SERVER_USERNAME);
	m_strDatabasePassword = Decrypt(GetProfileString(SECTION_SERVER, PROP_PASSWORD, DEF_SERVER_PASSWORD));
	// logger properties
	m_strLogDir = GetProfileString(SECTION_LOGGER, PROP_LOG_DIR, strDefaultDirectory + DEF_LOG_DIR);
	m_strLogFilename = GetProfileString(SECTION_LOGGER, PROP_LOG_FILENAME, DEF_LOG_FILENAME);
	m_nLogLevel = GetProfileInt(SECTION_LOGGER, PROP_LOG_LEVEL, DEF_LOG_LEVEL);
	// service properties
	m_nInterVal = GetProfileInt(SECTION_SERVICE, PROP_INTERVAL, DEF_INTERVAL);
	m_strServiceDependency = GetProfileString(SECTION_SERVICE, PROP_DEPENDENCY, DEF_SVC_DEPENDENCY);
}

CBoxManagerServiceConfig::~CBoxManagerServiceConfig(void)
{
}

void
CBoxManagerServiceConfig::Update(void)
{
	CSingleLock sgl(&m_mtxConfig, TRUE);
	BOOL bRet;

	CBoxManagerConfigDlg::Update();

	// server properties
	bRet = WriteProfileString(SECTION_SERVER, PROP_DATABASE, m_strDatabaseName);
	bRet = WriteProfileString(SECTION_SERVER, PROP_USERNAME, m_strDatabaseUsername);
	bRet = WriteProfileString(SECTION_SERVER, PROP_PASSWORD, Decrypt(m_strDatabasePassword));
	
	// logger properties
	bRet = WriteProfileString(SECTION_LOGGER, PROP_LOG_DIR, m_strLogDir);
	bRet = WriteProfileString(SECTION_LOGGER, PROP_LOG_FILENAME, m_strLogFilename);
	bRet = WriteProfileInt(SECTION_LOGGER, PROP_LOG_LEVEL, m_nLogLevel);

	// Service properties
	bRet = WriteProfileInt(SECTION_SERVICE, PROP_INTERVAL, m_nInterVal);
	bRet = WriteProfileString(SECTION_SERVICE, PROP_DEPENDENCY, m_strServiceDependency);
	
	// create directory
	mkdirp(m_strLogDir);
}

void
CBoxManagerServiceConfig::Install()
{
	CBoxManagerService* pMain = (CBoxManagerService*)AfxGetApp();
	CString strMessage;
	if (pMain->InstallService())		
	{
		strMessage.Format("%s was installed.", m_strDisplayName);
		MessageBox(strMessage, "Install", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		strMessage.Format("Failed to install %s.", m_strDisplayName);
		MessageBox(strMessage, "Install", MB_OK | MB_ICONERROR);
	}
}

void
CBoxManagerServiceConfig::Uninstall()
{
	CBoxManagerService* pMain = (CBoxManagerService*)AfxGetApp();
	CString strMessage;
	if (pMain->RemoveService())
	{
		strMessage.Format("%s was uninstalled.", m_strDisplayName);
		MessageBox(strMessage, "Uninstall", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		strMessage.Format("Failed to uninstall %s.", m_strDisplayName);
		MessageBox(strMessage, "Uninstall", MB_OK | MB_ICONERROR);
	}	
}

void
CBoxManagerServiceConfig::Startup()
{
	TCHAR szErr[256];
	CString strMessage;
	CBoxManagerService* pMain = (CBoxManagerService*)AfxGetApp();
	if (pMain->StartupService())
	{
		strMessage.Format("%s started.", m_strDisplayName);
		MessageBox(strMessage, "Startup", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		pMain->GetLastErrorText(szErr,256);
		strMessage.Format("Failed to start %s.", m_strDisplayName);
		MessageBox(strMessage, "Startup", MB_OK | MB_ICONERROR);
	}
}

void
CBoxManagerServiceConfig::Shutdown()
{
	CBoxManagerService* pMain = (CBoxManagerService*)AfxGetApp();
	CString strMessage;
	if (pMain->EndService())
	{
		strMessage.Format("%s stopped.", m_strDisplayName);
		MessageBox(strMessage, "Shutdown", MB_OK | MB_ICONINFORMATION);
	}
	else
	{
		strMessage.Format("Failed to stop %s.", m_strDisplayName);
		MessageBox(strMessage, "Shutdown", MB_OK | MB_ICONERROR);
	}
}

void
CBoxManagerServiceConfig::Save()
{
	MessageBox("Configuration saved.", "Save", MB_OK | MB_ICONINFORMATION);
}

const char* 
CBoxManagerServiceConfig::GetVersion()
{
	return PANDORA_VERSION;
}

const char*
CBoxManagerServiceConfig::GetBuildNumber()
{
	return PANDORA_BUILD_NUMBER;	
}

CString
CBoxManagerServiceConfig::Encrypt(const CString& strText)
{
	CString strResult;
	int nIndex, nLength = strText.GetLength();
	char c;

	for(nIndex = nLength-1; nIndex >= 0; nIndex--)
	{
		c = strText.GetAt(nIndex);
		if (c >= 0x50)
			c -= 0x30;
		else
			c += 0x30;
		strResult += (char)(0x9F - c); //hsshin migration added.(char)
	}
	return strResult;
}

CString
CBoxManagerServiceConfig::Decrypt(const CString& strText)
{
	CString strResult;
	int nIndex, nLength = strText.GetLength();
	char c;

	for(nIndex = nLength-1; nIndex >= 0; nIndex--)
	{
		c = strText.GetAt(nIndex);
		if (c >= 0x50)
			c -= 0x30;
		else
			c += 0x30;
		strResult += (char)(0x9F - c); //hsshin migration added.(char)
	}
	return strResult;
}