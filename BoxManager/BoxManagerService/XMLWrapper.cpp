// XMLWrapper.cpp: implementation of the XMLWrapper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "XMLWrapper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define MWS_XML_VERSION					_T("version='1.0' encoding='utf-8'")
#define	MWS_XML							_T("xml")
#define	MWS_STATUS						_T("status")
#define	MWS_SUCCESS						_T("SUCCESS")
#define MWS_CANCEL						_T("CANCEL")
#define MWS_FAIL						_T("FAIL")

IXMLDOMNodePtr XMLCreateInstance(const CString strRootElement, const BOOL bAppendXMLVersion/* = TRUE*/)
{
	IXMLDOMDocument2Ptr pDoc;
	IXMLDOMNodePtr pNode;
	try
	{
		if(strRootElement.IsEmpty())
			return NULL;

		HRESULT hr = pDoc.CreateInstance(__uuidof(DOMDocument40));
		pDoc->async = false;
		if (FAILED(hr))
			throw hr;
		if (bAppendXMLVersion)
			if (!XMLAppendXMLVersion(pDoc))
				throw hr;
		if(pNode = pDoc->createElement(_bstr_t(strRootElement)))
		{
			pDoc->appendChild(pNode);
			return pNode;
		}
		else
			return NULL;
	}
	catch(...)
	{
		if(pDoc)
			pDoc.Release();
		return NULL;
	}
}

IXMLDOMDocument2Ptr	XMLCreateInstance(const BOOL bAppendXMLVersion/* = TRUE*/)
{
	IXMLDOMDocument2Ptr pDoc;
	try
	{
		if (pDoc)
			XMLRelease(pDoc);
		HRESULT hr = pDoc.CreateInstance(__uuidof(DOMDocument40));
		pDoc->async = false;
		if (FAILED(hr))
			throw hr;
		if (bAppendXMLVersion)
			if (!XMLAppendXMLVersion(pDoc))
				throw hr;
		return pDoc;
	}
	catch(...)
	{
		pDoc.Release();
		return NULL;
	}
}

