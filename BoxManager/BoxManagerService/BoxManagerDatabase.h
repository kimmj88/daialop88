/************************************************************************
 *
 *	Copyright (c) 1997-2001, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerDatabase.h $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// BoxManagerDatabase.h: interface for the CBoxManagerDatabase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CachedoraDatabase_H__762DA965_FBE8_4210_AAA8_5A3D25959576__INCLUDED_)
#define AFX_CachedoraDatabase_H__762DA965_FBE8_4210_AAA8_5A3D25959576__INCLUDED_

#include "MFLogger.h"
#include "Dcm.h"
#include <List>


#define FILE_FOLDER	_T("파일 폴더")


using namespace std;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*------------------------------------------------------------------------------------*/
//#define	TO_PCHAR(str)		((LPTSTR)(LPCSTR)(str))

struct PANDORAINFO
{
	CString	strSourceDir;
	CString strStoreDir;
	int nInterval;
};


struct FBINFO
{
	CString strVolumeType;
	CString	strVolumeCode;
	CString	strVolumePath;
	CString	strUsername;
	CString	strPassword;
	CString strInstitutionCode;
	UINT	nThreshold;
	BOOL	bInUse;

	FBINFO(void);

	friend bool	operator==(const FBINFO& a, const FBINFO& b);
	friend bool	operator!=(const FBINFO& a, const FBINFO& b);
	friend bool	operator<(const FBINFO& a, const FBINFO& b);
	friend bool	operator>(const FBINFO& a, const FBINFO& b);
};

struct INTERBOXINFO
{
	int	nJob_key;
	CString strJobType;
	CString	strJobStat;

	friend bool	operator==(const INTERBOXINFO& a, const INTERBOXINFO& b);
	friend bool	operator!=(const INTERBOXINFO& a, const INTERBOXINFO& b);
	friend bool	operator<(const INTERBOXINFO& a, const INTERBOXINFO& b);
	friend bool	operator>(const INTERBOXINFO& a, const INTERBOXINFO& b);
};

struct DBINFO
{
	CString	strDatabase;
	CString	strUsername;
	CString	strPassword;

	DBINFO(void);
	DBINFO(const char* pszDatabase, const char* pszUsername, const char* pszPassword);
};

/*------------------------------------------------------------------------------------*/

class CBoxManagerDatabase  
{
protected:
	CMFLogger*		m_pLogger;
//	CThzlib			m_zlib;

	// database
	CMutex				m_mtxDatabase;
	void*				m_sqlSessionContext;
	CString				m_strSessionName;
	CString				m_strDatabase;
	CString				m_strUsername;
	CString				m_strPassword;

	BOOL				m_bIsDBOpen;
	CString				m_strLastError;

	BOOL				m_bUsePublicUploadDir;	

	list<FBINFO>		m_fbl;
	list<INTERBOXINFO>	m_ibinfo;

public:
	CBoxManagerDatabase(CMFLogger* pLogger);
	virtual ~CBoxManagerDatabase();

	BOOL	Open(const DBINFO& dbinfo);
	BOOL	Close(void);
	BOOL	IsOpen(void);
	
	BOOL	OpenPublicFolderSession(CString& strPublicUploadDir);
	CString	GetProfileString(CString strSection, CString strEntry, CString strValue = "");

	BOOL	GetAllRecord(list<INTERBOXINFO>* list_ibinfo);
	BOOL	DeletedStatus(int nJob_key, int nErrorCode);
	BOOL	IsRollBackInterBoxStatus(BOOL bDelete, CString strFolderPath);


	CString	GetShareFolderFullPath();
	CString GetDatabaseName();

	CString	m_strPublicSourceDir;

	
	const char*	GetLastError(void);
	const char*	GetVersion(void);


protected:
	// database
	BOOL	OpenDBSession(void);
	BOOL	CloseDBSession(void);

	BOOL	OpenFBSession(FBINFO& fbinfo);
	BOOL	CloseFBSession(FBINFO& fbinfo);

	// error
	void	SetLastError(const char* pszFormat, ...);

};

#endif // !defined(AFX_BoxManagerDatabase_H__762DA965_FBE8_4210_AAA8_5A3D25959576__INCLUDED_)
