// Thzlib.cpp: implementation of the CThzlib class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "MultiFiler.h"
#include "Thzlib.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CThzlib::CThzlib( CWnd* pTarget )
{

	m_pTarget = pTarget;
}

CThzlib::~CThzlib()
{      

}

void CThzlib::InitZTarget( CWnd* pWnd )
{	
	ASSERT( pWnd );
	m_pTarget = pWnd;
}

void CThzlib::progress( int nPercent )
{
	m_pTarget->SendMessage( Z_PROGRESS, (WPARAM)nPercent,0L );
}

void CThzlib::status( char* message )
{
	m_sStatus = message;
	m_pTarget->SendMessage( Z_STATUS );
}

void CThzlib::AbortProcess()
{
	set_abort_flag(1); 
}