/************************************************************************
 *
 *	Copyright (c) 1997-2001, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerRemove.h $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// BoxManageraPutter.h: interface for the CBoxManagerRemove class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CachedoraPutter_H__A8AD7A24_9666_47EA_A543_4B9696F06DAC__INCLUDED_)
#define AFX_CachedoraPutter_H__A8AD7A24_9666_47EA_A543_4B9696F06DAC__INCLUDED_

#include "MFLogger.h"
#include "ThinThread.h"
#include "BoxManagerDatabase.h"

#import "msxml4.dll"
//using namespace MSXML2; hsshin migration deleted.

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct SPFILEINFO
{
	CTime		tmModifiedTime;
	CString		strFullPath;
	CString		strPathname;
	CString		strFilename;
	CString		strDstFilePath;

	friend bool	operator==(const SPFILEINFO& a, const SPFILEINFO& b);
	friend bool	operator!=(const SPFILEINFO& a, const SPFILEINFO& b);
	friend bool	operator<(const SPFILEINFO& a, const SPFILEINFO& b);
	friend bool	operator>(const SPFILEINFO& a, const SPFILEINFO& b);
};

class CBoxManagerRemove : public CThinThread  
{
private:
	CStringList m_FnameList;
protected:
	IXMLDOMDocumentPtr		m_pXMLDoc;
	CMFLogger*				m_pLogger;
	CBoxManagerDatabase*			m_pDatabase;
	PANDORAINFO*			m_pbi;

	HANDLE					m_hStop;
	
	CString					m_strJobUid;

public:
	CBoxManagerRemove(CMFLogger* pLogger);
	virtual ~CBoxManagerRemove();

	BOOL	Start(CBoxManagerDatabase* pDatabase, PANDORAINFO* pbi);
	BOOL	Stop(void);

	CMFLogger*	GetLogger(void);
	const char*	GetVersion(void);

	BOOL DeleteDirectoryAndFiles(CString FoldrPath, int nJob_key);
	void DeleteInterBox(CString strDeletePath, int nJob_key);
	

protected:
	void	Run(void);
	
};

#endif // !defined(AFX_BoxManagerRemove_H__A8AD7A24_9666_47EA_A543_4B9696F06DAC__INCLUDED_)
