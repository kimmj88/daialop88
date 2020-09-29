// XMLWrapper.h: interface for the XMLWrapper class.
// Date		: 2004/05/18
// Version	: 1.1
// Author	: Park Chul Hyun (javagoo@infinitt.com)
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_XMLWRAPPER_H__161B31E1_5472_4518_805C_B0FF0051697A__INCLUDED_)
#define AFX_XMLWRAPPER_H__161B31E1_5472_4518_805C_B0FF0051697A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxdisp.h>
#import "msxml4.dll"
using namespace MSXML2;

//VS2008 migration added.(hsshin)
#define IXMLDOMNodePtr			MSXML2::IXMLDOMNodePtr
#define IXMLDOMDocumentPtr		MSXML2::IXMLDOMDocumentPtr
#define IXMLDOMNodeListPtr		MSXML2::IXMLDOMNodeListPtr
#define IXMLDOMElementPtr 		MSXML2::IXMLDOMElementPtr 
#define IXMLDOMAttributePtr		MSXML2::IXMLDOMAttributePtr
#define IXMLDOMNamedNodeMapPtr	MSXML2::IXMLDOMNamedNodeMapPtr
#define IXMLDOMDocument			MSXML2::IXMLDOMDocument
#define NODE_ELEMENT			MSXML2::NODE_ELEMENT


#pragma warning(disable:4786)
enum XML_STAT
{
	XML_SUCCESS,
	XML_CANCEL,
	XML_FAIL
};
static	CString				s_strErrorStatus;
extern	IXMLDOMNodePtr		XMLCreateInstance(CString strRootElement, const BOOL bAppendXMLVersion = TRUE);
extern	IXMLDOMDocument2Ptr	XMLCreateInstance(const BOOL bAppendXMLVersion = TRUE);
extern	BOOL				XMLRelease(IXMLDOMNodePtr pNode);
extern	BOOL				XMLRelease(IXMLDOMDocument2Ptr pDoc);
extern	BOOL				XMLAppendXMLVersion(IXMLDOMDocument2Ptr pDoc);
extern	IXMLDOMNodePtr		XMLCreateChildElement(IXMLDOMNodePtr pNode, 
													 const CString strElementName,
													 const CString strElementValue, 
													 const UINT nAttributeCount = 0, ...);
extern	IXMLDOMNodePtr		XMLCreateChildElement(IXMLDOMNodePtr pNode, 
													 const CString strElementName,
													 const int iElementValue, 
													 const UINT nAttributeCount = 0, ...);
extern	IXMLDOMNodePtr		XMLCreateChildElement(IXMLDOMNodePtr pNode, 
													 const CString strElementName,
													 const COleDateTime tmDateTime, 
													 const UINT nAttributeCount = 0, ...);
extern	IXMLDOMNodePtr		XMLCreateChildElement(IXMLDOMNodePtr pNode,
													 const CString strElementName,
													 const LPBYTE lpbyData,
													 const int iDataSize,
													 const UINT nAttributeCount = 0, ...);
extern	BOOL				XMLCloneNode(IXMLDOMNodePtr pDestNode, IXMLDOMNodePtr pSrcNode,
											const BOOL bOverWrite = FALSE, const BOOL bAppend = TRUE);
extern	IXMLDOMNodePtr		XMLCloneNode2(IXMLDOMNodePtr pDestNode, IXMLDOMNodePtr pSrcNode,
											 const BOOL bAppend = FALSE);
extern	BOOL				XMLPutChildNodeText(IXMLDOMNodePtr pParentNode, const CString strXPath,
												   const CString strText, const BOOL bAppend = TRUE);
extern	BOOL				XMLRemoveChild(IXMLDOMNodePtr pParentNode);
extern	BOOL				XMLRemoveNode(IXMLDOMNodePtr pNode);
extern	void				XMLSetLastError(_com_error e);
extern	CString				XMLGetLastError();
extern	BOOL				XMLSetResponseStatus(IXMLDOMDocument2Ptr pDoc, const CString strXPath, XML_STAT stat);
extern	XML_STAT			XMLGetResponseStatus(IXMLDOMDocument2Ptr pDoc, const CString strXPath);
extern	UINT				XMLGetChildNodesCount(IXMLDOMNodePtr pNode, CString strXPath = _T(""));
extern	IXMLDOMNodePtr		XMLGetFirstChildNode(IXMLDOMNodePtr pParentNode);
extern	IXMLDOMNodePtr		XMLGetParentNode(IXMLDOMNodePtr pNode);
extern	CString				XMLGetText(IXMLDOMNodePtr pNode);
extern	BOOL				XMLGetData(IXMLDOMNodePtr pNode, LPBYTE* ppbyData, int* piDataSize);
extern	BOOL				XMLGetAttributeValue(IXMLDOMNodePtr pNode, const CString strName, CString &strValue);
extern	BOOL				XMLGetChildNodeValue(IXMLDOMNodePtr pParentNode, const CString strXPath,
													CString &strValue);
extern	BOOL				XMLGetChildNodeValue2(IXMLDOMNodePtr pParentNode, const CString strXPath,
													CString &strValue);
extern	IXMLDOMDocument2Ptr	XMLGetownerDocument(IXMLDOMNodePtr pNode);
extern	IXMLDOMNodePtr		XMLSelectSingleNode(IXMLDOMNodePtr pNode, const CString strXPath);
extern	IXMLDOMNodePtr		XMLSelectSingleNode(IXMLDOMDocument2Ptr pDoc, const CString strXPath);
extern	IXMLDOMNodeListPtr	XMLSelectNodes(IXMLDOMNodePtr pNode, const CString strXPath);
extern	IXMLDOMNodeListPtr	XMLSelectNodes(IXMLDOMDocument2Ptr pDoc, const CString strXPath);
extern	BOOL				XMLExistsElement(IXMLDOMNodePtr pNode, const CString strXPath);
extern	BOOL				XMLSave(IXMLDOMDocument2Ptr pDoc, const CString strFilename);
extern	BOOL				XMLSave(IXMLDOMNodePtr pNode, const CString strFilename);
extern	BOOL				XMLLoad(IXMLDOMDocument2Ptr pDoc, const CString strFilename);
extern	BOOL				XMLLoad(IXMLDOMNodePtr pNode, const CString strFilename);
extern	BOOL				XMLSetAttrValue(IXMLDOMNodePtr pNode , CString strName , CString strValue);
extern	BOOL				XMLAddAttribute(IXMLDOMNodePtr pNode , CString strAttrName , CString strAttrValue);
extern	IXMLDOMNodePtr		XMLSearchNode(IXMLDOMNodePtr pSearchNode, const CString strSearchNodeName, 
											const UINT nAttributeCount, ...);
extern	IXMLDOMNodePtr		XMLSearchNode(IXMLDOMNodePtr pSearchNode, const CString strSearchNodeName,
											 const CString strSearchNodeValue);
extern	IXMLDOMNodePtr		XMLCreateElementInsertBefore(IXMLDOMNodePtr pRefNode , const CString strElementName, 
							  const CString strElementValue, const UINT nAttributeCount, ...);
extern	IXMLDOMNodePtr		XMLAddChildElement(IXMLDOMNodePtr pNode, const CString strElementName, 
												 const CString strElementValue, const BOOL bOverWrite = TRUE );

#endif // !defined(AFX_XMLWRAPPER_H__161B31E1_5472_4518_805C_B0FF0051697A__INCLUDED_)
