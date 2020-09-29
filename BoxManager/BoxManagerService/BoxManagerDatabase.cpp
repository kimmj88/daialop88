
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[22];
};
static const struct sqlcxp sqlfpn =
{
    21,
    "BoxManagerDatabase.pc"
};


static unsigned int sqlctx = 152840211;


static struct sqlexd {
   unsigned int   sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
            void  **sqphsv;
   unsigned int   *sqphsl;
            int   *sqphss;
            void  **sqpind;
            int   *sqpins;
   unsigned int   *sqparm;
   unsigned int   **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
              int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
            void  *sqhstv[5];
   unsigned int   sqhstl[5];
            int   sqhsts[5];
            void  *sqindv[5];
            int   sqinds[5];
   unsigned int   sqharm[5];
   unsigned int   *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

// Prototypes
extern "C" {
  void sqlcxt (void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlcx2t(void **, unsigned int *,
               struct sqlexd *, const struct sqlcxp *);
  void sqlbuft(void **, char *);
  void sqlgs2t(void **, char *);
  void sqlorat(void **, unsigned int *, void *);
}

// Forms Interface
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern "C" { void sqliem(unsigned char *, signed int *); }

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{12,4138,178,0,0,
5,0,0,0,0,0,60,108,0,0,0,0,0,1,0,
20,0,0,0,0,0,58,109,0,0,1,1,0,1,0,3,109,0,0,
39,0,0,0,0,0,59,126,0,0,1,1,0,1,0,3,109,0,0,
58,0,0,0,0,0,1051,183,0,0,4,4,0,0,128,1,97,0,0,1,97,0,0,1,97,0,0,1,10,0,0,1,97,
0,0,
93,0,0,2,0,0,1056,218,0,0,0,0,0,0,128,1,97,0,0,
112,0,0,3,20,0,1028,246,0,0,0,0,0,0,128,1,97,0,0,
131,0,0,4,0,0,1041,335,0,0,1,1,0,0,128,1,97,0,0,1,97,0,0,
154,0,0,4,0,0,1069,336,0,0,0,0,0,0,128,1,97,0,0,
173,0,0,4,0,0,1037,340,0,0,3,0,0,0,128,2,3,0,0,2,9,0,0,2,9,0,0,1,97,0,0,
204,0,0,4,0,0,1039,356,0,0,0,0,0,0,128,1,97,0,0,
223,0,0,5,112,0,1030,461,0,0,3,3,0,0,128,3,9,0,0,3,9,0,0,3,9,0,0,1,97,0,0,
254,0,0,6,96,0,1030,517,0,0,2,2,0,0,128,3,3,0,0,3,3,0,0,1,97,0,0,
281,0,0,7,0,0,1053,550,0,0,0,0,0,0,128,1,97,0,0,
300,0,0,8,0,0,1055,555,0,0,0,0,0,0,128,1,97,0,0,
};


 /************************************************************************
 *
 *	Copyright (c) 1997-2002, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerDatabase.pc $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

#include "BoxManagerDatabase.h"

#include <sys/stat.h>
#include <assert.h>
#include <sqlca.h>

#include "ServerCommon.h"
#include "DirectEx.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif
#ifdef _DEBUG

#define new DEBUG_NEW
#endif
#define _EXT_	_T("dcm")
#define BUF_SIZE 10000; 
char szZIPFileName[_MAX_PATH];


///////////////////////////////////////////////////////////////////////////////////////////////

FBINFO::FBINFO(void)
{
	nThreshold = 95;
	bInUse = FALSE;
}

//#define	TO_PCHAR(str)		((LPTSTR)(LPCSTR)(str))

#define	CSTR_TO_VSTR(strValue, vszValue, niIndicator) \
{ \
	if (strValue.IsEmpty()) \
	{ \
		(niIndicator) = -1; \
	} \
	else \
	{ \
		int nValueSize = sizeof((vszValue).arr); \
		strncpy((char*)(vszValue).arr, TO_PCHAR(strValue), nValueSize); \
		(vszValue).arr[nValueSize - 1] = '\0'; \
		(vszValue).len = strlen((char*)(vszValue).arr); \
		(niIndicator) = 0; \
	} \
}

#define	VSTR_TO_CSTR(vszValue, niIndicator, strValue) \
{ \
	if ((niIndicator) == 0) \
	{ \
		(vszValue).arr[(vszValue).len] = '\0'; \
		strValue = (vszValue).arr; \
	} \
	else \
	{ \
		strValue = ""; \
	} \
}

#define	INIT_VSTR(vstr) \
{ \
	(vstr).len = sizeof((vstr).arr); \
	memset((vstr).arr, 0, (vstr).len); \
} \

#define GET_SQL_ERROR(sqlca, pszErrorText) \
{ \
	pszErrorText = sqlca.sqlerrm.sqlerrmc; \
	pszErrorText[sqlca.sqlerrm.sqlerrml - 1] = 0; \
} 
///////////////////////////////////////////////////////////////////////////////////////////////

DBINFO::DBINFO(void)
{
}

DBINFO::DBINFO(const char* pszDatabase, const char* pszUsername, const char* pszPassword)
{
	strDatabase = pszDatabase;
	strUsername = pszUsername;
	strPassword = pszPassword;
}

//////////////////////////////////////////////////////////////////////

CBoxManagerDatabase::CBoxManagerDatabase(CMFLogger* pLogger)
{
	m_pLogger = pLogger;
	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;

	/* EXEC SQL ENABLE THREADS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL CONTEXT ALLOCATE :sqlContext; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )20;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&sqlContext;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(void *);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	m_sqlSessionContext = sqlContext;
	m_strSessionName = "BoxManager";
	m_bIsDBOpen = FALSE;
}

CBoxManagerDatabase::~CBoxManagerDatabase()
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;

	if (m_bIsDBOpen)
		Close();

	sqlContext = m_sqlSessionContext;
	/* EXEC SQL CONTEXT FREE :sqlContext; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )39;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&sqlContext;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(void *);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


}

BOOL
CBoxManagerDatabase::Open(const DBINFO& dbinfo)
{
	if (m_bIsDBOpen)
		return TRUE;

	m_strDatabase = dbinfo.strDatabase;
	m_strUsername = dbinfo.strUsername;
	m_strPassword = dbinfo.strPassword;

	if (!OpenDBSession())
		return FALSE;

	m_bIsDBOpen = TRUE;

	UINT nOpenCount = 0;


	if (!OpenPublicFolderSession(m_strPublicSourceDir))
	{
		m_pLogger->LogMessage(1, LOG_FAIL, "database: open: distributed server start failed: can't access public upload-folder");
		return FALSE;
	}
	if (m_strPublicSourceDir.IsEmpty())
	{
		m_pLogger->LogMessage(1, LOG_FAIL, "database: open: distributed server start failed: can't find public upload-folder");
		return FALSE;
	}

	m_pLogger->LogMessage(4, LOG_DEBUG, "database: open: find public session source folder (source folder=%s)", m_strPublicSourceDir);


	return TRUE;
}

BOOL
CBoxManagerDatabase::OpenDBSession(void)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
		const char*	sqlSession;
		const char*	sqlDatabase;
		const char*	sqlUsername;
		const char*	sqlPassword;
	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;

	sqlContext = m_sqlSessionContext;
	sqlSession = m_strSessionName;
	sqlDatabase = m_strDatabase;
	sqlUsername = m_strUsername;
	sqlPassword = m_strPassword;

	/* EXEC SQL CONTEXT USE :sqlContext; */ 

	/* EXEC SQL CONNECT :sqlUsername IDENTIFIED BY :sqlPassword AT :sqlSession USING :sqlDatabase; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )10;
 sqlstm.offset = (unsigned int  )58;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)sqlUsername;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sqlPassword;
 sqlstm.sqhstl[1] = (unsigned int  )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)sqlDatabase;
 sqlstm.sqhstl[2] = (unsigned int  )0;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[4] = (         void  *)sqlSession;
 sqlstm.sqhstl[4] = (unsigned int  )0;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         void  *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned int  )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlstm.sqlcmax = (unsigned int )100;
 sqlstm.sqlcmin = (unsigned int )2;
 sqlstm.sqlcincr = (unsigned int )1;
 sqlstm.sqlctimeout = (unsigned int )0;
 sqlstm.sqlcnowait = (unsigned int )0;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}


	if (sqlca.sqlcode != 0)
	{
		SetLastError("database session open failed (db=%s,user=%s,sqlcode=%d)", m_strDatabase, m_strUsername, sqlca.sqlcode);
		m_pLogger->LogMessage(1, LOG_FAIL, "database: open: database session open failed (name=%s,db=%s,user=%s,sqlcode=%d)",
			sqlSession, m_strDatabase, m_strUsername, sqlca.sqlcode);
		return FALSE;
	}
	
	m_pLogger->LogMessage(3, LOG_INFO, "database: open: database session opened (name=%s,db=%s,user=%s)", sqlSession, m_strDatabase, m_strUsername);
	return TRUE;
}

BOOL
CBoxManagerDatabase::Close(void)
{
	CloseDBSession();

	m_bIsDBOpen = FALSE;
	return TRUE;
}

BOOL
CBoxManagerDatabase::CloseDBSession(void)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
		const char* sqlSession;
	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;

	sqlContext = m_sqlSessionContext;
	sqlSession = m_strSessionName;

	/* EXEC SQL CONTEXT USE :sqlContext; */ 

	/* EXEC SQL AT :sqlSession ROLLBACK WORK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )93;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)sqlSession;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}



	if (sqlca.sqlcode != 0)
		m_bIsDBOpen = FALSE;

	m_pLogger->LogMessage(3, LOG_INFO, "database: close: database session closed (name=%s)", sqlSession);
	return TRUE;
}

BOOL
CBoxManagerDatabase::IsOpen(void)
{
	if (!m_bIsDBOpen)
	{
		if (!Open(DBINFO(m_strDatabase, m_strUsername, m_strPassword)))
			return FALSE;
	}

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
		const char* sqlSession;
	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;

	sqlContext = m_sqlSessionContext;
	sqlSession = m_strSessionName;
	/* EXEC SQL CONTEXT USE :sqlContext; */ 

	
	/* EXEC SQL AT :sqlSession	SELECT 1 FROM dual; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select 1  from dual ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )112;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)sqlSession;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}


	if (sqlca.sqlcode == 0)
		return TRUE;

	m_pLogger->LogMessage(1, LOG_FAIL, "database: isopen: database session broken (name=%s)", sqlSession);

	CloseDBSession();
	return OpenDBSession();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////

const char*
CBoxManagerDatabase::GetLastError(void)
{
	return m_strLastError;
}

void
CBoxManagerDatabase::SetLastError(const char* pszFormat, ...)
{
	va_list ap;

	va_start(ap, pszFormat);
	vsprintf(m_strLastError.GetBuffer(256), pszFormat, ap);
	m_strLastError.ReleaseBuffer();
	va_end(ap);
}

const char*
CBoxManagerDatabase::GetVersion(void)
{
	CString strWorkfile = "$Workfile: BoxManagerDatabase.pc $";
	CString strRevision = "$Revision: 1 $";
	CString strDate = "$Date: 08-12-22 9:30a $";
	static CString strVersion;

	strWorkfile.Replace("$", ""); strWorkfile.TrimLeft(); strWorkfile.TrimRight();
	strRevision.Replace("$", ""); strRevision.TrimLeft(); strRevision.TrimRight();
	strDate.Replace("$", ""); strDate.TrimLeft(); strDate.TrimRight();
	strVersion.Format("%s, %s, %s", strWorkfile, strRevision, strDate);

	return strVersion;
}

BOOL
CBoxManagerDatabase::GetAllRecord(list<INTERBOXINFO>* list_ibinfo)
{
	CSingleLock sgl(&m_mtxDatabase, TRUE);

	if (!IsOpen())
	{
		//m_pLogger->LogMessage(1, LOG_FAIL, "%s: %s: failed (broken)", strModuleName, strFuncName);
		return FALSE;
	}

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
		const char* sqlSession;
		const char*	pszSQLstmt;

		int		nJob_key;
		/* VARCHAR	szJobType[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } szJobType;

		/* VARCHAR szJobStat[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } szJobStat;


		short	niJobType = 0;
		short	niJobStat = 0;


	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;
	INTERBOXINFO	ibinfo;
	CString strSQLstmt;
	CString strHostname, strSharename, strProtocol;
	UINT nPort = 3004;

	sqlContext = m_sqlSessionContext;
	sqlSession = m_strSessionName;

	list_ibinfo->clear();

	//////as
	/* EXEC SQL CONTEXT USE :sqlContext; */ 

	strSQLstmt.Format("SELECT JOB_KEY, JOB_TYPE, JOB_STAT FROM INTERBOX WHERE DELETE_REQUEST = 'Y'");
	pszSQLstmt = strSQLstmt;
	/* EXEC SQL AT :sqlSession DECLARE sql_volume STATEMENT; */ 

	/* EXEC SQL AT :sqlSession DECLARE cur_volume CURSOR FOR sql_volume; */ 

	/* EXEC SQL AT :sqlSession PREPARE sql_volume FROM :pszSQLstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )131;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)pszSQLstmt;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)sqlSession;
 sqlstm.sqhstl[1] = (unsigned int  )0;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL AT :sqlSession OPEN cur_volume; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )154;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (         void  *)sqlSession;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}



	while(sqlca.sqlcode == 0)
	{
		/* EXEC SQL AT :sqlSession FETCH cur_volume
			INTO :nJob_key,
				:szJobType:niJobType, 
				:szJobStat:niJobStat; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )173;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (           int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (         void  *)&nJob_key;
  sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (         void  *)&szJobType;
  sqlstm.sqhstl[1] = (unsigned int  )12;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         void  *)&niJobType;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned int  )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (         void  *)&szJobStat;
  sqlstm.sqhstl[2] = (unsigned int  )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         void  *)&niJobStat;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned int  )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (         void  *)sqlSession;
  sqlstm.sqhstl[3] = (unsigned int  )0;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         void  *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned int  )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}



		if (sqlca.sqlcode != 0)
		{
			break;
		}
		ibinfo.nJob_key = nJob_key;
		VSTR_TO_CSTR(szJobType, niJobType, ibinfo.strJobType);
		VSTR_TO_CSTR(szJobStat, niJobStat, ibinfo.strJobStat);

		
		list_ibinfo->push_back(ibinfo);
	}
	/* EXEC SQL AT :sqlSession CLOSE cur_volume; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )204;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)sqlSession;
 sqlstm.sqhstl[0] = (unsigned int  )0;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}



//	m_bIgnoreOpenError = FALSE;
	
	if (list_ibinfo->size() == 0)
	{
		return FALSE;
	}
	return TRUE;
}

BOOL
CBoxManagerDatabase::OpenFBSession(FBINFO& fbinfo)
{
	NETRESOURCE netrc;
	DWORD nRet;

	netrc.dwType = RESOURCETYPE_DISK;
	netrc.lpLocalName = NULL;
	netrc.lpRemoteName = (LPTSTR)(LPCSTR)fbinfo.strVolumePath;
	netrc.lpProvider = NULL;
	nRet = WNetAddConnection2(&netrc, fbinfo.strPassword, fbinfo.strUsername, 0);
	if (nRet != NO_ERROR)
	{
		fbinfo.bInUse = FALSE;
		SetLastError("filebase attach failed (volume=%s[%s],user=%s,error=%s,neterror=%s)", 
			fbinfo.strVolumePath, fbinfo.strVolumeCode, fbinfo.strUsername, GET_ERRORINFO, GetNetErrorMessage(nRet));
		m_pLogger->LogMessage(1, LOG_FAIL, "database: open: filebase attach failed (volume=%s, user=%s,error=%s,neterror=%s)", 
			fbinfo.strVolumePath, fbinfo.strUsername, GET_ERRORINFO, GetNetErrorMessage(nRet));			
		return FALSE;
	}
	fbinfo.bInUse = TRUE;
	m_pLogger->LogMessage(3, LOG_INFO, "database: open: filebase attached (Folder Path=%s, User=%s)", 
		fbinfo.strVolumePath, fbinfo.strUsername);
	return TRUE;
}

BOOL
CBoxManagerDatabase::CloseFBSession(FBINFO& fbinfo)
{
	if (fbinfo.bInUse)
	{
		WNetCancelConnection2(fbinfo.strVolumePath, 0, TRUE);

		fbinfo.bInUse = FALSE;
		m_pLogger->LogMessage(4, LOG_DEBUG, "database: close: filebase detached (volume=%s[%s])", 
			fbinfo.strVolumePath, fbinfo.strVolumeCode);
	}
	return TRUE;
}

BOOL
CBoxManagerDatabase::OpenPublicFolderSession(CString& strPublicUploadDir)
{
	CString strUsername, strPassword;
	BOOL bRet = TRUE;

	strPublicUploadDir = GetProfileString("INTERBOX", "SHAREPATH", "");
	strUsername = GetProfileString("INTERBOX", "USERID", "");
	strPassword = GetProfileString("INTERBOX", "PASSWORD", "");
	
	FBINFO fbinfo;

	fbinfo.strUsername = strUsername;
	fbinfo.strPassword = strPassword;
	fbinfo.bInUse = TRUE;
	fbinfo.strVolumePath = strPublicUploadDir;

	bRet = OpenFBSession(fbinfo);
	
	m_bUsePublicUploadDir = bRet;

	return bRet;
}

CString
CBoxManagerDatabase::GetProfileString(CString strSection, CString strEntry, CString strValue)
{
	CSingleLock sgl(&m_mtxDatabase, TRUE);

	if (!IsOpen())
	{
//		m_pLogger->LogMessage(1, LOG_FAIL, "%s: %s: failed (broken)", strModuleName, strFuncName);
		return strValue;
	}

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
		const char* sqlSession;

		/* VARCHAR		szSection[70], szEntry[70], szValue[2050]; */ 
struct { unsigned short len; unsigned char arr[70]; } szSection;

struct { unsigned short len; unsigned char arr[70]; } szEntry;

struct { unsigned short len; unsigned char arr[2050]; } szValue;

		short		niSection, niEntry, niValue;
	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;
	char* pszSQLError;

	sqlContext = m_sqlSessionContext;
	sqlSession = m_strSessionName;

	/* EXEC SQL CONTEXT USE :sqlContext; */ 


	CSTR_TO_VSTR(strSection, szSection, niSection);
	CSTR_TO_VSTR(strEntry, szEntry, niEntry);
	CSTR_TO_VSTR(strValue, szValue, niValue);

	/* EXEC SQL AT :sqlSession EXECUTE
	BEGIN
		:szValue:niValue := sp_profile.get_string(:szSection:niSection, :szEntry:niEntry, :szValue);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :szValue:niValue := sp_profile . get_string ( :szSecti\
on:niSection , :szEntry:niEntry , :szValue ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )223;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&szValue;
 sqlstm.sqhstl[0] = (unsigned int  )2052;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&niValue;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&szSection;
 sqlstm.sqhstl[1] = (unsigned int  )72;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&niSection;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)&szEntry;
 sqlstm.sqhstl[2] = (unsigned int  )72;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)&niEntry;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (         void  *)sqlSession;
 sqlstm.sqhstl[3] = (unsigned int  )0;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         void  *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned int  )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}


	if (sqlca.sqlcode != 0)
	{
		GET_SQL_ERROR(sqlca, pszSQLError);
		m_pLogger->LogMessage(1, LOG_FAIL, "database: get-profile-failed (section=%s,entry=%s,sqlerrm=%s)", strSection, strEntry, pszSQLError);
		return strValue;
	}

	VSTR_TO_CSTR(szValue, niValue, strValue);
	return strValue;
}

CString
CBoxManagerDatabase::GetShareFolderFullPath()
{
	return	m_strPublicSourceDir;
}

BOOL	
CBoxManagerDatabase::DeletedStatus(int nJob_key, int nErrorCode)
{
	CSingleLock sgl(&m_mtxDatabase, TRUE);

	if (!IsOpen())
	{
//		m_pLogger->LogMessage(1, LOG_FAIL, "%s: %s: failed (broken)", strModuleName, strFuncName);
		return 0;
	}

	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
		const char* sqlSession;

		int			nErrorcode;
		short		niErrorcode;
		short		niJob_key;

	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;
	char* pszSQLError;

	
	sqlContext = m_sqlSessionContext;
	sqlSession = m_strSessionName;

	niErrorcode = 0;

	/* EXEC SQL CONTEXT USE :sqlContext; */ 

	nErrorCode = nErrorCode;

	niJob_key = (short)nJob_key;

	/* EXEC SQL AT :sqlSession EXECUTE
	BEGIN
		SP_INTERBOX.SET_STATUS_DELETED(:nJob_key:niJob_key,  :nErrorcode:niErrorcode);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin SP_INTERBOX . SET_STATUS_DELETED ( :nJob_key:niJob_key\
 , :nErrorcode:niErrorcode ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )254;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (         void  *)&nJob_key;
 sqlstm.sqhstl[0] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         void  *)&niJob_key;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned int  )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (         void  *)&nErrorcode;
 sqlstm.sqhstl[1] = (unsigned int  )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         void  *)&niErrorcode;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned int  )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (         void  *)sqlSession;
 sqlstm.sqhstl[2] = (unsigned int  )0;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         void  *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned int  )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}



	if (sqlca.sqlcode != 0)
	{
		GET_SQL_ERROR(sqlca, pszSQLError);
		
		//m_pLogger->LogMessage(1, LOG_FAIL, "database: get-profile-boolean (section=%s,entry=%s,sqlerrm=%s)", strSection, strEntry, pszSQLError);
		return FALSE;
	}

	return TRUE;
}

BOOL
CBoxManagerDatabase::IsRollBackInterBoxStatus(BOOL bDelete, CString strFolderPath)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		SQL_CONTEXT sqlContext;
		const char* sqlSession;
	/* EXEC SQL END DECLARE SECTION; */ 

	struct sqlca sqlca;

	sqlContext = m_sqlSessionContext;
	sqlSession = m_strSessionName;

	/* EXEC SQL CONTEXT USE :sqlContext; */ 


	if(bDelete)
	{
		/* EXEC SQL AT :sqlSession COMMIT WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )281;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)sqlSession;
  sqlstm.sqhstl[0] = (unsigned int  )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}


		m_pLogger->LogMessage(3, LOG_INFO, _T("Deletion Files : Folder Path = %s with Database Commit"), strFolderPath);
	}
	else
	{
		/* EXEC SQL AT :sqlSession ROLLBACK WORK; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )300;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (         void  *)sqlSession;
  sqlstm.sqhstl[0] = (unsigned int  )0;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         void  *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned int  )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqphsv = sqlstm.sqhstv;
  sqlstm.sqphsl = sqlstm.sqhstl;
  sqlstm.sqphss = sqlstm.sqhsts;
  sqlstm.sqpind = sqlstm.sqindv;
  sqlstm.sqpins = sqlstm.sqinds;
  sqlstm.sqparm = sqlstm.sqharm;
  sqlstm.sqparc = sqlstm.sqharc;
  sqlstm.sqpadto = sqlstm.sqadto;
  sqlstm.sqptdso = sqlstm.sqtdso;
  sqlcxt(&sqlContext, &sqlctx, &sqlstm, &sqlfpn);
}


		m_pLogger->LogMessage(1, LOG_FAIL, _T("Deletion Failed :Folder Path = %s with Database Rollback"), strFolderPath);
		
	}
	if (sqlca.sqlcode != 0)
		m_bIsDBOpen = FALSE;

	return TRUE;
}
CString
CBoxManagerDatabase::GetDatabaseName()
{
	return m_strDatabase;
}
