#include "stdafx.h"
#include "SystemInfo.h"

CSystemInfo::CSystemInfo()
{
	int			nPos;
	CString		strProgramPath;

	GetModuleFileName(NULL, (LPTSTR)strProgramPath.GetBuffer(_MAX_PATH), _MAX_PATH);
	strProgramPath.ReleaseBuffer();
	if ((nPos = strProgramPath.ReverseFind('\\')) >= 0)
		strProgramPath = strProgramPath.Left(nPos);
	
	m_strExcutePath = strProgramPath;
	m_strSystemInfoPath = m_strExcutePath + _T("\\") + SYSTEMINFO_FILENAME ;
	
}

CSystemInfo::CSystemInfo(const char* pszSystemInfoPath)
{

	int			nPos;
	CString		strProgramPath;

	GetModuleFileName(NULL, (LPTSTR)strProgramPath.GetBuffer(_MAX_PATH), _MAX_PATH);
	strProgramPath.ReleaseBuffer();
	if ((nPos = strProgramPath.ReverseFind('\\')) >= 0)
		strProgramPath = strProgramPath.Left(nPos);
	
	m_strExcutePath = strProgramPath;
	m_strSystemInfoPath = pszSystemInfoPath;

}

CSystemInfo::~CSystemInfo()
{
}

BOOL
CSystemInfo::LoadSystemInfo()
{
	try
	{
		HRESULT hResult = NULL;
		MSXML2::IXMLDOMNodePtr pRoot;

		pXMLDoc.CreateInstance(__uuidof(MSXML2::DOMDocument40));

		hResult = pXMLDoc->load(_bstr_t(m_strSystemInfoPath));
		
		if (pRoot = pXMLDoc->selectSingleNode(_bstr_t("system_info")))
		{
			
 			for (int i=0; i<sizeof(g_SystemInfoList)/sizeof(g_SystemInfoList[0]); ++i)
			{
				CString strTemp;
				strTemp.Format("%s", (LPSTR)(pRoot->selectSingleNode(_bstr_t(g_SystemInfoList[i].pszNodeName))->text));

				ZeroMemory(g_SystemInfoList[i].pszValue, sizeof(g_SystemInfoList[i].pszValue));
				memcpy(g_SystemInfoList[i].pszValue, strTemp, strTemp.GetLength());
			}

			return m_bSystemInfoLoadStatus = TRUE;
		}
		else
		{
			return m_bSystemInfoLoadStatus = FALSE;
		}
		
	}
	catch(...)
	{
		return m_bSystemInfoLoadStatus = FALSE;
	}
}

BOOL
CSystemInfo::IsLoadSystemInfo()
{
	return m_bSystemInfoLoadStatus;
}

void
CSystemInfo::GetSystemInfo(CString& strValue, NODE_KIND nNode)
{
	try
	{
		strValue = (LPSTR)(LPCTSTR)g_SystemInfoList[nNode].pszValue; 
	}
	catch(...)
	{
		strValue = _T("");
	}
}

void 
CSystemInfo::GetSystemInfo(HBITMAP& hBitmap, NODE_KIND nNode)
{
	try
	{
		CString strOriFilePath = (LPSTR)(LPCTSTR)g_SystemInfoList[nNode].pszValue;
		CString strNewFilePath;

		if (strOriFilePath.Find(_T(":"), 0) >= 0)				// FullPath가 있을경우
			strNewFilePath = strOriFilePath;
		else if (strOriFilePath.Find(_T("\\"), 0) < 0)			// FileName만 있을경우
			strNewFilePath = m_strExcutePath + _T("\\") + strOriFilePath;
		else if (strOriFilePath.Find(_T(".\\"), 0) >= 0)		// 하위 폴더에 있을경우
			strNewFilePath = m_strExcutePath + strOriFilePath.Mid(1);
		else
			strNewFilePath = strOriFilePath;
		
		hBitmap = (HBITMAP)::LoadImage(AfxGetInstanceHandle(), strNewFilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	catch(...)
	{
		hBitmap = NULL;
	}
}

BOOL
CSystemInfo::ParseXML(CString& strValue, CString strElement, MSXML2::IXMLDOMNodePtr pParentNode)
{
	try
	{
		MSXML2::IXMLDOMNodePtr pNode;

		pNode = pParentNode->selectSingleNode(_bstr_t(strElement));
		strValue = LPTSTR(pNode->text);
		strValue.Replace("\n","\r\n");

		return TRUE;
	}
	catch(...)
	{
		return FALSE;
	}
}


void  
CSystemInfo::MoveImage(CPoint& point, CStatic* imgPic)
{
	try
	{
		CRect rct;
		HBITMAP hBitmap;
		
		hBitmap = imgPic->GetBitmap();
		
		imgPic->GetClientRect(rct);

		if (hBitmap)
		{
			point.y -= rct.Height() + 2;

			rct.bottom = point.y + rct.Height();			rct.top = point.y;
			rct.right = point.x + rct.Width();				rct.left = point.x;

			imgPic->MoveWindow(rct, TRUE);
		}
	}
	catch(...)
	{
		return;
	}
}