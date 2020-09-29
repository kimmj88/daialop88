
// ProcTestDialog.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProcTestDialogApp:
// See ProcTestDialog.cpp for the implementation of this class
//

class CProcTestDialogApp : public CWinAppEx
{
public:
	CProcTestDialogApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CProcTestDialogApp theApp;