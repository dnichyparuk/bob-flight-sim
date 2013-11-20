#ifndef __RSTATICH__
#define __RSTATICH__
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CRStatic wrapper class

class CRStatic : public CWnd
{
protected:
	DECLARE_DYNCREATE(CRStatic)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0xc42bac3d, 0xca3c, 0x11d6, { 0xa1, 0xf0, 0x44, 0x45, 0x53, 0x54, 0x0, 0x0 } };
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
	CString GetCaption();
	void SetCaption(LPCTSTR);
	OLE_COLOR GetForeColor();
	void SetForeColor(OLE_COLOR);
	BOOL GetUpdateCaption();
	void SetUpdateCaption(BOOL);
	long GetFontNum();
	void SetFontNum(long);
	CString GetString();
	void SetString(LPCTSTR);
	long GetResourceNumber();
	void SetResourceNumber(long);
	long GetPictureFileNum();
	void SetPictureFileNum(long);
	BOOL GetCentral();
	void SetCentral(BOOL);

// Operations
public:
};

#endif