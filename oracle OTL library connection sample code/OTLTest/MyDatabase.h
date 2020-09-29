#pragma once
#include <string>
#include <iostream>
#include "OTLDatabase.h"
struct DBINFO
{
	CString	strHostName;
	CString	strPort;
	CString	strDatabase;
	CString	strUsername;
	CString	strPassword;
	CString	strScheduledStudyTable;
	CString	strPerformedStudyTable;
};

class CMyDatabase : public COTLDatabase
{
private:
	DBINFO	m_dbinfo;
public:
	CMyDatabase( int nPoolCount=1, int nPoolSize=3);
	~CMyDatabase(void);
public:
	BOOL DBOpen(const DBINFO& dbinfo);
	BOOL GetProfileNumber(CString strSection, CString strEntry, int bDefault);
};
