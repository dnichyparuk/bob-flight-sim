#ifndef __REDTBTH__
#define __REDTBTH__

// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CREdtBt wrapper class

class CREdtBt : public CWnd
{
protected:
	DECLARE_DYNCREATE(CREdtBt)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x461a1fe3, 0xb81b, 0x11d6, { 0xa1, 0xf0, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:
	OLE_COLOR GetForeColor();
	void SetForeColor(OLE_COLOR);
	CString GetCaption();
	void SetCaption(LPCTSTR);
	long GetFontNum();
	void SetFontNum(long);
	long GetDragAndDropID();
	void SetDragAndDropID(long);
	OLE_COLOR GetBackColor();
	void SetBackColor(OLE_COLOR);
	long GetShadow();
	void SetShadow(long);

// Operations
public:
	void SetPictureFileNum(long picture);
};

#endif
