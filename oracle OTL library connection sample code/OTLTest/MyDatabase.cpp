#include "MyDatabase.h"

CMyDatabase::CMyDatabase( int nPoolCount, int nPoolSize):COTLDatabase(nPoolCount, nPoolSize)
{
}

CMyDatabase::~CMyDatabase(void)
{
}

BOOL CMyDatabase::DBOpen(const DBINFO& dbinfo)
{
	m_dbinfo = dbinfo;
	SetConnInfo(0, m_dbinfo.strHostName, m_dbinfo.strPort, m_dbinfo.strUsername, m_dbinfo.strPassword, m_dbinfo.strDatabase);
	if(Open(0,0) > 0)
	{
		MessageBox(0, L"Successful DB Connection", 0,  0);
		return TRUE;
	}
	return FALSE;
}

BOOL CMyDatabase::GetProfileNumber(CString strSection, CString strEntry, int bDefault)
{
	CString strValue, strError;

	int	nIndex = Lock(0);
	if(nIndex == -1) {
		
		return FALSE;
	}

	SetQuery(0, nIndex, "sp_profile", "get_number(:p01,:p02,:p03)", ":p04");
	SetParameter(0, nIndex, ":p01", typeChar,	 IN_PARAM, 64, strSection);
	SetParameter(0, nIndex, ":p02", typeChar,	 IN_PARAM, 64, strEntry);
	SetParameter(0, nIndex, ":p03", typeInteger, IN_PARAM,	   bDefault);
	SetParameter(0, nIndex, ":p04", typeInteger, OUT_PARAM);

	if(ExecuteQuery(0, nIndex, CmdStoredProc) < 0)	
		goto on_failure;

	while(NextRecord(0, nIndex) > 0) {
		GetFieldValue(0, nIndex, 0, strValue);
	}		

	UnLock(0, nIndex);

	return _ttoi(strValue);


on_failure:
	strError = GetLastSessionError(0, nIndex);				
	

	UnLock(0, nIndex);
	return FALSE;	
}