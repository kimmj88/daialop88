/************************************************************************
 *
 *	Copyright (c) 2003, INFINITT Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerServiceConfig.h $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

#ifndef	__CachedoraServiceCONFIG_H
#define	__CachedoraServiceCONFIG_H

#include "stdafx.h"
#include <afxmt.h>
#include "../BoxManagerConfig/BoxManagerConfigDlg.h"
#include "RegLocalConfig.h"
//#include "SystemInfo.h"

#define	DEF_PANDORA_SERVICE_NAME		TEXT("BoxManager")
#define	DEF_PANDORA_DISPLAY_NAME		TEXT("InterBox Manager")

class CBoxManagerServiceConfig : public CBoxManagerConfigDlg, public CRegLocalConfig
{
protected:
	CMutex		m_mtxConfig;

public:
	CBoxManagerServiceConfig(const char* pszServiceName, const char* pszDisplayName, const char* pszMutexName, const char* pszRegistryRootName);
	virtual ~CBoxManagerServiceConfig(void);

	virtual void	Update(void);

	virtual void	Install(void);
	virtual void	Uninstall(void);
	virtual void	Startup(void);
	virtual void	Shutdown(void);
	virtual void	Save(void);
	
	virtual const char* GetVersion(void);
	virtual const char* GetBuildNumber(void);
	CString			m_strDisplayName;

	//CSystemInfo m_CSystemInfo;
	CSystemInfo*	m_pSystemInfo;

protected:
	virtual CString	Encrypt(const CString& strText);
	virtual CString	Decrypt(const CString& strText);
};

#endif	// __BoxManagerServiceCONFIG_H