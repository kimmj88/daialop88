#ifndef	__SYSTEMINFO_H
#define	__SYSTEMINFO_H

#import "msxml4.dll"
//using namespace MSXML2; //hsshin migration deleted.

enum NODE_KIND
{
	NODE_TITLE				= 0,
	NODE_COMPANYLOGO		= 1,
	NODE_SOLUTIONLOGO		= 2,
	NODE_CELOGO				= 3,
	NODE_PRODUCTNAME		= 4,
	NODE_COPYRIGHT			= 5,
	NODE_CONTACT_INFO		= 6,
	NODE_REGISTRAION_INFO	= 7,
	NODE_REGISTRY_ROOT		= 8,
	NODE_COMPANY_NAME		= 9,
	NODE_SERVICE_DISPLAY_NAME = 10,
	NODE_DEFAULT_DIRECTORY_ROOT = 11
}; 

struct SYSTEMINFO
{
	NODE_KIND	nNodeKind;
	char*		pszNodeName;
	char		pszValue[300];
};


static struct SYSTEMINFO g_SystemInfoList[] =
{
	NODE_TITLE,					"title",					"",
	NODE_COMPANYLOGO,			"company_logo",				"",
	NODE_SOLUTIONLOGO,			"solution_logo",			"",
	NODE_CELOGO,				"ce_logo",					"",
	NODE_PRODUCTNAME,			"product_name",				"",
	NODE_COPYRIGHT,				"copyright_info",			"",
	NODE_CONTACT_INFO,			"contact_info",				"",
	NODE_REGISTRAION_INFO,		"registation_info",			"",
	NODE_REGISTRY_ROOT,			"registry_root",			"",
	NODE_COMPANY_NAME,			"company_name",				"",
	NODE_SERVICE_DISPLAY_NAME,	"service_display_name",		"",
	NODE_DEFAULT_DIRECTORY_ROOT,"default_directory_root",	""
};

/////////////////////////////////////////////////////////////////

#define SYSTEMINFO_FILENAME		_T("system_info.dll")

class CSystemInfo : public CObject 
{
private:
	CString				m_strExcutePath;
	CString				m_strSystemInfoPath;
	BOOL				m_bSystemInfoLoadStatus;
	BOOL				ParseXML(CString& strValue, CString strElement, MSXML2::IXMLDOMNodePtr pParentNode);
	MSXML2::IXMLDOMDocumentPtr	pXMLDoc;
	
public:
	CSystemInfo();
	CSystemInfo(const char* pszSystemInfoPath);
	~CSystemInfo();

	BOOL LoadSystemInfo();
	BOOL IsLoadSystemInfo();
	void GetSystemInfo(CString& strValue, NODE_KIND nNode);
	void GetSystemInfo(HBITMAP& hBitmap, NODE_KIND nNode);
	
	void MoveImage(CPoint& point, CStatic* imgPic);
};

#endif	// __SYSTEMINFO_H