BOOL XMLRelease(IXMLDOMNodePtr pNode)
{
	try
	{
		if (pNode == NULL)
			return FALSE;
		XMLGetownerDocument(pNode).Release();
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
	return TRUE;
}

BOOL XMLRelease(IXMLDOMDocument2Ptr pDoc)
{
	try
	{
		if (pDoc)
			pDoc.Release();
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
	return TRUE;
}

BOOL XMLAppendXMLVersion(IXMLDOMDocument2Ptr pDoc)
{
	try
	{
		pDoc->appendChild(pDoc->createProcessingInstruction(_bstr_t(MWS_XML), _bstr_t(MWS_XML_VERSION)));
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
	return TRUE;
}

IXMLDOMNodePtr XMLCreateChildElement(IXMLDOMNodePtr pNode, const CString strElementName, 
							  const CString strElementValue, const UINT nAttributeCount, ...)
{
	try
	{
		IXMLDOMElementPtr pElement;
		IXMLDOMDocumentPtr pDoc = pNode->GetownerDocument();
		if (pDoc == NULL)
			return NULL;
		pElement = pDoc->createElement(_bstr_t(strElementName));
		pElement->text = (_bstr_t)strElementValue;
		va_list marker;
		va_start(marker, nAttributeCount);
		CString strAttName, strAttValue;
		for(UINT nIndex = 1 ; nIndex <= nAttributeCount ; nIndex++)
		{
			if (nIndex % 2)
				strAttName = (LPTSTR)va_arg(marker, UINT);
			else
				strAttValue = (LPTSTR)va_arg(marker, UINT);

			if (!(nIndex % 2) && !strAttName.IsEmpty())
			{
				IXMLDOMAttributePtr pAtt = pDoc->createAttribute(_bstr_t(strAttName));
				pAtt->text = (_bstr_t)strAttValue;
				pElement->setAttributeNode(pAtt);
				strAttName = strAttValue = _T("");
			}
		}
		va_end( marker );
		return pNode->appendChild(pElement);     
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodePtr XMLCreateChildElement(IXMLDOMNodePtr pNode, const CString strElementName, 
							  const int iElementValue, const UINT nAttributeCount, ...)
{
	try
	{
		IXMLDOMElementPtr pElement;
		CString strElementValue;
		IXMLDOMDocumentPtr pDoc = pNode->GetownerDocument();
		if (pDoc == NULL)
			return NULL;
		pElement = pDoc->createElement(_bstr_t(strElementName));
		strElementValue.Format(_T("%d"), iElementValue);
		pElement->text = (_bstr_t)strElementValue;
		va_list marker;
		va_start(marker, nAttributeCount);
		CString strAttName, strAttValue;
		for(UINT nIndex = 1 ; nIndex <= nAttributeCount ; nIndex++)
		{
			if (nIndex % 2)
				strAttName = (LPTSTR)va_arg(marker, UINT);
			else
				strAttValue = (LPTSTR)va_arg(marker, UINT);

			if (!(nIndex % 2) && !strAttName.IsEmpty())
			{
				IXMLDOMAttributePtr pAtt = pDoc->createAttribute(_bstr_t(strAttName));
				pAtt->text = (_bstr_t)strAttValue;
				pElement->setAttributeNode(pAtt);
				strAttName = strAttValue = _T("");
			}
		}
		va_end( marker );
		return pNode->appendChild(pElement);     
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodePtr XMLCreateChildElement(IXMLDOMNodePtr pNode, const CString strElementName, 
							  const COleDateTime tmDateTime, const UINT nAttributeCount, ...)
{
	try
	{
		IXMLDOMElementPtr pElement;
		CString strElementValue;
		IXMLDOMDocumentPtr pDoc = pNode->GetownerDocument();
		if (pDoc == NULL)
			return NULL;

		pElement = pDoc->createElement(_bstr_t(strElementName));
		if (tmDateTime.GetStatus() != COleDateTime::null)
		{
			strElementValue.Format(_T("%04d-%02d-%02d %02d:%02d:%02d"), 
				tmDateTime.GetYear(), tmDateTime.GetMonth(), tmDateTime.GetDay(),
				tmDateTime.GetHour(), tmDateTime.GetMinute(), tmDateTime.GetSecond());
		}
		pElement->text = (_bstr_t)strElementValue;
		va_list marker;
		va_start(marker, nAttributeCount);
		CString strAttName, strAttValue;
		for(UINT nIndex = 1 ; nIndex <= nAttributeCount ; nIndex++)
		{
			if (nIndex % 2)
				strAttName = (LPTSTR)va_arg(marker, UINT);
			else
				strAttValue = (LPTSTR)va_arg(marker, UINT);

			if (!(nIndex % 2) && !strAttName.IsEmpty())
			{
				IXMLDOMAttributePtr pAtt = pDoc->createAttribute(_bstr_t(strAttName));
				pAtt->text = (_bstr_t)strAttValue;
				pElement->setAttributeNode(pAtt);
				strAttName = strAttValue = _T("");
			}
		}
		va_end( marker );
		return pNode->appendChild(pElement);     
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodePtr XMLCreateChildElement(IXMLDOMNodePtr pNode, const CString strElementName, const LPBYTE lpbyData,
							  const int iDataSize, const UINT nAttributeCount, ...)
{
	try
	{
		HRESULT hResult;
		IXMLDOMElementPtr pElement;
		IXMLDOMDocumentPtr pDoc = pNode->GetownerDocument();
		if (pDoc == NULL)
			return NULL;
		pElement = pDoc->createElement(_bstr_t(strElementName));
		hResult = pElement->put_dataType(BSTR(_T("bin.base64")));
		if (FAILED(hResult))
			return NULL;
		SAFEARRAY* pSA = SafeArrayCreateVector(VT_UI1, 0L, iDataSize);
		memcpy(pSA->pvData, lpbyData, iDataSize);
		VARIANT var;
		VariantInit(&var);
		var.parray = pSA;
		var.vt = (VT_ARRAY | VT_UI1);
		//pElement->nodeTypedValue = var;
		hResult = pElement->put_nodeTypedValue(var);
		if (FAILED(hResult))
			return NULL;
		va_list marker;
		va_start(marker, nAttributeCount);
		CString strAttName, strAttValue;
		for(UINT nIndex = 1 ; nIndex <= nAttributeCount ; nIndex++)
		{
			if (nIndex % 2)
				strAttName = (LPTSTR)va_arg(marker, UINT);
			else
				strAttValue = (LPTSTR)va_arg(marker, UINT);

			if (!(nIndex % 2) && !strAttName.IsEmpty())
			{
				IXMLDOMAttributePtr pAtt = pDoc->createAttribute(_bstr_t(strAttName));
				pAtt->text = (_bstr_t)strAttValue;
				pElement->setAttributeNode(pAtt);
				strAttName = strAttValue = _T("");
			}
		}
		va_end( marker );
		return pNode->appendChild(pElement);     
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

/*
 Function :: Append pSrcNode's children to pDestNode's children
*/
BOOL XMLCloneNode(IXMLDOMNodePtr pDestNode, IXMLDOMNodePtr pSrcNode, const BOOL bOverWrite/* = FALSE*/, const BOOL bAppend/* = TRUE*/)
{
	IXMLDOMDocument2Ptr	pTempDoc;
	try
	{
		IXMLDOMNodeListPtr pSrcNodeList = pSrcNode->selectNodes(_bstr_t("*"));
		IXMLDOMNodePtr pNode, pCompareNode;
		pTempDoc.CreateInstance(__uuidof(DOMDocument40));
		while (pNode = pSrcNodeList->nextNode())
		{
			pTempDoc->loadXML(pNode->xml);
			if ((pCompareNode = pDestNode->selectSingleNode(_bstr_t(pNode->nodeName))) != NULL)
			{
				if (bOverWrite)
					pDestNode->removeChild(pCompareNode);
				if (bAppend)
					pDestNode->appendChild(pTempDoc->GetfirstChild());
			}
			else
				pDestNode->appendChild(pTempDoc->GetfirstChild());
		}
		if (pTempDoc)
			pTempDoc.Release();
	}
	catch (_com_error e)
	{
		if (pTempDoc)
			pTempDoc.Release();
		XMLSetLastError(e);
		return FALSE;
	}
	return TRUE;
}

/*
 Function :: Append pSrcNode to pDestNode's child , and Return pointer of an appended node
*/
IXMLDOMNodePtr XMLCloneNode2(IXMLDOMNodePtr pDestNode, IXMLDOMNodePtr pSrcNode, const BOOL bAppend/* = FALSE*/)
{
	IXMLDOMDocument2Ptr	pTempDoc;
	IXMLDOMNodePtr pNode;
	CString strNodeName;
	try
	{
		pTempDoc.CreateInstance(__uuidof(DOMDocument40));
		pTempDoc->loadXML(pSrcNode->xml);
		if (!bAppend)
		{
			strNodeName = LPTSTR(pTempDoc->GetfirstChild()->nodeName);
			if (pNode = XMLSelectSingleNode(pDestNode, strNodeName))
				XMLRemoveNode(pNode);
		}
		pNode = pDestNode->appendChild(pTempDoc->GetfirstChild());
		if (pTempDoc)
			pTempDoc.Release();
	}
	catch (_com_error e)
	{
		if (pTempDoc)
			pTempDoc.Release();
		XMLSetLastError(e);
		return NULL;
	}
	return pNode;
}

BOOL XMLPutChildNodeText(IXMLDOMNodePtr pParentNode, const CString strXPath, const CString strText, const BOOL bAppend/* = TRUE*/)
{
	try
	{
		if (pParentNode == NULL)
			return FALSE;
		IXMLDOMNodePtr pNode;
		if (pNode = pParentNode->selectSingleNode(_bstr_t(strXPath)))
		{
			pNode->Puttext(_bstr_t(strText));
			return TRUE;
		}
		else
		{
			if (bAppend)
			{
				XMLCreateChildElement(pParentNode, strXPath, strText);
				return TRUE;
			}
			else
				return FALSE;
		}
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLRemoveChild(IXMLDOMNodePtr pParentNode)
{
	try
	{
		if (pParentNode == NULL)
			return FALSE;
		IXMLDOMNodePtr pNode;
		IXMLDOMNodeListPtr pSrcNodeList = pParentNode->selectNodes(_bstr_t("*"));
		while (pNode = pSrcNodeList->nextNode())
			pParentNode->removeChild(pNode);
		return TRUE;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLRemoveNode(IXMLDOMNodePtr pNode)
{
	try
	{
		if (pNode == NULL)
			return FALSE;
		IXMLDOMNodePtr pParentNode = pNode->GetparentNode();
		if (pParentNode)
			pParentNode->removeChild(pNode);
		return TRUE;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

void XMLSetLastError(_com_error e)
{
	TRACE(_T("Error:\n"));
	TRACE(_T("Code = %08lx\n"), e.Error());
	TRACE(_T("Code meaning = %s\n"), (LPTSTR)e.ErrorMessage());
	TRACE(_T("Source = %s\n"), (LPTSTR)e.Source());
	TRACE(_T("Error Description = %s\n"), (LPTSTR)e.Description());
	s_strErrorStatus.Format(_T("error code = %08lx, code meaning = %s, source = %s, error description =%s"),
		e.Error(), (LPTSTR)e.Source(), (LPTSTR)e.ErrorMessage(), (LPTSTR)e.Description());
}

CString XMLGetLastError()
{
	return s_strErrorStatus;
}

BOOL XMLSetResponseStatus(IXMLDOMDocument2Ptr pDoc, const CString strXPath, XML_STAT stat)
{
	try
	{
		if (pDoc == NULL)
			return FALSE;
		
		IXMLDOMNodePtr pNode;
		CString strXMLStatus;
		pNode = XMLSelectSingleNode(pDoc, strXPath);
		if (pNode == NULL)
			return FALSE;
		
		if (stat == XML_SUCCESS)
			strXMLStatus = MWS_SUCCESS;
		else if	(stat == XML_CANCEL)
			strXMLStatus = MWS_CANCEL;
		else if (stat == XML_FAIL)
			strXMLStatus = MWS_FAIL;
		XMLAddAttribute(pNode, MWS_STATUS, strXMLStatus);
		return TRUE;
	}
	catch (_com_error e)
	{
		return FALSE;
	}
}

XML_STAT XMLGetResponseStatus(IXMLDOMDocument2Ptr pDoc, const CString strXPath)
{
	try
	{
		if (pDoc == NULL)
			return XML_FAIL;

		IXMLDOMNodePtr pNode;
		IXMLDOMNamedNodeMapPtr pAttrs;
		CString strStatus;
		if (pNode = pDoc->selectSingleNode(_bstr_t(strXPath)))
			if (pNode = XMLGetFirstChildNode(pNode))
				if (XMLGetAttributeValue(pNode, MWS_STATUS, strStatus))
					if (strStatus == MWS_SUCCESS)
						return XML_SUCCESS;
					else if (strStatus == MWS_CANCEL)
						return XML_CANCEL;
		return XML_FAIL;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return XML_FAIL;
	}
}

UINT XMLGetChildNodesCount(IXMLDOMNodePtr pNode, CString strXPath/* = _T("") */)
{
	try
	{
		if (pNode == NULL)
			return 0;

		if (strXPath.IsEmpty())
			strXPath = _T("*");
		IXMLDOMNodeListPtr pNodeList = XMLSelectNodes(pNode, strXPath);
		if (pNodeList)
			return pNodeList->Getlength();
		else
			return 0xffffffff;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return 0xffffffff;
	}
}

IXMLDOMNodePtr XMLGetFirstChildNode(IXMLDOMNodePtr pParentNode)
{
	try
	{
		if (pParentNode == NULL)
			return NULL;
		
		IXMLDOMNodePtr pChild = pParentNode->GetfirstChild();   
		if( pChild == NULL ) return NULL;
		if (pChild->GetnodeType() != NODE_ELEMENT)
			pChild = pChild->GetnextSibling();
		return pChild;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodePtr XMLGetParentNode(IXMLDOMNodePtr pNode)
{
	try
	{
		if (pNode == NULL)
			return NULL;

		return pNode->GetparentNode();
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

CString	XMLGetText(IXMLDOMNodePtr pNode)
{
	try
	{
		if (pNode == NULL)
			return _T("");

		return (LPCSTR)pNode->text;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return _T("");
	}
}

BOOL XMLGetData(IXMLDOMNodePtr pNode, LPBYTE* ppbyData, int* piDataSize)
{
	try
	{
		*piDataSize = 0;

		if (pNode == NULL)
			return FALSE;

		IXMLDOMElementPtr pElement;

		long lDataSize = 0;
		HRESULT hResult;
		hResult = SafeArrayGetUBound(pNode->nodeTypedValue.parray, 1, &lDataSize);
		if (FAILED(hResult))
			return FALSE;

		*piDataSize = ++lDataSize;

		if (NULL == ppbyData)
			return FALSE;

		*ppbyData = new BYTE[lDataSize];

		memcpy(*ppbyData, pNode->nodeTypedValue.parray->pvData, lDataSize);

		return TRUE;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLGetAttributeValue(IXMLDOMNodePtr pNode, const CString strName, CString &strValue)
{
	try
	{
		IXMLDOMNamedNodeMapPtr pAttrs = NULL;
		long lTotalAttr = 0;
		long lCountAttr = 0;
		CString strAttrName;
		CString strAttrValue;

		strValue.Empty();
		if (pNode)
			pAttrs = pNode->Getattributes();
		if (pAttrs)
			lTotalAttr = pAttrs->Getlength();
		while (lCountAttr < lTotalAttr)
		{
			strAttrName = (LPCTSTR)pAttrs->Getitem(lCountAttr)->GetnodeName();
			if (strAttrName.CompareNoCase(strName) == 0)
			{
				strAttrValue = (LPCTSTR)(_bstr_t)pAttrs->Getitem(lCountAttr)->GetnodeValue();
				strValue = strAttrValue;
				break;
			}
			lCountAttr++;
		}
		if (pAttrs == NULL || strAttrValue.IsEmpty())
			return FALSE;
		return TRUE;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLGetChildNodeValue(IXMLDOMNodePtr pParentNode, const CString strXPath, CString &strValue)
{
	try
	{
		if (pParentNode == NULL)
			return FALSE;

		IXMLDOMNodePtr pNode;
		if (pNode = pParentNode->selectSingleNode(_bstr_t(strXPath)))
		{
			strValue = (LPCTSTR)pNode->text;
			return TRUE;
		}
		else
		{
			strValue.Empty();		//by khpark 0712
			return FALSE;
		}
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLGetChildNodeValue2(IXMLDOMNodePtr pParentNode, const CString strXPath, CString &strValue)
{
	try
	{
		if (pParentNode == NULL)
			return FALSE;

		IXMLDOMNodePtr pNode;
		if (pNode = pParentNode->selectSingleNode(_bstr_t(strXPath)))
		{
			strValue = (LPCTSTR)pNode->text;
			if (strValue.IsEmpty())
				return FALSE;
			else 
				return TRUE;
		}
		else
		{
			strValue.Empty();		//by khpark 0712
			return FALSE;
		}
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

IXMLDOMDocument2Ptr XMLGetownerDocument(IXMLDOMNodePtr pNode)
{
	try
	{
		if (pNode == NULL)
			return NULL;
		
		return (IXMLDOMDocument*)pNode->GetownerDocument();
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodePtr XMLSelectSingleNode(IXMLDOMNodePtr pNode, const CString strXPath)
{
	try
	{
		if (pNode == NULL)
			return NULL;
		
		return pNode->selectSingleNode(_bstr_t(strXPath));
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodePtr XMLSelectSingleNode(IXMLDOMDocument2Ptr pDoc, const CString strXPath)
{
	try
	{
		if (pDoc == NULL)
			return NULL;

		return pDoc->selectSingleNode(_bstr_t(strXPath));
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodeListPtr XMLSelectNodes(IXMLDOMNodePtr pNode, const CString strXPath)
{
	try
	{
		if (pNode == NULL)
			return NULL;

		return pNode->selectNodes(_bstr_t(strXPath));
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

IXMLDOMNodeListPtr XMLSelectNodes(IXMLDOMDocument2Ptr pDoc, const CString strXPath)
{
	try
	{
		return pDoc->selectNodes(_bstr_t(strXPath));
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

BOOL XMLExistsElement(IXMLDOMNodePtr pNode, const CString strXPath)
{
	try
	{
		if (pNode == NULL)
			return FALSE;

		if (pNode->selectSingleNode(_bstr_t(strXPath)))
			return TRUE;
		else 
			return FALSE;
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLSave(IXMLDOMDocument2Ptr pDoc, const CString strFilename)
{
	if (pDoc == NULL)
		return FALSE;

	try
	{
		HRESULT hResult;
		DWORD dwFileAttr;
		BOOL	bReadOnly = FALSE;

		dwFileAttr = GetFileAttributes(strFilename);
		if(dwFileAttr != -1)
		{
			bReadOnly = (dwFileAttr & FILE_ATTRIBUTE_READONLY);
			if(bReadOnly)
			{
				dwFileAttr &= ~FILE_ATTRIBUTE_READONLY;
				if(!SetFileAttributes(strFilename, dwFileAttr))
					return FALSE;
			}
		}
		
		hResult = pDoc->save(_bstr_t(strFilename));

		if(bReadOnly)
		{
			dwFileAttr |= FILE_ATTRIBUTE_READONLY;
			SetFileAttributes(strFilename, dwFileAttr);
		}

		/*
		if(hResult)
			return TRUE;
		else
			return FALSE;
		*/
		
		return SUCCEEDED(hResult);
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLSave(IXMLDOMNodePtr pNode,  const CString strFilename)
{
	return XMLSave(XMLGetownerDocument(pNode), strFilename);
}

BOOL XMLLoad(IXMLDOMDocument2Ptr pDoc, const CString strFilename)
{
	try
	{
		HRESULT hResult;
		CFileFind	ff;
		if (pDoc == NULL)
			return FALSE;

		if (!ff.FindFile(strFilename))
			return FALSE;

		hResult = pDoc->load(_bstr_t(strFilename));

		if(hResult)
			return TRUE;
		else
			return FALSE;

//		return SUCCEEDED(hResult);

	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

BOOL XMLLoad(IXMLDOMNodePtr pNode, const CString strFilename)
{
	return XMLLoad(XMLGetownerDocument(pNode) , strFilename);
}
/*
 	made by khpark , 20040520
	Set Attribute's value

	++modified by khpark , 20040811
*/
BOOL XMLSetAttrValue(IXMLDOMNodePtr pNode , CString strAttrName , CString strAttrValue)
{
	if(pNode == NULL || strAttrName.IsEmpty())
		return FALSE;

	try
	{
		IXMLDOMNamedNodeMapPtr pAttrMap = NULL;
		IXMLDOMAttributePtr pAttr = NULL;

		pAttrMap = pNode->Getattributes();
		if(pAttrMap == NULL)
			return FALSE;

		pAttr = pAttrMap->getNamedItem((_bstr_t)(LPCTSTR)strAttrName);
		if(pAttr == NULL)
			return FALSE;

		pAttr->PutnodeValue((_bstr_t)(LPCTSTR)strAttrValue);
		return TRUE;

/*		
		long lTotalAttr = 0;
		long lCountAttr = 0;
		CString strTmpAttrName;

		if (pAttrMap)
			lTotalAttr = pAttrMap->Getlength();
		else
			return FALSE;

		while (lCountAttr < lTotalAttr)
		{
			strTmpAttrName = (LPCTSTR)pAttrMap->Getitem(lCountAttr)->GetnodeName();
			if (strTmpAttrName.CompareNoCase(strAttrName) == 0)
			{
				pAttrMap->Getitem(lCountAttr)->PutnodeValue((_bstr_t)(LPCTSTR)strAttrValue);
				break;				
			}
			lCountAttr++;
		}
		
		if(lCountAttr == lTotalAttr)
			return FALSE;

		return TRUE;
*/
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}
/*
 	made by khpark , 20040520
	Search the first node matching given conditions( pairs of attribute-name and attribute-value )
*/
IXMLDOMNodePtr XMLSearchNode(IXMLDOMNodePtr pSearchNode, const CString strSearchNodeName, const UINT nAttributeCount, ...)
{
	IXMLDOMNodeListPtr	pNodeList;
	IXMLDOMNodePtr		pNode;
	int i , iNodeCount;
	CString strAttrName, strAttrValue , strValue;
	BOOL bFound = TRUE;

	pNodeList = XMLSelectNodes(pSearchNode , strSearchNodeName);
	if(pNodeList == NULL)
		return NULL;

	iNodeCount = pNodeList->Getlength();
	for(i=0 ; i< iNodeCount ; i++)
	{
		pNode = pNodeList->nextNode();
		bFound = TRUE;

		va_list marker;
		va_start(marker, nAttributeCount);
		for(UINT nIndex = 1 ; nIndex <= nAttributeCount ; nIndex++)
		{
			if (nIndex % 2)
				strAttrName = (LPTSTR)va_arg(marker, UINT);
			else
				strAttrValue = (LPTSTR)va_arg(marker, UINT);

			if (!(nIndex % 2) && !strAttrValue.IsEmpty())
			{
				XMLGetAttributeValue(pNode , strAttrName , strValue);
				if(strValue != strAttrValue)
				{
					bFound = FALSE;
					break;
				}
			}
		}
		va_end( marker );

		if(bFound)
			return pNode;
	}

	return NULL;
}

IXMLDOMNodePtr XMLSearchNode(IXMLDOMNodePtr pSearchNode, const CString strSearchNodeName, const CString strSearchNodeValue)
{
	IXMLDOMNodePtr pNode;
	IXMLDOMNodeListPtr pNodeList;
	CString strNodeValue;

	try
	{
		if (pSearchNode == NULL)
			return NULL;
			
		pNodeList = XMLSelectNodes(pSearchNode, strSearchNodeName);	
		if (pNodeList == NULL || pNodeList->length < 1)
			return NULL;
		
		while (pNode = pNodeList->nextNode())
		{
			if ((LPCSTR)pNode->text == strSearchNodeValue)
				break;
		}
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
	return pNode;
}

/*
 	made by khpark , 20040520
	CreateElement & Insert before a referenced Node(pRefNode)
*/
IXMLDOMNodePtr XMLCreateElementInsertBefore(IXMLDOMNodePtr pRefNode ,/* IXMLDOMNodePtr pNode,*/ const CString strElementName, 
							  const CString strElementValue, const UINT nAttributeCount, ...)
{
	try
	{
		IXMLDOMNodePtr		pParentNode;
		IXMLDOMElementPtr	pElement;
		IXMLDOMDocumentPtr	pDoc = pRefNode->GetownerDocument();
		if (pDoc == NULL)
			return NULL;

		pParentNode = pRefNode->GetparentNode();
		if(pParentNode==NULL)
			return NULL;

		pElement = pDoc->createElement(_bstr_t(strElementName));
		pElement->text = (_bstr_t)strElementValue;
		va_list marker;
		va_start(marker, nAttributeCount);
		CString strAttName, strAttValue;
		for(UINT nIndex = 1 ; nIndex <= nAttributeCount ; nIndex++)
		{
			if (nIndex % 2)
				strAttName = (LPTSTR)va_arg(marker, UINT);
			else
				strAttValue = (LPTSTR)va_arg(marker, UINT);

			if (!(nIndex % 2) && !strAttName.IsEmpty())
			{
				IXMLDOMAttributePtr pAtt = pDoc->createAttribute(_bstr_t(strAttName));
				pAtt->text = (_bstr_t)strAttValue;
				pElement->setAttributeNode(pAtt);
				strAttName = strAttValue = _T("");
			}
		}
		va_end( marker );
		
		VARIANT varRefNode;
		varRefNode.vt = VT_UNKNOWN;
		varRefNode.punkVal = pRefNode;

		return pParentNode->insertBefore(pElement , varRefNode);
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}

/*
	made by khpark , 20040811
	Add an attribute to a specified node with attribute's name & value
	If the attribute to be added already exists, this will only change the attribute's value
*/
BOOL XMLAddAttribute(IXMLDOMNodePtr pNode , CString strAttrName , CString strAttrValue)
{
	if(pNode == NULL || strAttrName.IsEmpty())
		return FALSE;

	try
	{
		IXMLDOMDocument2Ptr pDoc;		
		IXMLDOMNamedNodeMapPtr pAttrMap = NULL;
		IXMLDOMAttributePtr	pAttr = NULL;

		pDoc = XMLGetownerDocument(pNode);
		pAttrMap = pNode->Getattributes();
		if(pDoc == NULL || pAttrMap == NULL)
			return FALSE;

		pAttr = pAttrMap->getNamedItem((_bstr_t)(LPCTSTR)strAttrName);
		if(pAttr)
		{
			pAttr->PutnodeValue((_bstr_t)(LPCTSTR)strAttrValue);
			return TRUE;
		}
		else
		{
			pAttr = pDoc->createAttribute((_bstr_t)(LPCTSTR)strAttrName);
			if(pAttr == NULL)
				return FALSE;

			pAttr->PutnodeValue((_bstr_t)(LPCTSTR)strAttrValue);
			pAttrMap->setNamedItem(pAttr);
			return TRUE;
		}
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return FALSE;
	}
}

/*

*/
IXMLDOMNodePtr XMLAddChildElement(IXMLDOMNodePtr pNode, 
									 const CString strElementName, 
									 const CString strElementValue,
									 const BOOL bOverWrite/*=TRUE*/ )
{
	if(pNode == NULL || strElementName.IsEmpty())
		return NULL;
	
	try
	{
		IXMLDOMNodePtr pTempNode;
		pTempNode = XMLSelectSingleNode(pNode, strElementName);
		if(pTempNode == NULL)
		{
			return XMLCreateChildElement(pNode, strElementName, strElementValue);
		}
		else
		{
			if(!bOverWrite)
				return NULL;
			else
			{
				pTempNode->Puttext(_bstr_t(strElementValue));
				return pTempNode;
			}
		}
	}
	catch (_com_error e)
	{
		XMLSetLastError(e);
		return NULL;
	}
}