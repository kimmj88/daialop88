/************************************************************************
 *
 *	Copyright (c) 1997-2001, Mediface Co., Ltd.
 *	All Rights Reserved
 *
 *	$Workfile: BoxManagerConfig.cpp $
 *	$Author: Jin0416 $
 *	$Date: 08-12-22 9:30a $
 *	$Revision: 1 $
 *
 ************************************************************************/

// BoxManagerConfig.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include <afxdllx.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


static AFX_EXTENSION_MODULE BoxManagerConfigDLL = { NULL, NULL };

extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// Remove this if you use lpReserved
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("BoxManager.DLL Initializing!\n");
		
		// Extension DLL one-time initialization
		if (!AfxInitExtensionModule(BoxManagerConfigDLL, hInstance))
			return 0;

		// Insert this DLL into the resource chain
		// NOTE: If this Extension DLL is being implicitly linked to by
		//  an MFC Regular DLL (such as an ActiveX Control)
		//  instead of an MFC application, then you will want to
		//  remove this line from DllMain and put it in a separate
		//  function exported from this Extension DLL.  The Regular DLL
		//  that uses this Extension DLL should then explicitly call that
		//  function to initialize this Extension DLL.  Otherwise,
		//  the CDynLinkLibrary object will not be attached to the
		//  Regular DLL's resource chain, and serious problems will
		//  result.

		new CDynLinkLibrary(BoxManagerConfigDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("BoxManagerConfig.DLL Terminating!\n");
		// Terminate the library before destructors are called
		AfxTermExtensionModule(BoxManagerConfigDLL);
	}
	return 1;   // ok
}
