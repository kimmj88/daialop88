/************************************************************************
 *
 *	Copyright (c) 1997-2001, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerRemove.cpp $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// BoxManagerRemove.cpp: implementation of the CBoxManagerRemove class.
//
//////////////////////////////////////////////////////////////////////


#include "BoxManagerRemove.h"
#include "MFmacro.h"
#include "DirectEx.h"
#include "IRSCipherLib.h"

#include <sys/stat.h>
#include <direct.h>
#include <shellapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define DECRYPT_KEY				_T("!@#")

//////////////////////////////////////////////////////////////////////

bool	operator<(const SPFILEINFO& a, const SPFILEINFO& b)
{
	return (a.tmModifiedTime < b.tmModifiedTime) ? true : false;
}

bool	operator>(const SPFILEINFO& a, const SPFILEINFO& b)
{
	return (a.tmModifiedTime > b.tmModifiedTime) ? true : false;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBoxManagerRemove::CBoxManagerRemove(CMFLogger* pLogger)
{
	m_pLogger = pLogger;
}

CBoxManagerRemove::~CBoxManagerRemove()
{
	if (IsThreadRunning())
		Stop();
}

BOOL
CBoxManagerRemove::Start(CBoxManagerDatabase* pDatabase, PANDORAINFO* pbi)
{
	m_pDatabase = pDatabase;
	m_pbi = pbi;

	return CThinThread::Start();
}

BOOL
CBoxManagerRemove::Stop(void)
{
	if (m_hStop)
		::SetEvent(m_hStop);
	return CThinThread::Stop();
}

CMFLogger*
CBoxManagerRemove::GetLogger(void)
{
	return m_pLogger;
}

const char*
CBoxManagerRemove::GetVersion(void)
{
	CString strWorkfile = "$Workfile: BoxManagerRemove.cpp $";
	CString strRevision = "$Revision: 1 $";
	CString strDate = "$Date: 08-12-22 9:30a $";
	static CString strVersion;

	strWorkfile.Replace("$", ""); strWorkfile.TrimLeft(); strWorkfile.TrimRight();
	strRevision.Replace("$", ""); strRevision.TrimLeft(); strRevision.TrimRight();
	strDate.Replace("$", ""); strDate.TrimLeft(); strDate.TrimRight();
	strVersion.Format("%s, %s, %s", strWorkfile, strRevision, strDate);

	return strVersion;
}

//////////////////////////////////////////////////////////////////////////////////////////

void CBoxManagerRemove::Run(void)
{
	HRESULT hr = CoInitialize(NULL);
	int nPos;
	CString strProgramPath;
	CString strUploadDir;

	GetModuleFileName(NULL, (LPTSTR)strProgramPath.GetBuffer(_MAX_PATH), _MAX_PATH);
	strProgramPath.ReleaseBuffer();
	if ((nPos = strProgramPath.ReverseFind('\\')) >= 0)
		strProgramPath = strProgramPath.Left(nPos);

	m_hStop = ::CreateEvent(0, TRUE, FALSE, "/EVENT/BoxManager/InterBoxRemove");
	do
	{	
 		list<INTERBOXINFO> list_ibinfo;
		
		if(m_pDatabase->GetAllRecord(&list_ibinfo))
		{
			CString strJobType, strJob_key;
			int RecordSizeCount = 1;
			m_pLogger->LogMessage(3, LOG_INFO, _T("Delete Size = %d"), list_ibinfo.size()); 
 			for(list<INTERBOXINFO>::iterator fbli = list_ibinfo.begin(); fbli != list_ibinfo.end(); fbli++)
			{
				m_pLogger->LogMessage(3, LOG_INFO, _T("Deleting %d/%d : Job_key = %d, Job_type = %s"), RecordSizeCount, list_ibinfo.size(), fbli->nJob_key, fbli->strJobType);
				INTERBOXINFO* pIbinfo = (INTERBOXINFO*)(&(*fbli));  
				strJobType = pIbinfo->strJobType;
				strJob_key.Format(_T("%d"), pIbinfo->nJob_key);

				CString strCombinePath;
				strCombinePath.Format(_T("%s\\%s"),m_pDatabase->GetShareFolderFullPath(), strJobType+strJob_key);
				DeleteInterBox(strCombinePath, pIbinfo->nJob_key);
				RecordSizeCount++;
			}
		}
	}
	while(::WaitForSingleObject(m_hStop, (m_pbi->nInterval * 60) * 1000) != WAIT_OBJECT_0);
	if (m_hStop)
		::CloseHandle(m_hStop);

	CoUninitialize();
}

BOOL CBoxManagerRemove::DeleteDirectoryAndFiles(CString strDeletePath, int nJob_key)
{
	
	CFileFind find;
	CString fname = _T("");;
	CString fname_buf = _T("");
	CString strShareFolderPath = strDeletePath;
	strShareFolderPath += _T("\\*.*");

	int res = 1;
	int nFailCount = 0;

	if(!m_pDatabase->DeletedStatus(nJob_key, 1))
	{
		return FALSE;
	}
	
	if(BOOL bCheck = find.FindFile(strDeletePath)==NULL)
	{
		m_pLogger->LogMessage(0, LOG_FAIL, _T("Dicom File Not Found : Delete Target Path = %s"), strDeletePath);
		m_pDatabase->IsRollBackInterBoxStatus(FALSE, strDeletePath);
		return FALSE;
	}

	find.FindFile(strShareFolderPath);
	
	while(res)
	{
		res = find.FindNextFile();
		fname = find.GetFileName();
		
		if(!(fname == _T(".") || fname == _T("..")))
		{
			CString strDeleteDirectory;
			strDeleteDirectory.Format(_T("%s\\%s"), strDeletePath, fname);
			m_pLogger->LogMessage(3, LOG_INFO, _T("File Deleted : %s"), fname);

			if(!DeleteFile(strDeleteDirectory))
				nFailCount++;
		}
	}
	if(nFailCount > 0)
	{
		m_pDatabase->IsRollBackInterBoxStatus(FALSE, strDeletePath);
	}
	else
	{
		m_pDatabase->IsRollBackInterBoxStatus(TRUE, strDeletePath);
	}
	return TRUE;
}

void CBoxManagerRemove::DeleteInterBox(CString strDeletePath, int nJob_key)
{
	if(DeleteDirectoryAndFiles(strDeletePath, nJob_key))
	{
		RemoveDirectory(_T(strDeletePath));
	}
}